#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b, c, d, len, occur, printl;
    printl = 1;

    //The program does not work
    if (argc != 2)
    {
        printf("Invalid input, Usage: ./mexp file1.text\n");
        return 0;
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return 0;
    }

    //Proceed if input valid
    fscanf(fp, "%d", &len);

    //Declaration of Matricies
    int **Matrix1 = (int **)malloc(len * sizeof(int *));
    int **Matrix2d = (int **)malloc(len * sizeof(int *));
    int **MatrixAns = (int **)malloc(len * sizeof(int *));

    for (a = 0; a < len; a++)
    {
        Matrix1[a] = (int *)malloc(len * sizeof(int));
        Matrix2d[a] = (int *)malloc(len * sizeof(int));
        MatrixAns[a] = (int *)malloc(len * sizeof(int));
    }

    for (a = 0; a < len; a++)
    {
        for (b = 0; b < len; b++)
        {
            fscanf(fp, "%d", &Matrix1[a][b]);
            if (Matrix1[a][b] > 0)
            {
                printl = 0;
            }
            Matrix2d[a][b] = Matrix1[a][b];
        }
    }

    fscanf(fp, "%d", &occur);

    if (occur != 0)
    {
        printl = 0;
    }

    if (printl == 1)
    {
        for(int a = 0; a < len; a++)
        {
            for(b = 0; b < len; b++)
            {
                if( a == b)
                {
                    if (b == len-1)
                        printf("1");
                    else
                        printf("1 ");
                }
                else{

                    if (b == len-1)
                        printf("0");
                    else
                        printf("0 ");

                }


            }

            printf("\n");
        }

        for (int a = 0; a < len; a++)
        {
            free(Matrix1[a]);
            free(Matrix2d[a]);
            free(MatrixAns[a]);
        }
        free(Matrix1);
        free(Matrix2d);
        free(MatrixAns);

        return 0;

    }

    for (d = 0; d < occur-1; d++)
    {
        for (a = 0; a < len; a++)
        {
            for (b = 0; b < len; b++)
            {
                MatrixAns[a][b] = 0;
                for (c = 0; c < len; c++)
                    MatrixAns[a][b] += Matrix1[a][c] * Matrix2d[c][b];
            }
        }

        for(a = 0; a < len; a++)
        {
            for(b = 0; b < len; b++)
            {
                Matrix2d[a][b] = MatrixAns[a][b];
            }
        }
    }

    for(int a = 0; a < len; a++)
    {
        for(b = 0; b < len; b++)
        {
            if (b == len-1)
                printf("%d", MatrixAns[a][b]);
            else
                printf("%d ", MatrixAns[a][b]);
        }
        printf("\n");
    }

    for (int a = 0; a < len; a++)
    {
        free(Matrix1[a]);
        free(Matrix2d[a]);
        free(MatrixAns[a]);
    }
    free(Matrix1);
    free(Matrix2d);
    free(MatrixAns);

    fclose(fp);
    return 0;

}

