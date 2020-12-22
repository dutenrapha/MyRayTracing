#include "../include/header.h"

void writePixel(t_canvas *cv, int w, int h, t_color c)
{
	cv->pixel[h][w] = c; 
}
