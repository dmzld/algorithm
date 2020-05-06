#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

int T, n;
string p, tmp , num = "";
deque<int> arr;


int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> p >> n >> tmp;

		bool error = false;

		for (int i = 0; i < tmp.length(); i++){
			if (tmp[i] >= '0' && tmp[i] <= '9')
				num += tmp[i];
			else if ((tmp[i] == ',' || tmp[i] == ']') && num.length() > 0){
				arr.push_back(stoi(num));
				num = "";
			}
		}

		// check error
		if (n != arr.size())
			error = true;

		int R = 0;
		for (int i = 0; i < p.length(); i++){
			if (p[i] == 'R')
				R++;
			else if (p[i] == 'D'){
        // check error
				if (arr.empty()){
					error = true;
					break;
				}
				if (R % 2 == 1) // reverse
					arr.pop_back();
				else // not reverse
					arr.pop_front();
			}
		}
		if (R % 2 == 1) reverse(arr.begin(), arr.end());

		
		if (error)
			cout << "error\n";
		else{
			if (arr.empty())
				cout << "[]\n";
			else{
				cout << "[";
				for (int i = 0; i < arr.size() - 1; i++)
					cout << arr[i] << ",";
				cout << arr[arr.size() - 1] << "]\n";
			}
		}

		arr.clear();
	}
	
	return 0;
}
