CC = clang
FLAGS = -Wall -Wextra -Werror -ferror-limit=1
LIBS = `pkg-config sdl2 SDL2_image SDL2_ttf SDL2_mixer SDL2_gfx --libs --cflags`
EXE = liberty_space_battle

SOURCES = 	src/main.c \
			src/game.c\
			src/sceneManager.c\
			src/splash_screen.c\
			src/input.c

mac:
	$(CC) -o $(EXE) $(SOURCES) $(FLAGS) $(LIBS)

linux_debug:
	$(CC) -o $(EXE) $(FLAGS) -g $(SOURCES) $(LIBS)


linux_release:
	$(CC) -o $(EXE) $(FLAGS) -O2 $(SOURCES) $(LIBS)


profile:
	$(CC) -o $(EXE) $(SOURCES) $(LIBS) -pg
	./$(EXE)
	gprof $(EXE) gmon.out > profile.txt


clean:
	rm -f $(EXE) 2>/dev/null; true
	rm gmon.out profile.txt 2>/dev/null; true

.PHONY: clean
