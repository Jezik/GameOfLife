#include "Board.h"
#include "GameOfLife.h"

#include <iostream>
#include <thread>

int main()
{
	std::cout << "Input the width of a field: ";
	int width;
	std::cin >> width;

	std::cout << "Input the height of a field: ";
	int height;
	std::cin >> height;

	Board board{ width, height };

	for (size_t i = 0; i < 100; ++i)
	{
		std::cout << "Generation: #" << (i + 1) << std::endl;
		board.pretty_print();
		board.set_board(GameOfLife::create_next_generation(board.get_board(), width, height));
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		system("cls");
	}

	return 0;
}