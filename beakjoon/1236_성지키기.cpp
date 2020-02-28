#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool R[50] = { false, }, C[50] = { false, };
int ans = 0;

int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			char tmp;
			cin >> tmp;
			if (tmp == 'X'){
				R[i] = true;
				C[j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			while (C[j])
				j++;
			while (R[i])
				i++;
			if (i >= N || j >= M)
				break;

			R[i] = true;
			C[j] = true;
			ans++;
		}
	}

	for (int i = 0; i < N; i++)
		if (!R[i])
			ans++;
	for (int i = 0; i < M; i++)
		if (!C[i])
			ans++;

	cout << ans;

	return 0;
}
