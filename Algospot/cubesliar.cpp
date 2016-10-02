#include <iostream>
#include <list>
#include <stack>
using namespace std;
int T, N, M;

typedef struct _node
{
	int divNum;
	int dif;
}Node;

bool isCyclicUtil(std::list<Node>* list, int v, bool visited[], bool * recStack,std::stack<int>* stack)
{
	if (visited[v] == false)
	{
		visited[v] = true;
		recStack[v] = true;
		stack->push(v);

		std::list<Node>::iterator i;
		for (i = list[v].begin(); i != list[v].end(); ++i)
		{
			if (!visited[(*i).divNum] && isCyclicUtil(list, (*i).divNum, visited, recStack,stack))
				return true;
			else if (recStack[(*i).divNum])
			{
				int start = (*i).divNum;
				for (int vertex = stack->top(); vertex != start; stack->pop())
				{
					stack->pop();
					if (list[vertex].)
				}
				return true;
			}
				
		}
	}
	recStack[v] = false;
	stack->pop();
	return false;
}

bool isCyclic(std::list<Node>* mylist)
{
	bool ret = false;
	bool *visited = new bool[N]();
	bool *recStack = new bool[N]();
	std::stack<int> stack;
	for (int i = 0; i < N; i++)
		if (isCyclicUtil(mylist, i, visited, recStack,&stack))
			ret = true;

	delete[] visited;
	delete[] recStack;

	return ret;
}

void spread(int* divergence, std::list<Node>* mylist, int divNum, int k)
{
	divergence[divNum] = k;
	for (std::list<Node>::iterator it = mylist[divNum].begin(); it != mylist[divNum].end(); ++it)
	{
		int k = divergence[divNum] + (*it).dif;
		spread(divergence, mylist, (*it).divNum, k);
	}

}



int main(void)
{

	cin >> T;

	while (T--)
	{


		cin >> N >> M;
		std::list<Node>* mylist = new std::list<Node>[N];

		int* divergence = new int[N]();	//0으로 초기화

		int** map = new int*[M];
		for (int i = 0; i < M; i++)
		{
			map[i] = new int[3];
		}
		//bool* flag = new bool[N]();	//0으로 초기화하는 방법. 따라서, 모두 false 로 초기화 됨.
		//bool* flag = new bool[N]();

		for (int i = 0; i < M; i++)
		{
			cin >> map[i][0] >> map[i][1] >> map[i][2];
			

			Node newNode;
			newNode.divNum = map[i][0];
			newNode.dif = map[i][2];
			mylist[map[i][1]].push_front(newNode);
		
		}

		if (isCyclic(mylist))
		{
			cout << "-1" << endl;
			for (int i = 0; i < M; i++)
			{
				delete[] map[i];
			}
			delete[] map;
			delete[] divergence;
			delete[] mylist;
			continue;
		}

		//map setting
		for (int i = 0; i < M; i++)
		{
			int k = map[i][2];
			int q = map[i][1];
			int p = map[i][0];
			if (divergence[p] < divergence[q] + k)
			{
				spread(divergence, mylist, p, k);
			}

		}


		for (int i = 0; i < N; i++)
		{
			cout << divergence[i] << ' ';
		}

		cout << endl;



		for (int i = 0; i < M; i++)
		{
			delete[] map[i];
		}


		delete[] map;
		//delete[] flag;
		delete[] divergence;
		delete[] mylist;
		//Node 제거 만들기
	}



	return 0;
}