#include "shape.h"

void draw_cube(Shape *cube, G3Xvector scale_factor)
{
    int step_x = max(1, (int)(1. / scale_factor.x));
    int step_y = max(1, (int)(1. / scale_factor.y));
    int step_z = max(1, (int)(1. / scale_factor.z));

    for (int i = 0; i < cube->n2 - 1; i += step_y)
    {
        for (int j = 0; j < cube->n1 - 1; j += step_x)
        {
            int k;
            // k = (i)* cube->n1 + (j);
            k = (i)*cube->n1 + (j);
            g3x_Normal3dv(cube->norm[k]);
            g3x_Vertex3dv(cube->vrtx[k]);
            k = (i)*cube->n1 + min(j + step_x, cube->n1 - 1);
            // k = (i)* cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[k]);
            g3x_Vertex3dv(cube->vrtx[k]);

            k = min(i + step_y, cube->n2 - 1) * cube->n1 + min(j + step_x, cube->n1 - 1);
            // k = (i + 1) *  cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[k]);
            g3x_Vertex3dv(cube->vrtx[k]);

            k = min(i + step_y, cube->n2 - 1) * cube->n1 + (j);
            // k = (i + 1) *  cube->n1 + (j);
            g3x_Normal3dv(cube->norm[k]);
            g3x_Vertex3dv(cube->vrtx[k]);
        }
    }
    for (int i = 0; i < cube->n2 - 1; i += step_y)
    {
        for (int j = 0; j < cube->n1 - 1; j += step_x)
        {
            int k;
            // k = (i)* cube->n1 + (j);
            k = (i)*cube->n1 + (j);

            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 + k]);

            k = (i)*cube->n1 + min(j + step_x, cube->n1 - 1);
            // k = (i)* cube->n1 + (j + 1);

            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 + k]);

            k = min(i + step_y, cube->n2 - 1) * cube->n1 + min(j + step_x, cube->n1 - 1);
            // k = (i + 1) *  cube->n1 + (j + 1);

            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 + k]);

            k = min(i + step_y, cube->n2 - 1) * cube->n1 + (j);
            // k = (i + 1) *  cube->n1 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 + k]);
        }
    }

    for (int i = 0; i < cube->n3 - 1; i += step_z)
    {
        for (int j = 0; j < cube->n1 - 1; j += step_x)
        {
            int k;
            // k = (i)* cube->n1 + (j);
            k = (i)*cube->n3 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 2 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 2 + k]);

            k = (i)*cube->n3 + min(j + step_x, cube->n1 - 1);
            // k = (i)* cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 2 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 2 + k]);

            k = min(i + step_z, cube->n3 - 1) * cube->n1 + min(j + step_x, cube->n1 - 1);
            // k = (i + 1) *  cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 2 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 2 + k]);

            k = min(i + step_z, cube->n3 - 1) * cube->n1 + (j);
            // k = (i + 1) *  cube->n1 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 2 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 2 + k]);
        }
    }
    for (int i = 0; i < cube->n3 - 1; i += step_z)
    {
        for (int j = 0; j < cube->n1 - 1; j += step_x)
        {
            int k;
            // k = (i)* cube->n1 + (j);
            k = (i)*cube->n3 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 3 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 3 + k]);

            k = (i)*cube->n3 + min(j + step_x, cube->n1 - 1);
            // k = (i)* cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 3 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 3 + k]);

            k = min(i + step_z, cube->n3 - 1) * cube->n1 + min(j + step_x, cube->n1 - 1);
            // k = (i + 1) *  cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 3 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 3 + k]);

            k = min(i + step_z, cube->n3 - 1) * cube->n1 + (j);
            // k = (i + 1) *  cube->n1 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 3 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 3 + k]);
        }
    }

    for (int i = 0; i < cube->n2 - 1; i += step_y)
    {
        for (int j = 0; j < cube->n3 - 1; j += step_z)
        {
            int k;
            // k = (i)* cube->n1 + (j);
            k = (i)*cube->n1 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 4 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 4 + k]);

            k = (i)*cube->n1 + min(j + step_z, cube->n3 - 1);
            // k = (i)* cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 4 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 4 + k]);

            k = min(i + step_y, cube->n1 - 1) * cube->n1 + min(j + step_z, cube->n3 - 1);
            // k = (i + 1) *  cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 4 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 4 + k]);

            k = min(i + step_y, cube->n1 - 1) * cube->n1 + (j);
            // k = (i + 1) *  cube->n1 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 4 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 4 + k]);
        }
    }
    for (int i = 0; i < cube->n2 - 1; i += step_y)
    {
        for (int j = 0; j < cube->n3 - 1; j += step_z)
        {
            int k;
            // k = (i)* cube->n1 + (j);
            k = (i)*cube->n1 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 5 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 5 + k]);

            k = (i)*cube->n1 + min(j + step_x, cube->n3 - 1);
            // k = (i)* cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 5 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 5 + k]);

            k = min(i + step_y, cube->n1 - 1) * cube->n1 + min(j + step_z, cube->n3 - 1);
            // k = (i + 1) *  cube->n1 + (j + 1);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 5 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 5 + k]);

            k = min(i + step_y, cube->n1 - 1) * cube->n1 + (j);
            // k = (i + 1) *  cube->n1 + (j);
            g3x_Normal3dv(cube->norm[cube->n1 * cube->n1 * 5 + k]);
            g3x_Vertex3dv(cube->vrtx[cube->n1 * cube->n1 * 5 + k]);
        }
    }
}

Shape *init_cube()
{
    Shape *cube;
    if (NULL == (cube = malloc(1 * sizeof(Shape))))
        return NULL;

    cube->n1 = 100;
    cube->n2 = 100;
    cube->n3 = 100;

    if (NULL == (cube->vrtx = malloc(cube->n1 * cube->n2 * 6 * sizeof(G3Xpoint))))
        return NULL;
    if (NULL == (cube->norm = malloc(cube->n1 * cube->n2 * 6 * sizeof(G3Xvector))))
        return NULL;

    double dy = 2. / (cube->n2 - 1), dx = 2. / (cube->n1 - 1), dz = 2. / (cube->n3 - 1);
    int i, j;

    for (i = 0; i < cube->n2 - 1; i++)
    {
        for (j = 0; j < cube->n1 - 1; j++)
        {
            cube->vrtx[i * cube->n1 + j] = (G3Xpoint){(-1. + j * dx), (-1. + i * dy), 1.};
            cube->norm[i * cube->n1 + j] = (G3Xvector){0., 0., 1.};
            cube->vrtx[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xpoint){(-1. + j * dx), (-1. + i * dy), -1.};
            cube->norm[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xvector){0., 0., -1.};

            cube->vrtx[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., (-1. + i * dz)};
            cube->norm[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xvector){0., 1, 0.};
            cube->vrtx[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xpoint){(-1. + j * dx), -1., (-1. + i * dz)};
            cube->norm[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xvector){0., -1., 0.};

            cube->vrtx[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xpoint){1., (-1. + i * dy), (-1. + j * dz)};
            cube->norm[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xvector){1., 0., 0.};
            cube->vrtx[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xpoint){-1., (-1. + i * dy), (-1. + j * dz)};
            cube->norm[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xvector){-1., 0., 0.};
        }
        j = cube->n1 - 1;
        cube->vrtx[i * cube->n1 + j] = (G3Xpoint){1., (-1. + i * dy), 1.};
        cube->norm[i * cube->n1 + j] = (G3Xvector){0., 0., 1.};
        cube->vrtx[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xpoint){+1, (-1. + i * dy), -1.};
        cube->norm[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xvector){0., 0., -1.};

        cube->vrtx[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xpoint){+1, 1., (-1. + i * dz)};
        cube->norm[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xvector){0., 1., 0.};
        cube->vrtx[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xpoint){+1, -1., (-1. + i * dz)};
        cube->norm[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xvector){0., -1., 0.};

        cube->vrtx[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xpoint){1., (-1. + i * dy), 1.};
        cube->norm[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xvector){1., 0., 0.};
        cube->vrtx[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xpoint){-1., (-1. + i * dy), 1.};
        cube->norm[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xvector){-1., 0., 0.};
    }

    i = cube->n2 - 1;

    for (j = 0; j < cube->n1 - 1; j++)
    {
        cube->vrtx[i * cube->n1 + j] = (G3Xpoint){(-1. + j * dx), 1., 1.};
        cube->norm[i * cube->n1 + j] = (G3Xvector){0., 0., 1.};
        cube->vrtx[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., -1.};
        cube->norm[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xvector){0., 0., -1.};

        cube->vrtx[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xpoint){(-1. + j * dx), 1., 1.};
        cube->norm[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xvector){0., 1., 0.};
        cube->vrtx[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xpoint){(-1. + j * dx), -1., 1.};
        cube->norm[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xvector){0., -1., 0.};

        cube->vrtx[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xpoint){1., 1., (-1. + j * dz)};
        cube->norm[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xvector){1., 0., 0.};
        cube->vrtx[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xpoint){-1., 1., (-1. + j * dz)};
        cube->norm[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xvector){-1., 0., 0.};
    }

    j = cube->n1 - 1;
    cube->vrtx[i * cube->n1 + j] = (G3Xpoint){1., 1., 1.};
    cube->norm[i * cube->n1 + j] = (G3Xvector){0., 0., 1.};
    cube->vrtx[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xpoint){1, 1., -1.};
    cube->norm[(cube->n1 * cube->n1) + (i * cube->n1 + j)] = (G3Xvector){0., 0., -1.};

    cube->vrtx[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xpoint){1, 1., 1.};
    cube->norm[(cube->n1 * cube->n1) * 2 + (i * cube->n1 + j)] = (G3Xvector){0., 1., 0.};
    cube->vrtx[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xpoint){1, -1., 1.};
    cube->norm[(cube->n1 * cube->n1) * 3 + (i * cube->n1 + j)] = (G3Xvector){0., -1., 0.};

    cube->vrtx[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xpoint){1, 1., 1.};
    cube->norm[(cube->n1 * cube->n1) * 4 + (i * cube->n1 + j)] = (G3Xvector){1., 0., 0.};
    cube->vrtx[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xpoint){-1, 1., 1.};
    cube->norm[(cube->n1 * cube->n1) * 5 + (i * cube->n1 + j)] = (G3Xvector){-1., 0., 0.};

    cube->draw_faces = draw_cube;

    return cube;
}
