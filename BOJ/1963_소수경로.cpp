#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, n1, n2;
int pn[10000]; // prime number 1000 ~ 9999
bool check[10000];
int ans;

int bfs(){
	int res = 0;
	memset(check, false, sizeof(check));

	queue<int> q;
	q.push(n1);
	check[n1] = true;

	while (!q.empty()){
		res++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int n = q.front();
			q.pop();

			for (int i = 10; i <= 10000; i *= 10){
				for (int j = 0; j <= 9; j++){
					if (i == 10000 && j == 0) continue;

					int nn = (n / i) * i + j * (i / 10);
					if (i >= 100) nn += (n % (i / 10));
					if (pn[nn] != 0 && !check[nn]){
						if (nn == n2)
							return res; // exit

						q.push(nn);
						check[nn] = true;
					}
				}
			}
		}
	}

	return -1;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2; i < 10000; i++)
		pn[i] = i;

	// Sieve of Eratosthenes
	for (int i = 2; i < 10000; i++){
		if (pn[i] == 0) // already checked
			continue;
		for (int j = i + i; j < 10000; j += i) // except i, check multiples of i
			pn[j] = 0; // not prime number
	}

	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> n1 >> n2;

		if (n1 == n2){
			cout << "0\n";
			continue;
		}

		ans = bfs();

		cout << ans << "\n";
	}

	return 0;
}
