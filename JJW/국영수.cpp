#include<iostream>
#include<string>
#include<algorithm>
#include<utility> //pair  class
using namespace std;

const int MAX = 100001;
pair<pair<string, int>, pair<int, int> >student[MAX];

bool cmp(pair<pair<string, int>, pair<int, int> >s1,pair<pair<string, int>, pair<int, int> >s2) { //정렬 조건 bool의 반환형 함수 cmp 
    if (s1.first.second > s2.first.second)
                 return true;
        else if (s1.first.second == s2.first.second)
        {
                 if (s1.second.first < s2.second.first)
                         return true;
                 else if (s1.second.first ==s2.second.first)
                 {
                         if (s1.second.second >s2.second.second)
                                 return true;
                         else if(s1.second.second == s2.second.second)
                                 if (s1.first.first < s2.first.first)
                                          return true;
                 }
        }
        return false;
}

int main(void){ 
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
       cin >> student[i].first.first >> student[i].first.second >> student[i].second.first >> student[i].second.second;
	}
    sort(student,student+n,cmp); // 정렬
    
	for(int i= 0; i < n ; i++){
		cout << student[i].first.first <<"\n";
	}
	
	return 0;
}
