// Protoypes

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


// Fonctions

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
  // printf("Fonction creuse :\n");
  // n est la taille de la matrice tab
  int i, j; // i lignes et j colonnes
  int reste = pow(n, 2); // Nombre de cases restantes
  // printf("Reste : %d\n", reste);
  int zero = ceil(0.7 * reste); // Nombre de zéros à placer (au moins 70%)
  // printf("Zero : %d\n", zero);
  int aleat = 1 + rand() % reste; // Nombre aléatoire
  // printf("aleat : %d\n", aleat);

  for(i = 0; i < n; i ++)
  {
    for(j = 0; j < n; j++)
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
        tab[i][j] = random();
        reste--; // Il y a une case de moins à traiter
      }
    }
  }
}
