#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int	N, K, W[101], V[101];
pair<int,int> res[100001][101]; // total weight, value => res[i][j] maximum value at maximum 'i' weight when 'j'th item is considered

// ** it can be solved 1-dimension array

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= K; i++){ // under i weight
		for (int j = 1; j <= N; j++){ // considering j-th item

			if (res[i][j - 1].first + W[j] <= i) // if adding j-th item is possible 
				res[i][j] = { res[i][j - 1].first + W[j], res[i][j - 1].second + V[j] };
			else{
				if (i - W[j] >= 0 && res[i][j - 1].second < res[i - W[j]][j - 1].second + V[j])
					res[i][j] = { res[i - W[j]][j - 1].first + W[j], res[i - W[j]][j - 1].second + V[j] };
				else
					res[i][j] = res[i][j - 1];
			}
		}
	}

	cout << res[K][N].second;

	return 0;
}
