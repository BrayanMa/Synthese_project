#include "node.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 1000, WHEIGHT = 500;

Shape *cube;
Shape *cube2;
Shape *cube3;
Shape *cube4;
Shape *cube5;
Shape *cube6;
Shape *cylinder1;
Shape *cylinder2;
Shape *cylinder3;
Shape *cylinder4;
Shape *cylinder5;
Shape *test;

Node *full_scene;

Node *table;
Node *table_ronde;

Node *sol;

Node *plateau;
Node *plateau2;

Node *pieds;
Node *pieds2;

Node *pied1;
Node *pied2;
Node *pied3;
Node *pied4;

Node *pied5;
Node *pied6;
Node *pied7;
Node *pied8;

Node *test1;

double mat[4] = {.2, .6, .9, 1};

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{
  /*Premier élément*/
  cube = init_cube();
  cube2 = init_cube();
  cube3 = init_cube();
  cube4 = init_cube();
  cube5 = init_cube();
  cube6 = init_cube();
  test = init_cylinder();

  cylinder1 = init_cylinder();
  cylinder2 = init_cylinder();
  cylinder3 = init_cylinder();
  cylinder4 = init_cylinder();
  cylinder5 = init_cylinder();

  test1 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, (G3Xvector){1, 1, 1}, test);
  apply_homot(test1, .5, .5, 1);

  full_scene = init_node(g3x_Identity(), (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, (G3Xvector){1, 1, 1});

  /*Premier element */
  sol = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, full_scene->scale_factor, cube2);
  apply_homot(sol, 1.3, 1.3, .01);
  apply_rotat(sol, 0, 0, 1);

  /* Table normale */
  table = init_node(g3x_Identity(), (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, full_scene->scale_factor);
  apply_trans(table, 0, 0, 1);

  plateau = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, table->scale_factor, cube);
  apply_homot(plateau, .5, 1, .05);

  pieds = init_node(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table->scale_factor);
  apply_homot(pieds, .05, .05, .5);

  pied1 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder1);
  apply_trans(pied1, 8, -18, -1);
  pied2 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder2);
  apply_trans(pied2, 8, 18, -1);
  pied3 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder3);
  apply_trans(pied3, -8, -18, -1);
  pied4 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder4);
  apply_trans(pied4, -8, 18, -1);

  /*Table ronde*/
  table_ronde = init_node(g3x_Identity(), (G3Xcolor){0.40, 0.30, 0.20, 0.00}, mat, full_scene->scale_factor);
  apply_trans(table_ronde, .3, .3, -1.1);
  apply_rotat(table_ronde, 3.15, 0, 0);

  plateau2 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.40, 0.20, 0.00}, mat, table_ronde->scale_factor, cylinder5);
  apply_homot(plateau2, .5, .5, .05);

  pieds2 = init_node(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table_ronde->scale_factor);
  apply_homot(pieds2, .03, .03, .5);

  pied5 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds2->scale_factor, cube3);
  apply_trans(pied5, -13, 0, -1);
  pied6 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds2->scale_factor, cube4);
  apply_trans(pied6, 13, 0, -1);
  pied7 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds2->scale_factor, cube5);
  apply_trans(pied7, 0, 13, -1);
  pied8 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds2->scale_factor, cube6);
  apply_trans(pied8, 0, -13, -1);

  /*Lien*/
  full_scene->down = sol;
  sol->next = table;
  table->down = plateau;
  plateau->next = pieds;
  pieds->down = pied1;
  pied1->next = pied2;
  pied2->next = pied3;
  pied3->next = pied4;
  table->next = table_ronde;
  table_ronde->down = plateau2;
  plateau2->next = pieds2;
  pieds2->down = pied5;
  pied5->next = pied6;
  pied6->next = pied7;
  pied7->next = pied8;
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
  draw_node(full_scene);
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