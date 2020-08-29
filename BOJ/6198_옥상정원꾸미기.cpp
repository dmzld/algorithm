#include <iostream>
#include <stack>

using namespace std;

int N, h;
stack<int> s;
long long ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> h;
		if (s.empty() || s.top() > h)
			s.push(h);
		else{
			int popSize = 0;

			while (!s.empty() && s.top() <= h){
				s.pop();
				popSize++;
			}

			// sub stack
			for (int i = popSize - 1; i > 0; i--)
				ans += i;

			// stack
			if (!s.empty()){
				ans += s.size()*popSize;
			}

			s.push(h);
		}
	}
	
	// rest element of stack
	for (int i = s.size() - 1; i > 0; i--)
		ans += i;

	cout << ans;

	return 0;
}
