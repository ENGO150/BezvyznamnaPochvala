FILES = src/main.c

all:
	$(CC) $(FILES) -lGL -lglfw -o out/main