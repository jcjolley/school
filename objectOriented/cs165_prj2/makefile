######################################################################
# Program: 
#   Skeet
# Authors: 
#   Sam Barney and Joshua Jolley
# Summary:
#   This program emulates the game of skeet, complete with menus, 
#   original sounds and original songs, levels, high scores, power ups etc.
#   Estimated Time: 15.0
#   Actual Time: 30
#   The hardest part was learning classes and implementing homing and sound
#
#
#
#   Extras:
#   Sound
#   Original Songs for Start Screen, Gameplay, and Game Over
#   Start Screen
#   Level Screen with Tips
#   Help Page
#   Persistent High Scores and highscore page
#   Powerups - Shotgun and Homing     (These drop randomly from killing birds)
#   Levels that increase in difficulty 
#   Lives
#   Bird movement patterns - Crasy, Square, Jumper (Play up to level 7 for a
#                                                   chance to see all movements)
#
########################################################################
SKEET_SOURCES= Game.cpp vector.cpp bird.cpp bullet.cpp startScreen.cpp selector.cpp skeet.cpp score.cpp rifle.cpp shotgun.cpp main.cpp uiDraw.cpp uiInteract.cpp point.cpp scene.cpp gameOver.cpp levelScreen.cpp helpScreen.cpp startScreen.cpp homingPowerup.cpp shotgunPowerup.cpp selector.cpp SoundManager.cpp callbacks.cpp

SKEET_OBJECTS=$(SKEET_SOURCES:.cpp=.o)
EXECUTABLE_NAME=.Skeet


LINKER_FLAGS_LINUX= -lGL -lglut -lGLU -L. -lfmodex64-4.42.05 -lfmodexL64-4.42.05

#LINKER_FLAGS_MAC=-framework OpenGL -framework GLUT -L. -lfmodexL -lfmodex


linux: $(SKEET_OBJECTS) linux_executable clean

#mac : $(SKEET_OBJECTS) mac_executable clean

all: linux


%.o: %.cpp
	g++ -c $< -o $@

linux_executable : 
	@echo "CREATING LINUX EXECUTABLE"
	g++ $(LINKER_FLAGS_LINUX) *.o -o $(EXECUTABLE_NAME)
	tar -cf project2.tar *.cpp *.h makefile *.mp3 *.so *.hpp skeet.out
#skeet.out isn't the actual executable, it's a shell script that sets up the
#environment and runs the actual executable 

#mac_executable :
#	@echo "CREATING MAC EXECUTABLE"
#	g++ $(LINKER_FLAGS_MAC) *.o -o $(EXECUTABLE_NAME)
#	tar -cvf project2.tar *.cpp fmod.hpp *.h makefile *.mp3 *.so 
clean :
	@rm *.o
