CC = clang
FLAGS = -Wall -Wextra -Werror -ferror-limit=1
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
