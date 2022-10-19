#ifndef MATH_VECTOR_2D_H
#define MATH_VECTOR_2D_H

typedef struct 
{
    float x;
    float y;
}vector2D_t;

void vector2D_add(vector2D_t * result, vector2D_t v1, vector2D_t v2);

void vector2D_sub(vector2D_t * result, vector2D_t v1, vector2D_t v2);

double vector2D_magnitude(vector2D_t vector);

void vector2D_multiply_with_scalar(vector2D_t * vector, float scalar);

#endif