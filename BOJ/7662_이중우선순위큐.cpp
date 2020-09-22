#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int T, K;
long N;
char O;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	for (int t = 0; t < T; t++){

		multiset<long> s;
		cin >> K;
		for (int i = 0; i < K; i++){
			cin >> O >> N;

			if (O == 'I'){
				s.insert(N);
			}
			else if (O == 'D'){
				if (s.empty())
					continue;

				if (N == 1){
        // iterator는 기본 iterator와 reverse_iterator가 있고 서로 assign할 수 없다.
        // 따라서 multiset의 마지막 원소만 지우기 위해선 end()--; 로 따로 연산을 해줘야함(마지막 원소가 중복되면 다 지워지기 때문에)
					multiset<long>::iterator it = s.end();
					it--;
					s.erase(it);
				}
				else if (N == -1){
					s.erase(s.begin());
				}
			}
		}

		if (s.empty())
			cout << "EMPTY\n";
		else{
			cout << *s.rbegin() << " " << *s.begin() << "\n";
		}
	}
	return 0;
}
