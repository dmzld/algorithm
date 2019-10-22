#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(){

	int T = 0, K = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		queue<int> abil;
		int bored = 0;

		scanf("%d", &K);
		for (int j = 0; j < pow(2,K); j++){
			int a;
			scanf("%d", &a);
			abil.push(a);
		}

		while (abil.size() != 1){
			int x, y, z;
			x = abil.front();
			abil.pop();
			y = abil.front();
			abil.pop();
			bored += abs(x - y);
			abil.push(x > y ? x : y);
		}
		
		printf("#%d %d\n", i + 1, bored);
	}
	return 0;
}
