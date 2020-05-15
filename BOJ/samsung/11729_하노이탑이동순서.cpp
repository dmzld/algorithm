#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> v;

void hanoi(int n, int A, int B, int C){
	if (n == 1){
		v.push_back({ A, C });
	}
	else{
		hanoi(n - 1, A, C, B);
		v.push_back({ A, C });
		hanoi(n - 1, B, A, C);
	}
}


int main(){

	cin >> N;

	hanoi(N, 1, 2, 3);

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}
