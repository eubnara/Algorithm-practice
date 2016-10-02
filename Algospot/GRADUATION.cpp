#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <intrin.h>
using namespace std;
#define MAXN 12
const int INF = 987654321;
int n, k, m, l;

int prerequisite[MAXN];
int classes[10];
int cache[10][1 << MAXN];



int min(int a, int b) {
	return (a > b) ? b : a;
}

int graduate(int semester, int taken) {
	if (__popcnt(taken) >= k) return 0;
	if (semester == m) return INF;
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;

	int canTake = (classes[semester] & ~taken);

	for (int i = 0; i < n; ++i) {
		if ((canTake & (1 << i)) && (taken&prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	}
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (__popcnt(take) > l) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

int main(void) {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(cache, -1, 10 *(1<<MAXN)*4);
		int answer;
		cin >> n >> k >> m >> l;
		for (int i = 0; i < n; ++i){
			int numOfPrerequisite;
			cin >> numOfPrerequisite;
			for (int j = 0; j < numOfPrerequisite; ++j) {
				int input;
				cin >> input;
				prerequisite[i] |= (1<<input);
			}
		}

		for (int i = 0; i < m; ++i) {
			int numOfSubjects;
			cin >> numOfSubjects;
			for (int j = 0; j < numOfSubjects; ++j) {
				int input;
				cin >> input;
				classes[i] |= (1 << input);
			}
		}

		answer = graduate(0, 0);
		if (answer == INF)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << answer << endl;
	}

	return 0;
}