#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

int main(){

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++){
			char tmp;
			cin >> tmp;
			if (tmp == 'F' && (i + j) % 2 == 0)
				ans++;
		}

	cout << ans;

	return 0;
}
