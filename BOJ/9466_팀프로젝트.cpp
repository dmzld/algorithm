#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, n, choice[100001], cnt;
bool check[1000001], done[1000001] = { false, };

void solution(int num){
	check[num] = true;

	int nnum = choice[num];

	if (!check[nnum] && !done[nnum])
		solution(nnum);
	else if (check[nnum] && !done[nnum]){
		for (int i = nnum; i != num; i = choice[i]) // ** range is point to shorten the time
			if (check[i]) cnt++;
		cnt++;
	}

	done[num] = true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++){		
		cin >> n;

		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));
		cnt = 0;

		for (int i = 1; i <= n; i++)
			cin >> choice[i];

		for (int i = 1; i <= n; i++){
			if (!done[i]) solution(i);
		}

		cout << n - cnt << "\n";
	}


	return 0;
}
