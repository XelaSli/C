#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	first_line(int nbr_bloc)
{
  int	i;
  int	first;
  int	jump;

  i = 1;
  first = 1;
  jump = 4;
  while (i < nbr_bloc)
    {
      if (i % 2 == 0)
	{
	  jump = jump + 2;
	  first = first+ jump;
	}
      else
	{
	  first = first+jump;
	}
      i++;
    }
  return (first);
}

int	last_line(int nbr_bloc)
{
  int	last;
  int	j;
  int	jump;

  last = 7;
  j = 1;
  jump = 6;
  
  while (j < nbr_bloc)
    {
      if (j % 2 == 0)
	{
	  jump = jump + 2;
	  last = last + jump;
	}
      else
	{
	  last = last + jump;
	}
      j++;
    }
 return (last);  
}

void	print_haut(int num, int size)
{
  int	i;
  int	j;
  int	taille;
  int	etoile;
  int	espace;

  i = 1;
  j = 0;
  taille = num + 3;
  etoile = first_line(num);
  espace = last_line(size) / 2 - etoile / 2;

  while (i <= taille )
    {
      while ( j< espace)
	{
	  my_putchar(' ');
	  j++;
	}
      j=0;
      while (j < etoile)
	{
	  my_putchar('*');
	  j++;
	}
      j = 0;
      espace--;
      etoile = etoile + 2;
      my_putchar('\n');
      i++;
    }
}
void	print_tronc(int size)
{
  int	largeur;
  int	hauteur;
  int	i;
  int	j;
  int	espace;

  if (size % 2 != 0)
    largeur = size;
  else
    largeur = size + 1;

  hauteur = size;
  espace = last_line(size) / 2 - (largeur / 2);

  while (i < hauteur)
    {
      j = 0;
      while (j < espace)
	{
	  my_putchar(' ');
	  j++;
	}
      j = 0;
      while (j < largeur)
	{
	  my_putchar('|');
	  j++;
	}
      j = 0;
      my_putchar('\n');
      i++;
    }
}

void	sapin( int size)
{
  int	i;
  if (size > 0)
    {
      i = 1;
      while (i <= size)
	{
	  print_haut(i , size);
	  i++;
	}
      print_tronc(size);
    }
}
	    
  int	main(int argc, char**argv)
  {
    if (argc == 2)
      {
	sapin(atoi(argv[1]));
      }
    else
      printf("Argument missing !");
  }
