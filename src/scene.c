#include "node.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

Shape *cube;
// Shape *sphere_can;
// Shape *cylinder;
Shape *torus;
Shape *cone;

Node *table;

double mat[4] = {.2, .6, .9, 1};

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
  cube = init_cube();
  // sphere_can = init_sphere();
  // cylinder = init_cylinder();
  torus = init_torus();
  cone = init_cone();

  table = init_node(g3x_Identity(), G3Xb, mat, (G3Xvector){1, 1, 1}, cone);
  add_shape(table, torus);
  add_shape(table, cube);
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
  // cube_can->draw_faces(cube_can, (G3Xvector){1,1,1});
  // sphere_can->draw_faces(sphere_can, (G3Xvector){1,1,1});
  // cylinder->draw_faces(cylinder, (G3Xvector){1,1,1});
  // torus->draw_faces(torus,(G3Xvector){1,1,1});
  draw_full_node(table);
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