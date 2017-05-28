#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int debug = 0;

int main(int argc, char **argv)
{
	int a, b;
	int tc;//testcases
	int len;//Length of string
	int count = 0;


	scanf("%d", &tc);
	if (debug) printf ("TC=%d\n", tc);
	for( a = 0; a < tc; a++)
	{
		count = 0;
		scanf("%d", &len);
		char snake;
		for(b = 0; b < len; b++)
		{
			scanf("%c", &snake);

			if(snake == 'H' && count == 0)
			{
				count = 1;
			}
			else if(snake == 'H' && count > 0)
			{
				count = 2;
			}
			else if(snake == 'T' && count == 1)
			{
				count = 0;
			}
			else if(snake == 'T' && count != 1)
			{
				count = 2;
			}
		}
			if(count == 1)
			{
				printf("Invalid\n");
			}
			else if(count == 0)
				printf("Valid\n");
			else{
				printf("Invalid\n");
			}
	}

	return 0;
	}
