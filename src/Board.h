#pragma once

class Board
{
public:
	Board(int width, int height);

	void pretty_print() const;

	~Board()
	{
		delete[] m_board;
	}

private:
	int m_width;
	int m_height;
	int* m_board;
};

