CC = gcc
FLAGS = -pedantic -Wall -Wextra -g -pg
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
EXE = liberty_space_battle

SOURCES = 	src/main.c \
			src/game.c

linux_debug:
	$(CC) -o $(EXE) $(FLAGS) $(SOURCES) $(LIBS)


profile:
	$(CC) -o $(EXE) $(SOURCES) $(LIBS) -pg
	./$(EXE)
	gprof $(EXE) gmon.out > profile.txt

web:
	emcc -s USE_SDL=2 -o web/index.html -s ASYNCIFY $(SOURCES)

clean:
	rm -f $(EXE) 2>/dev/null; true
	rm gmon.out profile.txt 2>/dev/null; true

.PHONY: web clean