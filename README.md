linux_gl_fps
============

Display the fps via LD_PRELOAD on linux games.

Depends on: 
-libmymath: https://github.com/Yours3lf/libmymath
-instanced_font_rendering: https://github.com/Yours3lf/instanced_font_rendering
-SFML: http://sfml-dev.org/
-GLEW: http://glew.sourceforge.net/
-freetype: http://www.freetype.org/

build by:
mkdir build
cd build
cmake ..
make

todo before running a game:
copy the resources/shaders folders (from the instanced font lib) to /home/[user_name]/.linux_gl_fps/
copy the built .so file to /home/[user_name]/.linux_gl_fps/
(rename the 32 bit to .so.32, 64 to .so.64 just for the sake of knowing which is which)

start games by:
LD_PRELOAD=/home/[user_name]/.linux_gl_fps/liblinux_gl_fps.so.32 ./game_exe

for steam games you need to set up the launch options like this:
LD_PRELOAD="/home/[user_name]/.linux_gl_fps/liblinux_gl_fps.so.32" %command%

you need to build a 64 bit version for 64 bit game exes, 32 bit version for 32 bit game exes.

TESTED:

works: 
* world of goo
* unity based games
* chromium-bsu
* neverball
* vertigo
* amnesia
* red eclipse
* world-of-padman
* xonotic
* cube2 sauerbraten
* cube2 metalheart
* cube2 metalheart2 combat squared

doesn't work: 
* metro last light (it seems to use glxswapbuffers, but I fear that it uses it the same way as SDL does)
* alien-arena (seems to be using xfree86, like what the hell, this is the third buffer swapping lib... srsly )
* penumbra ep1 (probably libstdc++ version mismatch), mars a ridiculous shooter (probably sfml .so version mismatch)
* overgrowth (a204)
* source-engine based games (probably because of cheat protection, they seem to be linking to stuff statically, except c / c++)

glitchy: 
* stuntrally (the menu works, but in the game the fps is in the car window reflection, which is cool but not what I wanted :D )