FILES = src/main.c

all:
	$(CC) $(FILES) -lm -lGL -lglfw -lGLEW -o out/main