#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main(){

	int N = 0, idx = 0, var = 0;
	string c;
	string push = "push";
	string pop = "pop";
	string size = "size";
	string empty = "empty";
	string top = "top";

	cin >> N;
	vector<int> s(N);

	for (int i = 0; i < N; i++){
		
		cin >> c;
		if (c.compare(push)==0){
			cin >> var;
			s[idx++] = var;
		}
		else if (c.compare(pop) == 0){
			
			if (idx > 0){
				cout << s[--idx] << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else if (c.compare(size) == 0){
			cout << idx << "\n";
		}
		else if (c.compare(empty) == 0){
			if (idx == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (c.compare(top) == 0){
			if (idx == 0)
				cout << -1 << "\n";
			else
				cout << s[idx-1] << "\n";
		}
	}

	return 0;
}
