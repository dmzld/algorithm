#include <iostream>
#include <vector>

using namespace std;

int n;
int w[10001];
int res[10001];

int max(int n1, int n2){
	int res;
	if (n1 > n2) res = n1;
	else res = n2;
	return res;
}

int main(){
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	res[1] = w[1];
	res[2] = w[1] + w[2];
	for (int i = 3; i <= n; i++)
		res[i] = max(res[i - 1], max(w[i] + w[i - 1] + res[i - 3], w[i] + res[i - 2]));
	// i번째 와인
	// 안마시면 => i-1까지의 아무조건없이 제일 큰 값
	// 마시면 => i-1번째 마셨을때 : i-2를 건너 뛰고 i-3까지의 아무조건없이 제일 큰 값
	//			i-1번째 안마셨을때 : i-2까지의 아무조건없이 제일 큰 값

	cout << res[n];

	return 0;
}
