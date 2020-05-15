#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int main(){

	int N, M;
	bool flag = true;
	int day = 0;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	cin >> M >> N;
	vector< vector<int> > box(N, vector<int>(M, 0));
	vector< vector<int> > visited(N, vector<int>(M, 0));
	queue< pair<int, int> > q;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> box[i][j];
			if (box[i][j] == 1){
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			else if (box[i][j] == 0)
				flag = false;
		}
	}
	if (flag){
		cout << day;
		return 0;
	}


	while (1){
		queue< pair<int, int> > q2;

		while (!q.empty()){
						
			
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for (int i = 0; i < 4; i++){
				int cx = x + dx[i];
				int cy = y + dy[i];
				
				if (cx<0 || cx>=N || cy<0 || cy>=M)
					continue;
				if (box[cx][cy] != 0 || visited[cx][cy])
					continue;

				box[cx][cy] = 1;
				q2.push(make_pair(cx, cy));
				visited[cx][cy] = 1;
			}
		}
		q = q2;
		if (q.empty())
			break;
		day++;

	}
	

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
			if (box[i][j] == 0)
				day = -1;
	}
	
	cout << day;

	return 0;
}
