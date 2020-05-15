#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, A[1000], ans = 0;
bool flag = false;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++){ // pivot == the biggest number of series
		vector<int> a, d;

		a.push_back(A[0]);
		for (int j = 1; j <= i; j++){
			if (A[i] < A[j]) continue; // pivot must be the biggest in a
			if (a.back() < A[j])
				a.push_back(A[j]);
			else{
				for (int k = 0; k < a.size(); k++)
					if (a[k] >= A[j]){
						a[k] = A[j];
						break;
					}
			}
		}

		d.push_back(A[i]);
		for (int j = i + 1; j < N; j++){
			if (A[i] < A[j]) continue; // pivot must be the biggest in b
			if (d.back() > A[j])
				d.push_back(A[j]);
			else{
				for (int k = 0; k < d.size(); k++)
					if (d[k] <= A[j]){
						d[k] = A[j];
						break;
					}
			}
		}

		if (ans < a.size() + d.size() - 1)
			ans = a.size() + d.size() - 1;
	}

	cout << ans;

	return 0;
}
