#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "usuelles.h"
#include "tab2d.h"
#include "genmat.h"


// reste à faire Tx+C et itérer

// Fonctions

//TP1

// Fonctions Gauss
void remplirSys(double*, int);

void afficheSys(double*, int);

void echangeLigne(double**, int, int, int);

void diviseLigne(double*, int, double);

void soustractionLigne(double**, int, int,int, int);

void gauss(double**, int, double*);

// Cholesky

//TP2

//Jacobi
void matDR(double** tab, double** diag, double** matR , int taille)
{
  int i,j;
  for(i=0; i< taille ; i++)
    {
      for(j=0; j< taille; j++)
	{
	  if(i==j)
	    {
	      diag[i][j] = 1/tab[i][j];
	      matR[i][j] = 0;
	    }
	  else
	    {
	      diag[i][j] = 0;
	      matR[i][j] = tab[i][j];
	    }
	}
    }
  printf("\nD = ");
  afficheTab2D(diag,taille);
  printf("\nR = ");
  afficheTab2D(matR,taille);
}

double** prodMat(double** matG,double** matD, int taille)
{

  double** matRes = (double**) malloc(taille * sizeof(double*));
  int i,j,k;
  for(i=0; i<taille ;i++)
    {
    matRes[i]  = (double*) malloc(taille * sizeof(double));
      for(j=0 ; j<taille ; j++)
	{
	  for(k=0; k<taille ; k++)
	    {
	      matRes[i][j] = matRes[i][j] + matG[i][k] * matD[k][j];
	    }
	}
    }
  printf("\nT = ");
  afficheTab2D(matRes,taille);
  return matRes;
}
double* prodSys(double** matG,double* sysB, int taille)
{

  double* matRes = (double*) malloc(taille * sizeof(double));
  int i,k;
  for(i=0; i<taille ;i++)
    {
	  for(k=0; k<taille ; k++)
	    {
	      matRes[i] = matRes[i] + matG[i][k] * sysB[k];
	      // printf("matRes[%d] = %lf",i,matRes[i]);
	    }
    }
  printf("\nC = ");
  afficheSys(matRes,taille);
  return matRes;
}

void remplirX0(double* x,int taille)
{
  int i = 0;
  for(i=0; i<taille ; i++)
    {
      x[i] = 1;
    }
  printf("\nX = \n");
  afficheSys(x,taille);
}


void sommeSys(double* matA, double* matB, int taille)
{
  int i =0;
  for(i=0; i<taille; i++)
    {
      matA[i] = matA[i]+matB[i];
    }
}

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
  double** diag = (double**) malloc(taille * sizeof(double*));
  double** matR = (double**) malloc(taille * sizeof(double*));
  for(i = 0; i < taille; i++)
  {
    tab[i]  = (double*) malloc(taille * sizeof(double));
    diag[i]  = (double*) malloc(taille * sizeof(double));
    matR[i]  = (double*) malloc(taille * sizeof(double));
  }

  double* systeme = (double*) malloc(taille * sizeof(double));
  double* resouSys = (double*) malloc(taille * sizeof(double));
  resouSys = remplirX0(resouSys,taille);





  // Remplir matrice
  remplirTab(tab, taille);
  matDR(tab,diag,matR,taille);
  remplirSys(systeme, taille);

  // Affiche la matrice
  afficheTab2D(tab, taille);
  double** matT =  prodMat(diag,matR,taille);
  //afficheSys(systeme, taille);
  resouSys= prodSys(diag,systeme,taille);

  // Résolution par la méthode de Gauss
  // gauss(tab,taille, systeme); //Echelonnage

  // soustractionLigne(tab,taille,0,1,1);
  // echangeLigne(tab,taille,0,1);

  afficheTab2D(tab,taille);
  afficheSys(systeme, taille);
  free(tab);
  free(systeme);
  free(resouSys);
  free(diag);
  free(matR);
  free(matT);
  return 0;
}


// Fonctions

// Fonctions Gauss

void remplirSys(double* tab,int taille)
// Remplit une matrice
{
  int i;
  double valeur = 0;
  // printf("i%d",i);
  for(i = 0; i < taille; i++)
  {
    //printf("j%d",j);
    printf("inconnue %d =  : ", i + 1);
    scanf("%lf", &valeur);
    tab[i] = valeur;
  }
}

void afficheSys(double* tab, int taille)
{
  int j;
  printf("\nSystème\n");
  for(j = 0; j < taille; j++)
  {
    printf("%lf ", tab[j]);
  }
  printf("\n");
}

void echangeLigne(double** tab, int taille, int nouv, int anc)
{
  //double* liEx = (double*) malloc(taille * sizeof(double));
  //liEx = tab[nouv];
  //tab[nouv] = tab[anc];
  //tab[anc] = liEx;
  //free(liEx);

  double echange = 0;
  int i;
  for(i = 0; i < taille; i++)
  {
    echange = tab[nouv][i];
    tab[nouv][i] = tab[anc][i];
    tab[anc][i] = echange;
  }
}

void diviseLigne(double* tab, int taille, double divi)
{
  int i = 0;
  for(i = 0; i < taille; i++)
  {
    tab[i]=tab[i] / divi;
  }
}

void soustractionLigne(double** tab, int taille, int pivot,int sous, int col)
{
  int i;
  double divi = tab[sous][col] / tab[pivot][col];
  // printf("divi %lf", divi);
  for(i = col; i < taille; i++)
  {
    tab[sous][i] = tab[sous][i] - (divi * tab[pivot][i]);
  }
}

void gauss(double** tab, int taille,double* sys)
{
  int i, j, k, resteI;
  i = 0;
  j = 0;
  k = 0;
  double pass = 0;

  // Trigonalisation

  while(j < taille) // Changer de colonne
  {
    i = k;
    resteI = 0;
    // printf("k = %d et i = %d\n", k, i);
    // afficheTab2D(tab,taille);
    while(tab[i][j] == 0  && i < taille - 1) // Changer de ligne dans une colonne
    {
      i++;
    }
    if(tab[i][j] != 0)
    {

      sys[i]=sys[i]/tab[i][j];
      diviseLigne(tab[i],taille,tab[i][j]);
      resteI = i + 1;

      while(resteI < taille) // diviser chaque ligne
      {
        sys[resteI] =sys[resteI]- (tab[resteI][j]/tab[i][j]) * sys[i];
        soustractionLigne(tab, taille, i, resteI, j);
        resteI++;
      }
      //printf("\nici\n");
      //	  printf("Pivot = %lf colonne %d\n",tab[i][j], j+1);

      if (i != k) // met le pivot en haut mais pas trop pour echelonner
      {
        //  printf("\nici\n");
        pass = sys[k];
        sys[k] = sys[i];
        sys[i] = pass ;
        echangeLigne(tab, taille, i, k);
      }
      k++;
    }
    else
    {
      //printf("Pas de pivot colonne %d\n", j+1);
    }
    j++;
  }

  // Diagonalisation

  i = taille-1;
  j = taille-1;
  k = taille-1;

  while(j > 0) // Changer de colonne
  {
    i = k;
    resteI = 0;
    //printf("k = %d et i = %d\n",k,i);
    while(tab[i][j] == 0  && i > 1) // Changer de ligne dans une colonne
    {
      i--;
    }
    if(tab[i][j] != 0)
    {
      sys[i] = sys[i] / tab[i][j];
      diviseLigne(tab[i], taille, tab[i][j]);
      resteI = i - 1;

      while(resteI > 0) // diviser chaque ligne
      {
        sys[resteI] = sys[resteI] - (tab[resteI][j] / tab[i][j]) * sys[i];
        soustractionLigne(tab, taille, i, resteI, j);
        resteI++;
      }
      //printf("\nici\n");
      //printf("Pivot = %lf colonne %d\n",tab[i][j], j + 1);

      if (i != k) // met le pivot en haut mais pas trop pour echelonner
      {
        //printf("\nici\n");
        pass = sys[k];
        sys[k] = sys[i];
        sys[i] = pass ;
        echangeLigne(tab, taille, i, k);
      }
      k--;
    }
    else
    {
    }
    j--;
  }
}
