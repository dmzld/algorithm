#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;


int main(){

	int N = 0, M = 0;
	int cur = 1, tar = 0, idx = 0;
	int count = 0;
	deque<int> dq;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	for (int i = 0; i < M; i++){
		cin >> tar;
		for (int j = 0; j < dq.size(); j++){
			if (dq[j] == tar){
				idx = j; // tar -> idx
			}
		}

		
		if (idx < dq.size() - idx){
			while (dq.front() != tar){
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			dq.pop_front();
		}
		else{
			while (dq.front() != tar){
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
			dq.pop_front();
		}
	}

	cout << count;

	return 0;
}
