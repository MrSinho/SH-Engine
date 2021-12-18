#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "shTime.h"

void shGetTime(ShTime* time)
{
	time->now = glfwGetTime();
	time->delta_time = (float)time->now - time->last_time;
	time->last_time = (float)time->now;
}

void shSetTime(double now, ShTime *time)
{
	time->now = now;
	glfwSetTime(time->now);
}