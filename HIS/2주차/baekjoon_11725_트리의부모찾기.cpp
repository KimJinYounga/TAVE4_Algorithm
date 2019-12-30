/*
1, 2번 째 시간초과 : endl 대신 "\n" 사용해야한다.
					 시간제한이 1초로 매우 짧기 때문.
					 + 노드 개수 제한이 100,000로 매우 크기 때문에, 2차 배열은 불가능하다.
3번 째 틀렸습니다 : bfs를 통해 꼼꼼히 살펴야되는데 야매로 1차 배열로 퉁치려고함..
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<int> v[100001];
queue<int> tempBfs;
bool visited[100001];
int parent[100001];

void bfs(int start);

// bfs를 통해 같은 높이에 있는 노드먼저 수행하기 위해 대기 노드들을 queue에 넣어서 선입선출하도록 한다.
void bfs2() {
	while (!tempBfs.empty()) {
		int temp = tempBfs.front();
		tempBfs.pop();
		bfs(temp);
	}
}

void bfs(int start) {
	visited[start] = 1;
	while (!v[start].empty()) {
		int next = v[start].back();
		v[start].pop_back();
		if (!visited[next]) {
			parent[next] = start;
			tempBfs.push(next);
		}
	}
	bfs2();
}

int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	bfs(1);
	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";
}

/*
프로세스 구성도
// vector 배열에 먼저 연결된 노드를 모두 입력
1 6 -> v[1] = {6}, v[6] = {1}
6 3 -> v[1] = {6}, v[6] = {1, 3}, v[3] = {6}
3 5	-> v[1] = {6}, v[6] = {1, 3}, v[3] = {5, 6}, v[5] = {3}
...
// 1번 노드부터 시작이므로 1번 노드부터 연결된 모든 노드를 bfs로 탐색
v[1] = {4, 6}
v[2] = {4}
v[3] = {5, 6}
v[4] = {1, 2, 7}
v[5] = {3}
v[6] = {1, 3}
v[7] = {4}

// 탐색할 때, bfs 진입한 순간 visited를 true로 바꾸고, 
// 연결된 노드 중에 visited[next]가 false인 경우 parent[next] = start로 설정해준다.
1부터 쭉 확인 (visited[1] = 1)
1
4		6
-> 4와 6을 bfs로 확인 (visited[4], visited[6] = 1)
					  (parent[4] = 1, parent[6] = 1)
4		6
2, 7	3
-> 2, 7, 3을 bfs로 확인 (visited[2], visited[3], visited[7] = 1)
						(parent[2] = 4, parent[3] = 6, parent[7] = 4)
2		7		3
.		.		5
-> 5를 bfs로 확인 (visited[5] = 1)
					(parent[5] = 3)
*/