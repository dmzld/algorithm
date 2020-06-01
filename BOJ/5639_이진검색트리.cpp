#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int N, tmp, pre[10000];

void post(int begin, int end){ // [start, end)
	if (begin == end) // for no input case
		return;

	if (begin == end - 1){
		cout << pre[begin] << "\n";
		return;
	}
	
	int idx = begin + 1;
	while (idx < end && pre[idx] < pre[begin]) // find right sub tree' root (pre[begin] == cur tree's root
		idx++;

	post(begin + 1, idx);
	post(idx, end);
	cout << pre[begin] << "\n";
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	N = 0;
	while (cin >> tmp)
		pre[N++] = tmp;

	post(0, N);


	return 0;
}
