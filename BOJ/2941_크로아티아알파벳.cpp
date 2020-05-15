#include <iostream>
#include <cstring>
using namespace std;

int main(){

	char s[100];
	int n = 0;

	scanf("%s", s);

	for (int i = 0; s[i] != NULL; i++){
		if (s[i] == 'c' && s[i + 1] == '='){
			n++; i++;
			continue;
		}
		else if (s[i] == 'c' && s[i + 1] == '-'){
			n++; i++;
			continue;
		}
		else if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '='){
			n++;
			i += 2;
			continue;
		}
		else if (s[i] == 'd' && s[i + 1] == '-'){
			n++; i++;
			continue;
		}
		else if (s[i] == 'l' && s[i + 1] == 'j'){
			n++; i++;
			continue;
		}
		else if (s[i] == 'n' && s[i + 1] == 'j'){
			n++; i++;
			continue;
		}
		else if (s[i] == 's' && s[i + 1] == '='){
			n++; i++;
			continue;
		}
		else if (s[i] == 'z' && s[i + 1] == '='){
			n++; i++;
			continue;
		}
		else{
			n++;
			continue;
		}
	}

	cout << n;

	return 0;
}
