#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string str[100000], str2[100000];

int main(){

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];

	for (int i = 0; i < N - 1; i++)
		cin >> str2[i];
	
	sort(str, str + N);
	sort(str2, str2 + (N - 1));

	for (int i = 0; i < N - 1; i++){
		if (str[i] != str2[i]){
			cout << str[i];
			return 0;
		}
	}
	cout << str[N - 1];
	return 0;
}
