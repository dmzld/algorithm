#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


int main(){	
	
	int N = 0, var = 0, idx = 0;
	
	cin >> N;

	queue<int> q;

	for (int i = 0; i < N; i++)
		q.push(i + 1);
	
	while (q.size() != 1){
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << "\n";

	return 0;
}
