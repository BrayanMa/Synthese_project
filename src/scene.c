#include "node.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 512, WHEIGHT = 512;

Shape *cube;
Shape *cube2;
Shape *cylinder1;
Shape *cylinder2;
Shape *cylinder3;
Shape *cylinder4;
Shape *test;

Node *table;
Node *plateau;
Node *plateau2;
Node *pieds;
Node *pied1;
Node *pied2;
Node *pied3;
Node *pied4;

double mat[4] = {.2, .6, .9, 1};

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
  cube = init_cube();
  cube2 = init_cube();
  cylinder1 = init_cylinder();
  cylinder2 = init_cylinder();
  cylinder3 = init_cylinder();
  cylinder4 = init_cylinder();
  test = init_cylinder();

  table = init_node(g3x_Identity(), (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, (G3Xvector){1, 1, 1});
  // apply_homot(table, .2, .2, 1);
  apply_trans(table, 0, 0, -1);
  apply_rotat(table, 10, 0, 0);

  plateau = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, (G3Xvector){1, 1, 1}, cube);
  apply_homot(plateau, 1, 1, .01);

  pieds = init_node(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, (G3Xvector){1, 1, 1});
  apply_homot(pieds, .05, .05, 1);
  // apply_trans(pieds, 0, 0, -1);

  // apply_rotat(pieds, .1, .1, .1);

  pied1 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, (G3Xvector){1, 1, 1}, cylinder1);
  apply_trans(pied1, 18, -18, -1);
  pied2 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, (G3Xvector){1, 1, 1}, cylinder2);
  apply_trans(pied2, 18, 18, -1);
  pied3 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, (G3Xvector){1, 1, 1}, cylinder3);
  apply_trans(pied3, -18, -18, -1);
  pied4 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, (G3Xvector){1, 1, 1}, cylinder4);
  apply_trans(pied4, -18, 18, -1);

  table->down = plateau;
  // plateau->next = plateau2;
  plateau->next = pieds;
  pieds->down = pied1;
  pied1->next = pied2;
  pied2->next = pied3;
  pied3->next = pied4;
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
  // draw_node(pieds);
  draw_node(table);
  // draw_node(table);
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