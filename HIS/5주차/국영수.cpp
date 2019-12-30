#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N;
pair < pair<string, int>, pair<int, int>> v[100000];

/*
error1 : pair 자료형이 아닌 vec를 사용하면 불편하다. pair배열도 자료형으로써 쓸만함을 알게됨

error2 : "\n"을 생활화하자. endl쓰지말자. 조건문을 많이 써서 시간초과가 발생한 줄 알았는데, 이 문제였다.

배운 점1 : comp 함수는 2가지 방식으로 구현할 수 있다.
  아래 코드에서 comp, comp2 두 가지 방식 모두 정답이다.
  comp는 pair배열의 원소 중 하나의 값에 대해 같지 않은 경우, 조건에 따라 정렬
  comp2는 조건에 따라 정렬한 뒤, 같은 경우에 대해 다음 조건으로 넘어가는 방식
  논리적으로는 comp가 더 조건문도 적어서 빠를 듯 하다.
  // comp 함수는 return 내의 논리에 대해 해당 논리가 true가 되도록 정렬한다고 이해하면 좋다.

  배울 점2 : c++의 cin, cout은 그 속도가 느리다는 것은 익히 유명하다. 
  해당 문제를 풀면서 시간 초과가 많이 발생해서 조사한 결과 (물론 "\n"문제였지만)
  c의 printf, scanf를 굳이 사용하지 않고도, cin, cout의 속도를 단축시키는 코드를 찾았다.
  [code]
  ios_base::sync_with_stdio(0); // 168ms->92ms
  cin.tie(0);					// 168ms->168ms (이것만으로는 단축효과 x)
  둘 다 사용하는 경우			// 168ms->88ms
  [/code]
  제한시간이 1초라는 점에서 88ms를 단축하는것은 큰 문제가 아니므로, 해당 문제에서는 큰 소용이 없지만
  외워둔다면 쓸모가 있을것으로 보인다.
*/

/*
시간 단축 코드에 대한 이해
ios_base::sync_with_stdio(0)	= cpp의 iostream을 c의 stdio와 동기화시키는 역할.
								  본래는 iostream, stdio의 버퍼를 모두 사용해서 딜레이가 발생하는데,
								  0, 즉, false로 설정하면 c++만의 독립적인 버퍼가 생성된다.
cin.tie(0)						= cin이 뒤에 cout 나오더라도 cin을 먼저하게하는 코드라는 것 같다.
								  실질적으로 쓰일지는 모르겠다. 위에것만 외워두자.
*/

bool comp(pair < pair<string, int>, pair<int, int>> a, pair < pair<string, int>, pair<int, int>> b) {
	if (a.first.second != b.first.second)
		return a.first.second > b.first.second;
	else {
		if (a.second.first != b.second.first)
			return a.second.first < b.second.first;
		else {
			if (a.second.second != b.second.second)
				return a.second.second > b.second.second;
			else {
				return a.first.first < b.first.first;
			}
		}
	}
}

bool comp2(pair < pair<string, int>, pair<int, int>> a, pair < pair<string, int>, pair<int, int>> b) {
	if (a.first.second > b.first.second)
		return true;
	else if (a.first.second == b.first.second) {
		if (a.second.first < b.second.first)
			return true;
		else if (a.second.first == b.second.first) {
			if (a.second.second > b.second.second)
				return true;
			else if (a.second.second == b.second.second) {
				if (a.first.first < b.first.first)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string ts;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	sort(v, v + N, comp);
	for (int i = 0; i < N; i++)
		cout << v[i].first.first << "\n";
}

/*
1. 국어는 내림차순
2. 영어는 오름차순
3. 수학은 내림차순
4. 이름은 사전순, 대문자는 소문자보다 앞에 온다.
*/