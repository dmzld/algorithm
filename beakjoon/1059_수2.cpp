#include <iostream>
#include <algorithm>

using namespace std;

int L, LS[50];
int N;
int idx, ans = 0;

int main(){

	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> LS[i];
	cin >> N; // must included

	for (int i = 0; i < L; i++) // N이 unlucky set 일때
		if (LS[i] == N){
			cout << ans;
			return 0;
		}

	sort(LS, LS + L);

	idx = 0;
	while (LS[idx] < N)
		idx++;
	// LS[idx-1] < N <= LS[idx]

	if (idx == 0)
		ans = (LS[idx] - N)*N - 1; // this point
	else
		ans = (LS[idx] - N)*(N - LS[idx - 1]) - 1;

	cout << ans;


	return 0;
}
