#include "../include/header.h"

void writePixel(t_canvas *cv, int i, int j, t_color c)
{
	cv->pixel[i][j] = c; 
}
