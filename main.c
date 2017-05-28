#include<stdio.h>
#include<stdlib.h>

int debug = 0;

int main()
{
	int t, n, a, b, count1, count2, condition, scelly, ecelly;
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
				} while (input == '\r' || input == '\n');
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
			for(count2 = scelly; count2 < ecelly; count2++)
				{
					if(cell[0][count2] == 0)
					{
						if(cell[1][count2] == 0) condition = 0;
					}
					if (cell[0][count2+1] == 0 && cell[1][count2] == 0)
					condition = 0;
					if(cell[1][count2+1] == 0 && cell[0][count2] == 0)condition = 0;
					if(cell[0][count2] == 1)
										{
											if(cell[1][count2] == 1)
											{
												if(cell[0][count2+1] == 1 && cell[1][count2+1] == 0)
												{
													//yet to addd code
												}
											}
										}
				}
			if(condition == 1) printf("yes\n");
			else printf("no\n");
	}
	return 0;
}
