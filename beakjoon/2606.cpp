#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;


int main(){

	int N = 0, P = 0, count = 0;
	stack< pair<int, int> > s; 

	cin >> N >> P;

	vector< vector<int> > parr(N + 1, vector<int>(N + 1, 0)); // 1 ~ N
	vector<int> com(N + 1, 0);
	vector<int> visited(N + 1, 0);

	for (int i = 0; i < P; i++){
		int x, y;
		cin >> x >> y;
		parr[x][y] = 1;
		parr[y][x] = 1;
	}
	visited[1] == 1;
	for (int i = 1; i <= N; i++){
		if (parr[1][i] == 1){
			count++;
			visited[i] = 1;
			s.push(make_pair(1, i));
		}
	}
	while (!s.empty()){
		int x = s.top().first;
		int y = s.top().second;
		s.pop();
		for (int i = 2; i <= N; i++){
			if (parr[y][i] == 1 && visited[i] != 1){
				s.push(make_pair(x, y));
				s.push(make_pair(y, i));
				visited[i] = 1;
				count++;
			}
		}
	}
	
	cout << count;
	
	return 0;
}
