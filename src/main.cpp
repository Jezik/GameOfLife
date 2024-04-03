#include "Board.h"

#include <iostream>

int main()
{
	std::cout << "Input the width of a field: ";
	int width;
	std::cin >> width;

	std::cout << "Input the height of a field: ";
	int height;
	std::cin >> height;

	Board board{ width, height };
	board.pretty_print();


	return 0;
}