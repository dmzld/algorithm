#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){	
	
	int N = 0, var = 0, idx = 0;
	string s;
	string push = "push";
	string pop = "pop";
	string size = "size";
	string empty = "empty";
	string front = "front";
	string back = "back";

	cin >> N;
	vector<int> q(N, 0);
	
	for (int i = 0; i < N; i++){
		cin >> s;

		if (s.compare(push) == 0){
			cin >> var;
			q[idx++] = var; // idx == next push point
		}
		else if (s.compare(pop) == 0){
			if (idx == 0)
				cout << "-1\n";
			else{
				cout << q[0] << "\n";
				for (int j = 1; j < idx; j++)
					q[j - 1] = q[j];
				idx--;
			}

		}
		else if (s.compare(size) == 0){
			cout << idx << "\n";
		}
		else if (s.compare(empty) == 0){
			if (idx == 0)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (s.compare(front) == 0){
			if (idx == 0)
				cout << "-1\n";
			else
				cout << q[0] << "\n";
		}
		else if (s.compare(back) == 0){
			if (idx == 0)
				cout << "-1\n";
			else
				cout << q[idx - 1] << "\n";
		}
	}

	return 0;
}
