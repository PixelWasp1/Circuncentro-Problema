all: main.cpp
	g++ main.cpp -o programa
clear:
	rm programa
run: all
	./main
