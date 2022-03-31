/*=================================================================*/
/*= E.Incerti - eric.incerti@univ-eiffel.fr                       =*/
/*= Université Gustave Eiffel                                     =*/
/*= Code "squelette" pour prototypage avec libg3x.6c              =*/
/*=================================================================*/

#include "shape.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

static struct _shape_ cylinder;

static double scale_n1 = 1.;
static double scale_n2 = 1.;
static double scale_n3 = 1.;
static double H = 2; // Hauteur du cylindre
static double R = 1; // Rayon du cylindre

/* Notre tableau de point */

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
    cylinder.n1 = 100; // nm
    cylinder.n2 = 100; // np
    cylinder.n3 = 100; // np

    cylinder.vrtx = malloc(cylinder.n1 * cylinder.n2 * 3 * sizeof(G3Xpoint));
    cylinder.norm = malloc(cylinder.n1 * cylinder.n2 * 3 * sizeof(G3Xvector));

    double theta = 2 * PI / (cylinder.n1 - 1);
    double t = H / (cylinder.n2 - 1);
    double r = R / (cylinder.n3 - 1);

    int i, j, k;
    for (i = 0; i < cylinder.n1; i++)
    {
        for (j = 0; j < cylinder.n2 - 1; j++)
        {
            cylinder.vrtx[i * cylinder.n1 + j] = (G3Xpoint){R * cos(i * theta), R * sin(i * theta), (j * t) - (H / 2.)};
            cylinder.norm[i * cylinder.n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 0};
        }
        j = cylinder.n2 - 1;
        cylinder.vrtx[i * cylinder.n1 + j] = (G3Xpoint){R * cos(i * theta), R * sin(i * theta), (j * t) - (H / 2.)};
        cylinder.norm[i * cylinder.n1 + j] = (G3Xvector){R * cos(i * theta), R * sin(i * theta), 0};

        for (k = 0; k < cylinder.n3 - 1; k++)
        {
            cylinder.vrtx[(cylinder.n1 * cylinder.n2) + (i * cylinder.n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), (H / 2.)};
            cylinder.norm[(cylinder.n1 * cylinder.n2) + (i * cylinder.n1 + k)] = (G3Xvector){0, 0, 1};
            cylinder.vrtx[(cylinder.n1 * cylinder.n2) * 2 + (i * cylinder.n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
            cylinder.norm[(cylinder.n1 * cylinder.n2) * 2 + (i * cylinder.n1 + k)] = (G3Xvector){0, 0, -1};
        }
        k = cylinder.n3 - 1;
        cylinder.vrtx[(cylinder.n1 * cylinder.n2) + (i * cylinder.n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), (H / 2.)};
        cylinder.norm[(cylinder.n1 * cylinder.n2) + (i * cylinder.n1 + k)] = (G3Xvector){0, 0, 1};
        cylinder.vrtx[(cylinder.n1 * cylinder.n2) * 2 + (i * cylinder.n1 + k)] = (G3Xpoint){(k * r) * cos(i * theta), (k * r) * sin(i * theta), -(H / 2.)};
        cylinder.norm[(cylinder.n1 * cylinder.n2) * 2 + (i * cylinder.n1 + k)] = (G3Xvector){0, 0, -1};
    }
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
    g3x_CreateScrollv_d("step", &scale_n1, 1, 1000, 1, "Pas de rendu");
    g3x_CreateScrollv_d("step", &scale_n2, 1, 1000, 1, "Pas de rendu");
    g3x_CreateScrollv_d("step", &scale_n3, 1, 1000, 1, "Pas de rendu");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
    glPointSize(3);
    g3x_Material(G3Xg, .2, .6, .9, 1, 1);

    glBegin(GL_QUADS);
    for (int i = 0; i < cylinder.n2 - 1; i += scale_n2)
    {
        for (int j = 0; j < cylinder.n1 - 1; j += scale_n1)
        {
            int k;
            k = (i)*cylinder.n1 + min(j + scale_n1, cylinder.n1 - 1);
            printf("%d\n", k);
            // k = (i)*cylinder.n1 + (j + 1);

            g3x_Normal3dv(cylinder.norm[k]);
            g3x_Vertex3dv(cylinder.vrtx[k]);

            k = min(i + scale_n2, cylinder.n2 - 1) * cylinder.n1 + min(j + scale_n1, cylinder.n1 - 1);
            // k = (i + 1) * cylinder.n1 + (j + 1);
            g3x_Normal3dv(cylinder.norm[k]);
            g3x_Vertex3dv(cylinder.vrtx[k]);

            k = min(i + scale_n2, cylinder.n2 - 1) * cylinder.n1 + (j);
            // k = (i + 1) * cylinder.n1 + (j);
            g3x_Normal3dv(cylinder.norm[k]);
            g3x_Vertex3dv(cylinder.vrtx[k]);

            k = (i)*cylinder.n1 + (j);
            // k = (i)*cylinder.n1 + (j);
            g3x_Normal3dv(cylinder.norm[k]);
            g3x_Vertex3dv(cylinder.vrtx[k]);
        }
        for (int l = 0; l < cylinder.n3 - 1; l += scale_n3)
        {
            int k;
            k = (i)*cylinder.n1 + min(l + scale_n3, cylinder.n3 - 1);
            // k = (i)*cylinder.n1 + (l + 1);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) + k]);

            k = min(i + scale_n2, cylinder.n2 - 1) * cylinder.n1 + min(l + scale_n3, cylinder.n3 - 1);
            // k = (i + 1) * cylinder.n1 + (l + 1);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) + k]);

            k = min(i + scale_n2, cylinder.n2 - 1) * cylinder.n1 + (l);
            // k = (i + 1) * cylinder.n1 + (l);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) + k]);

            k = (i)*cylinder.n1 + (l);
            // k = (i)*cylinder.n1 + (l);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) + k]);
        }
        for (int m = 0; m < cylinder.n3 - 1; m += scale_n3)
        {
            int k;
            k = (i)*cylinder.n1 + min(m + scale_n3, cylinder.n3 - 1);
            // k = (i)*cylinder.n1 + (l + 1);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) * 2 + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) * 2 + k]);

            k = min(i + scale_n2, cylinder.n2 - 1) * cylinder.n1 + min(m + scale_n3, cylinder.n3 - 1);
            // k = (i + 1) * cylinder.n1 + (l + 1);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) * 2 + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) * 2 + k]);

            k = min(i + scale_n2, cylinder.n2 - 1) * cylinder.n1 + (m);
            // k = (i + 1) * cylinder.n1 + (l);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) * 2 + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) * 2 + k]);

            k = (i)*cylinder.n1 + (m);
            // k = (i)*cylinder.n1 + (l);
            g3x_Normal3dv(cylinder.norm[(cylinder.n1 * cylinder.n2) * 2 + k]);
            g3x_Vertex3dv(cylinder.vrtx[(cylinder.n1 * cylinder.n2) * 2 + k]);
        }

        /*for (int i = 0; i < NBM; i += step)
        {
            for (int j = 0; j < NBP; j += step)
            {
                // Premier triangle (SW -> SE -> NW)
                NormalVertex3dv(side[i][min(j + step, NBP - 1)]);
                NormalVertex3dv(side[min(i + step, NBM) % NBM][min(j + step, NBP - 1)]);
                NormalVertex3dv(side[i][j]);

                // Second triangle (NW -> SE -> NE)
                NormalVertex3dv(side[i][j]);
                NormalVertex3dv(side[min(i + step, NBM) % NBM][min(j + step, NBP - 1)]);
                NormalVertex3dv(side[min(i + step, NBM) % NBM][j]);
            }*/
        /* for (int j = 0; j < NBC; j += step) {
             // Premier triangle (SW -> SE -> NW)
             NormalVertex3dv(top[i][min(j + step, NBC - 1)]);
             NormalVertex3dv(top[min(i + step, NBM) % NBM][min(j + step, NBC - 1)]);
             NormalVertex3dv(top[i][j]);

             // Second triangle (NW -> SE -> NE)
             NormalVertex3dv(top[i][j]);
             NormalVertex3dv(top[min(i + step, NBM) % NBM][min(j + step, NBC - 1)]);
             NormalVertex3dv(top[min(i + step, NBM) % NBM][j]);


             // Premier triangle (SW -> SE -> NW)
             NormalVertex3dv(bottom[i][min(j + step, NBC - 1)]);
             NormalVertex3dv(bottom[min(i + step, NBM) % NBM][min(j + step, NBC - 1)]);
             NormalVertex3dv(bottom[i][j]);

             // Second triangle (NW -> SE -> NE)
             NormalVertex3dv(bottom[i][j]);
             NormalVertex3dv(bottom[min(i + step, NBM) % NBM][min(j + step, NBC - 1)]);
             NormalVertex3dv(bottom[min(i + step, NBM) % NBM][j]);
         }*/
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
