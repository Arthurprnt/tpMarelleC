#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define TAILLE 7

// Constantes et variables

const int V = 0;  // Résultat à définir
const int G = 1;  // On est a gagné
const int N = 2;  // La partie est nulle
const int P = 3; // On a perdu

int mar1[TAILLE] = {2,-1,4,3,0,7,-8}; // Marelle 1
int rep1[TAILLE] = {V,V,V,V,V,V,V};   // Espace de stockage de la réponse 1
int sol1[TAILLE] = {P,P,P,P,N,G,P};   // Solution 1 attendue

int mar2[TAILLE] = {-1,2,-1,3,1,-1,1}; // Marelle 2
int rep2[TAILLE] = {V,V,V,V,V,V,V}; // Espace de stockage de la réponse 2
int sol2[TAILLE] = {P,G,G,G,N,N,G}; // Solution 2 attendue

int mar3[TAILLE] = {10,10,4,-1,10,10,-3}; // Marelle 3
int rep3[TAILLE] = {V,V,V,V,V,V,V}; // Espace de stockage de la réponse 3
int sol3[TAILLE] = {G,G,N,N,G,G,N}; // Solution 3 attendue

int mar4[TAILLE] = {-1,-1,-1,-1,-1,-1,-1}; // Marelle 4
int rep4[TAILLE] = {V,V,V,V,V,V,V}; // Espace de stockage de la réponse 4
int sol4[TAILLE] = {P,P,P,P,P,P,P}; // Solution 4 attendue

int mar5[TAILLE] = {4,-1,-1,-1,-1,-1,-6}; // Marelle 5
int rep5[TAILLE] = {V,V,V,V,V,V,V}; // Espace de stockage de la réponse 5
int sol5[TAILLE] = {N,N,N,N,N,N,N}; // Solution 5 attendue

// Fonctions

void affiche(int tab[], int n) {
    // Affiche une liste d'entiers

    printf("| ");
    for(int i=0; i<n; i+=1) {
        printf("%d | ", tab[i]);
    }
    printf("\n");

}

void marelle(int tab[], int n, int result[]) {

    for (int i=0; i<n; i+=1) {

        int indice = i; // On créer une variable pour ne pas modifier l'indice de la boucle for
        int compteur = 0; 

        while (indice >= 0 && // Vérifie si l'indice existe
               indice < n &&
               tab[indice] != 0 && // Si la valeur vaut 0, on bouclera
               compteur <= n) { // Vérifie que le nombre de déplacements maximal n'est pas dépassé

            indice += tab[indice];
            compteur += 1;
    
        }

        if (indice >= 0 && indice < n) { // L'indice existe donc nous avions dépassé le nombre de déplacements maximal
            result[i] = N;
        } else if (indice >= n) {        // On est sorti par la droite
            result[i] = G;
        } else {                         // On est sorti par la gauche
            result[i] = P;
        }

    }

}

bool verif(int tab1[], int tab2[], int n) {
    // Vérifie si une réponse correspond bien à une solution
    for(int i=0; i<n; i+=1) {
        if(tab1[i] != tab2[i]) {
            return false;
        }
    }
    return true;
}

// Programme principal

int main(){
    printf("Défi marelle !\n");

    marelle(mar1, TAILLE, rep1);
    affiche(rep1, TAILLE);
    assert(verif(rep1, sol1, TAILLE));

    marelle(mar2, TAILLE, rep2);
    affiche(rep2, TAILLE);
    assert(verif(rep2, sol2, TAILLE));

    marelle(mar3, TAILLE, rep3);
    affiche(rep3, TAILLE);
    assert(verif(rep3, sol3, TAILLE));

    marelle(mar4, TAILLE, rep4);
    affiche(rep4, TAILLE);
    assert(verif(rep4, sol4, TAILLE));

    marelle(mar5, TAILLE, rep5);
    affiche(rep5, TAILLE);
    assert(verif(rep5, sol5, TAILLE));

    return 0;
}
