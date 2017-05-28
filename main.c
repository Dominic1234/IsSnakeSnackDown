#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t, n, a, b, count1, count2, condition, scelly, ecelly;
	char input;
	int *cell[2];
	scanf("%d", &t);
	for(a = 0; a < t; a++)
	{
		condition = 1;
		scanf("%d", &n);
		for(b = 0; b < 2; b++)
			cell[b] = (int*)malloc(n * sizeof(int));
		for(count1 = 0; count1 < 2; count1++)
		{
			for(count2 = 0; count2 < n; count2++)
			{
				scanf("%c", &input);
				if(input == '#') cell[count1][count2] = 1;
				else cell[count1][count2] = 0;
			}
		}

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

												}
											}
										}
				}
			if(condition == 1) printf("yes\n");
			else printf("no\n");
	}
	return 0;
}
