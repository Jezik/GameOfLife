#include "Board.h"

#include <iostream>
#include <random>

Board::Board(int width, int height) : m_width{ width }, m_height{ height }
{
	m_board = new int[width * height];

	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distrib(0, 1);

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			*(m_board + i * width + j) = distrib(generator);
		}
	}
}

void Board::pretty_print() const
{
	for (size_t i = 0; i < m_height; ++i)
	{
		if (i == 0)
		{
			for (size_t z = 0; z < m_width; ++z)
			{
				if (z == 0) std::cout << ' ';
				std::cout << '-';
			}
			std::cout << std::endl;
		}

		for (size_t j = 0; j < m_width; ++j)
		{	
			if (j == 0)
			{
				std::cout << '|';
			}

			if (*(m_board + i * m_width + j) == 1)
			{
				std::cout << '#';					// Here we print real board state
			} 
			else
			{
				std::cout << ' ';
			}

			if (j == m_width - 1)
			{
				std::cout << '|';
			}
		}
		std::cout << std::endl;

		if (i == m_height - 1)
		{
			for (size_t z = 0; z < m_width; ++z)
			{
				if (z == 0) std::cout << ' ';
				std::cout << '-';
			}
			std::cout << std::endl;
		}
	}
}