main: main.cxx
	g++ -Wall src/main.cxx src/myGL/*.cpp -I include lib/libglfw3.a include/glad.o -o main

# hehehe
