#include <iostream>

using namespace std;

int T;

int N, M, map[21][21];
int ans;

void solution(int y, int x){
	for (int k = 1; k <= N + 1; k++){
		int tot = 0, profit = -(k*k + (k - 1)*(k - 1));

		for (int i = y - (k - 1); i < y; i++)
			for (int j = x - (i - (y - (k - 1))); j <= x + (i - (y - (k - 1))); j++)
				if (i >= 1 && i <= N&&j >= 1 && j <= N)
					if (map[i][j] == 1)
						tot++;

		for (int j = x - (k - 1); j <= x + (k - 1); j++)
			if (j >= 1 && j <= N)
				if (map[y][j] == 1)
					tot++;

		for (int i = y + (k - 1); i > y; i--)
			for (int j = x - ((y + (k - 1)) - i); j <= x + ((y + (k - 1)) - i); j++)
				if (i >= 1 && i <= N&&j >= 1 && j <= N)
					if (map[i][j] == 1)
						tot++;


		if (tot > 0){
			profit += tot * M;
			if (profit >= 0 && ans < tot)
				ans = tot;
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		ans = -1;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> map[i][j];

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				solution(i, j);

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}
