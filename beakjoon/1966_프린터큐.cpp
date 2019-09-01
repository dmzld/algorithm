#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


int main(){	
	
	int T = 0, N = 0, M = 0;
	int input = -1, p = 0;
	int max = 0;

	int arr[9] = { 0, };
	
	cin >> T;

	for (int i = 0; i < T; i++){
		queue<int> q;
		priority_queue<int> q2;
		cin >> N >> M;

		for (int j = 0; j < N; j++){
			cin >> input;
			q.push(input);
			q2.push(input);
		}
		while (1){
			// no print
			if (q2.top() > q.front()){
				input = q.front();
				q.pop();
				q.push(input);
				if (M > 0)
					M--;
				else
					M = q.size() - 1;
			}
			// print
			else{ // top <= front
				p++;
				if (M == 0)
					break;
				else{
					q.pop();
					q2.pop();
					M--;
				}
			}
		}
		cout << p << "\n";
		p = 0;
	}
	
	return 0;
}
