#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//structure ���ο��� �����Ҵ��� �ȵǴµ�?
//candidate ���� 5���� �ְ�ϱ�, 5������ ���� �� �ִ� ������ ������ ����.
typedef struct group{
	int total;
	int preferSeq[5];
	//�⺻ �ʱ�ȭ�� 0? �ʱ�ȭ�� �ȵǳ�

}GROUP;

int main(){
	int answer[100] = { 0 };
	int check = 0;
	while (1){
		unsigned int i, j;
		//candidate ��, Group ���� �޴´�.
		unsigned int G;
		unsigned int N;
		scanf("%d %d", &G, &N);
		if (G == 0 || N == 0){
			break;
		}
		//candidate�� �پ ��, ���� candidate ���� �������� ����
		unsigned int leftN = N;

		//������ ���ϱ� ���� �� candidate�� ��ǥ�񱳿� ����
		//N+1�� ������ ������ ��ȣ��ȣ�� �迭��ȣ�� �����ַ��� ���ǻ�. (����, 0��° �迭�� �ǹ̾����ڸ�)
		int* cmpCand = (int*)malloc(sizeof(int)*(N + 1));
		//cmpCand�� �ʱ�ȭ, ���߿� ���ŵǸ� -1�� �����Ŵ�.
		for (i = 0; i < N + 1; i++){
			*(cmpCand + i) = 0;
		}
		//���θ��� Group�� �� �ο��� preference ������ ������
		GROUP* groupPtr = (GROUP*)malloc(sizeof(GROUP)*G);
		for (i = 0; i < G; i++){
			scanf("%d", &((groupPtr + i)->total)); //&�ڿ� ��ȣ�� ������ϴ��� üũ
			for (j = 0; j < N; j++){
				scanf("%d", &((groupPtr + i)->preferSeq[j]));
			}
		}

		while (leftN != 1){
			//first choices of M people�� �ϴ� ����
			for (i = 0; i < G; i++){
				for (j = 0; j < N; j++){
					if ((groupPtr + i)->preferSeq[j] == 0){
						continue;
					}
					else{
						cmpCand[((groupPtr + i)->preferSeq[j])] += (groupPtr + i)->total;
						break;
					}
				}
			}


			//least popular ã�� cmpCand�� 1���� ����(��ȣ ��ȣ�� ����), num�� least popular�� ����� �ش� ��ȣ��ȣ
			//cmpPtr�� �ش� ���� -1�� �ٲ��ֱ�����.
			int* cmpPtr = NULL;
			int num = 1;
			for (i = 1; i < N + 1; i++){
				if (cmpCand[i] == -1){
					continue;
				}
				else{
					cmpPtr = &cmpCand[i];
				}
				for (j = i + 1; j < N + 1; j++){
					if (cmpCand[j] == -1){
						continue;
					}
					else if (*cmpPtr >= cmpCand[j]){
						cmpPtr = &cmpCand[j];
						num = i;
					}
				}
				break;

			}
			//least popular ���ֱ� cmpCand�� 1���� ����(��ȣ ��ȣ�� ����)
			//�� ����ü�� preferSequence�� 0����, cmpCand ���� -1�� ��ȭ
			for (i = 0; i < G; i++){
				for (j = 0; j < N; j++){
					if (num == (groupPtr + i)->preferSeq[j]){
						(groupPtr + i)->preferSeq[j] = 0;
					}
				}
			}
			*(cmpPtr) = -1;

			//�� ������ �������� candidate�� �پ
			leftN--;
			//���� candidate����� ��ǥ�� �ٽ� �����ؾ���
			for (i = 1; i < N + 1; i++){
				if (*(cmpCand + i) != -1){
					*(cmpCand + i) = 0;

				}

			}

		}
		
		for (i = 1; i < N + 1; i++){
			if (cmpCand[i] != -1){
				//printf("%d\n", i);
				answer[check] = i;
				check++;
			}
		}
		
		


		free(cmpCand);
		free(groupPtr);
	}
	int i;
	for (i = 0; i < 100; i++){
		if (answer[i] != 0)
			printf("%d\n", answer[i]);
	}
	return 0;
}