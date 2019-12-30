#include <iostream>
using namespace std;
int dp[11]; //n은 양수이며 11보다 작다.
int recursive(int n){
    if(n == 1){ // 1의 경우의 수 1 => 1개
        return 1;
    }
    if(n == 2){ // 2의 경우의 수 1+1, 2 => 2개
        return 2;
    }
    if(n == 3){  // 3의 경우의 수 1+1+1, 1+2, 2+1, 3 => 4개
        return 4;
    }
    if(dp[n]){
       return dp[n] = recursive(n-1) + recursive(n-2) + recursive(n-3);
    }
    //N 값이 4가 들어 오게 되면 최종적으로 1,2,3 을 만났을 경우 그 값을 리턴하게 된다면 그 경우의 수들이 모두 저장되게
}
int main(){
	ios_base::sync_with_stdio(0);
    int num, n ,result ;
    cin >> num;
    while(num >= 1){
        cin >> n;
        for(int i = 4; i <= n; i++){
        result = recursive(n-1);
    	}
        cout << result << "\n";
        num--;
    }
    return 0;
}
