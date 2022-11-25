FILES = src/main.c

all:
	$(CC) $(FILES) -lGL -lglfw -lGLEW -o out/main