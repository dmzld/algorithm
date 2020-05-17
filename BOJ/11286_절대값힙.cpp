#include <iostream>
#include <queue>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;

int N, num;
priority_queue<int, vector<pair<int, int>>, greater<pair<int,int>>> pq;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> num;
		if (num == 0){
			if (!pq.empty()){
				cout << pq.top().first*pq.top().second << "\n";
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
			pq.push({ abs(num), num / abs(num) }); // abs, sign
	}

	return 0;
}
