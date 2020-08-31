#include <iostream>
#include <stack>

using namespace std;

int T;

int N, op[4]; // +, -, *, /
long long num[12];

stack<long long> s;

void solution(int cnt, int res){
	if (cnt == N){
		s.push(res);
		return;
	}

	for (int i = 0; i < 4; i++){
		if (op[i] > 0){
			op[i]--;

			if (i == 0)
				solution(cnt + 1, res + num[cnt]);
			else if (i == 1)
				solution(cnt + 1, res - num[cnt]);
			else if (i == 2)
				solution(cnt + 1, res * num[cnt]);
			else if (i == 3)
				solution(cnt + 1, res / num[cnt]);
			
			op[i]++;
		}
	}

	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> N;
		for (int i = 0; i < 4; i++)
			cin >> op[i];
		for (int i = 0; i < N; i++)
			cin >> num[i];

		solution(1, num[0]);

		long long min = s.top(), max = s.top();
		s.pop();
		while (!s.empty()){
			if (min > s.top())
				min = s.top();
			if (max < s.top())
				max = s.top();
			s.pop();
		}

		cout << "#" << t << " " << max - min << "\n";
	}

	return 0;
}
