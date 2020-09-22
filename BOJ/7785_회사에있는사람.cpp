#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int N;
string name, state;
set<string> s;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> name >> state;
		if (state == "enter")
			s.insert(name);
		else if (state == "leave")
			s.erase(name);
	}

	for (auto it = s.rbegin(); it != s.rend(); it++)
		cout << *it << "\n";

	return 0;
}
