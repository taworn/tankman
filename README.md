**tankman**
-------

A battle city clone game.

**Preamble**

This game is NOT a fun game.  It's just a simple game to let you learn how to writing a game.

**Tools and Library Usage**

 - Microsoft Visual Studio Community 2015
 - SDL2 v.2.0.4
 - SDL2_image v.2.0.1
 - SDL2_ttf v.2.0.14
 - SDL2_mixer v.2.0.1

**Compiling**

 - download and unzip SDL2, SDL2_image, SDL2_ttf, SDL2_mixer
 - change sub-directory to SDL*\VisualC
 - open Visual Studio
 - load SDL*.sln, edit include and library paths, and build it
 - load Tankman and set include and library paths to compile
 - compile and run

**How to Play**

 - key Tab to select menu
 - key Enter to choose menu
 - key Up, Down, Left, Right to move tank
 - key W, S, A, D also move tank
 - key Space and Enter to shoot
 - if you get shot, your HP decrease
 - if you HP decrease to zero, you die and game over
 - you have to shoot and destroy all eagle(s) to win stage

**Build Map**

You can edit map by open tankmap (https://github.com/taworn/tankmap).  Beware,
there is some limit:

 - enemy tanks can have 64 units
 - bullets in game can have 64 units
 - items in game can appear 4 units

If you add new map, don't forget to rename file "0000.map" by "0000" is 0..stage-1, then,
edit file src/game/common.hxx, change STAGE_COUNT to your number of stages.

**Thanks**

 - visualstudio.com - download Visual Studio
 - libsdl.org - download SDL library
 - libsdl.org/projects/SDL_image - download SDL_image
 - libsdl.org/projects/SDL_ttf - download SDL_ttf
 - libsdl.org/projects/SDL_mixer - download SDL_mixer
 - github.com - to host this project
 - google.com - to search every time when you want to learn any new things
 - stackoverflow.com - good community
 - www.spriters-resource.com - provide graphics, thank to Zephiel87 and Superjustinbros
 - www.sounds-resource.com - provide sounds, thank to J-Sinn
 - and Namco Limited (www.namco.co.jp) to build this original game

---------
Taworn T.

My English is very poor, I'm not English native, sorry. T_T

