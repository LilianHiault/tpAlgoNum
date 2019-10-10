#include <stdio.h>
#include <stdlib.h>


// Fonctions

void remplirTab(double** tab, int taille)
// Remplit une matrice
{
  int i,j;
  double valeur = 0;
  for(i = 0; i < taille; i++)
    {
      // printf("i%d",i);
      for(j = 0; j < taille; j++)
	{
	  //printf("j%d",j);
	  printf("Valeur de [%d, %d] : ", i + 1, j + 1);
	  scanf("%lf", &valeur);
	  tab[i][j] = valeur;
	}
    }
}


void afficheTab2D(double ** tab, int taille)
{
  int i,j;
  for(i = 0; i < taille; i++)
    {
      printf("\n");
      for(j = 0; j < taille; j++)
	{
	  printf("%lf ", tab[i][j]);
	}
      printf("\n");
    }
  printf("\n");
}		    


void gauss(double** tab, int taille)
{  
  int i, j,k;
  i = 0;
  j = 0;
  k = 0;
  int coord[2] = {0, 0};
  
  while(j < taille) // Changer de colonne
    {
      coord[0] = 0;
      coord[1] = 0;
      
      while(tab[i][j] == 0  && i < taille-1) // Changer de ligne dans une colonne
	{
	  i++;
	}
      if(tab[i][j] != 0)
	{
	  printf("Pivot = %lf colonne %d\n",tab[i][j], j+1);
	  	}
      
      else
	{
	  printf("Pas de pivot colonne %d\n", j+1);
	}
      j++; 
    }
}





// Main

int main()
{
  // Taille de la matrice
  int taille = 0;
  printf("Taille : ");
  scanf("%d", &taille);
  int i; // Compteurs
  
  // Crée une matrice vide de taille taille
  double** tab = (double**) malloc(taille * sizeof(double*));
  for(i = 0; i < taille; i++)
    {
      tab[i]  = (double*) malloc(taille * sizeof(double));
    }

  // afficheTab2D(tab, taille);

  // Remplir matrice
  remplirTab(tab, taille);

  // Affiche la matrice
  afficheTab2D(tab, taille);

  // Calcul
  gauss(tab,taille);

  free(tab);
  return 0;
}
