#include "node.h"

Node *init_node_with_shape(G3Xhmat Md, G3Xcolor col, double *mat, G3Xvector scale_factor, Shape *instance)
{
    if (instance == NULL)
        return NULL;

    Node *node;

    if (NULL == (node = malloc(1 * sizeof(Node))))
        return NULL;

    node->down = NULL;
    node->next = NULL;
    node->col = col;
    node->Md = Md;
    node->mat[0] = mat[0];
    node->mat[1] = mat[1];
    node->mat[2] = mat[2];
    node->mat[3] = mat[3];
    node->scale_factor = scale_factor;
    node->instance = instance;

    return node;
}

Node *init_node(G3Xhmat Md, G3Xcolor col, double *mat, G3Xvector scale_factor)
{
    Node *node;

    if (NULL == (node = malloc(1 * sizeof(Node))))
        return NULL;

    node->down = NULL;
    node->next = NULL;
    node->col = col;
    node->Md = Md;
    node->mat[0] = mat[0];
    node->mat[1] = mat[1];
    node->mat[2] = mat[2];
    node->mat[3] = mat[3];
    node->scale_factor = scale_factor;
    node->instance = NULL;

    return node;
}

void add_shape(Node *father, Shape *instance)
{
    Node *tmp;

    if (father->down == NULL)
    {
        // father->down = init_node(father->Md, father->col, father->mat, father->scale_factor, instance);
        return;
    }
    tmp = father->down;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp->next = init_node(father->Md, father->col, father->mat, father->scale_factor, instance);
}

double get_distance(Node *node, G3Xpoint *cam)
{
    return sqrt(pow(node->Md.m[12] - cam->x, 2) + pow(node->Md.m[13] - cam->y, 2) + pow(node->Md.m[14] - cam->z, 2));
}

void draw_node(Node *node, G3Xpoint *cam)
{
    double dist = get_distance(node, cam);
    if (NULL == node)
        return;
    g3x_Material(node->col, node->mat[0], node->mat[1], node->mat[2], node->mat[3], 1);
    glPushMatrix();
    glMultMatrixd(node->Md.m);
    if (NULL != node->instance)
    {
        node->instance->draw_faces(node->instance, node->scale_factor, dist);
    }
    glPopMatrix();

    if (node->down != NULL)
        draw_node(node->down, cam);
    if (node->next != NULL)
        draw_node(node->next, cam);
}

void apply_homot(Node *node, double x, double y, double z)
{
    node->Md = g3x_Mat_x_Mat(node->Md, g3x_Homothetie3d(x, y, z));
    node->scale_factor.x *= x;
    node->scale_factor.y *= y;
    node->scale_factor.z *= z;
}

void apply_rotat(Node *node, double x, double y, double z)
{
    node->Md = g3x_Mat_x_Mat(node->Md, g3x_RotationX(x));
    node->Md = g3x_Mat_x_Mat(node->Md, g3x_RotationY(y));
    node->Md = g3x_Mat_x_Mat(node->Md, g3x_RotationZ(z));
}

void apply_trans(Node *node, double x, double y, double z)
{
    node->Md = g3x_Mat_x_Mat(node->Md, g3x_Translation3d(x, y, z));
}
