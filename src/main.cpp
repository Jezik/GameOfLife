#include <iostream>
#include <random>

int main()
{
	std::cout << "Input the width of a field: ";
	int width;
	std::cin >> width;

	std::cout << "Input the height of a field: ";
	int height;
	std::cin >> height;

	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distrib(0, 1);

	int* board = new int[width * height];
	for(size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			*(board + i * width + j) = distrib(generator);
		}
	}

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			std::cout << *(board + i * width + j);
		}
		std::cout << std::endl;
	}


	delete[] board;
	return 0;
}