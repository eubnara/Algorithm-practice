#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct square{
	int a, b;
	int c, d;
	int e, f;
}SQ;

int main(){
	int testCase;
	scanf("%d", &testCase);
	SQ* sq = (SQ*)malloc(sizeof(SQ)*testCase);
	int i;
	for (i = 0; i < testCase; i++){
		scanf("%d %d", &sq[i].a, &sq[i].b);
		scanf("%d %d", &sq[i].c, &sq[i].d);
		scanf("%d %d", &sq[i].e, &sq[i].f);
	}

	int x, y;
	for (i = 0; i < testCase; i++){
		if (sq[i].a == sq[i].c)
			x = sq[i].e;
		else{
			if (sq[i].a == sq[i].e)
				x = sq[i].c;
			else
				x = sq[i].a;
		}
		if (sq[i].b == sq[i].d)
			y = sq[i].f;
		else{
			if (sq[i].b == sq[i].f)
				y = sq[i].d;
			else
				y = sq[i].b;
		}
		printf("%d %d\n", x, y);
	}

	return 0;
}