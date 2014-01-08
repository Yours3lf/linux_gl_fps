#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <fstream>

#include "mymath/mymath.h"

#include "SFML/System.hpp"

#include "font.h"

#include <GL/glx.h>

#define STRINGIFY(s) #s
#define INFOLOG_SIZE 4096
#define LINUX_GL_FPS_API extern "C"

using namespace std;
using namespace mymath;

typedef void( *swap_func )( Display*, GLXDrawable );

LINUX_GL_FPS_API void init( void ) __attribute__( ( constructor ) );

static void ( *old_glXSwapBuffers )( Display* display, GLXDrawable drawable );

void compile_shader( const char* text, const GLuint& program, const GLenum& type );
void link_shader( const GLuint& shader_program );
void load_shader( GLuint& program, const GLenum& type, const string& filename );

font_inst instance;
int size = 22;
uvec2 screen( 1280, 720 );
wstring text;
sf::Clock timer;
unsigned int frame_count = 0;
wstring fpstext = L"";
wstringstream ss;

// shaders and the font file are located at
// ~/.linux_gl_fps/
// therefore we need the home path
string homepath = "";

LINUX_GL_FPS_API void init( void )
{
  old_glXSwapBuffers = ( swap_func )dlsym( RTLD_NEXT, "glXSwapBuffers" );

  cerr << " -- linux_gl_fps: functions registered" << endl;
  homepath = string( getenv( "HOME" ) ) + "/";
  cerr << " -- linux_gl_fps: home at --> " << homepath << endl;
}

void get_screen_size()
{
  int viewport[4];
  glGetIntegerv( GL_VIEWPORT, viewport );
  screen = uvec2( viewport[2], viewport[3] );
}

LINUX_GL_FPS_API void glXSwapBuffers( Display* display, GLXDrawable drawable )
{
  //glXGetFBConfigAttrib();
  //load shader if not loaded yet
  if( !font::get().get_shader() && glXGetCurrentContext() )
  {
    GLenum glew_error = glewInit();

    if( glew_error != GLEW_OK )
    {
      cerr << " -- linux_gl_fps: Error initializing GLEW: " << glewGetErrorString( glew_error ) << endl;
    }

    load_shader( font::get().get_shader(), GL_VERTEX_SHADER, homepath + ".linux_gl_fps/shaders/font/font.vs" );
    load_shader( font::get().get_shader(), GL_FRAGMENT_SHADER, homepath + ".linux_gl_fps/shaders/font/font.ps" );

    cerr << " -- linux_gl_fps: shaders loaded" << endl;

    get_screen_size();
    font::get().resize( screen );

    cerr << " -- linux_gl_fps: screen size: " << screen << endl;

    font::get().load_font( homepath + ".linux_gl_fps/resources/font.ttf", instance, size );

    cerr << " -- linux_gl_fps: font initialized" << endl;
  }

  ++frame_count;

  if( timer.getElapsedTime().asMilliseconds() > 1000 )
  {
    int timepassed = timer.getElapsedTime().asMilliseconds();
    int fps = 1000.0f / ( ( float ) timepassed / ( float ) frame_count );

    ss << L"FPS: " << fps
       << L" - Time: " << ( float ) timepassed / ( float ) frame_count;

    fpstext = ss.str();
    ss.str( L"" );

    frame_count = 0;
    timer.restart();
  }

  if( font::get().get_shader() && glXGetCurrentContext() )
  {
    get_screen_size();
    font::get().resize( screen );
    font::get().add_to_text( instance, fpstext.c_str() );
    font::get().render( instance, vec3( 1 ), uvec2( 10 ) );
  }

  ( *old_glXSwapBuffers )( display, drawable ); //call original function
}

void compile_shader( const char* text, const GLuint& program, const GLenum& type )
{
  GLchar infolog[INFOLOG_SIZE];

  GLuint id = glCreateShader( type );
  glShaderSource( id, 1, &text, 0 );
  glCompileShader( id );

  GLint success;
  glGetShaderiv( id, GL_COMPILE_STATUS, &success );

  if( !success )
  {
    glGetShaderInfoLog( id, INFOLOG_SIZE, 0, infolog );
    cerr << infolog << endl;
  }
  else
  {
    glAttachShader( program, id );
    glDeleteShader( id );
  }
}

void link_shader( const GLuint& shader_program )
{
  glLinkProgram( shader_program );

  GLint success;
  glGetProgramiv( shader_program, GL_LINK_STATUS, &success );

  if( !success )
  {
    GLchar infolog[INFOLOG_SIZE];
    glGetProgramInfoLog( shader_program, INFOLOG_SIZE, 0, infolog );
    cout << infolog << endl;
  }

  glValidateProgram( shader_program );

  glGetProgramiv( shader_program, GL_VALIDATE_STATUS, &success );

  if( !success )
  {
    GLchar infolog[INFOLOG_SIZE];
    glGetProgramInfoLog( shader_program, INFOLOG_SIZE, 0, infolog );
    cout << infolog << endl;
  }
}

void load_shader( GLuint& program, const GLenum& type, const string& filename )
{
  ifstream f( filename );

  if( !f ) cerr << "Couldn't load shader: " << filename << endl;

  string str( ( istreambuf_iterator<char>( f ) ),
              istreambuf_iterator<char>() );

  if( !program ) program = glCreateProgram();

  compile_shader( str.c_str(), program, type );
  link_shader( program );
}
