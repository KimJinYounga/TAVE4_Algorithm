#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;


void dfs (int start, vector<int> graph[], bool check[]) {
	check[start] = true;
	printf("%d",start); 
	
	for(int i=0; i<graph[start].size(); i++){
		int next = graph[start][i]; 
		if(check[next]==false){ //방문하지 않았다면 
			dfs(next, graph, check); //재귀함수 호출 
		}
	}
}

int main(void) {
	
	int n, m, start;
	cin>>n, m, start; 
	
	vector<int>graph[n+1];
	bool check[n+1];
	fill(check, check+n+1, false);
	
	for(int i =0; i<m; i++){
		int u, v;
		cin>>u,v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1; i<=n; i++){
		sort(graph[i].begin(),graph[i].end());
	}
	
	dfs(start, graph, check);
	printf("\n");
}
