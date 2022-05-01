#include "shape.h"

void draw_cone(Shape *cone, G3Xvector scale_factor, double distanceCam)
{
    /* Mise en place des différents pas de parcours */
    int step1 = max(1, (int)(1. / (scale_factor.x * (1. / distanceCam))));
    int step2 = max(1, (int)(1. / (scale_factor.y * (1. / distanceCam))));
    int step3 = max(1, (int)(1. / (scale_factor.z * (1. / distanceCam))));

    /*Demarage de la phase de dessin*/
    glBegin(GL_QUADS);

    for (int i = 0; i < cone->n2 - 1; i += step2)
    {
        for (int j = 0; j < cone->n1 - 1; j += step1)
        {
            int k;
            k = (i)*cone->n1 + min(j + step1, cone->n1 - 1);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + min(j + step1, cone->n1 - 1);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + (j);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);

            k = (i)*cone->n1 + (j);
            g3x_Normal3dv(cone->norm[k]);
            g3x_Vertex3dv(cone->vrtx[k]);
        }
        for (int m = 0; m < cone->n3 - 1; m += step3)
        {
            int k;
            k = (i)*cone->n1 + min(m + step3, cone->n3 - 1);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + min(m + step3, cone->n3 - 1);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);

            k = min(i + step2, cone->n2 - 1) * cone->n1 + (m);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);

            k = (i)*cone->n1 + (m);
            g3x_Normal3dv(cone->norm[(cone->n1 * cone->n2) + k]);
            g3x_Vertex3dv(cone->vrtx[(cone->n1 * cone->n2) + k]);
        }
    }
    glEnd();
    /*Fin de la phase de dessin*/
}

Shape *init_cone()
{
    /* Allocation mémoire pour un cone*/
    Shape *cone;
    if (NULL == (cone = malloc(1 * sizeof(Shape))))
        return NULL;

    cone->n1 = 500;
    cone->n2 = 500;
    cone->n3 = 500;

    if (NULL == (cone->vrtx = malloc(cone->n1 * cone->n2 * 2 * sizeof(G3Xpoint))))
        return NULL;
    if (NULL == (cone->norm = malloc(cone->n1 * cone->n2 * 2 * sizeof(G3Xvector))))
        return NULL;

    double H = 2; // Hauteur du cylindre
    double R = 1; // Rayon du cylindre

    /*Mise en place des variables pour la construction du cylindre*/
    double theta = 2 * PI / (cone->n1 - 1);
    double t = H / (cone->n2 - 1);
    double r = R / (cone->n3 - 1);

    int i, j, k;
    for (i = 0; i < cone->n1; i++)
    {
        for (j = 0; j < cone->n2 - 1; j++)
        {
            cone->vrtx[i * cone->n1 + j] = (G3Xpoint){((H - (j * t)) / H) * R * cos(i * theta), ((H - (j * t)) / H) * R * sin(i * theta), (j * t) - (H / 2.)};
            cone->norm[i * cone->n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 1};
        }
        j = cone->n2 - 1;
        cone->vrtx[i * cone->n1 + j] = (G3Xpoint){((H - (j * t)) / H) * R * cos(i * theta), ((H - (j * t)) / H) * R * sin(i * theta), (j * t) - (H / 2.)};
        cone->norm[i * cone->n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 1};

        for (k = 0; k < cone->n3 - 1; k++)
        {
            cone->vrtx[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
            cone->norm[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xvector){0, 0, -1};
        }
        k = cone->n3 - 1;
        cone->vrtx[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
        cone->norm[(cone->n1 * cone->n2) + (i * cone->n1 + k)] = (G3Xvector){0, 0, -1};
    }

    /* Assignation de la fonction de dessin spécifique au cône */
    cone->draw_faces = draw_cone;
    return cone;
}
