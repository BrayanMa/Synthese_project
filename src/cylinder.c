#include "shape.h"

void draw_cylinder(Shape *cylinder, G3Xvector scale_factor, double distanceCam)
{
     printf("cylinder  : %f\n", distanceCam);

    int step1 = max(1, (int)(1. / (scale_factor.y * (1. / distanceCam))));
    int step2 = max(1, (int)(1. / (scale_factor.x * (1. / distanceCam))));
    int step3 = max(1, (int)(1. / (scale_factor.z * (1. / distanceCam))));

    // Face 1 = base du cylinder
    // double step_n1 = 1;
    // printf("%d\n", step_n1);
    glBegin(GL_QUADS);

    for (int i = 0; i < cylinder->n2 - 1; i += step2)
    {
        for (int j = 0; j < cylinder->n1 - 1; j += step3)
        {
            int k;
            k = (i)*cylinder->n1 + min(j + step3, cylinder->n1 - 1);
            // k = (i)*cylinder->n1 + (j + 1);

            g3x_Normal3dv(cylinder->norm[k]);
            g3x_Vertex3dv(cylinder->vrtx[k]);

            k = min(i + step2, cylinder->n2 - 1) * cylinder->n1 + min(j + step3, cylinder->n1 - 1);
            // k = (i + 1) * cylinder->n1 + (j + 1);
            g3x_Normal3dv(cylinder->norm[k]);
            g3x_Vertex3dv(cylinder->vrtx[k]);

            k = min(i + step2, cylinder->n2 - 1) * cylinder->n1 + (j);
            // k = (i + 1) * cylinder->n1 + (j);
            g3x_Normal3dv(cylinder->norm[k]);
            g3x_Vertex3dv(cylinder->vrtx[k]);

            k = (i)*cylinder->n1 + (j);
            // k = (i)*cylinder->n1 + (j);
            g3x_Normal3dv(cylinder->norm[k]);
            g3x_Vertex3dv(cylinder->vrtx[k]);
        }
    }
    for (int i = 0; i < cylinder->n2 - 1; i += step2)
    {
        for (int l = 0; l < cylinder->n3 - 1; l += step1)
        {
            int k;
            k = (i)*cylinder->n1 + min(l + step1, cylinder->n3 - 1);
            // k = (i)*cylinder->n1 + (l + 1);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) + k]);

            k = min(i + step2, cylinder->n2 - 1) * cylinder->n1 + min(l + step1, cylinder->n3 - 1);
            // k = (i + 1) * cylinder->n1 + (l + 1);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) + k]);

            k = min(i + step2, cylinder->n2 - 1) * cylinder->n1 + (l);
            // k = (i + 1) * cylinder->n1 + (l);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) + k]);

            k = (i)*cylinder->n1 + (l);
            // k = (i)*cylinder->n1 + (l);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) + k]);
        }
    }
    for (int i = 0; i < cylinder->n2 - 1; i += step2)
    {
        for (int m = 0; m < cylinder->n3 - 1; m += step1)
        {
            int k;
            k = (i)*cylinder->n1 + min(m + step1, cylinder->n3 - 1);
            // k = (i)*cylinder->n1 + (l + 1);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) * 2 + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) * 2 + k]);

            k = min(i + step2, cylinder->n2 - 1) * cylinder->n1 + min(m + step1, cylinder->n3 - 1);
            // k = (i + 1) * cylinder->n1 + (l + 1);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) * 2 + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) * 2 + k]);

            k = min(i + step2, cylinder->n2 - 1) * cylinder->n1 + (m);
            // k = (i + 1) * cylinder->n1 + (l);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) * 2 + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) * 2 + k]);

            k = (i)*cylinder->n1 + (m);
            // k = (i)*cylinder->n1 + (l);
            g3x_Normal3dv(cylinder->norm[(cylinder->n1 * cylinder->n2) * 2 + k]);
            g3x_Vertex3dv(cylinder->vrtx[(cylinder->n1 * cylinder->n2) * 2 + k]);
        }
    }
    glEnd();
}

Shape *init_cylinder()
{
    Shape *cylinder;
    if (NULL == (cylinder = malloc(1 * sizeof(Shape))))
        return NULL;

    cylinder->n1 = 1000;
    cylinder->n2 = 1000;
    cylinder->n3 = 1000;

    if (NULL == (cylinder->vrtx = malloc(cylinder->n1 * cylinder->n2 * 3 * sizeof(G3Xpoint))))
        return NULL;
    if (NULL == (cylinder->norm = malloc(cylinder->n1 * cylinder->n2 * 3 * sizeof(G3Xvector))))
        return NULL;

    double H = 2; // Hauteur du cylindre
    double R = 1;
    double theta = 2 * PI / (cylinder->n1 - 1);
    double t = H / (cylinder->n2 - 1);
    double r = R / (cylinder->n3 - 1);

    int i, j, k;
    for (i = 0; i < cylinder->n1; i++)
    {
        for (j = 0; j < cylinder->n2 - 1; j++)
        {
            cylinder->vrtx[i * cylinder->n1 + j] = (G3Xpoint){R * cos(i * theta), R * sin(i * theta), (j * t) - (H / 2.)};
            cylinder->norm[i * cylinder->n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 0};
        }
        j = cylinder->n2 - 1;
        cylinder->vrtx[i * cylinder->n1 + j] = (G3Xpoint){R * cos(i * theta), R * sin(i * theta), (j * t) - (H / 2.)};
        cylinder->norm[i * cylinder->n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 0};

        for (k = 0; k < cylinder->n3 - 1; k++)
        {
            cylinder->vrtx[(cylinder->n1 * cylinder->n2) + (i * cylinder->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), (H / 2.)};
            cylinder->norm[(cylinder->n1 * cylinder->n2) + (i * cylinder->n1 + k)] = (G3Xvector){0, 0, 1};
            cylinder->vrtx[(cylinder->n1 * cylinder->n2) * 2 + (i * cylinder->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
            cylinder->norm[(cylinder->n1 * cylinder->n2) * 2 + (i * cylinder->n1 + k)] = (G3Xvector){0, 0, -1};
        }
        k = cylinder->n3 - 1;
        cylinder->vrtx[(cylinder->n1 * cylinder->n2) + (i * cylinder->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), (H / 2.)};
        cylinder->norm[(cylinder->n1 * cylinder->n2) + (i * cylinder->n1 + k)] = (G3Xvector){0, 0, 1};
        cylinder->vrtx[(cylinder->n1 * cylinder->n2) * 2 + (i * cylinder->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
        cylinder->norm[(cylinder->n1 * cylinder->n2) * 2 + (i * cylinder->n1 + k)] = (G3Xvector){0, 0, -1};
    }
    cylinder->draw_faces = draw_cylinder;
    return cylinder;
}
