#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){	
	int N, M;
	string s;
	int ans = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> s;

	for (int i = 0; i < s.length() - 2; i++){
		if (s.at(i) == 'I'){
			int cnt = 0;
			while (s.at(i + 1) == 'O' && s.at(i + 2) == 'I'){
				cnt++;
				i += 2;
				if (cnt == N){
					ans++;
					cnt--;
				}
				if (i >= s.length() - 2)
					break;
			}
		}
	}

	cout << ans;

	return 0;
}
