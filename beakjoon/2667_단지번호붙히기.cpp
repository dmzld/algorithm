#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int main(){

	int N, v = 0;
	char c;
	vector< vector<int> > a(25, vector<int>(25, 0)); // 아파트
	vector< vector<int> > visited(25, vector<int>(25, 0)); // mark
	queue< pair<int,int> > q;
	vector<int> num(25*25/2 + 1,0); // n단지의 아파트 개수 == num[n-1]

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	
	cin >> N; // 5<=N<=25
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> c;
			a[i][j] = c - 48;
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (a[i][j] == 1 && visited[i][j] == 0){
				
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				num[v]++;
				
				while (!q.empty()){

					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++){
						int cx = x + dx[k];
						int cy = y + dy[k];

						if (cx >= N || cx < 0 || cy >= N || cy < 0)
							continue;
						if (a[cx][cy] != 1 || visited[cx][cy] == 1)
							continue;

						q.push(make_pair(cx, cy));
						visited[cx][cy] = 1;
						num[v]++;
					}
				}v++;
			}
		}
	}

	sort(num.begin(), num.end());
	cout << v << "\n";
	for (int i = 0; i < num.size(); i++){
		if (num[i] != 0)
			cout << num[i] << "\n";
	}
	

	return 0;
	
}
