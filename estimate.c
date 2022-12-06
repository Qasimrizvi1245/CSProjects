//
// Created by Qasim Rizvi on 10/15/22.
//
// This is a simple machine learning algorithm
/*Given matrices X and Y , your program will compute (XT X)
−1XT Y inv order to learn W. This will
require (1) multiplying, (2) transposing, and (3) inverting matrices. Programming Assignment I
        already involved matrix multiplication; you may adapt your implementation for this assignment.
Transposing an m × n matrix produces an n × m matrix. Each row of the X becomes a column
of XT
.
To find the inverse of XT X, you will use a simplified form of Gauss-Jordan elimination
*/

// I will use count functions for every transpose, multiplication function,
// and inverse functions. Count will allow me to keep track of the number
// of iterations per function

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

// This function transposes the matrix, Transposing an m × n matrix produces an n × m matrix.
// Each row of the X becomes a column of X^T
void transpose(double** ma , double** tra, int ro, int col)
{
    for(int i = 0 ; i < col ; i++){


        for(int j = 0 ; j < ro ; j++){


            tra[i][j] = ma[j][i];
        }
    }
}
// This function counts the number of times the number of times each row of the X
// becomes a column of x^t inv the transpose function
int cTranspose(double** ma , double** tra, int ro, int col){


    int count  =0;


    for(int x=0; x < col; x++){


        for(int j =x +1; j<x; j++){


            if (tra[x][j] == ma[x][j]){


                count++;
            }
        }
    }
    return count;
}

// This functions multiples the function
// used from pa1: mexp
// To compute M^n, it is sufficient to multiply M by itself n − 1 times.
// That is, M^3 = M × M × M.
//Naturally, a different strategy is needed for M^0
//
void multiply(double** ma1 , double** ma2 , double** out, int tr , int al , int z)

{
    double sum = 0;

    for(int x = 0 ; x < tr ; x++){


        for(int y = 0 ; y < z ; y++){


            for(int z = 0; z < al ; z++){


                sum = sum + ma1[x][z] * ma2[z][y];

            }
            out[x][y] = sum;


            sum = 0;
        }
    }
}

// This function counts the number of times the number of times each for loop
// this function iterates where over the loop and counts the sum
int Cmultiply(double** ma1 , double** ma2 , double** output, int tr , int ab , int z)
{
    int count =0;


    double sum = 0;

    for(int x = 0 ; x < tr ; x++){


        for(int y = 0 ; y < z ; y++){


            for(int z = 0; z < ab ; z++){


                sum = sum + ma1[x][z] * ma2[z][y];

                count++;
            }
            output[x][y] = sum;

            sum = 0;
        }
    }
    return count;
}

// this function finds the inverse of the matrix, to find the inverse you must first
// simplify the matrix, to do this I used G Elimination
// inv this elimination we want
// 1 0 0 | values
// 0 1 0 | values
// 0 0 1 | values
// this means that it is simplified
// from here I can find the inverse, After that step, the left half of A is the identity
// matrix and the right half of A contains M−1, That is, A = I|M−1
// The algorithm is complete and the inverse of M has been found.

void inverse(double** ma , double** inv, int ne)
{
    double t = 0;


    for(int x = 0; x < ne ; x++){



        t = ma[x][x];


        for(int y = 0; y < ne ; y++){


            ma[x][y] /= t;


            inv[x][y] /= t;
        }
        for(int i = x+1; i < ne; i++){


            t = ma[i][x];
            for(int a = 0; a < ne ; a++){


                ma[i][a] -= ma[x][a]*t;


                inv[i][a] -= inv[x][a]*t;
            }
        }
    }
    for(int x = ne-1; x >= 0 ; x--){


        for(int i = x-1; i >= 0 ; i--){


            t = ma[i][x];


            for(int z = 0; z < ne ; z++){
                ma[i][z] -= ma[x][z]*t;


                inv[i][z] -= inv[x][z]*t;
            }
        }
    }
}

// this functions counts the number of times the elimination takes place
int cInverse(double** ma , double** inv, int ne)

{
    int count = 0;


    double t = 0;
    for(int x = 0; x < ne ; x++){
        t = ma[x][x];
        for(int y = 0; y < ne ; y++){


            ma[x][y] /= t;


            inv[x][y] /= t;

            count++;
        }
        for(int i = x+1; i < ne; i++){

            t = ma[i][x];

            for(int a = 0; a < ne ; a++){

                ma[i][a] -= ma[x][a]*t;

                inv[i][a] -= inv[x][a]*t;


                count++;
            }
        }
    }
    for(int x = ne-1; x >= 0 ; x--){


        for(int i = x-1; i >= 0 ; i--){


            t = ma[i][x];
            for(int z = 0; z < ne ; z++){

                ma[i][z] -= ma[x][z]*t;

                inv[i][z] -= inv[x][z]*t;
            }
        }
    }
    return count;
}



// this function creates a matrix
double** createM(int tr , int al)
{
    // allocates new memory
    double** ma = (double**)malloc(sizeof(double*)*tr);


    for(int i = 0; i < tr; i++)


        ma[i] = (double*)malloc(sizeof(double)*al);

    return ma;
}
// this function deletes a matrix
void delM(double** ma, int tr)
{
    for(int i = 0; i < tr; i++)


        free(ma[i]);

    free(ma);
}


int main(int argc , char** argv )
{
    if (argc != 3){


        printf("error\n");
        exit(0);
    }

    char tick[10] = {};
    char* ff1 = argv[1];


    char* ff2 = argv[2];


    FILE* fil1 = NULL;
    FILE* fil2 = NULL;


    FILE* tf = NULL;
    FILE* datf = NULL;
    int r, c;



    fil1 = fopen(ff1, "r");


    fil2 = fopen(ff2, "r");

    if (fil1 == NULL || fil2 == NULL) {



        printf("File not found");
        exit(0);
    }

    fscanf(fil1,"%5s\n",tick);




    if((strncmp(tick,"train",5) == 0)){
        tf= fil1;


        datf = fil2;
    }else{
        tf= fil2;


        datf = fil1;
    }

    fscanf(tf,"%d\n",&c);


    fscanf(tf,"%d\n",&r);
    c++;

    double** tp = createM(r, c);

    for (int i = 0; i < r; i++) {


        for (int j = 0; j < c; j++) {


            fscanf(tf,"%lf ",&tp[i][j]);
        }
        fscanf(tf,"\n");
    }

    double** X = createM(r , c);

    for(int i = 0; i < r ; i++){


        for(int j = 0; j < c; j++){
            if(j==0){


                X[i][j] = 1;
            }
            else{


                X[i][j] = tp[i][j-1];
            }
        }
    }

    double** Y = createM(r , 1);

    for (int i = 0; i < r; i++) {


        Y[i][0] = tp[i][c-1];
    }

    double** Z = createM(c , r);

    transpose(X,Z,r,c);



    double** product = createM(c, c);

    multiply(Z, X, product, c, r, c);

    double** X_inv = createM(c , c);


    for(int i = 0 ; i < c ; i++){

        for(int j = 0 ; j < c ; j++){

            if(i==j){

                X_inv[i][j] = 1;
            }
            else{
                X_inv[i][j] = 0;
            }
        }
    }

    inverse(product, X_inv, c);


    double** p2 = createM(c , r);


    multiply(X_inv, Z, p2, c, c, r);


    double** p3 = createM(c, 1);


    multiply(p2,Y, p3, c , r, 1);

    fscanf(datf,"%s\n", tick);


    if (strncmp(tick,"data",4) != 0) {


        printf("error\n");

        exit(0);

    }

    int row2, col2;

    fscanf(datf,"%d\n",&col2);


    fscanf(datf,"%d\n",&row2);
    col2++;

    double** inv = createM(row2, col2);

    for(int i = 0; i < row2; i++){


        inv[i][0] = 1;
    }

    for(int i = 0; i < row2; i++){


        for(int j = 1; j < col2 ; j++){


            fscanf(datf,"%lf ",&inv[i][j]);
        }
        fscanf(datf,"\n");
    }

    double** fina = createM(row2,1);



    multiply(inv, p3, fina, row2, col2, 1);

    for (int i = 0; i < row2; i++) {

        printf("%.0f\n", fina[i][0]);
    }

    delM(tp, r);


    delM(X,r);

    delM(Y, r);

    delM(Z, c);

    delM(product, c);

    delM(X_inv, c);

    delM(p2, c);

    delM(p3, c);


    delM(inv, row2);



    delM(fina, row2);

    return EXIT_SUCCESS;
}