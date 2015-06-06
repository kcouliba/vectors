#include <vector.h>

t_vector2d      vector2d_add_scal(t_vector2d u, double x, double y)
{
    u.x += x;
    u.y += y;
    return (u);
}

t_vector2d      vector2d_add(t_vector2d u, t_vector2d v)
{
    t_vector2d  add;

    add.x = u.x + v.x;
    add.y = u.y + v.y;
    return (add);
}
