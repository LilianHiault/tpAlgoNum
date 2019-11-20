#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "usuelles.h"
#include "tab2d.h"
#include "genmat.h"


// Fonctions

// Gauss-Seidel

void gaussSeidel(double**, double*, int);


// Main

int main()
{
  int taille = 0; // Taille de la matrice
  printf("Taille de la matrice : ");
  scanf("%d", &taille);
  int i; // Compteur

  // Crée une matrice vide de taille taille
  // i lignes j colonnes
  double** tab = (double**) malloc(taille * sizeof(double*));
  for(i = 0; i < taille; i++)
  {
    tab[i]  = (double*) malloc(taille * sizeof(double));
  }

  double* systeme = (double*) malloc(taille * sizeof(double));

  afficheTab2D(tab,taille);
  afficheSys(systeme, taille);

  free(tab);
  free(systeme);
  return 0;
}


// Fonctions

// Gauss-Seidel

void gaussSeidel(double** mat, double* sys, int taille){
  int i = 0;
  int j = 0;
  double* resultat = malloc(taille*sizeof(double)); // choix initial de solution
  int sigma = 0;
  while(1){
    // Jusqu'à la convergence
    for(i = 0; i < taille; i++){
      sigma = 0;
      for(j = 0; j < taille; j++){
        if(j != i){
          sigma = sigma + mat[i][j] * resultat[j]; //
        }
      }
      resultat = 1/tab[i][i](sys[i] - sigma);
      // Convergence atteinte ?
    }
  }
