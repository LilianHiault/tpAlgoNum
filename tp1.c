#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Fonctions

// Fonctions usuelles

int min(int a, int b)
{
  int valMin = a;
  if (b < a)
  {
    valMin = b;
  }
  return valMin;
}

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

// Générateurs de matrices

void bord(double** tab, int n)
// Crée une matrice Bord
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(i == j)
      {
        tab[i][j] = 1;
      }
      else if((i == 0) || (j == 0) || (i == n - 1) || (j == n - 1))
      {
        tab[i][j] = pow(2, (i+1) - (j + 1));
      }
      else
      {
        tab[i][j] = 0;
      }
    }
  }
}

void dingDong(double** tab, int n)
// Crée une matrice Ding Dong
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      tab[i][j] = 1 / (2 * (n - (i + 1) - (j + 1) + 1.5));
    }
  }
}

void franc(double** tab, int n)
// Crée une matrice Franc
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(i >= j + 2)
      {
        tab[i][j] = 0;
      }
      else
      {
        tab[i][j] = min((i + 1), (j + 1));
      }
    }
  }
}

void hilbert1(double** tab, int n)
// Crée une matrice Hilbert
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      tab[i][j] = 1 / (i + j + 1.0);
    }
  }
}

void hilbert2(double** tab, int n)
// Crée une matrice Hilbert
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      tab[i][j] = 1 / (i + j + 3.0);
    }
  }
}

void kms(double** tab, int n);

void lehmer(double** tab, int n);

void lotkin(double** tab, int n);

void moler(double** tab, int n);


// Fonctions Gauss

void remplirSys(double* tab,int taille)
// Remplit une matrice
{
  int i;
  double valeur = 0;
  // printf("i%d",i);
  for(i = 0; i <taille; i++)
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
  printf("\nSysteme\n");
  for(j = 0; j < taille; j++)
  {
    printf("%lf ", tab[j]);
  }
  printf("\n");
}

void echangeLigne(double** tab, int taille, int nouv, int anc)
{
  //    double* liEx = (double*) malloc(taille * sizeof(double));
  //liEx = tab[nouv];
  //tab[nouv] = tab[anc];
  //tab[anc] = liEx;
  //free(liEx);

  double echange = 0;
  int i;
  for(i=0; i<taille; i++)
  {
    echange = tab[nouv][i];
    tab[nouv][i] = tab[anc][i];
    tab[anc][i] = echange;
  }
}

void diviseLigne(double* tab, int taille, double divi)
{
  int i = 0;
  for(i=0;i<taille;i++)
  {
    tab[i]=tab[i]/divi;
  }
}

void soustractionLigne(double** tab, int taille, int pivot,int sous, int col)
{
  int i;
  double divi = tab[sous][col] / tab[pivot][col];
  // printf("divi %lf", divi);
  for(i=col;i<taille;i++)
  {
    tab[sous][i] = tab[sous][i] - ( divi * tab[pivot][i] );
  }
}

void gauss(double** tab, int taille)
{
  int i, j,k, resteI;
  i = 0;
  j = 0;
  k = 0;
  int coord[2] = {0, 0};
  while(j < taille) // Changer de colonne
  {
    coord[0] = 0;
    coord[1] = 0;
    i = k;
    resteI = 0;
    // printf("k = %d et i = %d\n",k,i);


    // afficheTab2D(tab,taille);
    while(tab[i][j] == 0  && i < taille-1) // Changer de ligne dans une colonne
    {
      i++;
    }


    if(tab[i][j] != 0)
    {


      diviseLigne(tab[i],taille,tab[i][j]);
      resteI = i+1;

      while(resteI<taille) // diviser chaque ligne
      {

        soustractionLigne(tab,taille,i,resteI,j);
        resteI++;
      }
      //printf("\nici\n");

      //	  printf("Pivot = %lf colonne %d\n",tab[i][j], j+1);

      if (i != k) // met le pivot en haut mais pas trop pour echelonner
      {
        //  printf("\nici\n");
        echangeLigne(tab,taille,i,k);
      }



      k++;
    }

    else
    {
      //	  printf("Pas de pivot colonne %d\n", j+1);
    }
    j++;
  }
}


// Main

int main()
{
  // Taille de la matrice
  int taille = 0;
  printf("Taille de la matrice : ");
  scanf("%d", &taille);
  int i; // Compteurs

  // Crée une matrice vide de taille taille
  // i ligne j colonne
  double** tab = (double**) malloc(taille * sizeof(double*));
  for(i = 0; i < taille; i++)
  {
    tab[i]  = (double*) malloc(taille * sizeof(double));
  }

  //   double* systeme = (double*) malloc(taille * sizeof(double));
  // afficheTab2D(tab, taille);

  hilbert2(tab, taille);

  // Remplir matrice
  //remplirTab(tab, taille);
  //remplirSys(systeme, taille);

  // Affiche la matrice
  afficheTab2D(tab, taille);

  // Résolution par la méthode de Gauss
  gauss(tab,taille); //Echelonnage

  // soustractionLigne(tab,taille,0,1,1);
  // echangeLigne(tab,taille,0,1);

  afficheTab2D(tab,taille);
  free(tab);
  //free(systeme);
  return 0;
}