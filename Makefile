CC = gcc
FLAGS = -pedantic -Werror -Wall -Wextra -g -pg
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
EXE = liberty_space_defense

SOURCES = 	src/main.c \
			src/game.c

linux_debug:
	$(CC) -o $(EXE) $(SOURCES) $(LIBS)


profile:
	$(CC) -o $(EXE) $(SOURCES) $(LIBS) -pg
	./$(EXE)
	gprof $(EXE) gmon.out > profile.txt


clean:
	rm -f liberty_space_defense 2>/dev/null; true
	rm gmon.out profile.txt 2>/dev/null; true