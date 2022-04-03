#include "shape.h"

void draw_cone(Shape *cone, G3Xvector scale_factor)
{


    int step1 = min(1, (int)(1. / scale_factor.x));
    int step2 = min(1, (int)(1. / scale_factor.y));
    int step3 = min(1, (int)(1. / scale_factor.z));


    for (int i = 0; i < cone->n2 - 1; i += step2)
    {
        for (int j = 0; j < cone->n1 - 1; j += step1)
        {
            int k;
            k = (i)*cone->n1 + min(j + step1, cone->n1 - 1);
            // k = (i)*cone->n1 + (j + 1);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + min(j + step1, cone->n1 - 1);
            // k = (i + 1) * cone->n1 + (j + 1);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + (j);
            // k = (i + 1) * cone->n1 + (j);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);

            k = (i)*cone->n1 + (j);
            // k = (i)*cone->n1 + (j);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);
        }
        for (int m = 0; m < cone->n3 - 1; m += step3)
        {
            int k;
            k = (i)*cone->n1 + min(m + step3, cone->n3 - 1);
            // k = (i)*cone->n1 + (l + 1);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + min(m + step3, cone->n3 - 1);
            // k = (i + 1) * cone->n1 + (l + 1);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + (m);
            // k = (i + 1) * cone->n1 + (l);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);

            k = (i)*cone->n1 + (m);
            // k = (i)*cone->n1 + (l);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);
        }

    }
}

Shape *init_cone()
{
    Shape *cone;
    if (NULL == (cone = malloc(1 * sizeof(Shape))))
        return NULL;

    cone->n1 = 100;
    cone->n2 = 100;
    cone->n3 = 100;

    if (NULL == (cone->vrtx = malloc(cone->n1 * cone->n2 * 2 * sizeof(G3Xpoint))))
        return NULL;
    if (NULL == (cone->norm = malloc(cone->n1 * cone->n2 * 2 * sizeof(G3Xvector))))
        return NULL;

    double H = 2; // Hauteur du cylindre
    double R = 1;

       double theta = 2 * PI / (cone->n1 - 1);
    double t = H / (cone->n2 - 1);
    double r = R / (cone->n3 - 1);

    int i, j, k;
    for (i = 0; i < cone->n1; i++)
    {
        for (j = 0; j < cone->n2 - 1; j++)
        {
            cone->vrtx[i * cone->n1 + j] = (G3Xpoint){((H - (j * t)) / H) * R * cos(i * theta),((H - (j * t)) / H) * R * sin(i * theta), (j * t) - (H / 2.)};
            cone->norm[i * cone->n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 1};
        }
        j = cone->n2 - 1;
        cone->vrtx[i * cone->n1 + j] = (G3Xpoint){((H - (j * t)) / H) * R * cos(i * theta), ((H - (j * t)) / H)*  R * sin(i * theta), (j * t) - (H / 2.)};
        cone->norm[i * cone->n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 1};

        for (k = 0; k < cone->n3 - 1; k++)
        {
            //cone->vrtx[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), (H / 2.)};
            //cone->norm[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xvector){0, 0, 1};
            cone->vrtx[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
            cone->norm[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xvector){0, 0, -1};
        }
        k = cone->n3 - 1;
        //cone->vrtx[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), (H / 2.)};
        //cone->norm[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xvector){0, 0, 1};
        cone->vrtx[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
        cone->norm[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xvector){0, 0, -1};
    }

    cone->draw_faces = draw_cone;
    return cone;

}
