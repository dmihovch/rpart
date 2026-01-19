#ifndef MATHS_H
#define MATHS_H
#include <stdlib.h>
#include "raylib.h"

//if I want to use this math library outside of raylib, need to delete the include and uncomment the struct below

/***************
typedef struct {
	float x,y;
}Vector2;
***************/

//returns a random float [tmin,tmax]
float rand_float(float tmin, float tmax);
void vec2_add_ip(Vector2* res, Vector2 v);
void vec2_sub_ip(Vector2* res, Vector2 v);
void vec2_negate_ip(Vector2* v);
void vec2_zero(Vector2* v);

#endif //MATHS_H
