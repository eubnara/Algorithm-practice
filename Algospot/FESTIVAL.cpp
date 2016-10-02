#include <iostream>
using namespace std;

int main(void)
{
	int C;
	int N, T;
	cin >> C;
	int testCase = 0;
	double * ans = new double[C];

	while (testCase < C)
	{
		cin >> N >> T;
		double * cost = new double[N];
		for (int i = 0; i < N; i++)
		{
			cin >> cost[i];
		}
		int	dif = N - T + 1;
		double sum;
		double avg = 101;
		double tmpAvg = 101;
		for (int i = 0; i < dif; i++)
		{
			sum = 0.0;
			int j = i;
			for (; j < T + i; j++)
				sum += cost[j];

			tmpAvg = sum / (double)T;
			if (tmpAvg < avg)
				avg = tmpAvg;
			double tmpSum = sum;
			for (int k = 1; j < N; k++)
			{
				tmpSum += cost[j];

				tmpAvg = tmpSum / (double)(T + k);
				if (tmpAvg < avg)
					avg = tmpAvg;
				j++;
			}

		}
		ans[testCase] = avg;

		testCase++;
	}
	for (int i = 0; i < C; i++)
		printf("%.10lf\n", ans[i]);


	delete[]ans;
	return 0;
}