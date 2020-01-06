#include <iostream>
#include <queue>

using namespace std;

int main(){
	int N, cnt = -1;
	long long num; // num는 자연수지만 9876543210보다 클 수 없다
	bool flag = false;
	queue<long long> q;

	cin >> N;

	for (int i = 0; i <= 9; i++){
		if (i == N){
			num = i;
			flag = true;
			break;
		}
		q.push(i);
		cnt++;
	}

	while (!flag){
		int upper = q.front() % 10;
		for (int i = 0; i < upper; i++){
			q.push(q.front() * 10 + i);
			cnt++;
			if (cnt == N){
				num = q.back();
				flag = true;
				break;
			}
			if (q.back() == 9876543210 && N != cnt){
				num = -1;
				flag = true;
				break;
			}
		}
		q.pop();
	}

	cout << num;
}
