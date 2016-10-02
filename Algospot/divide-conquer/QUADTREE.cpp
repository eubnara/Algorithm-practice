#include <iostream>
#include <list>
using namespace std;

class node{
public:
	char color;
	list<node*> children;

public:
	node() : color(0)
	{}
};
//재귀적으로 입력을 받기위한 함수
node* getInput();

//상하반전을 해주는 함수
void turnOver(node& start);

//결과물 프린트하는 함수, 동적할당 반환도 여기서 처리
void printAll(node& start);

//동적할당 반환하는 함수
//void deallocate(node& start);

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		node* start;
		start = getInput();
		turnOver(*start);
		printAll(*start);
		cout << endl;
	}

	return 0;
}

node* getInput() {
	char c;
	node* newNode = new node();

	do{
		cin.get(c);
	} while ('\n' == c);

	if ('w' == c || 'b' == c){
		newNode->color = c;
	}
	else if('x' == c) {
		newNode->color = c;
		for (int i = 0; i < 4; i++) {
			newNode->children.push_back(getInput());
		}
	}
	return newNode;
}

void turnOver(node& start){
	if ('x' == start.color) {
		for (list<node*>::iterator it = start.children.begin(); it != start.children.end(); it++){
			turnOver(*(*it));	//*it ==> node*
		}
		//(1,3) (2,4) 자리바꾸기
		node* tmp;
		tmp = start.children.front();
		start.children.pop_front();
		start.children.push_back(tmp);

		tmp = start.children.front();
		start.children.pop_front();
		start.children.push_back(tmp);
	}
}

void printAll(node& start) {
	char c = start.color;
	if ('w' == c || 'b' == c){
		cout << c;
	}
	else if ('x' == c) {
		cout << c;
		for (int i = 0; i < 4; i++) {
			node* tmp;
			tmp = start.children.front();
			start.children.pop_front();
			printAll(*tmp);
		}
	}
	delete &start;
}


/*
void deallocate(node& start) {
	if ('x' == start.color){
		for (list<node*>::iterator it = start.children.begin(); it != start.children.end(); it++){
			deallocate(*(*it));	//*it ==> node*
		}
	}
	else{
		delete &start;
	}		
}
*/
