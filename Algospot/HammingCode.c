#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int char_to_int(char a);
int main()
{
	int testCases;
	scanf("%d", &testCases);
	int i;
	char** result = (char**)malloc(sizeof(char*)*testCases);
	for (i = 0; i < testCases; i++)
	{
		result[i] = (char*)malloc(sizeof(char) * 5);
		result[i][4] = '\0';
	}
	for (i = 0; i < testCases; i++)
	{
		fflush(stdin);
		char code[8];
		scanf("%s", code);
		int check1, check2, check3;
		//char syndrome[4];
		int location;

		int sum = 0;
		//1357
		sum += char_to_int(code[1 - 1]);
		sum += char_to_int(code[3 - 1]);
		sum += char_to_int(code[5 - 1]);
		sum += char_to_int(code[7 - 1]);
		check1 = sum % 2;
		//2367
		sum = 0;
		sum += char_to_int(code[2 - 1]);
		sum += char_to_int(code[3 - 1]);
		sum += char_to_int(code[6 - 1]);
		sum += char_to_int(code[7 - 1]);
		check2 = sum % 2;
		//4567
		sum = 0;
		sum += char_to_int(code[4 - 1]);
		sum += char_to_int(code[5 - 1]);
		sum += char_to_int(code[6 - 1]);
		sum += char_to_int(code[7 - 1]);
		check3 = sum % 2;
		location = check1 + (check2 * 2) + (check3 * 4);
		if (location != 0)
		{
			if (code[location - 1] == '1')
				code[location - 1] = '0';
			else if (code[location - 1] == '0')
				code[location - 1] = '1';
		}
		
		
		result[i][0] = code[3 - 1];
		result[i][1] = code[5 - 1];
		result[i][2] = code[6 - 1];
		result[i][3] = code[7 - 1];
	}
	for (i = 0; i < testCases; i++)
	{
		printf("%s\n", result[i]);
	}

	for (i = 0; i < testCases; i++)
	{
		free(result[i]);
	}
	free(result);

	return 0;
}

int char_to_int(char a)
{
	if (a == '1')
		return 1;
	else if (a == '0')
		return 0;
}