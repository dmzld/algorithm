#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, ans = -1;
char seq[9][9];

bool outOfBound(int cr, int cc){
	if (cr < 0 || cr >= N || cc < 0 || cc >= M)
		return true;
	return false;
}

void validate(int num){
	for (int i = (int)sqrt(num) - 1; i <= (int)sqrt(num) + 1; i++)
		if (i*i == num)
			if (num > ans) ans = num;
}

int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int r = 0; r < N; r++){
		for (int c = 0; c < M; c++){
			for (int dr = -N; dr < N; dr++){
				for (int dc = -M; dc < M; dc++){
					if (dr == 0 && dc == 0) continue;
					int res = 0, cr = r, cc = c;

					while (!outOfBound(cr, cc)){
						res = 10 * res + (int)(seq[cr][cc] - '0');
						validate(res);
						cr += dr;
						cc += dc;
					}

				}
			}
		}
	}

		
	cout << ans;

	return 0;
}
