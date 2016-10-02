#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Loc
{
	int x;
	int y;
}Loc;

typedef struct _Max
{
	int x;
	int y;
}Max;
int check(Loc a, Loc b, char** matrix,Max L);

int main(void)
{
	int testCases;
	scanf("%d", &testCases);
	int i, j, k;
	int* result = (int*)malloc(sizeof(int)*testCases);
	Loc A, B;
	for (i = 0; i < testCases; i++)
	{
		int x, y;
		Max L;
		result[i] = 0;
		scanf("%d %d", &x, &y);
		L.x = x - 1;
		L.y = y - 1;
		char **matrix = (char**)malloc(sizeof(char*)*x);
		for (j = 0; j < x; j++)
		{
			matrix[j] = (char*)malloc(sizeof(char)*y);
		}
		
		//사천성 판 내용 입력받기.
		for (j = 0; j < x*y; j++)
		{
			if ((j / y) == 0 || (j / y) == (x - 1) || (j%y) == 0 || (j%y) == (y - 1))
				continue;
			scanf("\n%c", &matrix[j / y][j%y]);
		}
		
		for (j = 0; j < x*y - 1; j++)
		{
			if ((j / y) == 0 || (j / y) == (x - 1) || (j%y) == 0 || (j%y) == (y - 1))
				continue;
			for (k = j + 1; k < x*y; k++)
			{
				if (matrix[j / y][j%y] == matrix[k / y][k%y])
				{
					A.x = j / y;
					A.y = j%y;
					B.x = k / y;
					B.y = k%y;
					result[i] += check(A, B, matrix,L);
				}
			}
			
		}

		for (j = 0; j < x; j++)
		{
			free(matrix[j]);
		}
		free(matrix);
	}
	for (i = 0; i < testCases; i++)
	{
		printf("%d\n", result[i]);
	}
	free(result);
	return 0;
}

int check(Loc a, Loc b, char** matrix,Max L)
{
	int result = 0;
	int i, j;
	if (a.x == b.x || a.y == b.y)
		return 1;
	//왼쪽
	result = 1;
	for (i = 1; a.x - i > -1; i++)
	{
		if (matrix[a.x - i][a.y] != '.')
		{
			result = 0;
			break;
		}
	}
	result = 1;
	for (i = 1; b.x - i > -1; i++)
	{
		if (matrix[b.x - i][b.y] != '.')
		{
			result = 0;
			break;
		}
	}
	if (result == 1)
		return result;

	//오른쪽


}