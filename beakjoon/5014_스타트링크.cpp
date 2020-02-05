#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int F, S, G, U, D; // 건물층, 현재층, 스타트링크층, up버튼, down버튼
bool check[1000001];
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	while (S != G){
		if (check[S])
			break;
		else
			check[S] = true;
		
		ans++;

		if (G > S)
			S += U;
		else
			S -= D;
	}

	if (check[S])
		cout << "use the stairs";
	else
		cout << ans;

	return 0;
}
