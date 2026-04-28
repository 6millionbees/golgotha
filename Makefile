main: main.cxx
	g++ -Wall main.cxx myGL/*.cpp -I include lib/libglfw3.a glad.o -o main

# hehehe
