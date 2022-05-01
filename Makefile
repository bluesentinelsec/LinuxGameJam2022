CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBS = `pkg-config sdl2 SDL2_image SDL2_mixer --libs --cflags`
EXE = liberty_space_battle

SOURCES = 	src/main.c \
			src/game.c \
			src/sceneManager.c \
			src/splash_screen.c \
			src/input.c \
			src/entity.c \
			src/title_screen.c \
			src/instructions_screen.c \
			src/gameplay_screen.c \
			src/credits_screen.c \
			src/lose_screen.c \
			src/win_screen.c

linux_debug:
	$(CC) -o $(EXE) $(FLAGS) -g $(SOURCES) $(LIBS)

ubuntu: linux_release
	zip -r LibertySpaceBattle_Ubuntu.zip LibertySpaceBattle/

fedora: linux_release
	zip -r LibertySpaceBattle_Fedora.zip LibertySpaceBattle/

linux_release:
	$(CC) -o $(EXE) $(FLAGS) -O2 $(SOURCES) $(LIBS)
	mkdir -p LibertySpaceBattle/
	cp $(EXE) LibertySpaceBattle
	cp -R media/ LibertySpaceBattle/
	cp LICENSE LibertySpaceBattle/
	cp Instructions.md LibertySpaceBattle/
	cp install_dependencies.sh LibertySpaceBattle/

WIN_EXE = windows/LibertySpaceBattle_windowsx64/liberty_space_battle.exe
WIN_CC = x86_64-w64-mingw32-gcc
WIN_FLAGS = -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer 
windows:
	mkdir -p windows/LibertySpaceBattle_windowsx64
	$(WIN_CC) -o $(WIN_EXE) $(SOURCES) $(WIN_FLAGS)
	mv liberty_space_battle.exe windows/LibertySpaceBattle_windowsx64/
	cp windows/runtime_libraries_x64/* windows/LibertySpaceBattle_windowsx64/
	cp -R media/ windows/LibertySpaceBattle_windowsx64/
	cp LICENSE windows/LibertySpaceBattle_windowsx64/
	cp Instructions.md windows/LibertySpaceBattle_windowsx64/

mac:
	$(CC) -o $(EXE) $(SOURCES) $(FLAGS) $(LIBS)


profile:
	$(CC) -o $(EXE) $(SOURCES) $(LIBS) -pg
	./$(EXE)
	gprof $(EXE) gmon.out > profile.txt


clean:
	rm -f $(EXE) 2>/dev/null; true
	rm gmon.out profile.txt 2>/dev/null; true
	rm -rf release 2>/dev/null; true
	rm -rf LibertySpaceBattle 2>/dev/null; true
	rm -rf LibertySpaceBattle.zip 2>/dev/null; true

.PHONY: clean windows
