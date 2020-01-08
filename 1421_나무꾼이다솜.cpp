#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int N, C, W; // 나무 개수, 나무 자르는 비용, 나무 한단위의 가격
	// 판매액 = 파는 나무 개수 * 나무의 길이 * 나무 한단위의 가격
	// 이익 = 판매액 - 자른 비용
	int wood[1000], max = 0;
	int res = 0;

	cin >> N >> C >> W;
	for (int i = 0; i < N; i++){
		cin >> wood[i];
		if (max < wood[i])
			max = wood[i];
	}

	for (int l = 1; l <= max; l++){
		int cnt = 0; // 자른 횟수
		int sum = 0; // 잘라서 길이가 l인 나무 개수
		for (int i = 0; i < N; i++){
			if (wood[i] < l) // 작으면 잘라도 불가능
				continue;
			int w = 0, c = 0; // wood, cut

			if (wood[i] % l == 0)
				c = wood[i] / l - 1;
			else
				c = wood[i] / l;
			w = wood[i] / l;

			if (c*C > w*W*l) // 자르는 비용 > 판매 값
				continue;
			else{
				cnt += c;
				sum += w;
			}

		}
		//cout << l << "," << cnt << "," << sum << " = " << W*sum*l - C*cnt<< "\n";

		if (res < W*sum*l - C*cnt)
			res = W*sum*l - C*cnt;
	}
	cout << res;
}
