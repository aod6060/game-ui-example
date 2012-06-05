cc=mingw32-g++
lib=-Llib -lmingw32 -lSDLmain -lSDL -lSDL_ttf -lopengl32 -lglu32
inc=-Iinclude
name=bin\run
src=src/main.cpp src/ui.cpp
all:
	$(cc) $(src) -o $(name) $(lib) $(inc)
	
clean:
	del $(name).exe