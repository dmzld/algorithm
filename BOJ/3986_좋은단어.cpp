#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){
	int N, ans = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++){
		stack<char> s;
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++){
			if (!s.empty() && s.top() == str.at(j))
				s.pop();
			else
				s.push(str.at(j));
		}
		if (s.empty())
			ans++;
	}
	cout << ans;
	return 0;
}
