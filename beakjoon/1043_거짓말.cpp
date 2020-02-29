#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int FN;
bool F[50] = { false, };
vector<int> P[50];
queue<int> q;
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> FN;
	for (int i = 0; i < FN; i++){
		int tmp;
		cin >> tmp;
		F[tmp] = true; // friend who knows reality
		q.push(tmp);
	}

	for (int i = 0; i < M; i++){
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++){
			int tmp2;
			cin >> tmp2; // friend who comes 'i' party
			P[i].push_back(tmp2);
		}
	}

	while (!q.empty()){
		int f = q.front();
		q.pop();
		for (int i = 0; i < M; i++){
			for (int j = 0; j < P[i].size(); j++){
				if (P[i][j] == f){ // if one knows
					for (int k = 0; k < P[i].size(); k++){ // then everyone knows
						if (F[P[i][k]] == false){
							F[P[i][k]] = true;
							q.push(P[i][k]);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < M; i++){ // for party
		bool attend = true;
		for (int j = 0; j < P[i].size(); j++){ // for people who comes 'i' party
			if (F[P[i][j]] == true){ // knows reality
				attend = false;
				break;
			}
		}
		if (attend)
			ans++;
	}

	cout << ans;

	return 0;
}
