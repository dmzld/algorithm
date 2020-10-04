#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int T, A, B;
bool check[10000];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> A >> B;

		memset(check, false, sizeof(check));
		queue<pair<int,string>> q;
		q.push({ A, "" });
		check[A] = true;

		while (!q.empty()){
			int num = q.front().first;
			string str = q.front().second;
			q.pop();

			if (num == B){
				cout << str << "\n";
				break;
			}

			int nnum;
			// D
			nnum = num * 2;
			if (nnum > 9999)
				nnum %= 10000;
			if (!check[nnum]){
				check[nnum] = true;
				q.push({ nnum, str + 'D' });
			}

			// S
			nnum = num - 1;
			if (nnum == 0)
				nnum = 9999;
			if (!check[nnum]){
				check[nnum] = true;
				q.push({ nnum, str + 'S' });
			}

			// L
			nnum = (num % 1000) * 10 + (num / 1000);
			if (!check[nnum]){
				check[nnum] = true;
				q.push({ nnum, str + 'L' });
			}

			// R
			nnum = (num / 10) + (num % 10) * 1000;
			if (!check[nnum]){
				check[nnum] = true;
				q.push({ nnum, str + 'R' });
			}
		}
	}

	return 0;
}
