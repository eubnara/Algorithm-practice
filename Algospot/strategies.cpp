//각 자료가 나타내는 인물을 쉽게 알아보기 위하여 숫자를 매크로 선언함.
#define BILL 0
#define STEVE 1
#define LINUS 2
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class person {
private:
	int elapsedTime;		//문제를 푸는데 경과된 시간
	int accumScore;			//문제를 푸는 동안 누적된 점수
	int numOfSolvedProbs;	//풀어낸 문제의 수
	int name;				//매크로로 선언된 BILL, STEVE, LINUS 중에 하나가 들어간다.
public:
	person() : elapsedTime(0), accumScore(0), numOfSolvedProbs(0), name(name)
	{}
	void setName(int name) { this->name = name; }
	/*
		문제풀기
		arg : 주어진 시간, 각 문제를 푸는데 걸리는 시간 배열, 총 문제의 수
		ret : void
		elapsedTime은 이 함수가 적용될 때에만 쓰임
		accumScore가 이 함수의 결과로 저장된 최종 점수
		numOfSolvedProbs는 풀어낸 결과


		BILL, STEVE, LINUS 에 따라 계산 방법이 달라지는데, 그 경우에 따라 정렬을 할지 말지, 오름차순으로 할지 내림차순으로 할지를
		이 함수 내에서 정한다.

		만일, 속도개선이 필요하다면, 이 함수를 호출하기 전에 정렬을 하는 방식으로 한다.

		BILL->STEVE->LINUS 순서대로 문제를 처리한다.
		따라서, STEVE일 때에만 정렬을 사용하고, LINUS일 때에는 정렬된 배열을 거꾸로 사용할 수 있도록 한다.
	*/
	void solve(int contestTime, int difOfProbs[], int numOfProbs) {
		if (this->name == STEVE) {
			std::sort(difOfProbs, difOfProbs + numOfProbs);		//STEVE는 쉬운 문제부터 푸니까 오름차순으로 정렬
		}
		else if (this->name == LINUS) {
			std::sort(difOfProbs, difOfProbs + numOfProbs, std::isgreater<int, int>);	//LINUS는 어려운 문제부터 푸니까 내림차순으로 정렬
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
누가 1등인지 비교하는 함수
먼저, 풀어낸 문제 수를 비교한다.
그 다음 점수를 비교한다.
그래도 tie 발생 시에는 STEVE가 우승한 것으로 한다.

매개변수 : person class 배열
반환값 : int (BILL, STEVE, LINUS 중 하나, 즉 0,1,2 중 하나)


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


	//문제 많이 푼 사람 순서로 승리자 판별
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
	

	//점수 적게 낸 사람 순서로 승리자 판별
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

	int numOfScenarios;	// 시나리오의 수
	cin >> numOfScenarios;
	int scenarioIdx = 1;
	while (scenarioIdx <= numOfScenarios) {
		int contestTime;	// 콘테스트 총 시간
		int numOfProbs;		// 주어진 전체 문제 수
		int winner;

		cin >> contestTime >> numOfProbs;

		int* difOfProbs = new int[numOfProbs];	// 각 문제의 난이도

		for (int i = 0; i < numOfProbs; i++) {
			cin >> difOfProbs[i];
		}
		//person class 를 생성할 시, 이름을 생성자 인자로 넘겨준다.
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