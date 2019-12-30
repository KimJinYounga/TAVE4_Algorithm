#include "pch.h"
#include <iostream>
using namespace std;

struct node
{
	char left;
	char right;
};

struct node arr[100];

void preOrder(char root) //전위순회
{
	if (root == '.') //노드에 값이 없다면 RETURN한다
		return;
	else {			
		cout << root;
		preOrder(arr[root].left);
		preOrder(arr[root].right);
	}
}

void inOrder(char root) //중위순회
{
	if (root == '.')
		return;
	else {
		inOrder(arr[root].left);
		cout << root;
		inOrder(arr[root].right);
	}
}

void postOrder(char root) //후위순회
{
	if (root == '.')
		return;
	else {
		postOrder(arr[root].left);
		postOrder(arr[root].right);
		cout << root;
	}
}



int main() {
	int n;
	cin >> n; //노드의 갯수 입력받기

	char t1, t2, t3;

	for (int i = 1; i <= n; i++) //노드의 값을 갯수만큼 입력받는다.
	{
		cin >> t1 >> t2 >> t3;
		arr[t1].left = t2;
		arr[t1].right = t3;
	}

	preOrder('A'); 
	cout << "\n";
	inOrder('A');
	cout << "\n";
	postOrder('A');
	cout << "\n";

}