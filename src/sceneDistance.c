#include "node.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 1300, WHEIGHT = 700;

Shape *cube;
Shape *torus;
Shape *cone;
Shape *cylinder;

Node *full_scene;
Node *nodeCube;
Node *nodeTorus;
Node *nodeCone;
Node *nodeCylinder;

double mat[4] = {.2, .6, .9, 1};

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
    cube = init_cube();

    torus = init_torus();

    cone = init_cone();

    cylinder = init_cylinder();

    full_scene = init_node(g3x_Identity(), (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, (G3Xvector){1, 1, 1});
    apply_homot(full_scene, .6, .6, .6);

    nodeCube = init_node_with_shape(full_scene->Md, G3Xr, mat, full_scene->scale_factor, cube);
    apply_trans(nodeCube, 3, 0, 0);

    nodeTorus = init_node_with_shape(full_scene->Md, G3Xg, mat, full_scene->scale_factor, torus);
    apply_trans(nodeTorus, 0, 3, 0);

    nodeCone = init_node_with_shape(full_scene->Md, G3Xb, mat, full_scene->scale_factor, cone);
    apply_trans(nodeCone, 0, -3, 0);

    nodeCylinder = init_node_with_shape(full_scene->Md, G3Xy, mat, full_scene->scale_factor, cylinder);
    apply_trans(nodeCylinder, -3, 0, 0);

    full_scene->down = nodeCube;
    nodeCube->next = nodeTorus;
    nodeTorus->next = nodeCone;
    nodeCone->next = nodeCylinder;
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
    draw_node(full_scene, g3x_GetCamera()->pos);
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
    g3x_InitWindow(argv[0], WWIDTH, WHEIGHT);

    g3x_SetInitFunction(init); /* fonction d'initialisation */
    g3x_SetCtrlFunction(ctrl); /* fonction de contrôle      */
    g3x_SetDrawFunction(draw); /* fonction de dessin        */
    g3x_SetAnimFunction(anim); /* fonction d'animation      */
    g3x_SetExitFunction(quit); /* fonction de sortie        */

    /* lancement de la boucle principale */
    return g3x_MainStart();
    /* RIEN APRES CA */
}