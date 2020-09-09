#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos{
	int y, x;
};
struct BC{
	int y, x, C, P;
};

int	T;
int M, nBC;
int A[101], B[101], ax, ay, bx, by;
BC bc[8];
vector<pair<int, int>> av, bv; // <P, BC>
pos dir[5] = { { 0, 0 }, { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int ans;

bool comp(pair<int, int> a, pair<int, int> b){
	return a.first > b.first;
}

void init(){
	cin >> M >> nBC;
	A[0] = 0, B[0] = 0;
	for (int i = 1; i <= M; i++)
		cin >> A[i];
	for (int i = 1; i <= M; i++)
		cin >> B[i];
	for (int i = 0; i < nBC; i++){
		int x, y, C, P;
		cin >> x >> y >> C >> P;
		bc[i] = { y, x, C, P };
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		ans = 0;
		init();

		ay = 1, ax = 1, by = 10, bx = 10;
		for (int i = 0; i <= M; i++){
			ay += dir[A[i]].y, ax += dir[A[i]].x;
			by += dir[B[i]].y, bx += dir[B[i]].x;

			for (int j = 0; j < nBC; j++){
				int ad = abs(ay - bc[j].y) + abs(ax - bc[j].x),
					bd = abs(by - bc[j].y) + abs(bx - bc[j].x);

				// 무선 충전할 수 있는 BC 저장
				if (ad <= bc[j].C)
					av.push_back({ bc[j].P, j });
				if (bd <= bc[j].C)
					bv.push_back({ bc[j].P, j });
			}

			// 충전량이 많은 곳 순으로 정렬
			sort(av.begin(), av.end(), comp);
			sort(bv.begin(), bv.end(), comp);

			// 비교하여 충전
			// 코드 바꿀 필요가 있음
			if (av.empty() && bv.empty()) continue;
			else if (av.empty() && !bv.empty()) ans += bv[0].first;
			else if (!av.empty() && bv.empty()) ans += av[0].first;
			else{
				if (av[0].second == bv[0].second){
					if (av.size() == 1 && bv.size() == 1)
						ans += av[0].first;
					else if (av.size() > 1 && bv.size() == 1)
						ans += av[1].first + bv[0].first;
					else if (av.size() == 1 && bv.size() > 1)
						ans += av[0].first + bv[1].first;
					else
						ans += max(av[0].first + bv[1].first, av[1].first + bv[0].first);
				}
				else{
					ans += av[0].first + bv[0].first;
				}
			}
			av.clear(), bv.clear();
		}

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
