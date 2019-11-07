#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// Fonctions

// Fonctions usuelles
int min(int, int);

void remplirTab(double**, int);

void afficheTab2D(double ** , int );

// Générateurs de matrices
void bord(double**, int);

void dingDong(double**, int);

void franc(double**, int);

void hilbert1(double**, int);

void hilbert2(double**, int);

void kms(double**, int, double);

void lehmer(double**, int);

void lotkin(double**, int);

void moler(double**, int);

void creuse(double**, int);

// Fonctions Gauss
void remplirSys(double*, int);

void afficheSys(double*, int);

void echangeLigne(double**, int, int, int);

void diviseLigne(double*, int, double);

void soustractionLigne(double**, int, int, int, int);

void gauss(double**, int, double*);

void renverseTab2D(double** , int);

void renverseSys(double*, int);

int verifSol(double**, double*, int);

void cholesky(double**,double**, int, double*);
 

// Main

int main()
{
  srand(time(NULL)); // Initialisation de valeurs aléatoires

  int taille = 0; // Taille de la matrice
  printf("Taille de la matrice : ");
  scanf("%d", &taille);
  int i; // Compteur

  printf("Taill/2 = %d",taille/2);

  // Crée une matrice vide de taille taille
  // i lignes j colonnes
  double** tab = (double**) malloc(taille * sizeof(double*));
  double** matR =(double**) malloc(taille * sizeof(double*)); 
  for(i = 0; i < taille; i++)
  {
    tab[i]  = (double*) malloc(taille * sizeof(double));
    matR[i]  = (double*) malloc(taille * sizeof(double));
  }

  int verif =0;

  double* systeme = (double*) malloc(taille * sizeof(double));
  double* resouSys = (double*) malloc(taille * sizeof(double));

  // creuse(tab, taille);

  afficheTab2D(tab, taille);

  // Remplir matrice
  remplirTab(tab, taille);
  //remplirSys(systeme, taille);
  cholesky(tab,matR,taille,systeme);
  //afficheSys(systeme, taille);

  //afficheTab2D(tab, taille);

  // gauss(tab,taille, systeme);
  //printf("\nRenverse\n");
  //renverseTab2D(tab,taille);
  //renverseSys(systeme,taille);

  // Affiche la matrice
  //afficheTab2D(tab, taille);
  // afficheSys(systeme, taille);


  // Résolution par la méthode de Gauss
  //gauss(tab,taille, systeme); //Echelonnage
  //printf("\n Re-Renverse\n");
  //renverseTab2D(tab,taille);
  //renverseSys(systeme,taille);

  //afficheSys(systeme, taille);
  //verif = verifSol(tab, systeme, taille);
  //printf("\n Verification = %d",verif);
  if(verif==-1)
  {
    printf("\n Il n'y a pas de solution");
  }
  else
  {
    if(verif==0)
    {
      //printf("\nLa solution est :");
    }
    else
    {
      //printf("\n Il y a plusieurs solutions : ");
    }
    // soustractionLigne(tab,taille,0,1,1);
    // echangeLigne(tab,taille,0,1);
    //printf("\nfinal");
    //afficheTab2D(tab,taille);
    //afficheSys(systeme, taille);
  }

  for(i = 0; i< taille; i++){
    free(tab[i]);
    free(matR[i]);
  }
  
  free(tab);
  free(systeme);
  free(resouSys);
  return 0;
}

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

void kms(double** tab, int n, double p)
// Crée une matrice kms
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      tab[i][j] = pow(p,(abs(i-j)));
    }
  }
}

void lehmer(double** tab, int n)
// Crée une matrice Lehmer
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(i <= j)
      {
        tab[i][j] = (i + 1) / (j + 1);
      }
      else
      {
        tab[i][j] = (j + 1) / (i + 1);
      }
    }
  }
}

void lotkin(double** tab, int n)
// Crée une matrice Lotkin
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(i == 0)
      {
        tab[0][j] = 1;
      }
      else
      {
        tab[i][j] = 1 / ((i + 1) + (j + 1) - 1);
      }
    }
  }
}

void moler(double** tab, int n)
// Crée une matrice Moler
{
  int i, j; // i lignes et j colonnes
  // n est la taille
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(i == j)
      {
        tab[i][j] = i + 1;
      }
      else
      {
        tab[i][j] = min((i + 1), (j + 1)) - 2;
      }
    }
  }
}

void creuse (double** tab, int n)
// Crée une matrice creuse aléatoire avec plus de 70% de valeurs nulles
{
  // n est la taille de la matrice tab
  int i, j; // i lignes et j colonnes
  int reste = pow(n, 2); // Nombre de cases restantes
  int zero = ceil(0.7 * reste); // Nombre de zéros à placer (au moins 70%)
  int aleat = 1 + rand() % reste;

  for(i = 0; i < n; i ++)
  {
    for(j = 0; i < n; j++)
    {
      aleat = 1 + rand() % reste;
      if(aleat <= zero)
      {
        tab[i][j] = 0;
        zero--; // Un zéro de moins à placer
        reste--; // Il y a une case de moins à traiter
      }
      else
      {
        reste--; // Il y a une case de moins à traiter
      }
    }
  }
}

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

  //printf("\n et ici");
  // Trigonalisation

  while(j < taille) // Changer de colonne
  {
    //printf("\nEn Fait j = %d",j);
    i = k;
    resteI = 0;
    //printf("\nk = %d et i = %d\n", k, i);
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
      // printf("\nici\n");
      //printf("Pivot = %lf colonne %d\n",tab[i][j], j+1);

      if (i != k) // met le pivot en haut mais pas trop pour echelonner
      {
        // printf("\nbouge\n");
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
    //printf("\n j = %d",j);
    // afficheSys(sys,taille);
  }
  //printf("\n Et là j = %d",j);

}

void renverseTab2D(double** tab,int taille)
{
  int i,j;
  double swap;
  for(i=0; i<taille/2 ; i++)
  {
    for(j=0 ; j<taille ; j++)
    {
      swap = tab[i][j];
      tab[i][j] = tab[taille-i-1][taille-1-j];
      tab[taille-i-1][taille-1-j] = swap;
    }
  }
  if(taille%2 == 1)
  {
    for(j = 0 ; j< taille/2 ; j++)
    {
      swap = tab[taille/2][j];
      tab[taille/2][j] = tab[taille/2][taille-1-j];
      tab[taille/2][taille-1-j] = swap;
    }
  }
}

void renverseSys(double* sys, int taille)
{
  int i;
  double swap;
  for(i=0 ; i<taille/2 ;i++)
  {
    swap = sys[i];
    sys[i] = sys[taille-1-i];
    sys[taille-i-1] = swap;
  }
}



int verifSol(double** tab, double* sys,int taille)
{
  int i,j,verif,compte0;
  verif = 0;   // 0 = normal/ 1  = exprssion par d'autres/ -1 Pas possible
  i = 0;
  while(verif >= 0 && i < taille)
  {
    compte0=0;
    for(j=0; j<taille;j++)
    {
      if(tab[i][j]==0)
      {
        compte0++;
      }
    }
    if(compte0==taille)
    {
      if(sys[i] == 0)
      {
        verif++;
      }
      else
      {
        verif=-1;
      }
    }
    else if(compte0==0)
    {
      verif++;
    }
    i++;
  }
  return verif;
}


void cholesky(double** tab,double** matR, int taille, double* sys) {
  int somme = 0;
  matR[0][0] = sqrt(tab[0][0]);
       for(int i =1; i<taille; i++){
	 for(int j = 0; j<taille; j++){
	   somme = 0;
	   if(i==j){
	     for(int k = 0; k<j; k++){
	       somme = somme + (matR[j][k]) * (matR[j][k]);
	     }
	     matR[j][j] = sqrt(tab[j][j] - somme);
	   }
	   else if(j>i){
	     matR[i][j] = 0;
	   }
	   
	   else{
	     for(int k = 0; k<j; k++){
	       somme = somme + (matR[i][k]) * (matR[j][k]);
	     }
	     matR[i][j] = (1/matR[j][j]) * (tab[i][j] - somme);
	   }
	 }
       }
       printf("\n matrice R\n");
       afficheTab2D(matR,taille);

       ////////////////////////////////////
       ///////////RESOLUTION///////////////
       ////////////////////////////////////

       for(i=0; i< taille; i++){
	 somme = 0;
	 for(j=0; j<i ;j++){
	   somme = somme + matR[i][j] * sys[i]
	     sys[i] = (sys[i]- somme) / matR[i][i];
       
}
		    
	   
	       
