#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int num = 10;
int n[10] = { 4, 2, 3, 1, 6, 8, 9, 10, 5, 7 };
int tmp[10];

void merge(int s, int m, int e){
	int i = s;
	int j = m + 1;
	int k = s;

	while (i <= m && j <= e){
		if (n[i] < n[j])
			tmp[k++] = n[i++];
		else
			tmp[k++] = n[j++];
	}

	if (i <= m)
		while (i <= m)
			tmp[k++] = n[i++];
	else if (j <= e)
		while (j <= e)
			tmp[k++] = n[j++];

	for (int i = s; i <= e; i++)
		n[i] = tmp[i];
}

void divide(int s, int e){
	if (s < e){
		int m = (s + e) / 2;
		divide(s, m);
		divide(m + 1, e);
		merge(s, m, e);
	}
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	divide(0, 9);

	for (int i = 0; i < 10; i++)
		cout << n[i] << " ";
	cout << "\n";

	return 0;
}
