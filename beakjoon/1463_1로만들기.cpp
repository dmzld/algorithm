#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int	N;
vector<int> v;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	v.resize(N + 1);
	v[1] = 0;
	v[2] = 1;
	v[3] = 1;

	for (int i = 4; i <= N; i++){
		v[i] = v[i - 1] + 1;
		if (i % 2 == 0)
			v[i] = min(v[i], v[i / 2] + 1);
		if (i % 3 == 0)
			v[i] = min(v[i], v[i / 3] + 1);
	}

	cout << v[N];

	return 0;
}
