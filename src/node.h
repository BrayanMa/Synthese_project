#ifndef __H_NODE
#define __H_NODE

#include "shape.h"

typedef struct _node_
{
    struct _node_ *down, *next; /* chaînage*/
    G3Xhmat Md;                 /* matrice de transformation directe*/
    G3Xcolor col;               /* couleur RGBA*/
    double mat[4];              /* 4 réels dans [0,1] : (ambi, diff, spec, shine) */
    G3Xvector scale_factor;     /* facteurs d’échelles locaux en x,y,z,*/
    Shape *instance;            /* une éventuelle instance d’objet*/
} Node, *SceneTree;

Node *init_node(G3Xhmat Md, G3Xcolor col, double *mat, G3Xvector scale_factor, Shape *instance);

void add_shape(Node *father, Shape *instance);
void draw_node();
void draw_full_node(Node *father);


#endif
