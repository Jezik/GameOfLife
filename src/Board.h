#pragma once

class Board
{
public:
	Board(int width, int height);

	void pretty_print() const;

	void set_board(int* board)
	{
		delete[] m_board;
		m_board = board;
	}

	int* get_board() const 
	{
		return m_board;
	}

	int get_height() const
	{
		return m_height;
	}

	int get_width() const
	{
		return m_width;
	}

	~Board()
	{
		delete[] m_board;
	}

private:
	int m_width;
	int m_height;
	int* m_board;
};

