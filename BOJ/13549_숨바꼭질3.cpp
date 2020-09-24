#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>


using namespace std;

struct comp{ // 커스텀함수
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.first > b.first;
	}
};

int N, K, ans;
bool check[100001] = { false, };


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // <cnt, idx>
	q.push({ 0, N });
	check[N] = true;

	while (!q.empty()){
		int idx = q.top().second, cnt = q.top().first;
		q.pop();

		if (idx == K){
			ans = cnt;
			break;
		}

		if (idx < K){
			if (idx * 2 <= 100000 && !check[idx * 2]){
				check[idx * 2] = true;
				q.push({ cnt, idx * 2 });
			}

			if (idx + 1 <= 100000 && !check[idx + 1]){
				check[idx + 1] = true;
				q.push({ cnt + 1, idx + 1 });
			}
		}

		if (idx - 1 >= 0 && !check[idx - 1]){
			check[idx - 1] = true;
			q.push({ cnt + 1, idx - 1 });
		}
	}

	cout << ans;

	return 0;
}
