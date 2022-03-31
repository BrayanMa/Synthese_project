/*=================================================================*/
/*= E.Incerti - eric.incerti@univ-eiffel.fr                       =*/
/*= Université Gustave Eiffel                                     =*/
/*= Code "squelette" pour prototypage avec libg3x.6c              =*/
/*=================================================================*/

#include "shape.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

static struct _shape_ cube;
static double scale_n1 = 1.;
static double scale_n2 = 1.;
static double scale_n3 = 1.;

/* Notre tableau de point */
// static G3Xpoint P[nx * ny * 6];
// static G3Xpoint normal[nx * ny * 6];

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
    cube.n1 = 10;
    cube.n2 = 10;
    cube.n3 = 10;
    cube.vrtx = malloc(cube.n1 * cube.n1 * 6 * sizeof(G3Xpoint));
    cube.norm = malloc(cube.n1 * cube.n1 * 6 * sizeof(G3Xvector));

    double y, x, dy = 2. / (cube.n2 - 1), dx = 2. / (cube.n1 - 1), dz = 2. / (cube.n3 - 1);
    int i, j, k;
    for (i = 0; i < cube.n2 - 1; i++)
    {
        for (j = 0; j < cube.n1 - 1; j++)
        {
            cube.vrtx[i * cube.n1 + j] = (G3Xpoint){(-1. + j * dx), (-1. + i * dy), 1.};
            cube.norm[i * cube.n1 + j] = (G3Xvector){0., 0., 1.};
            cube.vrtx[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xpoint){(-1. + j * dx), (-1. + i * dy), -1.};
            cube.norm[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xvector){0., 0., -1.};

            cube.vrtx[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., (-1. + i * dz)};
            cube.norm[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xvector){0., 1, 0.};
            cube.vrtx[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xpoint){(-1. + j * dx), -1., (-1. + i * dz)};
            cube.norm[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xvector){0., -1., 0.};

            cube.vrtx[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xpoint){1., (-1. + i * dy), (-1. + j * dz)};
            cube.norm[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xvector){1., 0., 0.};
            cube.vrtx[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xpoint){-1., (-1. + i * dy), (-1. + j * dz)};
            cube.norm[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xvector){-1., 0., 0.};
        }
        j = cube.n1 - 1;
        cube.vrtx[i * cube.n1 + j] = (G3Xpoint){1., (-1. + i * dy), 1.};
        cube.norm[i * cube.n1 + j] = (G3Xvector){0., 0., 1.};
        cube.vrtx[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xpoint){+1, (-1. + i * dy), -1.};
        cube.norm[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xvector){0., 0., -1.};

        cube.vrtx[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xpoint){+1, 1., (-1. + i * dz)};
        cube.norm[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xvector){0., 1., 0.};
        cube.vrtx[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xpoint){+1, -1., (-1. + i * dz)};
        cube.norm[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xvector){0., -1., 0.};

        cube.vrtx[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xpoint){1., (-1. + i * dy), 1.};
        cube.norm[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xvector){1., 0., 0.};
        cube.vrtx[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xpoint){-1., (-1. + i * dy), 1.};
        cube.norm[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xvector){-1., 0., 0.};
    }

    i = cube.n2 - 1;

    for (j = 0; j < cube.n1 - 1; j++)
    {
        cube.vrtx[i * cube.n1 + j] = (G3Xpoint){(-1. + j * dx), 1., 1.};
        cube.norm[i * cube.n1 + j] = (G3Xvector){0., 0., 1.};
        cube.vrtx[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., -1.};
        cube.norm[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xvector){0., 0., -1.};

        cube.vrtx[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., 1.};
        cube.norm[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xvector){0., 1., 0.};
        cube.vrtx[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xpoint){(-1. + j * dx), -1., 1.};
        cube.norm[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xvector){0., -1., 0.};

        cube.vrtx[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xpoint){1., 1., (-1. + j * dz)};
        cube.norm[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xvector){1., 0., 0.};
        cube.vrtx[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xpoint){-1., 1., (-1. + j * dz)};
        cube.norm[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xvector){-1., 0., 0.};
    }

    j = cube.n1 - 1;
    cube.vrtx[i * cube.n1 + j] = (G3Xpoint){1., 1., 1.};
    cube.norm[i * cube.n1 + j] = (G3Xvector){0., 0., 1.};
    cube.vrtx[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xpoint){1, 1., -1.};
    cube.norm[(cube.n1 * cube.n1) + (i * cube.n1 + j)] = (G3Xvector){0., 0., -1.};

    cube.vrtx[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xpoint){1, 1., 1.};
    cube.norm[(cube.n1 * cube.n1) * 2 + (i * cube.n1 + j)] = (G3Xvector){0., 1., 0.};
    cube.vrtx[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xpoint){1, -1., 1.};
    cube.norm[(cube.n1 * cube.n1) * 3 + (i * cube.n1 + j)] = (G3Xvector){0., -1., 0.};

    cube.vrtx[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xpoint){1, 1., 1.};
    cube.norm[(cube.n1 * cube.n1) * 4 + (i * cube.n1 + j)] = (G3Xvector){1., 0., 0.};
    cube.vrtx[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xpoint){-1, 1., 1.};
    cube.norm[(cube.n1 * cube.n1) * 5 + (i * cube.n1 + j)] = (G3Xvector){-1., 0., 0.};
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
    g3x_CreateScrollv_d("n1", &scale_n1, 1, 500, 1, "");
    g3x_CreateScrollv_d("n2", &scale_n2, 1, 1000, 1, "");
    g3x_CreateScrollv_d("n3", &scale_n3, 1, 1000, 1, "");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
    int step_x = 1;
    int step_y = 1;
    int step_z = 1;
    glPointSize(1);
    glBegin(GL_QUADS);
    for (int i = 0; i < cube.n2 - 1; i += step_y)
    {
        for (int j = 0; j < cube.n1 - 1; j += step_x)
        {
            int k;
            // k = (i)* cube.n1 + (j);
            k = (i)*cube.n1 + (j);
            g3x_Normal3dv(cube.norm[k]);
            g3x_Vertex3dv(cube.vrtx[k]);
           // g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
            //g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);

            k = (i)*cube.n1 + min(j + step_x, cube.n1 - 1);
            // k = (i)* cube.n1 + (j + 1);
            g3x_Normal3dv(cube.norm[k]);
            g3x_Vertex3dv(cube.vrtx[k]);
           // g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
           // g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);

            k = min(i + step_y, cube.n2 - 1) * cube.n1 + min(j + step_x, cube.n1 - 1);
            // k = (i + 1) *  cube.n1 + (j + 1);
            g3x_Normal3dv(cube.norm[k]);
            g3x_Vertex3dv(cube.vrtx[k]);
           // g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
           // g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);

            k = min(i + step_y, cube.n2 - 1) * cube.n1 + (j);
            // k = (i + 1) *  cube.n1 + (j);
            g3x_Normal3dv(cube.norm[k]);
            g3x_Vertex3dv(cube.vrtx[k]);
           // g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
           // g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);
        }
    }
        for (int i = 0; i < cube.n2 - 1; i += step_y)
    {
        for (int j = 0; j < cube.n1 - 1; j += step_x)
        {
            int k;
            // k = (i)* cube.n1 + (j);
            k = (i)*cube.n1 + (j);
            //g3x_Normal3dv(cube.norm[k]);
            //g3x_Vertex3dv(cube.vrtx[k]);
           g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);

            k = (i)*cube.n1 + min(j + step_x, cube.n1 - 1);
            // k = (i)* cube.n1 + (j + 1);
            //g3x_Normal3dv(cube.norm[k]);
            //g3x_Vertex3dv(cube.vrtx[k]);
           g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
           g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);

            k = min(i + step_y, cube.n2 - 1) * cube.n1 + min(j + step_x, cube.n1 - 1);
            // k = (i + 1) *  cube.n1 + (j + 1);
            //g3x_Normal3dv(cube.norm[k]);
           // g3x_Vertex3dv(cube.vrtx[k]);
           g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);

            k = min(i + step_y, cube.n2 - 1) * cube.n1 + (j);
            // k = (i + 1) *  cube.n1 + (j);
            //g3x_Normal3dv(cube.norm[k]);
            //g3x_Vertex3dv(cube.vrtx[k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 + k]);
        }
    }

    /*for (int i = 0; i < cube.n3 - 1; i += step_z)
    {
        for (int j = 0; j < cube.n1 - 1; j += step_x)
        {
            int k;
            // k = (i)* cube.n1 + (j);
            k = (i)*cube.n3 + (j);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 2 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 2 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 3 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 3 + k]);

            k = (i)*cube.n3 + min(j + step_x, cube.n1 - 1);
            // k = (i)* cube.n1 + (j + 1);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 2 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 2 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 3 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 3 + k]);

            k = min(i + step_z, cube.n3 - 1) * cube.n1 + min(j + step_x, cube.n1 - 1);
            // k = (i + 1) *  cube.n1 + (j + 1);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 2 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 2 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 3 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 3 + k]);

            k = min(i + step_y, cube.n3 - 1) * cube.n1 + (j);
            // k = (i + 1) *  cube.n1 + (j);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 2 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 2 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 3 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 3 + k]);
        }
    }

    for (int i = 0; i < cube.n2 - 1; i += step_y)
    {
        for (int j = 0; j < cube.n3 - 1; j += step_z)
        {
            int k;
            // k = (i)* cube.n1 + (j);
            k = (i)*cube.n1 + (j);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 4 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 4 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 5 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 5 + k]);

            k = (i)*cube.n1 + min(j + step_x, cube.n3 - 1);
            // k = (i)* cube.n1 + (j + 1);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 4 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 4 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 5 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 5 + k]);

            k = min(i + step_y, cube.n1 - 1) * cube.n1 + min(j + step_x, cube.n3 - 1);
            // k = (i + 1) *  cube.n1 + (j + 1);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 4 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 4 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 5 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 5 + k]);

            k = min(i + step_y, cube.n1 - 1) * cube.n1 + (j);
            // k = (i + 1) *  cube.n1 + (j);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 4 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 4 + k]);
            g3x_Normal3dv(cube.norm[cube.n1 * cube.n1 * 5 + k]);
            g3x_Vertex3dv(cube.vrtx[cube.n1 * cube.n1 * 5 + k]);
        }
    }*/
    glEnd();
}

/* la fonction d'animation (facultatif) */
static void anim(void)
{
}

/* la fonction de sortie  (facultatif) -- atexit() */
static void quit(void)
{
}

/***************************************************************************/
/* La fonction principale : NE CHANGE JAMAIS ou presque                    */
/***************************************************************************/
int main(int argc, char **argv)
{
    /* creation de la fenetre - titre et tailles (pixels) */
    g3x_InitWindow(*argv, WWIDTH, WHEIGHT);

    g3x_SetInitFunction(init); /* fonction d'initialisation */
    g3x_SetCtrlFunction(ctrl); /* fonction de contrôle      */
    g3x_SetDrawFunction(draw); /* fonction de dessin        */
    g3x_SetAnimFunction(anim); /* fonction d'animation      */
    g3x_SetExitFunction(quit); /* fonction de sortie        */

    /* lancement de la boucle principale */
    return g3x_MainStart();
    /* RIEN APRES CA */
}