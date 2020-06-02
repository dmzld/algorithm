#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, G[201][201], route[1000];
int conn[201] = { 0, };

int findHead(int n){
	int hN = conn[n];
	while (hN != conn[hN])
		hN = conn[hN];
	return hN;
}

bool arrive(){
	bool arrive = true;

	for (int i = 0; i < M - 1; i++)
		if (findHead(route[i]) != findHead(route[i + 1])){
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

	for (int i = 1; i <= N; i++)
		conn[i] = i;

	for (int i = 1; i <= N; i++){
		// head city of union is the smallest number city
		for (int j = 1; j <= N; j++){
			if (G[i][j] == 1){ 
				int p = findHead(i),
				    q = findHead(j);

				// connect head to head
				if (p < q) conn[q] = p;
				else conn[p] = q;
			}
		}
	}
		
	if (arrive())
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
