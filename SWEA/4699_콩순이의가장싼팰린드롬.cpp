#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int T;
int L, K; // <= 2000, <= 26
int cost[26]; // cost for insert or delete
int mem[2001][2001]; // memozation for min cost to make substring [i] to [j] of str pelindrome
string str;

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++){
		int a, b; // cost for inserting/deleting 'i'th alpabet
		memset(mem, 0, sizeof(int)*L);

		cin >> L >> K >> str;
		for (int i = 0; i < K; i++){
			cin >> a >> b;// inserting and deleting are same operation in palindrome **
			cost[i] = a < b ? a : b; // so save less cost
		}
		
		// init for memozation
		for (int i = 0; i < L; i++){
			mem[i][i] = 0; 
			for (int j = i + 1; j < L; j++)
				mem[i][j] = 987654321; // unknown
		}

		// start from length 1 substring of str
		for (int i = 1; i < L; i++){
			int l = 0, r = i; // substring that have (r-l+1) length
			for (int j = 0; j < L - i; j++){ // for # of substring of length (r-l+1) in str
				if (str[l] == str[r]) // no need to operation
					mem[l][r] = mem[l + 1][r - 1];
				else
					mem[l][r] = min(mem[l][r - 1] + cost[str[r] - 'a'], mem[l + 1][r] + cost[str[l] - 'a']);
				
				l++, r++;
			}
		}

		cout << "#" << tc << " " << mem[0][L - 1] << "\n";		
	}


	return 0;
}
