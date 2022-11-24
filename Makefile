FILES = src/main.cpp

all:
	g++ $(FILES) -lglfw -lGL -o out/main