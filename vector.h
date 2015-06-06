#ifndef VECTOR_H
# define VECTOR_H

typedef struct  s_vector2d
{
    double  x;
    double  y;
}               t_vector2d;

t_vector2d      vector2d_add_scal(t_vector2d u, double x, double y);
t_vector2d      vector2d_add(t_vector2d u, t_vector2d v);
t_vector2d      vector2d_sub_scal(t_vector2d u, double x, double y);
t_vector2d      vector2d_sub(t_vector2d u, t_vector2d v);
t_vector2d      vector2d_mult_scal(t_vector2d u, double x, double y);
t_vector2d      vector2d_mult(t_vector2d u, t_vector2d v);

#endif // VECTOR_H
