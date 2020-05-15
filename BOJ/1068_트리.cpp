#include <iostream>
#include <vector>

using namespace std;

int N;
int tree[50]; // not bin tree
int r, d;
int ans = 0;

void deleteNode(int idx){ // idx == parent node num
	for (int i = 0; i < N; i++){
		if (tree[i] == idx){
			tree[i] = -2;
			deleteNode(i);
		}
	}
}

void findChild(int idx){
	int child = 0;
	for (int i = 0; i < N; i++){
		if (tree[i] == idx){
			findChild(i);
			child++;
		}
	}

	if (child == 0){
		ans++;
	}
}

int main(){


	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tree[i];
		if (tree[i] == -1)
			r = i;
	}
		
	cin >> d;
	tree[d] = -2; // delete

	deleteNode(d);
	if (r != d)
		findChild(r);

	cout << ans;

	return 0;
}
