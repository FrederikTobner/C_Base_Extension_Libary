#include "vector3D.h"

#include "math.h"

void vector3D_add(vector3D_t * result, vector3D_t v1, vector3D_t v2)
{
    result->x = v1.x + v2.x;
    result->y = v1.y + v2.y;
    result->z = v1.z + v2.z;
}

void vector3D_sub(vector3D_t * result, vector3D_t v1, vector3D_t v2)
{
    result->x = v1.x - v2.x;
    result->y = v1.y - v2.y;
    result->z = v1.z - v2.z;
}

void vector3D_multiply_with_scalar(vector3D_t * vector, float scalar)
{
    vector->x *= scalar;
    vector->y *= scalar;
    vector->z *= scalar;
}

double vector3D_magnitude(vector3D_t vector)
{
    return sqrt(((long double)vector.x * vector.x) * vector.y * vector.y * vector.z * vector.z);
}