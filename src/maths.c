#include "../include/maths.h"
#include <raylib.h>

float rand_float(float tmin, float tmax)
{
	float rmin = 0.;
	float rmax = 1.;
	float ret = (float)rand()/RAND_MAX;
	ret = ret - rmin;
	ret = ret / (rmax - rmin);
	return ret * (tmax - tmin) + tmin;
}

void vec2_negate_ip(Vector2* v)
{
	v->x = -v->x;
	v->y = -v->y;
}

void vec2_add_ip(Vector2* res, Vector2 v)
{
	res->x += v.x;
	res->y += v.y;
}

void vec2_sub_ip(Vector2 *res, Vector2 v)
{
	res->x -= v.x;
	res->y -= v.y;
}

void vec2_zero(Vector2* v)
{
	v->x = 0;
	v->y = 0;
}
