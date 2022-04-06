#include "node.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 1000, WHEIGHT = 500;

Shape *cube;
Shape *cube2;
Shape *cube3;
Shape *cube4;
Shape *cube5;
Shape *cube6;
Shape *cube7;
Shape *cube8;
Shape *cube9;
Shape *cube10;
Shape *cube11;
Shape *cube12;
Shape *cube13;

Shape *cube14;

Shape *cylinder1;
Shape *cylinder2;
Shape *cylinder3;
Shape *cylinder4;
Shape *cylinder5;
Shape *cylinder6;
Shape *cylinder7;
Shape *cylinder8;
Shape *cylinder9;
Shape *cylinder10;

Node *full_scene;

Node *table;
Node *table2;

Node *table_ronde;
Node *table_ronde2;

Node *sol;
Node *sol2;
Node *sol3;
Node *sol4;

Node *plateau;
Node *plateau2;
Node *plateau3;
Node *plateau4;

Node *pieds;
Node *pieds2;
Node *pieds3;
Node *pieds4;

Node *pied1;
Node *pied2;
Node *pied3;
Node *pied4;

Node *pied5;
Node *pied6;
Node *pied7;
Node *pied8;

Node *pied9;
Node *pied10;
Node *pied11;
Node *pied12;

Node *pied13;
Node *pied14;
Node *pied15;
Node *pied16;

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
  cube7 = init_cube();
  cube8 = init_cube();
  cube9 = init_cube();
  cube10 = init_cube();
  cube11 = init_cube();
  cube12 = init_cube();
  cube13 = init_cube();
  cube14 = init_cube();

  cylinder1 = init_cylinder();
  cylinder2 = init_cylinder();
  cylinder3 = init_cylinder();
  cylinder4 = init_cylinder();
  cylinder5 = init_cylinder();
  cylinder6 = init_cylinder();
  cylinder7 = init_cylinder();
  cylinder8 = init_cylinder();
  cylinder9 = init_cylinder();
  cylinder10 = init_cylinder();

  full_scene = init_node(g3x_Identity(), (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, (G3Xvector){1, 1, 1});
  apply_homot(full_scene, .7, .7, .7);
  apply_trans(full_scene, .5, .5, 0);

  /*Premier element */
  sol = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, full_scene->scale_factor, cube2);
  apply_homot(sol, 1.3, 1.3, .01);
  // apply_rotat(sol, 0, 0, 1);

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

  /* Deuxieme element */
  sol2 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.6, 0.6, 0.6, 0.00}, mat, full_scene->scale_factor, cube7);
  apply_homot(sol2, 1.3, 1.3, .01);
  // apply_rotat(sol2, 0, 0, 1);
  apply_trans(sol2, 0, -2.6, 0);

  /*Table ronde*/
  table_ronde2 = init_node(g3x_Identity(), (G3Xcolor){0.40, 0.30, 0.20, 0.00}, mat, full_scene->scale_factor);
  apply_trans(table_ronde2, 0, -2.6, 1);

  plateau3 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.40, 0.20, 0.00}, mat, table_ronde->scale_factor, cylinder6);
  apply_homot(plateau3, .5, .5, .05);

  pieds3 = init_node(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table_ronde2->scale_factor);
  apply_homot(pieds3, .03, .03, .5);

  pied9 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cube8);
  apply_trans(pied9, -13, 0, -1);
  pied10 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cube9);
  apply_trans(pied10, 13, 0, -1);
  pied11 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cube10);
  apply_trans(pied11, 0, 13, -1);
  pied12 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cube11);
  apply_trans(pied12, 0, -13, -1);

  /*Troisième élément*/
  sol3 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, full_scene->scale_factor, cube12);
  apply_homot(sol3, 1.3, 1.3, .01);
  apply_trans(sol3, -2.6, -2.6, 0);

  /*Quatrième sol*/
  sol4 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.6, 0.6, 0.6, 0.00}, mat, full_scene->scale_factor, cube13);
  apply_homot(sol4, 1.3, 1.3, .01);
  apply_trans(sol4, -2.6, 0, 0);

  /* Deuxième table normale */
  table2 = init_node(g3x_Identity(), (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, full_scene->scale_factor);
  apply_trans(table2, -2.6, -1, 1);
  apply_rotat(table2, 0, 0, -.3);

  plateau4 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, table2->scale_factor, cube14);
  apply_homot(plateau4, .5, 1, .05);

  pieds4 = init_node(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table2->scale_factor);
  apply_homot(pieds4, .05, .05, .5);

  pied13 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds4->scale_factor, cylinder6);
  apply_trans(pied13, 8, -18, -1);
  pied14 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds4->scale_factor, cylinder8);
  apply_trans(pied14, 8, 18, -1);
  pied15 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds4->scale_factor, cylinder9);
  apply_trans(pied15, -8, -18, -1);
  pied16 = init_node_with_shape(g3x_Identity(), (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds4->scale_factor, cylinder10);
  apply_trans(pied16, -8, 18, -1);

  /*Lien*/
  full_scene->down = sol;
  sol->next = sol2;
  sol2->next = sol3;
  sol3->next = sol4;
  sol4->next = table;
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
  table_ronde->next = table_ronde2;
  table_ronde2->down = plateau3;
  plateau3->next = pieds3;
  pieds3->down = pied9;
  pied9->next = pied10;
  pied10->next = pied11;
  pied11->next = pied12;
  table_ronde2->next = table2;
  table2->down = plateau4;
  plateau4->next = pieds4;
  pieds4->down = pied13;
  pied13->next = pied14;
  pied14->next = pied15;
  pied15->next = pied16;
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