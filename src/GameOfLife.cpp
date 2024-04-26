#include "GameOfLife.h"

int* GameOfLife::create_next_generation(int* old_generation, int width, int height)
{
	int* new_generation = new int[width * height];
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			*(new_generation + i * width + j) = set_cell(get_neighbours_sum(old_generation, i, j, width, height), *(old_generation + i * width + j));
		}
	}

	return new_generation;
}

int GameOfLife::get_neighbours_sum(int* matrix, int i, int j, int width, int height)
{
	int offsets[8][2] = {
				{-1, -1}, {-1, 0}, {-1, 1},
				{0, -1},           {0, 1},
				{1, -1},  {1, 0},  {1, 1}
	};

	int sum = 0;
	for (int* offset : offsets)
	{
		int new_row = i + offset[0];
		int new_col = j + offset[1];
		
		if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width) {
			sum += *(matrix + new_row * width + new_col);
		}
	}

	return sum;
}

int GameOfLife::set_cell(int num_alive, int state_previous_generation)
{
	if ((state_previous_generation == 1 && (num_alive > 1 && num_alive < 4)) || (state_previous_generation == 0 && num_alive == 3)) {
		return 1;
	}
	return 0;
}
