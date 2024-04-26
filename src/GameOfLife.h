#pragma once
class GameOfLife
{
public:
	static int* create_next_generation(int* old_generation, int width, int height);

private:
	static int get_neighbours_sum(int* matrix, int i, int j, int width, int height);
	static int set_cell(int num_alive, int state_previous_generation);
};

