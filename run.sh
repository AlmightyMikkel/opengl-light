g++ *.cpp $(pkg-config --libs glfw3) $(pkg-config --cflags glfw3) $(pkg-config --libs glew) $(pkg-config --cflags glew)
./a.out
