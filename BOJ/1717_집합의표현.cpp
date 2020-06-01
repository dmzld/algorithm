#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, num[1000001];

int findParent(int n){
	int pN = num[n];
	while (pN != num[pN])
		pN = num[pN];
	return pN;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		num[i] = i; // itself

	for (int i = 0; i < M; i++){
		int c, a, b;
		cin >> c >> a >> b;

		int pA = findParent(a), pB = findParent(b); // compare with the highest parent

		if (c == 0){ // sum
			pA < pB ? num[pB] = pA : num[pA] = pB; // smaller includes bigger
		}
		else if (c == 1){ // check
			if (pA == pB)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
