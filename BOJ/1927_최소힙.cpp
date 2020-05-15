#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> pq; // T, Container, Compare

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> x;
		if (x == 0){
			if (pq.empty())
				cout << "0\n";
			else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else{
			pq.push(x);
		}
	}


	return 0;
}
