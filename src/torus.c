#include "shape.h"

void draw_torus(Shape *torus, G3Xvector scale_factor, double distanceCam)
{

    int step1 = max(1, (int)(1. / (scale_factor.x * (1. / distanceCam))));
    int step2 = max(1, (int)(1. / (scale_factor.y * (1. / distanceCam))));

    glBegin(GL_QUADS);

    for (int i = 0; i < torus->n2 - 1; i += step2)
    {
        for (int j = 0; j < torus->n1 - 1; j += step1)
        {
            int k;
            k = (i)*torus->n1 + min(j + step1, torus->n1 - 1);
            g3x_Normal3dv(torus->norm[k]);
            g3x_Vertex3dv(torus->vrtx[k]);

            k = min(i + step2, torus->n2 - 1) * torus->n1 + min(j + step1, torus->n1 - 1);
            g3x_Normal3dv(torus->norm[k]);
            g3x_Vertex3dv(torus->vrtx[k]);

            k = min(i + step2, torus->n2 - 1) * torus->n1 + (j);
            g3x_Normal3dv(torus->norm[k]);
            g3x_Vertex3dv(torus->vrtx[k]);

            k = (i)*torus->n1 + (j);
            g3x_Normal3dv(torus->norm[k]);
            g3x_Vertex3dv(torus->vrtx[k]);
        }
    }
    glEnd();
}

Shape *init_torus()
{
    Shape *torus;
    if (NULL == (torus = malloc(1 * sizeof(Shape))))
        return NULL;

    torus->n1 = 500;
    torus->n2 = 500;

    double R = 1.0; 
    double S = 0.5;
    if (NULL == (torus->vrtx = malloc(torus->n1 * torus->n2 * sizeof(G3Xpoint))))
        return NULL;
    if (NULL == (torus->norm = malloc(torus->n1 * torus->n2 * sizeof(G3Xvector))))
        return NULL;

    double theta = 2 * PI / (torus->n1 - 1);
    double phi = 2 * PI / (torus->n2 - 1); 

    int i, j;
    for (i = 0; i < torus->n1; i++)
    {
        for (j = 0; j < torus->n2; j++)
        {
            torus->vrtx[i * torus->n1 + j] = (G3Xpoint){cos(i * theta) * (R + S * cos(j * phi)), -sin(i * theta) * (R + S * cos(j * phi)), S * sin(j * phi)};
            torus->norm[i * torus->n1 + j] = (G3Xvector){cos(i * theta) * cos(j * phi), -sin(i * theta) * cos(j * phi), sin(j * phi)};
        }
    }
    torus->draw_faces = draw_torus;
    return torus;
}
