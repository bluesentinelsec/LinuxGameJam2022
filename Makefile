CC = gcc
FLAGS = -pedantic -Wall -Wextra
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
EXE = liberty_space_battle

SOURCES = 	src/main.c \
			src/game.c

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