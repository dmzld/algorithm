#include <iostream>

using namespace std;

int main(){

	char s[100];
	int ans[26];
	for (int i = 0; i < 26; i++)
		ans[i] = -1;

	scanf("%s", s);
	
	for (int i = 0; s[i] != NULL; i++){
		if (ans[s[i] - 'a'] == -1){
			ans[s[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++){
		cout << ans[i] << " ";
	}

	return 0;
}
