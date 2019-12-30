#include "pch.h"
#include <iostream>

void josae() {
	int n, k;
	int arr[100] = { 0 };//arr는 다 0으로 초기화
	int count;
	int index = 1; //출력될 숫자
	std::cin>>n>>k;
	std::cout<<"<";
	
	for (int i =0; i < n; i++) {
		count = 0;
		while (1) {
			if (arr[index] == 0)
				count++;
			if (count == k) { //count를 k만큼만 증가하게 함
				arr[index] = -1; 
				if (i == n - 1)
					std::cout<< index<<">"; //더이상 나올 숫자가 없으면 >출력
				else
					std::cout << index; 
				break;
			}
			index++;
			if (index > n)
				index = 1; //숫자를 다시 1로 초기화 시켜서 다시 순회하도록 함
		}
	}
}

int main(void) {
	josae();
}
