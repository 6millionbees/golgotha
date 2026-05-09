# I have a very stupid idea to make it into a onefile exec
# This probably wont work, and if it does I shouldn't use it anyways

#all: ./include/shadersHolder.o ./build/main
#
#./include/shadersHolder.o: ./src/shaders/shaderHolder.cpp
#         g++ - Wall scr/shaders/shaderHolder.cpp -o shaderHolder.o
#./build/main: ./src/main.cxx
#	g++ -Wall src/main.cxx src/myGL/*.cpp -I include lib/libglfw3.a include/glad.o include/shaderHolder.o -o build/main

./build/main: ./src/main.cxx
	make ./include/glad.o
	rm build/shaders/*
	cp -a src/shaders/. build/shaders
	g++ -Wall src/main.cxx src/myGL/*.cpp src/logic/*.cpp -I include lib/libglfw3.a include/glad.o -o build/main

./include/glad.o: ./include/glad.c
	g++ -c include/glad.c -I include -o include/glad.o

test:
	rm build/shaders/*
	cp -a src/shaders/. build/shaders
	g++ -Wall -g src/main.cxx src/myGL/*.cpp src/logic/*.cpp -I include lib/libglfw3.a include/glad.o -o build/main

clean:
	rm src/shaders/shaderHolder.o
# hehehe
