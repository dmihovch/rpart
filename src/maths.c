#include "../include/maths.h"
#include <raylib.h>

float rand_float_nonzero(float tmin, float tmax)
{
	float rand = rand_float(tmin,tmax);
	if(rand == 0.0f)
	{
		return 0.0001;
	}
	return rand;
}
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

float vec2_dot(Vector2 a, Vector2 b)
{
	return (a.x * b.x) + (a.y * b.y);
}

Vector2 vec2_sub(Vector2 a, Vector2 b)
{
	return (Vector2)
	{
		a.x - b.x,
		a.y - b.y,
	};
}
