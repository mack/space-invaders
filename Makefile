build:
	g++ -lncurses Controller/main.cpp board.cpp -I ./View -std=c++11 -o main