#include <iostream>
#include <string>
using namespace std;

int main(){

	char s[1000000];
	int a[26] = { 0, };
	int max = 0; // max idx
	bool dup = false;


	scanf("%s", s);

	for (int i = 0; s[i] != NULL; i++){
		if (s[i] > 90){ // 소문자
			a[s[i] - 'a']++;
		}
		else
			a[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++){
		if (a[max] < a[i]){
			dup = false;
			max = i;
		}
		else if (a[max] == a[i] && i != 0){
			dup = true;
		}
	}

	if (dup)
		cout << "?";
	else
		cout << (char)(max + 'A');

	return 0;
}
