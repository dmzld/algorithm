#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, K, T;
pair<int, int> map[20][20]; // <shark number, rest of time>
vector<int> smap[20][20]; // distribution of shark in map
int cDir[401]; // current directio of shark (1~4)
int pDir[401][4][4]; // priority of direction of shark (1~4)

pair<int, int> dir[5] = { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

void leaveSmell(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!smap[i][j].empty())
				map[i][j] = { smap[i][j][0], K };
}

void move(){
	vector<int> csmap[20][20]; // current smap;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			if (!smap[i][j].empty()){
				int n = smap[i][j][0]; // shark number
				
				// find no smell, adjacent area
				for (int k = 0; k < 4; k++){
					int nDir = pDir[n][cDir[n] - 1][k]; // 1 ~ 4, not 0

					int ny = i + dir[nDir].first,
						nx = j + dir[nDir].second;

					if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx].first != 0) // out of range || smell already exists
						continue;

					cDir[n] = nDir;
					csmap[ny][nx].push_back(n);
					smap[i][j][0] = -1; // check
					break;
				}

				// can't find area, then go back
				if (smap[i][j][0] != -1){
					for (int k = 0; k < 4; k++){
						int nDir = pDir[n][cDir[n] - 1][k]; // 1 ~ 4, not 0

						int ny = i + dir[nDir].first,
							nx = j + dir[nDir].second;

						if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx].first != n) // out of range || other shark's smell already exists
							continue;

						cDir[n] = nDir;
						csmap[ny][nx].push_back(n);
						break;
					}
				}
			}
		}

	// after moving is over, update smap
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			smap[i][j] = csmap[i][j];	
}

void banish(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (smap[i][j].size() > 1){ // more than one shark
				int min = M + 1;
				for (int k = 0; k < smap[i][j].size(); k++){
					if (min > smap[i][j][k])
						min = smap[i][j][k];
				}
				smap[i][j].clear();
				smap[i][j].push_back(min); // remain shark that have min number

			}
		}
	}
}

bool isOver(){
	int res = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			res += smap[i][j].size();

	if (res == 1)
		return true;
	else
		return false;
}

void smellAway(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			if (map[i][j].first != 0){
				map[i][j].second--;

				if (map[i][j].second == 0)
					map[i][j].first = 0;
			}
		}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			int tmp;
			cin >> tmp;
			map[i][j] = { tmp, 0 };
			if (tmp != 0)
				smap[i][j].push_back(tmp);
		}

	for (int i = 1; i <= M; i++){
		cin >> cDir[i];
	}
		
	for (int i = 1; i <= M; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> pDir[i][j][k];
	
	for (T = 1; T <= 1000; T++){
		leaveSmell();

		move();

		banish();

		if (isOver())
			break;

		smellAway();
	}

	if (T <= 1000)
		cout << T;
	else
		cout << -1;


	return 0;
}
