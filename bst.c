#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Tnode{
    int info;
    struct Tnode* r;
    struct Tnode* lf;
} ;

struct Tnode* root;

void insert(int ob, struct Tnode* tr){
    if(tr == NULL){
        tr = malloc(sizeof(struct Tnode));
        tr->info = ob;
        tr->r = NULL;
        tr->lf = NULL;
        root = tr;
        printf("inserted\n");
        return;

    }

    else if(ob > tr->info){
        //go r subtree
        if(tr->r == NULL){
            struct Tnode *tmp = malloc(sizeof(struct Tnode));
            tmp->info = ob;
            tr->r = tmp;
            tmp->r = NULL;
            tmp->lf = NULL;
            printf("inserted\n");
            return;
        }
        insert(ob, tr->r);

    }
    else if(ob < tr->info){
        //go to lf subtree
        if(tr->lf == NULL){
            struct Tnode *tmp = malloc(sizeof(struct Tnode));
            tmp->info = ob;
            tr->lf = tmp;
            tmp->r = NULL;
            tmp->lf = NULL;
            printf("inserted\n");
            return;
        }
        insert(ob, tr->lf);

    }
    else if(ob == tr->info){
        printf("not inserted\n");
        return;
    }
    else{
        printf("insert error %d %d\n", tr->info, ob);
    }
    //
    return;

}

void search(int ob, struct Tnode* tr){
    if(tr == NULL){
        printf("absent\n");
        return;

    }
    else if(ob == tr->info){
        printf("present\n");
        return;
    }

    else if(ob > tr->info){
        //go r subtree
        if(tr->r == NULL){
            printf("absent\n");
            return;
        }
        search(ob, tr->r);

    }
    else if(ob < tr->info){
        //go to lf subtree
        if(tr->lf == NULL){
            printf("absent\n");
            return;
        }
        search(ob, tr->lf);

    }
}

int maxLeft(struct Tnode* lp, struct Tnode* node1){
    if(lp->r == NULL && lp->lf == NULL && lp == node1->lf){
        int i = lp->info;
        free(lp);
        node1->lf = NULL;
        return i;
    }
    while(lp->r != NULL){
        node1 = lp;
        lp = lp->r;

    }
    int i = lp->info;
    if(lp->lf != NULL){
        node1->r = lp->lf;
        free(lp);
    }
    else{
        free(lp);
        node1->r = NULL;
    }

    return i;
}

void delete(int ob, struct Tnode* tr){
    //actual delete method 1
    if(tr == NULL){
        printf("absent\n");
        return;

    }
    if(root->info == ob){
        if(root->r == NULL && root->lf == NULL){
            free(tr);
            root = NULL;
            printf("deleted\n");
            return;
        }
        else if(root->r != NULL && root->lf == NULL){
            struct Tnode* temp = root->r;
            free(root);
            root = temp;
            printf("deleted\n");
            return;
        }
        else if(root->lf != NULL && root->r == NULL){
            struct Tnode* temp = root->lf;
            free(root);
            root = temp;
            printf("deleted\n");
            return;
        }
        else if(root->r != NULL && root->lf != NULL){
            root->info = maxLeft(root->lf, root);
            printf("deleted\n");
            // printf("%d", root->info);
            return;
        }
        // free(tr);
        // root = NULL;
        // return;
    }

    else if(ob > tr->info){
        if(tr->r == NULL){
            printf("absent\n");
            return;
        }
        else{
            if(tr->r->info == ob){
                if(tr->r->r == NULL && tr->r->lf == NULL){
                    free(tr->r);
                    tr->r = NULL;
                    printf("deleted\n");

                }
                else if(tr->r->lf != NULL && tr->r->r == NULL){
                    struct Tnode* temp = tr->r->lf;
                    free(tr->r);
                    tr->r = temp;
                    printf("deleted\n");


                }
                else if(tr->r->r != NULL && tr->r->lf == NULL){
                    struct Tnode* temp = tr->r->r;
                    free(tr->r);
                    tr->r = temp;
                    printf("deleted\n");
                }
                else if(tr->r->r != NULL && tr->r->lf != NULL){
                    tr->r->info = maxLeft(tr->r->lf, tr->r);
                    //tr->r->info = maxLeft(tr->r->lf, tr->r);
                    printf("deleted\n");
                    return;
                }
            }
            else{
                delete(ob, tr->r);
            }

        }

    }

    else if(ob < tr->info){
        if(tr->lf == NULL){
            printf("absent\n");
            return;
        }
        else{
            if(tr->lf->info == ob){
                if(tr->lf->lf == NULL && tr->lf->r == NULL){
                    free(tr->lf);
                    tr->lf = NULL;
                    printf("deleted\n");

                }
                else if(tr->lf->r != NULL && tr->lf->lf == NULL){
                    struct Tnode* temp = tr->lf->r;
                    free(tr->lf);
                    tr->lf = temp;
                    printf("deleted\n");


                }
                else if(tr->lf->lf != NULL && tr->lf->r == NULL){
                    struct Tnode* temp = tr->lf->lf;
                    free(tr->lf);
                    tr->lf = temp;
                    printf("deleted\n");
                }
                else if(tr->lf->lf != NULL && tr->lf->r != NULL){
                    tr->lf->info = maxLeft(tr->lf->lf, tr->lf);
                    //tr->lf->info = maxLeft(tr->lf->lf, tr->lf);
                    printf("deleted\n");
                    return;
                }
            }
            else{
                delete(ob, tr->lf);
            }

        }

    }
    return;
}

void printNodes(struct Tnode* tr){
    if(tr != NULL){
        printf("(");
        if(tr->lf != NULL){
            printNodes(tr->lf);
        }
        // printf("(");
        // printNodes(tr->lf);
        printf("%d", tr->info);
        if(tr->r != NULL){
            printNodes(tr->r);
        }

        printf(")");
    }

    return;
}

void freeTree(struct Tnode* tr){
    if(tr == NULL){
        return;
    }
    freeTree(tr->lf);
    freeTree(tr->r);
    free(tr);
    return;
}

int main(int argc, char **argv){

    int info;
    char c;
    while(scanf("%c", &c) != -1){

        if(c == 'i'){
            //printf("A\n");
            scanf("%d", &info);
            insert(info, root);
            //printNodes(root);

        }
        else if(c == 'd'){
            //printf("B\n");
            scanf("%d", &info);
            delete(info, root);
            //printNodes(root);
        }

        else if(c == 's'){
            //printf("C\n");
            scanf("%d", &info);
            search(info, root);
            //printNodes(root);

        }

        else if(c == 'p'){
            // printf("D\n");
            // if(root == NULL){
            // printf("ROOT IS NULL");
            // }
            printNodes(root);
            printf("\n");
        }

    }

    freeTree(root);
    return EXIT_SUCCESS;

}