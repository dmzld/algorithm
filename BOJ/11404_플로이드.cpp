#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, a, b, d;
int G[101][101]; // n <= 100 ==> Floyde-Wharshall algorithm can be applied
int INF = 987654321;

int main(){

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			G[i][j] = i == j ? 0 : INF;


	for (int i = 0; i < m; i++){
		cin >> a >> b >> d;
		G[a][b] = min(G[a][b], d);
	}
	
	// F-W algorithm
	for (int p = 1; p <= n; p++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (G[i][j] > G[i][p] + G[p][j])
					G[i][j] = G[i][p] + G[p][j];	
			}
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (G[i][j] == INF)
				cout << "0 ";
			else
				cout << G[i][j] << " ";
		}cout << "\n";
	}cout << "\n";

	return 0;
}
