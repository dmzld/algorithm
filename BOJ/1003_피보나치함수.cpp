#include <iostream>
#include <queue>
using namespace std;

vector< pair<int, int> > fibo(40, make_pair(-1, -1));
int last;

void num(int N){
	if (N <= last)
		return;
	else{
		for (int i = last + 1; i <= N; i++){
			fibo[i] = make_pair(fibo[i - 1].first+fibo[i-2].first, fibo[i - 1].second+fibo[i-2].second);
		}
		last = N;
	}
}

int main(){

	int T, N;
	fibo[0] = make_pair(1, 0);
	fibo[1] = make_pair(0, 1);
	last = 1;


	cin >> T;

	vector< pair<int, int> > res(T);

	for (int i = 0; i < T; i++){
		cin >> N;
		num(N);
		res[i] = fibo[N];
	}

	for (int i = 0; i < T; i++)
		cout << res[i].first << " " << res[i].second << "\n";

	return 0;
}
