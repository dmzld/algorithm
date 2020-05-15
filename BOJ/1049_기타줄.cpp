#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
int mx = 1000, my = 1000;
int res = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int x, y; // package, piece
		cin >> x >> y;
		if (mx > x)
			mx = x;
		if (my > y)
			my = y;
	}
	
	res = N * my; // only piece
	if (N % 6 > 0 && res > (N / 6 + 1)*mx) // only package
		res = (N / 6 + 1)*mx;
	for (int i = 1; i <= N / 6; i++){
		if (res > mx * i + (N - 6 * i) * my)
			res = mx * i + (N - 6 * i) * my;
	}

	cout << res;

	return 0;
}
