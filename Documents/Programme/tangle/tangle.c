#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 1000

typedef struct Node{
    int fid;
    struct Node* pere1;
    struct Node* pere2;
    struct Node* fils1;
    struct Node* fils2;
    int height;
}Node;

typedef struct Tangle{
    Node* racine;
}Tangle;

Node* creer_noeud(Node* pere1, Node* pere2, int fid) {
    Node* mynode = malloc(sizeof(Node));
    mynode->pere1=pere1;
    if (mynode->pere1->fils1==NULL) mynode->pere1->fils1=mynode;
    else mynode->pere1->fils2=mynode;
    mynode->pere2=pere2;
    if (mynode->pere2->fils1==NULL) mynode->pere2->fils1=mynode;
    else mynode->pere2->fils2=mynode;
    mynode->fid=fid;
    mynode->fils1=NULL;
    mynode->fils2=NULL;
    mynode->height=0; //hauteur;
    return mynode;
}

Tangle* creer_tangle(int fid) {

    Node* myracine=creer_noeud(NULL,NULL,fid);
    Tangle* myTangle=malloc(sizeof(Tangle));
    myTangle->racine=myracine;

    return myTangle;
}

void up_fid(Node* mynode) {
    mynode->fid++;
}

void reset_fid(Node* mynode) {
    mynode->fid=0;
}

int add_node(Tangle* mytangle,Node* mynode) {

    Node* nodetmp1=mytangle->racine; // on initialise un noeud qui va parcourir "aléatoirement" le tangle pour trouver le pere 1
    Node* nodetmp2=mytangle->racine; // un deuxième noeud va parcourir le tangle pour trouver le pere 2

    while(nodetmp1) { // Tant que notre noeud existe on continue de descendre dans le tangle

        srand(time(NULL));
        int random=rand() % MAX; // On initialise aléatoirement un entier qui va nous permettre de décider dans quel noeud descendre et à quel noeud notre nouveau noeud va se lier

        if ((nodetmp1->fils1==NULL)&&(nodetmp1->fils2==NULL)) { // Si notre noeud n'a aucun fils
            
            if (random%2==0) { // "aléatoirement" on rattache notre nouveau noeud à ce noeud
                nodetmp1->fils1=mynode; // le fils1 de notre noeud temporaire va devenir le noeud qu'on veut ajouter
                mynode->pere1=nodetmp1; // le pere de notre noeud va devenir notre noeud temporaire
                return -1;
            }

            else {
                nodetmp1->fils2=mynode;
                mynode->pere1=nodetmp1;
                return -1;
            }
        }

        if (nodetmp1->fils1==NULL) { // Si on a que le fils1 de NULL 

            nodetmp1->fils1=mynode; // On va faire la même chose qu'au dessus mais directement avec le fils1
            mynode->pere1=nodetmp1;

            return -1;
        } 
        
        if (nodetmp1->fils2==NULL) { // Si on a que le fils2 de NULL 

            nodetmp1->fils2=mynode; // Pareil avec le fils2
            mynode->pere1=nodetmp1;
            
            return -1;
        }

        else // Si les 2 fils sont différents de NULL

            if (random%2==0) nodetmp1=nodetmp1->fils1; // "aléatoirement" on descend dans le tangle par le fils1

            else nodetmp1=nodetmp1->fils2; // "aléatoirement" on descend dans le tangle par le fils1
    }

    while(nodetmp2) { // On recommence ce processus pour trouver "aleatoirement" le pere2 de notre nouveau noeud. Tant que notre noeud existe on continue de descendre dans le tangle

        srand(time(NULL));
        int random=rand() % MAX; // On initialise aléatoirement un entier qui va nous permettre de décider dans quel noeud descendre et à quel noeud notre nouveau noeud va se lier

        if ((nodetmp2->fils1==NULL)&&(nodetmp2->fils2==NULL)) { // Si notre noeud n'a aucun fils
            
            if (random%2==0) { // "aléatoirement" on rattache notre nouveau noeud à ce noeud
                nodetmp2->fils1=mynode; // le fils1 de notre noeud temporaire va devenir le noeud qu'on veut ajouter
                mynode->pere1=nodetmp2; // le pere de notre noeud va devenir notre noeud temporaire
                return -1;
            }

            else {
                nodetmp2->fils2=mynode;
                mynode->pere1=nodetmp2;
                return -1;
            }
        }

        if (nodetmp2->fils1==NULL) { // Si on a que le fils1 de NULL 

            nodetmp2->fils1=mynode; // On va faire la même chose qu'au dessus mais directement avec le fils1
            mynode->pere1=nodetmp2;

            return -1;
        } 
        
        if (nodetmp2->fils2==NULL) { // Si on a que le fils2 de NULL 

            nodetmp2->fils2=mynode; // Pareil avec le fils2
            mynode->pere1=nodetmp2;
            
            return -1;
        }

        else // Si les 2 fils sont différents de NULL

            if (random%2==0) nodetmp2=nodetmp2->fils1; // "aléatoirement" on descend dans le tangle par le fils1

            else nodetmp2=nodetmp2->fils2; // "aléatoirement" on descend dans le tangle par le fils1
        }

    return -1;
}

int main() {
    return 0;
}