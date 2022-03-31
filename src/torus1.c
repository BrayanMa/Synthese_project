/*=================================================================*/
/*= E.Incerti - eric.incerti@univ-eiffel.fr                       =*/
/*= Université Gustave Eiffel                                     =*/
/*= Code "squelette" pour prototypage avec libg3x.6c              =*/
/*=================================================================*/

#include <g3x.h>
#include <math.h>

#include "shape.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

static struct _shape_ torus;

static double scale_n1 = 1.;
static double scale_n2 = 1.;
static double scale_n3 = 1.;
static double R = 1.0;            // Rayon du trou
static double S = 0.5;            // Rayon du tore (épaisseur)

/* Notre tableau de point */

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
    torus.n1 = 100; // nm
    torus.n2 = 100; // np

    torus.vrtx = malloc(torus.n1 * torus.n2 * sizeof(G3Xpoint));
    torus.norm = malloc(torus.n1 * torus.n2 * sizeof(G3Xvector));

    double theta = 2 * PI / (torus.n1 - 1);
    double phi = 2 * PI / (torus.n2 - 1); // -1 ici, car on veut NBP faces et pas NBP lignes

    int i, j, k;
    for (i = 0; i < torus.n1; i++)
    {
        for (j = 0; j < torus.n2 ; j++)
        {
            torus.vrtx[i * torus.n1 + j] = (G3Xpoint){cos(i * theta) * (R + S * cos(j * phi)),-sin(i * theta) * (R + S * cos(j * phi)), S * sin(j * phi)};
            torus.norm[i * torus.n1 + j] = (G3Xvector){cos(i * theta) * cos(j * phi), - sin(i * theta) * cos(j * phi), sin(j * phi)};
        }
    }

}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
    g3x_CreateScrollv_d("step", &scale_n1, 1, 1000, 1, "Pas de rendu");
    g3x_CreateScrollv_d("", &scale_n2, 1, 1000, 1, "Pas de rendu");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
    glPointSize(3);
    g3x_Material(G3Xg, .2, .6, .9, 1, 1);

    glBegin(GL_QUADS);
    for (int i = 0; i < torus.n2 - 1; i += scale_n2)
    {
        for (int j = 0; j < torus.n1 - 1; j += scale_n1)
        {
            int k;
            k = (i)*torus.n1 + min(j + scale_n1, torus.n1 - 1);
            // k = (i)*torus.n1 + (j + 1);
            g3x_Normal3dv(torus.norm[k]);
            g3x_Vertex3dv(torus.vrtx[k]);

            k = min(i + scale_n2, torus.n2 - 1) * torus.n1 + min(j + scale_n1, torus.n1 - 1);
            // k = (i + 1) * torus.n1 + (j + 1);
            g3x_Normal3dv(torus.norm[k]);
            g3x_Vertex3dv(torus.vrtx[k]);

            k = min(i + scale_n2, torus.n2 - 1) * torus.n1 + (j);
            // k = (i + 1) * torus.n1 + (j);
            g3x_Normal3dv(torus.norm[k]);
            g3x_Vertex3dv(torus.vrtx[k]);

            k = (i)*torus.n1 + (j);
            // k = (i)*torus.n1 + (j);
            g3x_Normal3dv(torus.norm[k]);
            g3x_Vertex3dv(torus.vrtx[k]);
        }
        

       
    }
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
