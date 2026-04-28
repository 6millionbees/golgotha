# I have a very stupid idea to make it into a onefile exec
# This probably wont work, and if it does I shouldn't use it anyways

#all: ./build/shaders.o ./build/main
#
#./build/shaders.o: ./src/shaders/shaderHolder.cpp
#         g++ - Wall scr/shaders/shaderHolder.cpp -o shaderHolder.o
#./build/main: ./src/main.cxx
#	g++ -Wall src/main.cxx src/myGL/*.cpp -I include lib/libglfw3.a include/glad.o build/shaderHolder.o -o build/main


./build/main: ./src/main.cxx
	g++ -Wall src/main.cxx src/myGL/*.cpp -I include lib/libglfw3.a include/glad.o -o build/main

# hehehe
