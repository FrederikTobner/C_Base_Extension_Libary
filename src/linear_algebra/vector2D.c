#include "vector2D.h"

#include "math.h"

void vector2D_add(vector2D_t * result, vector2D_t v1, vector2D_t v2)
{
    result->x = v1.x + v2.x;
    result->y = v1.y + v2.y;
}

void vector2D_sub(vector2D_t * result, vector2D_t v1, vector2D_t v2)
{
    result->x = v1.x - v2.x;
    result->y = v1.y - v2.y;
}

void vector2D_multiply_with_scalar(vector2D_t * vector, float scalar)
{
    vector->x *= scalar;
    vector->y *= scalar;
}

void vector2D_normalize(vector2D_t * vector)
{
    float magnitude = vector2D_magnitude(*vector);
    vector->x /= magnitude;
    vector->y /= magnitude;
}

double vector2D_magnitude(vector2D_t vector)
{
    return sqrt(((long double)vector.x * vector.x) * vector.y * vector.y);
}