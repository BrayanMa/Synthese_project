#ifndef __H_SHAPE
#define __H_SHAPE

#include <g3x.h>
#include <math.h>

typedef struct _shape_
{
    int n1, n2, n3;  /* valeurs d’échantillonnage max - la plupart du temps 2 suffisent*/
    G3Xpoint *vrtx;  /* tableau des vertex   - spécifique d’une forme*/
    G3Xvector *norm; /* tableau des normales - spécifique d’une forme*/
    /*méthode d’affichage  - spécifique d’une forme*/
    void (*draw_points)(struct _shape_ *, G3Xvector scale_factor); /* mode GL_POINTS*/
    void (*draw_faces)(struct _shape_ *, G3Xvector scale_factor);  /* mode GL_TRIANGLES ou GL_QUADS */
} Shape;

int min(int a, int b);
int max(int a, int b);

Shape *init_cube();
Shape *init_sphere();
Shape *init_cylinder();
Shape *init_torus();
Shape *init_cone();

void draw_cube(Shape *cube, G3Xvector scale_factor);
void draw_sphere(Shape *sphere, G3Xvector scale_factor);
void draw_cylinder(Shape *cylinder, G3Xvector scale_factor);
void draw_torus(Shape *torus, G3Xvector scale_factor);
void draw_cone(Shape *cone, G3Xvector scale_factor);

#endif