#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, A[100000];
long long num;

bool find(int s, int e){
	if (s == e && A[s] != num)
		return false;

	int mid = (s + e) / 2;

	if (A[mid] == num)
		return true;
	else if (A[mid] < num)
		return find(mid + 1, e);
	else if (A[mid] > num)
		return find(s, mid);

}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> num;

		if (find(0, N - 1))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}
