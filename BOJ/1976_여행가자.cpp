#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, G[201][201], route[1000];
int conn[201] = { 0, };

int findParent(int n){
	int pN = conn[n];
	while (pN != conn[pN])
		pN = conn[pN];
	return pN;
}

bool arrive(){
	bool arrive = true;

	for (int i = 0; i < M - 1; i++)
		if (conn[route[i]] != conn[route[i + 1]]){
			arrive = false;
			break;
		}
	return arrive;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> G[i][j];

	for (int i = 0; i < M; i++)
		cin >> route[i];

	for (int i = 1; i <= N; i++){
    // need to fix
		// head city of union is the smallest number city
		conn[i] = i;
		for (int j = 1; j <= N; j++){
			if (G[i][j] == 1){ 
				int p = findParent(j);
				conn[i] = conn[i] < p ? conn[i] : p;
			}
		}
	}
		
	if (arrive())
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
