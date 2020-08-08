#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
char map[10][10];
pair<int, int> red, blue, exitMaze = { -1, -1 };

queue <pair<pair<int, int>, pair<int, int>>> q;
int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
int cnt = 0;

pair<int, int> roll(pair<int, int> ball, int cDy, int cDx){
	while (map[ball.first + cDy][ball.second + cDx] != '#' && map[ball.first + cDy][ball.second + cDx] != 'O')
		ball.first += cDy, ball.second += cDx;

	if (map[ball.first + cDy][ball.second + cDx] == 'O')
		return make_pair(-1, -1);
	else
		return ball;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 'R'){
				map[i][j] = '.';
				red = { i, j };
			}
			else if (map[i][j] == 'B'){
				map[i][j] = '.';
				blue = { i, j };
			}
		}
	}

	q.push({ red, blue });
	while (cnt < 10){
		cnt++;
		bool check[10][10][10][10] = { false, };

		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			pair<int, int> cRed = q.front().first;
			pair<int, int> cBlue = q.front().second;
			q.pop();
				
			for (int j = 0; j < 4; j++){
				pair<int,int> nRed = roll(cRed, dy[j], dx[j]);
				pair<int,int> nBlue = roll(cBlue, dy[j], dx[j]);

				if (nBlue == exitMaze){ // blue ball exit
					continue;
				}
				else if (nRed == exitMaze){ // only red ball exit
					cout << cnt << "\n";
					return 0;
				}
				else{ // not exit
					if (nRed == nBlue){
						if (dy[j] == 0){
							if (cRed.second * dx[j] > cBlue.second * dx[j])
								nBlue.second -= dx[j];
							else if (cRed.second * dx[j] < cBlue.second * dx[j])
								nRed.second -= dx[j];
						}
						else if (dx[j] == 0){
							if (cRed.first * dy[j] > cBlue.first * dy[j])
								nBlue.first -= dy[j];
							else if (cRed.first * dy[j] < cBlue.first * dy[j])
								nRed.first -= dy[j];
							
						}
					}
					if (!check[nRed.first][nRed.second][nBlue.first][nBlue.second]){
						check[nRed.first][nRed.second][nBlue.first][nBlue.second] = true;
						q.push({ nRed, nBlue });

						//cout << nRed.first << nRed.second << nBlue.first << nBlue.second << "\n";
					}
				}
			}
		}
	}

	cout << -1;

	return 0;
}
