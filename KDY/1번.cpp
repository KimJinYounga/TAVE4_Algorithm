#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int t[1001];

int avalue(int rank) {

	if(rank == 1) {
		return 5000000;		
	}
	else if((rank >= 2) && (rank <= 3)) {
		return 3000000;
	}
	else if((rank >= 4) && (rank <= 6)) {
		return 2000000;
	}
	else if((rank >= 7) && (rank <= 10)) {
		return 500000;
	}
	else if((rank >= 11) && (rank <= 15)) {
		return 300000;
	}
	else if((rank >= 16) && (rank <= 21)) {
		return 100000;
	}
	else {
		return 0;
	}
}


int bvalue(int rank) {

	if(rank == 1) {
		return 5120000;		
	}
	else if((rank >= 2) && (rank <= 3)) {
		return 2560000;
	}
	else if((rank >= 4) && (rank <= 7)) {
		return 1280000;
	}
	else if((rank >= 8) && (rank <= 15)) {
		return 640000;
	}
	else if((rank >= 16) && (rank <= 31)) {
		return 320000;
	}
	else {
		return 0;
	}
}


int main() {
	int n;
	cin >> n;

	int sum = 0;
	int a, b;
	
	for(int i = 1; i <= n; i++) {
		// 상금 a와 b 입력 
		cin >> a >> b;
		t[i] += avalue(a);
		t[i] += bvalue(b);
	}
	
	for(int i = 1; i <= n; i++) {
		cout << t[i] << '\n';
	}
	return 0;
}
