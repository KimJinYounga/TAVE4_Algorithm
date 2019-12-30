#include <iostream>
using namespace std;

int codeFest1(int rank) {
	int rank1 = rank;
	if (rank1 > 21) return 0;
	else if (rank1 == 0) return 0;
	else if (rank1 == 1) return 5000000;
	else if (rank1 >= 2 && rank1 <= 3) return 3000000;
	else if (rank1 >= 4 && rank1 <= 6) return 2000000;
	else if (rank1 >= 6 && rank1 <=10) return 500000;
	else if (rank1 >= 10 && rank1 <=15) return 300000;
	else if (rank1 >=15 && rank1 <=21) return 100000;
}

int codeFest2(int rank) {
	int rank2 = rank;
	if (rank2 > 31) return 0;
	else if (rank2 == 0) return 0;
	else if (rank2 ==1) return 5120000;
	else if (rank2 >= 2 && rank2 <= 3) return 2560000;
	else if (rank2 >= 4 && rank2 <= 7) return 1280000;
	else if (rank2 >= 8 && rank2 <= 15) return 640000;
	else if (rank2 >= 16 && rank2 <= 31) return 320000;
}

int main(void) {
	int t;
	cin >> t; //상상한 횟수 입력

	int a; 
	int b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << codeFest1(a) + codeFest2(b) << endl;
	}
	/*
	for (int i =0; i < t; i++) { //a등, b등 입력
		cin >> a[i] >> b[i];
	}
	cout << endl;

	for (int j = 0; j < t; j++) {
		cout <<( codeFest1(a[j]) + codeFest2(b[j]))<<"\n";
	}
	system("pause");
	*/
	return 0;
}