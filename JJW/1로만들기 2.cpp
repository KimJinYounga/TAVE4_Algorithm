#include<iostream>
using namespace std;
int dp[1000001];
int one(int num) {	
	int k; //연산 횟 수  TOP-DOWN 방식 
	if (num == 1){ 
		return 0;
	}
	dp[num] = one(num - 1) + 1; //num - 1을 기본적으로 깔고 들어가서 값을 저장시켜놓기 위함
	if (num % 3 == 0){
		k = one(num/3) + 1;
		if (dp[num] > k) //최솟값을 구하기 위해서 값을 비교하고 다시 저장 
		{
			dp[num] = k;
		}
	}
	if (num % 2 == 0)
	{
		k = one(num/2) + 1;
		if (dp[num] > k){
			dp[num] = k;
		}
	}
	return dp[num];
}

int main(){
	ios_base::sync_with_stdio(0);
	int num;
	cin >> num;
	cout << one(num) <<"\n";
	
	return 0;
}


