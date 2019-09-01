#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


int main(){	
	
	int N = 0, K = 0;
	int f = -1;

	cin >> N >> K;
	queue<int> q;

	for (int i = 0; i < N; i++)
		q.push(i + 1);

	cout << "<";
	while (q.size() != 1){
		for (int j = 0; j < K - 1; j++){
			f = q.front();
			q.pop();
			q.push(f);
		}

		cout << q.front() << ", ";
		q.pop();

	}
	cout << q.front() << ">\n";

	return 0;
}
