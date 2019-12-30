#include<iostream>
#include<queue>
using namespace std;
int n, m, h;
int map[101][101];
int check[101][101];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // up , down, left, right check
void BFS(int,int); 

int main(){
	cin>> n >> m;//input, 맵 표 시 
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
			cout <<map[i][j];
			}
		}	
	BFS(0,0);
	cout << check[n-1][m-1] << endl;
	return 0;
}
void BFS(int x, int y){
	queue<pair<int,int> >q;
	q.push(pair<int, int>(x,y)); //2개의 변수를 저장 할 수 있는 구조 
    check[x][y] = 1; //bfs가 지나가면서 몇번째 만에 그점에 접근했는지 
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
    for(int i = 0; i<4; i++){//상하좌우 네방향 탐색
    		int nx = x + d[i][0];
            int ny = y + d[i][1];
            if(0<=nx && nx<n && 0<= ny && ny<m){
                if(check[nx][ny]==0&&map[nx][ny]==1){
                    q.push(make_pair(nx,ny));// 이전에 방문한 곳 push 
                    check[nx][ny] = check[x][y] + 1;// 이전 방문값 +1 = 다음방문
                }
                else if(check[nx][ny]==0)
                    check[nx][ny] = -1;
            }
	}	
}
}



