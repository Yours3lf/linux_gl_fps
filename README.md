linux_gl_fps
============

Display the fps via LD_PRELOAD on linux games.

Depends on: 
-libmymath: https://github.com/Yours3lf/libmymath
-instanced_font_rendering: https://github.com/Yours3lf/instanced_font_rendering
-SFML
-GL
-GLEW
-freetype

build by:
mkdir build
cd build
cmake ..
make

todo before running a game:
copy the resources/shaders folders (from the instanced font lib) to /home/[user_name]/.linux_gl_fps/
copy the built .so file to /home/[user_name]/.linux_gl_fps/

start games by:
export LD_PRELOAD=/home/[user_name]/.linux_gl_fps/liblinux_gl_fps.so
./game_exe

you need to build a 64 bit version for 64 bit game exes, 32 bit version for 32 bit game exes.
