#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, G, S, updown[2], check[1000001] = { 0, };
queue<int> q;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> updown[0] >> updown[1];
	updown[1] = -updown[1];

	check[S] = 1;
	q.push(S);
	while (!q.empty()){
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int cs = q.front();
			q.pop();

			if (cs == G){
				cout << check[cs] - 1;
				return 0;
			}

			for (int i = 0; i < 2; i++){
				int ns = cs + updown[i];

				if (ns<1 || ns>F || check[ns] > 0) continue;

				check[ns] = check[cs] + 1;
				q.push(ns);
			}
		}
	}

	cout << "use the stairs";

	return 0;
}
