#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int debug = 0;

int main()
{
	int t, n, a, b, count1, count2, condition, scelly, ecelly, prev, col;
	char input;
	int *cell[2];
	scanf("%d", &t);
	if (debug) printf ("#Tests = %d\n", t);
	for(a = 0; a < t; a++)
	{
		condition = 1;
		scanf("%d", &n);
		if (debug) printf ("TC%d has %d columns\n", a, n);
		for(b = 0; b < 2; b++)
			cell[b] = (int*)malloc(n * sizeof(int));
		if (debug) printf ("\tReading inputs\n");
		for(count1 = 0; count1 < 2; count1++)
		{
			printf("\t");
			for(count2 = 0; count2 < n; count2++)
			{
				do {
					scanf("%c", &input);
				} while (isspace(input));
				if(input == '#') cell[count1][count2] = 1;
				else cell[count1][count2] = 0;
				if (debug) printf ("%c-%d, ", input, cell[count1][count2]);
			}
			if(debug) printf("\n");
		}

		if (debug)
		for(count1 = 0; count1 < 2; count1++)
				{
					for(count2 = 0; count2 < n; count2++)
					{
						printf("%d", cell[count1][count2]);
					}
					printf("\n");
				}

				for(count2 = 0; count2 < n; count2++)
					{
					if(cell[1][count2] == 1 || cell[0][count2] == 1)
						{
							//scell{x,y} stands for the x,y of the start cell
							scelly = count2;
							if(cell[1][count2] == 1 && cell[0][count2] == 1) prev = 2;
							else if(cell[1][count2] == 1)prev = 1;
							else if(cell[0][count2] == 1)prev = 0;
							break;
						}
					}

				for(count2 = n; count2 > scelly; count2--)
					{
					if(cell[0][count2] == 1 || cell[1][count2] == 1)
						{
							//ecell{x,y} stands for x,y of end cell
							ecelly = count2;
							break;
						}
					}
			for(col = scelly+1; col <= ecelly; col++)
				{
				if(prev == 0)
					{
					if(cell[0][col] == 0)
						{
						condition = 0;
						break;
						}
						else if(cell[1][col] == 1)
							{
							prev = 1;
							}
					}
					else if(prev == 1)
						{
						if(cell[1][col] == 0)
							{
							condition = 0;
							break;
							}
						else if(cell[0][col] == 1)
							{
							prev = 0;
							}
						}
					else if(prev == 2)
						{
						if(cell[0][col] == 1 && cell[1][col] == 1)
						{
							//skip card
						}

					else if(cell[0][col] == 1)
							{
							prev = 0;
							}
						else if(cell[1][col] == 1)
							{
							prev = 1;
							}
						else if(cell[0][col] == 0 && cell[1][col] == 0)
							{
							condition = 0;
							break;
							}
						}
				}

			if(condition == 1) printf("yes\n");
			else printf("no\n");
	}
	return 0;
}
