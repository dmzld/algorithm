#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int T, N;
string P, arr;

void solution(){
	deque<int> d;
	int R = 0; // %2 == 0 : normal, %2 == 1 : reverse

	for (int i = 0; i < arr.length(); i++){
		if (arr[i] < '0' || arr[i] > '9')
			continue;

		int res = 0;
		while (arr[i] >= '0' && arr[i] <= '9'){
			res = res * 10 + (int)(arr[i] - '0');
			i++;
		}

		d.push_back(res);
	}

	for (int i = 0; i < P.length(); i++){
		if (P[i] == 'R'){
			R++;
		}
		else if (P[i] == 'D'){
			if (d.empty()){
				cout << "error\n";
				return;
			}

			if (R % 2 == 0)
				d.pop_front();
			else
				d.pop_back();
		}
	}

	if (R % 2 == 1)
		reverse(d.begin(), d.end());

	cout << "[";
	while (!d.empty()){
		cout << d.front();
		d.pop_front();

		if (!d.empty())
			cout << ",";
	}
	cout << "]\n";
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> P >> N >> arr;

		solution();
	}

	return 0;
}
