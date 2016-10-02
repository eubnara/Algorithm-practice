#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct _point
{
	int x;
	int y;
}Point;

class Graph
{
public:
	int vertex;
	std::vector<int>* edge;
	Graph(int v) : vertex(v)
	{
		edge = new std::vector<int>[v]();
	}
	~Graph()
	{
		edge->clear();
		delete[]edge;
	}
	void addEdge(int v, int e)
	{
		edge[v].push_back(e);
	}

};
bool DFS2(Graph* graph, int start, int goal)
{
	bool *visited = new bool[graph->vertex]();
	stack<int> stack;
	stack.push(start);
	while (!stack.empty())
	{
		int tmp = stack.top();
		if (tmp == goal)
			return true;
		stack.pop();
		visited[tmp] = true;
		vector<int>::iterator it = graph->edge[tmp].begin();
		for (; it != graph->edge[tmp].end(); it++)
		{
			if (!visited[*it])
				stack.push(*it);
		}
	}



	delete[] visited;
	return false;
}



bool DFS(Graph* graph, int a, int goal, bool* visited)
{
	if (a == goal)
		return true;
	if (visited[a] == false)
	{
		visited[a] = true;
		std::vector<int>::iterator it = graph->edge[a].begin();
		for (; it != graph->edge[a].end(); it++)
		{
			if (DFS(graph, *it, goal, visited))
				return true;
		}
	}
	else
	{
		visited[a] = false;
	}
	return false;
}


int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		double jumpPow;
		Point start;
		Point end;

		cin >> jumpPow >> start.x >> start.y >> end.x >> end.y;
		int numOfStones;

		cin >> numOfStones;
		Graph graph(numOfStones + 2);
		Point* loc = new Point[numOfStones + 2];
		for (int i = 1; i <= numOfStones; i++)
		{
			cin >> loc[i].x >> loc[i].y;
		}
		loc[0] = start;
		loc[numOfStones + 1] = end;
		jumpPow *= jumpPow;
		//시작점에서 edge 추가
		for (int i = 1; i <= numOfStones+1; i++)
		{
			double hori = loc[0].x - loc[i].x;
			double vert = loc[0].y - loc[i].y;
			double tmp = hori*hori + vert* vert;
			if (jumpPow >= tmp)
				graph.addEdge(0, i);
		}


		for (int i = 1; i <= numOfStones; i++)
		{
			for (int j = 1; j <= numOfStones + 1; j++)
			{
				if (i != j)
				{
					double hori = loc[i].x - loc[j].x;
					double vert = loc[i].y - loc[j].y;
					double tmp = hori*hori + vert* vert;
					if (jumpPow >= tmp)
						graph.addEdge(i, j);
				}
			}
		}
		/*
		for (int i = 0; i <= numOfStones; i++)
		{
		std::vector<int>::iterator it = graph.edge[i].begin();
		for (; it != graph.edge[i].end(); it++)
		cout << (*it) << ' ';
		cout << endl;
		}
		*/

		bool* visited = new bool[numOfStones + 2]();
		if (DFS2(&graph, 0, numOfStones + 1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;



		delete[] visited;
	}



	return 0;
}