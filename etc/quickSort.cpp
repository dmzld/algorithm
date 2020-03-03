#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int num = 10;
int n[10] = { 4, 2, 3, 1, 6, 8, 9, 10, 5, 7 };

void quick(int s, int e){

	if (s >= e)
		return;

	int pivot = s;
	int i = s + 1;
	int j = e;
	int tmp;

	while (i<=j){ // 엇갈리기 전까지
		while (n[i] <= n[pivot])
			i++;
		while (n[j] >= n[pivot] && j > s)
			j--;

		if (i > j){ // 엇갈렸으면 pivot과 j
			tmp = n[pivot];
			n[pivot] = n[j];
			n[j] = tmp;
		}
		else{ // 아니면 i와 j
			tmp = n[i];
			n[i] = n[j];
			n[j] = tmp;
		}
	}

	// j == new sorted element
	quick(s, j - 1); 
	quick(j + 1, e);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	quick(0, 9);

	for (int i = 0; i < 10; i++)
		cout << n[i] << " ";
	cout << "\n";

	return 0;
}
