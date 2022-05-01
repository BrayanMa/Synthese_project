#include "node.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH = 1300, WHEIGHT = 700;

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
Shape *cube15;

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
Node *first_part;
Node *second_part;
Node *third_part;
Node *fourth_part;

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
  cube15 = init_cube();

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
  // apply_trans(full_scene, .5, .5, 0);
  apply_homot(full_scene, .6, .6, .6);

  first_part = init_node(full_scene->Md, (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, full_scene->scale_factor);

  second_part = init_node(full_scene->Md, (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, full_scene->scale_factor);
  apply_trans(second_part, 0, -2, 0);
  // apply_rotat(second_part, 0, 0, 1);

  third_part = init_node(full_scene->Md, (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, full_scene->scale_factor);
  apply_trans(third_part, -2, -2, 0);

  fourth_part = init_node(full_scene->Md, (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, full_scene->scale_factor);
  apply_trans(fourth_part, -2, 0, 0);

  /*Premier element */
  sol = init_node_with_shape(first_part->Md, (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, first_part->scale_factor, cube2);
  apply_homot(sol, 1, 1, .01);

  /* Table normale */
  table = init_node(first_part->Md, (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, first_part->scale_factor);
  apply_rotat(table, 0, 0, .5);

  plateau = init_node_with_shape(table->Md, (G3Xcolor){0.60, 0.40, 0.20, 0.00}, mat, table->scale_factor, cube);
  apply_homot(plateau, .5, 1, .05);
  apply_trans(plateau, 0, 0, 15);

  pieds = init_node(table->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table->scale_factor);
  apply_homot(pieds, .05, .05, .35);
  apply_trans(pieds, 0, 0, 1);

  pied1 = init_node_with_shape(pieds->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder1);
  apply_trans(pied1, 7, -17, 0);
  pied2 = init_node_with_shape(pieds->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder2);
  apply_trans(pied2, -7, -17, 0);
  pied3 = init_node_with_shape(pieds->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder3);
  apply_trans(pied3, 7, 17, 0);
  pied4 = init_node_with_shape(pieds->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds->scale_factor, cylinder4);
  apply_trans(pied4, -7, 17, 0);

  table_ronde2 = init_node(first_part->Md, (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, first_part->scale_factor);
  apply_rotat(table_ronde2, 3.14, 0, 0);
  apply_trans(table_ronde2, .4, 0, -1.6);

  plateau4 = init_node_with_shape(table_ronde2->Md, (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, table_ronde2->scale_factor, cylinder10);
  apply_homot(plateau4, .5, .5, .05);
  apply_trans(plateau4, 0, 0, 15);

  pieds4 = init_node(table_ronde2->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table_ronde2->scale_factor);
  apply_homot(pieds4, .05, .05, .35);
  apply_trans(pieds4, 0, 0, 1);

  pied13 = init_node_with_shape(pieds4->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds4->scale_factor, cube12);
  apply_trans(pied13, 8, 0, 0);

  pied14 = init_node_with_shape(pieds4->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds4->scale_factor, cube13);
  apply_trans(pied14, -8, 0, 0);

  pied15 = init_node_with_shape(pieds4->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds4->scale_factor, cube14);
  apply_trans(pied15, 0, 8, 0);

  pied16 = init_node_with_shape(pieds4->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds4->scale_factor, cube15);
  apply_trans(pied16, 0, -8, 0);

  /*Deixème partie*/
  sol2 = init_node_with_shape(second_part->Md, (G3Xcolor){0.6, 0.6, 0.6, 0.00}, mat, second_part->scale_factor, cube3);
  apply_homot(sol2, 1, 1, .01);

  table_ronde = init_node(second_part->Md, (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, second_part->scale_factor);

  plateau2 = init_node_with_shape(table_ronde->Md, (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, table_ronde->scale_factor, cylinder5);
  apply_homot(plateau2, .5, .5, .05);
  apply_trans(plateau2, 0, 0, 15);

  pieds2 = init_node(table_ronde->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table_ronde->scale_factor);
  apply_homot(pieds2, .05, .05, .35);
  apply_trans(pieds2, 0, 0, 1);

  pied5 = init_node_with_shape(pieds2->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds2->scale_factor, cube5);
  apply_trans(pied5, 8, 0, 0);

  pied6 = init_node_with_shape(pieds2->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds2->scale_factor, cube6);
  apply_trans(pied6, -8, 0, 0);

  pied7 = init_node_with_shape(pieds2->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds2->scale_factor, cube7);
  apply_trans(pied7, 0, 8, 0);

  pied8 = init_node_with_shape(pieds2->Md, (G3Xcolor){0.78, 0.68, 0.50, 0.00}, mat, pieds2->scale_factor, cube8);
  apply_trans(pied8, 0, -8, 0);

  /*Troisième partie */
  sol3 = init_node_with_shape(third_part->Md, (G3Xcolor){0.3, 0.3, 0.3, 0.00}, mat, third_part->scale_factor, cube9);
  apply_homot(sol3, 1, 1, .01);

  /*Quatrième partie*/

  sol4 = init_node_with_shape(fourth_part->Md, (G3Xcolor){0.6, 0.6, 0.6, 0.00}, mat, fourth_part->scale_factor, cube10);
  apply_homot(sol4, 1, 1, .01);

  table2 = init_node(fourth_part->Md, (G3Xcolor){0.30, 0.20, 0.10, 0.00}, mat, first_part->scale_factor);
  apply_rotat(table2, 0, 0, 1);

  plateau3 = init_node_with_shape(table2->Md, (G3Xcolor){0.60, 0.40, 0.20, 0.00}, mat, table2->scale_factor, cube11);
  apply_homot(plateau3, .5, 1, .05);
  apply_trans(plateau3, 0, 0, 15);

  pieds3 = init_node(table2->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, table2->scale_factor);
  apply_homot(pieds3, .05, .05, .35);
  apply_trans(pieds3, 0, 0, 1);

  pied9 = init_node_with_shape(pieds3->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cylinder6);
  apply_trans(pied9, 7, -17, 0);
  pied10 = init_node_with_shape(pieds3->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cylinder7);
  apply_trans(pied10, -7, -17, 0);
  pied11 = init_node_with_shape(pieds3->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cylinder8);
  apply_trans(pied11, 7, 17, 0);
  pied12 = init_node_with_shape(pieds3->Md, (G3Xcolor){0.60, 0.75, 0.95, 0.00}, mat, pieds3->scale_factor, cylinder9);
  apply_trans(pied12, -7, 17, 0);

  /*Lien*/
  full_scene->down = first_part;
  first_part->next = second_part;
  second_part->next = third_part;
  third_part->next = fourth_part;

  first_part->down = sol;
  sol->next = table;
  table->down = plateau;
  plateau->next = pieds;
  pieds->down = pied1;
  pied1->next = pied2;
  pied2->next = pied3;
  pied3->next = pied4;
  table->next = table_ronde2;
  table_ronde2->down = plateau4;
  plateau4->next = pieds4;
  pieds4->down = pied13;
  pied13->next = pied14;
  pied14->next = pied15;
  pied15->next = pied16;

  second_part->down = sol2;
  sol2->next = table_ronde;
  table_ronde->down = plateau2;
  plateau2->next = pieds2;
  pieds2->down = pied5;
  pied5->next = pied6;
  pied6->next = pied7;
  pied7->next = pied8;

  third_part->down = sol3;

  fourth_part->down = sol4;
  sol4->next = table2;
  table2->down = plateau3;
  plateau3->next = pieds3;
  pieds3->down = pied9;
  pied9->next = pied10;
  pied10->next = pied11;
  pied11->next = pied12;
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
  G3Xpoint *campos = g3x_GetCamera()->pos;
  draw_node(full_scene, campos);
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