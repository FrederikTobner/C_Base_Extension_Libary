#ifndef MATH_VECTOR_3D_H
#define MATH_VECTOR_3D_H

typedef struct 
{
    float x;
    float y;
    float z;
}vector3D_t;

void vector3D_add(vector3D_t * result, vector3D_t v1, vector3D_t v2);

void vector3D_sub(vector3D_t * result, vector3D_t v1, vector3D_t v2);

void vector3D_multiply_with_scalar(vector3D_t * vector, float scalar);

double vector3D_magnitude(vector3D_t vector);

#endif