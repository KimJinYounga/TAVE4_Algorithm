#include "iostream"

using namespace std;

// 입력 : 노드의 개수 N, <부모, LN, RN> 
// 출력 : 전위 순회(V-L-R), 중위 순회(L-V-R), 후위 순회(L-R-V) 순서의 노드 
/*
	<따져야 될 것> 
	1. 순회 도중 현재 노드를 빈(empty) 노드로 두고 싶으면 . 입력
	2. 이중배열을 통해 노드를 표현 => 노드 이름[부모 노드][자식 노드]
	3. 알파벳의 아스키 코드를 응용해서 생각해보기 
*/ 

void preorder(int x); 
void inorder(int x); 
void postorder(int x); 

// 이진 트리 배열 생성 
int node[50][2];

int main() {
	int count;
	char x, y, z;
	
	// 총 노드 개수 입력
	cin >> count;
	
	// 부모 >> 왼쪽 자식 >> 오른쪽 자식 입력 
	for(int i = 0; i < count; i++) {

		cin >> x >> y >> z;
		x = x - 'A';

		// 왼쪽 자식 노드 데이터가 없으면 -1 저장
		if(y == '.') {
			node[x][0] = -1;
		}
		// 왼쪽 자식 노드 데이터로 연산 결과를 저장
		else {
			node[x][0] = y - 'A';
		}

		// 오른쪽 자식 노드 데이터가 없ㅇ으면 -1 저장 
		if(z == '.') {
			node[x][1] = -1;
		}
		// 오른쪽 자식 노드 데이터로 연산 결과를 저장 
		else {
			node[x][1] = z - 'A';
		}
	}
	preorder(0);
	cout << endl;

	inorder(0);
	cout << endl;

	postorder(0);
	cout << endl;
	return 0;
}


// 전위 순회 : V - L - R 
void preorder(int x) {
	// 만약 해당 노드의 데이터가 존재하지 않는다면 출력 없이 반환 
	if(x == -1) {
		return;
	}
	
	// 현재 순회하는 노드 출력
	cout << (char)(x + 'A');

	// 왼쪽 -> 오른쪽 노드 순서로 재귀 호출
	preorder(node[x][0]);
	preorder(node[x][1]);
}


// 중위 순회 : L - V - R 
void inorder(int x) {
	if(x == -1) {
		return;
	}
	
	inorder(node[x][0]);
	cout << (char)(x + 'A');
	inorder(node[x][1]);
}


// 후위 순회 : L - R - V 
void postorder(int x) {
	if(x == -1) {
		return;
	}
	
	postorder(node[x][0]);
	postorder(node[x][1]);
	cout << (char)(x + 'A');
}


