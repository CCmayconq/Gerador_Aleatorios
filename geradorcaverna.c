#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct caverna
{
	char L;
	int M, B, T;
}c[22][22];

int main ()
{
	FILE *Ca;
	Ca=fopen ("Caverna.txt", "w");
	int i, j,k;
	
	srand (time(NULL));
	
	for (i=0;i<22;i++)
	{
		for (j=0;j<22;j++)
		{
			c[i][j].M=0;
			c[i][j].B=0;
			c[i][j].T=0;
		}
	}
	printf ("\n");
	printf ("\n");
	printf ("\n");
	for (k=0;k<100;k++)
	{
		i=1+rand()%21;
		j=1+rand()%21;
		printf ("%i - %i - ", i, j);
		
		c[i][j].M=1;
		c[i][j].B=0;
		c[i][j].T=0;
	}
	printf ("\n");
	printf ("\n");
	printf ("\n");
	for (k=0;k<100;k++)
	{
		i=1+rand()%21;
		j=1+rand()%21;
		printf ("%i - %i - ", i, j);
		c[i][j].M=0;
		c[i][j].B=1;
		c[i][j].T=0;
	}
	printf ("\n");
	printf ("\n");
	printf ("\n");
	for (k=0;k<50;k++)
	{
		i=1+rand()%21;
		j=1+rand()%21;
		printf ("%i - %i - ", i, j);
		c[i][j].M=0;
		c[i][j].B=0;
		c[i][j].T=1;
	}
	
	for (i=0;i<22;i++)
	{
		for (j=0;j<22;j++)
		{
			fprintf (Ca, "%i\n", c[i][j].M);
			fprintf (Ca, "%i\n", c[i][j].B);
			fprintf (Ca, "%i\n", c[i][j].T);
		}
	}
	
	printf ("Sua caverna foi gerada!");
	fclose (Ca);
	return (0);
}
