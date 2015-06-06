#include <vector.h>

t_vector2d      vector2d_mult_scal(t_vector2d u, double x, double y)
{
    u.x *= x;
    u.y *= y;
    return (u);
}

t_vector2d      vector2d_mult(t_vector2d u, t_vector2d v)
{
    t_vector2d  mult;

    mult.x = u.x * v.x;
    mult.y = u.y * v.y;
    return (add);
}
