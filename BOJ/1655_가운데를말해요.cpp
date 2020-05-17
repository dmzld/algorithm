#include <iostream>
#include <queue>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;

int N, num;
priority_queue<int, vector<int>, less<int>> pq1; // max heap (top == mid value)
priority_queue<int, vector<int>, greater<int>> pq2; // min heap

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> num;

		if (i % 2 == 0){
			if (num < pq1.top()){
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(num);
			}
			else
				pq2.push(num);
		}
		else{
			if (pq1.empty())
				pq1.push(num);
			else{
				if (num > pq2.top()){
					pq1.push(pq2.top());
					pq2.pop();
					pq2.push(num);
				}
				else
					pq1.push(num);
			}
		}

		cout << pq1.top() << "\n";

	}

	return 0;
}
