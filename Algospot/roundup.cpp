#include <iostream>
#include <queue>	//priority_queue
using namespace std;

int  A[1000];
int dif[1000];
int main(void)
{
	/* 
	//¹Ý¿Ã¸²
	double x = 16.6;
	int y = x;
	cout << y << endl;
	if ((double)y + 0.5 <= x)
		y += 1;
	cout << y << endl;
	*/

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		double sum = 0;
		for (int i = 0; i < N; i++)
		{
			int tmp = M * A[i];
			int roundupCheck = tmp % 10000;
			if (roundupCheck >= 5000)
				sum += (tmp + 10000 - roundupCheck);
			else
				sum += (tmp - roundupCheck);
		}
		if (sum == M)
		{
			cout << '0' << endl;
			continue;
		}
		else if (sum > M)
		{
			if ()
			double dif = sum - M;
			int timesOfChoice = dif / 10000;
		}
		else
		{
			double dif = M - sum;
			int timesOfChoice = dif / 10000;
		}
			
		
	}


	return 0;
}