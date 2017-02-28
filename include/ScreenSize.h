#pragma once

class ScreenSize
{
public:

	static void setWidth(int width)
	{
		s_width = width;
	}

	static void setHeight(int height)
	{
		s_height = height;
	}

	static int width()
	{
		return s_width;
	}

	static int height()
	{
		return s_height;
	}

private:

	static int s_width;

	static int s_height;
};
