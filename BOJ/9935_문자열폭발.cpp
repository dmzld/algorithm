#include <iostream>
#include <string>

using namespace std;

string str, bomb;
char ans[1000000];

int main(){

	cin >> str >> bomb;

	int idx = 0;
	for (int i = 0; i < str.length(); i++){
		ans[idx++] = str.at(i);
		
		if (ans[idx - 1] == bomb.at(bomb.length() - 1) && idx - bomb.length() >= 0 ){ // if end syntaxes are equal
			
			bool flag = true;
			
			for (int j = 0; j < bomb.length(); j++){
				if (ans[idx - bomb.length() + j] != bomb.at(j)){
					flag = false;
					break;
				}
			}

			if (flag){
				idx -= bomb.length();
			}
		}
	}

	if (idx == 0)
		cout << "FRULA\n";
	else{
		for (int i = 0; i < idx; i++)
			cout << ans[i];
	}

	return 0;
}
