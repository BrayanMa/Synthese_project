#include "shape.h"

void draw_sphere(Shape *sphere, G3Xvector scale_factor, double distanceCam)
{

    int step1 = max(1, (int)(1. / (scale_factor.x * (1. / distanceCam))));
    int step2 = max(1, (int)(1. / (scale_factor.y * (1. / distanceCam))));
    glBegin(GL_QUADS);

    for (int i = 0; i < sphere->n2 - 1; i += step2)
    {
        for (int j = 0; j < sphere->n1 - 1; j += step1)
        {
            int k;
            k = (i)*sphere->n1 + min(j + step2, sphere->n1 - 1);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);

            k = min(i + step2, sphere->n2 - 1) * sphere->n1 + min(j + step1, sphere->n1 - 1);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);

            k = min(i + step2, sphere->n2 - 1) * sphere->n1 + (j);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);

            k = (i)*sphere->n1 + (j);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);
        }
    }
    glEnd();
}

Shape *init_sphere()
{
    Shape *sphere;
    if (NULL == (sphere = malloc(1 * sizeof(Shape))))
        return NULL;

    sphere->n1 = 500;
    sphere->n2 = 500;

    if (NULL == (sphere->vrtx = malloc(sphere->n1 * sphere->n2 * sizeof(G3Xpoint))))
        return NULL;
    if (NULL == (sphere->norm = malloc(sphere->n1 * sphere->n2 * sizeof(G3Xvector))))
        return NULL;

    int i, j;
    double theta = (2 * PI) / (sphere->n1 - 1);
    double phi = (PI) / (sphere->n2);

    double r, z;

    i = 0;
    for (j = 0; j < sphere->n1; j++)
    {
        sphere->vrtx[i * sphere->n1 + j] = (G3Xpoint){0., 0., +1.};
        sphere->norm[i * sphere->n1 + j] = (G3Xvector){0., 0., +1.};
    }

    for (i = 1; i < sphere->n2 - 1; i++)
    {
        z = cos(i * phi);
        r = sin(i * phi);
        for (j = 0; j < sphere->n1; j++)
        {
            sphere->vrtx[i * sphere->n1 + j] = (G3Xpoint){r * cos(j * theta), r * sin(j * theta), z};
            sphere->norm[i * sphere->n1 + j] = (G3Xvector){r * cos(j * theta), r * sin(j * theta), z};
        }
    }
    i = sphere->n2 - 1;
    for (j = 0; j < sphere->n1; j++)
    {
        sphere->vrtx[i * sphere->n1 + j] = (G3Xpoint){0., 0., -1.};
        sphere->norm[i * sphere->n1 + j] = (G3Xvector){0., 0., -1.};
    }
    sphere->draw_faces = draw_sphere;
    return sphere;
}
