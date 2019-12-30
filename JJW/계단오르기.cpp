#include <iostream>
#include <algorithm>
using namespace std;
int stair[300]; // 계단은 300개 이하 
int sum[10000]; // 점수 최대값 
// 맨뒤 계단은 반드시 밟아야한다.
int main(){
	ios_base::sync_with_stdio(0);
	
	int num, i, j; // 계단의 개수 
	cin >> num; 
	for(j = 1; j <= num; j++){
		cin >>stair[j];
	}
	 // 두 가지 경우 중 최댓값이 그 계단까지의 최대 점수가 된다.
    // (1) 현재 계단 밟기, 1 이전 계단 밟기, 2 이전 계단 밟지 않기
    // (2) 현재 계단 밟기, 1 이전 계단 밟지 않기, 2 이전 계단 밟기
    
	for(i = 1; i <= num; i++){ //<=를 해줘야 한다 
		if(i == 1){
			sum[1] = stair[1];
		}
		if(i == 2){
			sum[2] = max(stair[1] + stair[2], stair[2]);
		}
		if(i >= 3){
			sum[i] = max(sum[i-2] + stair[i], sum[i-3] + stair[i-1] + stair[i]);
		}
	}
	cout << sum[num] << "\n"; 
	return 0;
}
