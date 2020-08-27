#include <iostream>
#include <queue>

using namespace std;

int N, M, F;
int map[21][21];
int Y, X; // location of taxi
pair<int, pair<int, int>> pmap[21][21]; // <passenger number, <location of destination (y,x)>>
bool check[401] = { false, }; // to check passenger was transported

int OUT_OF_RANGE = 21;

int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

bool passengerRemain(){
	for (int i = 1; i <= M; i++){
		if (!check[i])
			return true;
	}
	return false;
}

pair<int, int> findPsg(){
	queue<pair<int, int>> p;
	pair<int, int> minP = { OUT_OF_RANGE, OUT_OF_RANGE };

	bool visited[21][21] = { false, };
	queue<pair<int, int>> q;

	q.push({ Y, X });
	visited[Y][X] = true;

	while (!q.empty() && F > 0){
		F--;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){

			int cy = q.front().first, cx = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++){
				int ny = cy + dy[j], nx = cx + dx[j];

				// out of range, wall, visited
				if (ny <= 0 || ny > N || nx <= 0 || nx > N || map[ny][nx] == 1 || visited[ny][nx])
					continue;

				// find passenger
				if (pmap[ny][nx].first != 0 && !check[pmap[ny][nx].first])
					p.push({ ny, nx });
				// not
				else
					q.push({ ny, nx });

				visited[ny][nx] = true;
			}
		}

		if (!p.empty())
			break;
	}

	while (!p.empty()){
		if (p.front().first < minP.first || (p.front().first == minP.first && p.front().second < minP.second))
			minP = p.front();
		p.pop();
	}

	return minP;
}

bool canArriveDestination(pair<int, int> p){
	int tot = 0; // fuel consuption
	int y = p.first, x = p.second,
		gy = pmap[y][x].second.first, gx = pmap[y][x].second.second;

	bool visited[21][21] = { false, };
	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty() && F > 0){
		tot++;
		F--;
		int qSize = q.size();

		for (int i = 0; i < qSize; i++){
			int cy = q.front().first, cx = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++){
				int ny = cy + dy[j], nx = cx + dx[j];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N || map[ny][nx] == 1 || visited[ny][nx])
					continue;

				if (ny == gy && nx == gx){

					Y = gy, X = gx; // update location of taxi
					F += tot * 2;
					return true;
				}
				else{
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}
	}

	// arriving is impossible
	return false;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> F;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> map[i][j];
		}
	}

	cin >> Y >> X;
	for (int i = 1; i <= M; i++){
		int sy, sx, gy, gx;
		cin >> sy >> sx >> gy >> gx;
		pmap[sy][sx] = { i, { gy, gx } };
	}

	while (passengerRemain()){
		pair<int, int> p;
		
		if (pmap[Y][X].first != 0 && !check[pmap[Y][X].first]) // current loc of taxi == loc of nearest psg
			p = { Y, X };
		else
			p = findPsg(); // find nearest passenger

		if (p.first == OUT_OF_RANGE || !canArriveDestination(p)) // can't find psg || can't reach nearest psg
			break;

		check[pmap[p.first][p.second].first] = true;
	}

	if (passengerRemain())
		cout << -1;
	else
		cout << F;

	return 0;
}
