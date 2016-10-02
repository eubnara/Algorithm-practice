#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int weird(int* aliquot, int total,int originalTotal, int checkCount,int count, int inputNum);
void weird2(int* aliquot, int total, int originalTotal, int checkCount, int count, int inputNum, int* result,int k);
int main(){
	int cases;
	int count;
	int i=0;
	scanf("%d", &cases);
	int* result = (int*)malloc(sizeof(int)*cases);
	while (i < cases){
		count = 0;
		int inputNum;
		scanf("%d", &inputNum);
		int originalTotal = 0;
		int j = 1;
		while (j < inputNum){
			if (inputNum%j == 0){
				originalTotal += j;
				count++;
			}
			j++;
		}
		printf("total : %d\n", originalTotal);
		int* aliquot = (int*)malloc(sizeof(int)*count);
		int k=0;
		j = 1;
		while (j < inputNum){
			if (inputNum%j == 0){
				aliquot[k] = j;
				printf("%d\n", aliquot[k]);
				k++;
			}
			j++;
		}
		if (originalTotal <= inputNum)
			result[i] = -1;
		else if (originalTotal > inputNum){
			result[i] = 1;
			for (k = 0; k < count; k++){
				weird2(aliquot, originalTotal, originalTotal, k, count, inputNum, result,i);
			}
		}
			
		/*
		int l;
		
		for (l = 0; l < count; l++){

			result[i] = weird(aliquot, originalTotal, originalTotal, l, count, inputNum);
			if (result[i] == 1)
				continue;
			else if (result[i] == -1)
				break;
		}
		*/


		i++;
		free(aliquot);
	}

	i = 0;
	while (i < cases){
		if (result[i] == 1){
			printf("weird\n");
		}
		else if(result[i]==-1){
			printf("not weird\n");
		}
		i++;
	}
	free(result);
	return 0;
}
/*
배열에서 뺀건 -1로 치환.
약수 배열을 준다.
약수배열의 갯수도 준다.
원래 
함수 내에서 약수배열을 리셋한다.

*/
//기본적으로 약수의 합이 원래 수보다 크면 weird 후보, result[i]=1이라고 둔 후에, 아래 함수를 거치면서 
//not weird 경우가 하나라도 나오면 result[i]=-1로 저장하게끔한다.
void weird2(int* aliquot, int total, int originalTotal, int checkCount, int count, int inputNum, int* result,int k)
{
	if (result[k] == -1)
		return;
	int i;
	if (checkCount == count)
		return;
	
	for (i = checkCount; i <count ; i++)
	{
		total -= aliquot[i];
		printf("aliquot[i] : %d \n", aliquot[i]); 
		printf("checkCount : %d \n", checkCount);
		printf("total inside function : %d \n", total);
		if (total == inputNum)
			result[k] = -1;
		else if (total>inputNum)
			weird2(aliquot, total, originalTotal, ++i, count, inputNum, result,k);
		else if (total < inputNum)
			total += aliquot[i];
			continue;
	}
}


/*
int weird(int* aliquot, int total,int originalTotal, int checkCount,int count,int inputNum){
	
	int i;
	int check;
	if (checkCount == count)
		return 0;
	for (i = checkCount; i < count; i++){
		total -= aliquot[i];
		printf("%d", total);
		printf(" %d \n", aliquot[i]);
		if (total == inputNum)
			return -1;
		else if (total < inputNum){
			total += aliquot[i];
			continue;
		}
		else{
			int j = i + 1;
			printf("count : %d checkCount : %d \n", count, checkCount);
			check=weird(aliquot, total,originalTotal,j ,count, inputNum);
			if (check == 0){
				printf("check == 0\n");
				total=originalTotal;
				continue;
			}
				
			else if (check == -1)
				return -1;
			else if (check == 1)
				return 1;
			else{
				total += aliquot[i];
			}
		}
		
	}

}
int weirdCheck(int* aliquot, int total,int originalTotal, int count, int inputNum,int checkCount){
	if (checkCount == 0)
		return 1;
	if (count <= 0){
		checkCount--;
		count = checkCount;
		total = originalTotal;
		weirdCheck(aliquot, total,originalTotal, count, inputNum, checkCount);
	}
	if (originalTotal < inputNum){
		return -1;
	}

	total -= aliquot[count - 1];
	printf("total after minus : %d \n", total);

	if (total == inputNum){
		return -1;
	}
	if (total < inputNum){
		total += aliquot[count - 1];
		weirdCheck(aliquot, total, originalTotal, count-1, inputNum, checkCount);
		printf("total<inputNum\n");
		system("Pause");
	}
	if (total > inputNum){
		weirdCheck(aliquot, total, originalTotal, count - 1, inputNum, checkCount);
		printf("total>inputNum\n");
		printf("total : %d ||", total);
		system("Pause");
	}
	
}
*/