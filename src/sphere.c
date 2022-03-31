#include "shape.h"

void draw_sphere(Shape *sphere, G3Xvector scale_factor)
{
    g3x_Material(G3Xg, .2, .6, .9, 1, 1);
    // glPushMatrix();
    // glScaled(1, 0.2, 0.4);

    glBegin(GL_QUADS);

    int step1 = min(1, (int)(1. / scale_factor.x));
    int step2 = min(1, (int)(1. / scale_factor.y));

    // Face 1 = base du sphere
    // double step_n1 = 1;
    // printf("%d\n", step_n1);

    for (int i = 0; i < sphere->n2 - 1; i += step2)
    {
        for (int j = 0; j < sphere->n1 - 1; j += step1)
        {
            int k;
            k = (i)*sphere->n1 + min(j + step2, sphere->n1 - 1);
            // k = (i)*sphere->n1 + (j + 1);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);

            k = min(i + step2, sphere->n2 - 1) * sphere->n1 + min(j + step1, sphere->n1 - 1);
            // k = (i + 1) * sphere->n1 + (j + 1);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);

            k = min(i + step2, sphere->n2 - 1) * sphere->n1 + (j);
            // k = (i + 1) * sphere->n1 + (j);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);

            k = (i)*sphere->n1 + (j);
            // k = (i)*sphere->n1 + (j);
            g3x_Normal3dv(sphere->norm[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);
            /*int k;
            k = (i)*sphere->n1 + (j);
            g3x_Normal3dv(sphere->vrtx[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);
            k = (i)*sphere->n1 + (j + 1);
            g3x_Normal3dv(sphere->vrtx[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);
            k = (i + 1) * sphere->n1 + (j + 1);
            g3x_Normal3dv(sphere->vrtx[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);
            k = (i + 1) * sphere->n1 + (j);
            g3x_Normal3dv(sphere->vrtx[k]);
            g3x_Vertex3dv(sphere->vrtx[k]);*/
        }
    }
    glEnd();
    // glPopMatrix();
}

Shape *init_sphere()
{
    Shape *sphere;
    if (NULL == (sphere = malloc(1 * sizeof(Shape))))
        return NULL;

    sphere->n1 = 100;
    sphere->n2 = 100;

    if (NULL == (sphere->vrtx = malloc(sphere->n1 * sphere->n2 * sizeof(G3Xpoint))))
        return NULL;
    if (NULL == (sphere->norm = malloc(sphere->n1 * sphere->n2 * sizeof(G3Xvector))))
        return NULL;

    int i, j;
    double theta = (2 * PI) / (sphere->n1 - 1);
    double phi = (PI) / (sphere->n2);

    double r, x, y, z;

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
