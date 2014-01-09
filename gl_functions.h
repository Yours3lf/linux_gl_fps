#ifndef gl_functions_h
#define gl_functions_h

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glext.h>

#define TOUBYTE(x) (const GLubyte*)(x)

static PFNGLUSEPROGRAMPROC glUseProgram;
static PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
static PFNGLBINDBUFFERPROC glBindBuffer;
static PFNGLCREATESHADERPROC glCreateShader;
static PFNGLSHADERSOURCEPROC glShaderSource;
static PFNGLCOMPILESHADERPROC glCompileShader;
static PFNGLGETSHADERIVPROC glGetShaderiv;
static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
static PFNGLATTACHSHADERPROC glAttachShader;
static PFNGLDELETESHADERPROC glDeleteShader;
static PFNGLLINKPROGRAMPROC glLinkProgram;
static PFNGLGETPROGRAMIVPROC glGetProgramiv;
static PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
static PFNGLVALIDATEPROGRAMPROC glValidateProgram;
static PFNGLCREATEPROGRAMPROC glCreateProgram;
static PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
static PFNGLDELETEBUFFERSPROC glDeleteBuffers;
static PFNGLDELETEPROGRAMPROC glDeleteProgram;
static PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
static PFNGLGENBUFFERSPROC glGenBuffers;
static PFNGLBUFFERDATAPROC glBufferData;
static PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
static PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
static PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
static PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
static PFNGLUNIFORM3FVPROC glUniform3fv;
static PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;

static void load_gl_functions()
{
  glUseProgram = ( PFNGLUSEPROGRAMPROC )( glXGetProcAddress( TOUBYTE( "glUseProgram" ) ) );
  glBindVertexArray = ( PFNGLBINDVERTEXARRAYPROC )( glXGetProcAddress( TOUBYTE( "glBindVertexArray" ) ) );
  glBindBuffer = ( PFNGLBINDBUFFERPROC )( glXGetProcAddress( TOUBYTE( "glBindBuffer" ) ) );
  glCreateShader = ( PFNGLCREATESHADERPROC )( glXGetProcAddress( TOUBYTE( "glCreateShader" ) ) );
  glShaderSource = ( PFNGLSHADERSOURCEPROC )( glXGetProcAddress( TOUBYTE( "glShaderSource" ) ) );
  glCompileShader = ( PFNGLCOMPILESHADERPROC )( glXGetProcAddress( TOUBYTE( "glCompileShader" ) ) );
  glGetShaderiv = ( PFNGLGETSHADERIVPROC )( glXGetProcAddress( TOUBYTE( "glGetShaderiv" ) ) );
  glGetShaderInfoLog = ( PFNGLGETSHADERINFOLOGPROC )( glXGetProcAddress( TOUBYTE( "glGetShaderInfoLog" ) ) );
  glAttachShader = ( PFNGLATTACHSHADERPROC )( glXGetProcAddress( TOUBYTE( "glAttachShader" ) ) );
  glDeleteShader = ( PFNGLDELETESHADERPROC )( glXGetProcAddress( TOUBYTE( "glDeleteShader" ) ) );
  glLinkProgram = ( PFNGLLINKPROGRAMPROC )( glXGetProcAddress( TOUBYTE( "glLinkProgram" ) ) );
  glGetProgramiv = ( PFNGLGETPROGRAMIVPROC )( glXGetProcAddress( TOUBYTE( "glGetProgramiv" ) ) );
  glGetProgramInfoLog = ( PFNGLGETPROGRAMINFOLOGPROC )( glXGetProcAddress( TOUBYTE( "glGetProgramInfoLog" ) ) );
  glValidateProgram = ( PFNGLVALIDATEPROGRAMPROC )( glXGetProcAddress( TOUBYTE( "glValidateProgram" ) ) );
  glCreateProgram = ( PFNGLCREATEPROGRAMPROC )( glXGetProcAddress( TOUBYTE( "glCreateProgram" ) ) );
  glDeleteVertexArrays = ( PFNGLDELETEVERTEXARRAYSPROC )( glXGetProcAddress( TOUBYTE( "glDeleteVertexArrays" ) ) );
  glDeleteBuffers = ( PFNGLDELETEBUFFERSPROC )( glXGetProcAddress( TOUBYTE( "glDeleteBuffers" ) ) );
  glDeleteProgram = ( PFNGLDELETEPROGRAMPROC )( glXGetProcAddress( TOUBYTE( "glDeleteProgram" ) ) );
  glGenVertexArrays = ( PFNGLGENVERTEXARRAYSPROC )( glXGetProcAddress( TOUBYTE( "glGenVertexArrays" ) ) );
  glGenBuffers = ( PFNGLGENBUFFERSPROC )( glXGetProcAddress( TOUBYTE( "glGenBuffers" ) ) );
  glBufferData = ( PFNGLBUFFERDATAPROC )( glXGetProcAddress( TOUBYTE( "glBufferData" ) ) );
  glEnableVertexAttribArray = ( PFNGLENABLEVERTEXATTRIBARRAYPROC )( glXGetProcAddress( TOUBYTE( "glEnableVertexAttribArray" ) ) );
  glVertexAttribPointer = ( PFNGLVERTEXATTRIBPOINTERPROC )( glXGetProcAddress( TOUBYTE( "glVertexAttribPointer" ) ) );
  glVertexAttribDivisor = ( PFNGLVERTEXATTRIBDIVISORPROC )( glXGetProcAddress( TOUBYTE( "glVertexAttribDivisor" ) ) );
  glUniformMatrix4fv = ( PFNGLUNIFORMMATRIX4FVPROC )( glXGetProcAddress( TOUBYTE( "glUniformMatrix4fv" ) ) );
  glUniform3fv = ( PFNGLUNIFORM3FVPROC )( glXGetProcAddress( TOUBYTE( "glUniform3fv" ) ) );
  glDrawElementsInstanced = ( PFNGLDRAWELEMENTSINSTANCEDPROC )( glXGetProcAddress( TOUBYTE( "glDrawElementsInstanced" ) ) );
}

#endif

