
/*=================================================================*/
/*= E.Incerti - eric.incerti@univ-eiffel.fr                       =*/
/*= Université Gustave Eiffel                                     =*/
/*= Code "squelette" pour prototypage avec libg3x.6c              =*/
/*=================================================================*/

#include "shape.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

static struct _shape_ sphere;

static double scale_n1 = 1.;
static double scale_n2 = 1.;
static double scale_n3 = 1.;

/* Notre tableau de point */

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
    // double hx = 1;
    // double hy = 1;
    // double hz = 1;

    sphere.n1 = 100; // nm
    sphere.n2 = 100; // np

    sphere.vrtx = malloc(sphere.n1 * sphere.n2 * sizeof(G3Xpoint));
    sphere.norm = malloc(sphere.n1 * sphere.n2 * sizeof(G3Xvector));

    int i, j;
    double theta = (2 * PI) / (sphere.n1 - 1);
    double phi = (PI) / (sphere.n2);

    double r, x, y, z;

    i = 0;
    for (j = 0; j < sphere.n1; j++)
    {
        sphere.vrtx[i * sphere.n1 + j] = (G3Xpoint){0., 0., +1.};
        sphere.norm[i * sphere.n1 + j] = (G3Xvector){0., 0., +1.};
    }

    for (i = 1; i < sphere.n2 - 1; i++)
    {
        z = cos(i * phi);
        r = sin(i * phi);
        for (j = 0; j < sphere.n1; j++)
        {
            sphere.vrtx[i * sphere.n1 + j] = (G3Xpoint){r * cos(j * theta), r * sin(j * theta), z};
            sphere.norm[i * sphere.n1 + j] = (G3Xvector){r * cos(j * theta), r * sin(j * theta), z};
        }
    }
    i = sphere.n2 - 1;
    for (j = 0; j < sphere.n1; j++)
    {
        sphere.vrtx[i * sphere.n1 + j] = (G3Xpoint){0., 0., -1.};
        sphere.norm[i * sphere.n1 + j] = (G3Xvector){0., 0., -1.};
    }
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
    g3x_CreateScrollv_d("n1", &scale_n1, 1, 500, 1, "");
    g3x_CreateScrollv_d("n2", &scale_n2, 1, 500, 1, "");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
    g3x_Material(G3Xg, .2, .6, .9, 1, 1);
    //glPushMatrix();
    //glScaled(1, 0.2, 0.4);

    glBegin(GL_QUADS);

    int step1 = min(scale_n1, (int)(scale_n1 / 0.2));
    int step2 = min(scale_n2, (int)(scale_n2 / 0.2));

    // Face 1 = base du sphere
    // double step_n1 = 1;
    // printf("%d\n", step_n1);

    for (int i = 0; i < sphere.n2 - 1; i += step2)
    {
        for (int j = 0; j < sphere.n1 - 1; j += step1)
        {
            int k;
            k = (i)*sphere.n1 + min(j + scale_n1, sphere.n1 - 1);
            // k = (i)*sphere.n1 + (j + 1);
            g3x_Normal3dv(sphere.norm[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);

            k = min(i + scale_n2, sphere.n2 - 1) * sphere.n1 + min(j + scale_n1, sphere.n1 - 1);
            // k = (i + 1) * sphere.n1 + (j + 1);
            g3x_Normal3dv(sphere.norm[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);

            k = min(i + scale_n2, sphere.n2 - 1) * sphere.n1 + (j);
            // k = (i + 1) * sphere.n1 + (j);
            g3x_Normal3dv(sphere.norm[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);

            k = (i)*sphere.n1 + (j);
            // k = (i)*sphere.n1 + (j);
            g3x_Normal3dv(sphere.norm[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);
            /*int k;
            k = (i)*sphere.n1 + (j);
            g3x_Normal3dv(sphere.vrtx[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);
            k = (i)*sphere.n1 + (j + 1);
            g3x_Normal3dv(sphere.vrtx[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);
            k = (i + 1) * sphere.n1 + (j + 1);
            g3x_Normal3dv(sphere.vrtx[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);
            k = (i + 1) * sphere.n1 + (j);
            g3x_Normal3dv(sphere.vrtx[k]);
            g3x_Vertex3dv(sphere.vrtx[k]);*/
        }
    }
    glEnd();
    //glPopMatrix();
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