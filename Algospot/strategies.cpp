//�� �ڷᰡ ��Ÿ���� �ι��� ���� �˾ƺ��� ���Ͽ� ���ڸ� ��ũ�� ������.
#define BILL 0
#define STEVE 1
#define LINUS 2
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class person {
private:
	int elapsedTime;		//������ Ǫ�µ� ����� �ð�
	int accumScore;			//������ Ǫ�� ���� ������ ����
	int numOfSolvedProbs;	//Ǯ� ������ ��
	int name;				//��ũ�η� ����� BILL, STEVE, LINUS �߿� �ϳ��� ����.
public:
	person() : elapsedTime(0), accumScore(0), numOfSolvedProbs(0), name(name)
	{}
	void setName(int name) { this->name = name; }
	/*
		����Ǯ��
		arg : �־��� �ð�, �� ������ Ǫ�µ� �ɸ��� �ð� �迭, �� ������ ��
		ret : void
		elapsedTime�� �� �Լ��� ����� ������ ����
		accumScore�� �� �Լ��� ����� ����� ���� ����
		numOfSolvedProbs�� Ǯ� ���


		BILL, STEVE, LINUS �� ���� ��� ����� �޶����µ�, �� ��쿡 ���� ������ ���� ����, ������������ ���� ������������ ������
		�� �Լ� ������ ���Ѵ�.

		����, �ӵ������� �ʿ��ϴٸ�, �� �Լ��� ȣ���ϱ� ���� ������ �ϴ� ������� �Ѵ�.

		BILL->STEVE->LINUS ������� ������ ó���Ѵ�.
		����, STEVE�� ������ ������ ����ϰ�, LINUS�� ������ ���ĵ� �迭�� �Ųٷ� ����� �� �ֵ��� �Ѵ�.
	*/
	void solve(int contestTime, int difOfProbs[], int numOfProbs) {
		if (this->name == STEVE) {
			std::sort(difOfProbs, difOfProbs + numOfProbs);		//STEVE�� ���� �������� Ǫ�ϱ� ������������ ����
		}
		else if (this->name == LINUS) {
			std::sort(difOfProbs, difOfProbs + numOfProbs, std::isgreater<int, int>);	//LINUS�� ����� �������� Ǫ�ϱ� ������������ ����
		}

		for (int i = 0; i < numOfProbs; i++) {
			if (elapsedTime + difOfProbs[i] > contestTime) {
				break;
			}
			else {
				accumScore += (elapsedTime + difOfProbs[i]);
				elapsedTime += (difOfProbs[i]);
				numOfSolvedProbs++;
			}
		}
	}

	int getScore() {
		return this->accumScore;
	}

	int getNumOfSolvedProbs() {
		return this->numOfSolvedProbs;
	}
};

/*
���� 1������ ���ϴ� �Լ�
����, Ǯ� ���� ���� ���Ѵ�.
�� ���� ������ ���Ѵ�.
�׷��� tie �߻� �ÿ��� STEVE�� ����� ������ �Ѵ�.

�Ű����� : person class �迭
��ȯ�� : int (BILL, STEVE, LINUS �� �ϳ�, �� 0,1,2 �� �ϳ�)


*/

int whoIsWinner(person man[3]) {
	int accumScore[3];
	int numOfSolvedProbs[3];
	bool isTie = false;
	int mostSolvedProb = 0;
	int lowestScore = 2147483647;
	int winner;
	stack<int> tieStack;
	for (int i = 0; i < 3; i++) {
		accumScore[i] = man[i].getScore();
		numOfSolvedProbs[i] = man[i].getNumOfSolvedProbs();
	}


	//���� ���� Ǭ ��� ������ �¸��� �Ǻ�
	for (int i = 0; i < 3; i++) {
		if (mostSolvedProb == numOfSolvedProbs[i]) {
			isTie = true;
			tieStack.push(i);
		}
		if (mostSolvedProb < numOfSolvedProbs[i]) {
			isTie = false;
			mostSolvedProb = numOfSolvedProbs[i];
			winner = i;
			while (!tieStack.empty()){
				tieStack.pop();
			}
			tieStack.push(i);
		}
	}
	if (!isTie)
		return winner;
	

	//���� ���� �� ��� ������ �¸��� �Ǻ�
	while(!tieStack.empty()) {
		int name = tieStack.top();
		tieStack.pop();
		if (lowestScore == man[name].getScore()) {
			isTie = true;
		}
		if (man[name].getScore() < lowestScore) {
			isTie = false;
			lowestScore = man[name].getScore();
			winner = name;
		}
	}
	if (isTie)
		return STEVE;
	else
		return winner;
}





int main(void) {

	int numOfScenarios;	// �ó������� ��
	cin >> numOfScenarios;
	int scenarioIdx = 1;
	while (scenarioIdx <= numOfScenarios) {
		int contestTime;	// ���׽�Ʈ �� �ð�
		int numOfProbs;		// �־��� ��ü ���� ��
		int winner;

		cin >> contestTime >> numOfProbs;

		int* difOfProbs = new int[numOfProbs];	// �� ������ ���̵�

		for (int i = 0; i < numOfProbs; i++) {
			cin >> difOfProbs[i];
		}
		//person class �� ������ ��, �̸��� ������ ���ڷ� �Ѱ��ش�.
		person man[3];
		man[BILL].setName(BILL);
		man[STEVE].setName(STEVE);
		man[LINUS].setName(LINUS);
		
		for (int i = 0; i < 3; i++) {
			man[i].solve(contestTime, difOfProbs, numOfProbs);
		}

		winner = whoIsWinner(man);

		printf("Scenario #%d:\n", scenarioIdx);
		switch (winner) {
		case BILL:
			printf("Bill ");
			break;
		case STEVE:
			printf("Steve ");
			break;
		case LINUS:
			printf("Linus ");
			break;
		}
		printf("wins with %d solved problems and a score of %d.\n\n", man[winner].getNumOfSolvedProbs(), man[winner].getScore());

		delete[] difOfProbs;
		scenarioIdx++;
	}


	return 0;
}