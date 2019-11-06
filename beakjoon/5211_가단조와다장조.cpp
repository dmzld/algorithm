#include <iostream>
#include <string>

using namespace std;

int main(){	
	
	string music;
	int C = 0, A = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> music;

	if (music.at(0) == 'A' || music.at(0) == 'D' || music.at(0) == 'E')
		A++;
	else if (music.at(0) == 'C' || music.at(0) == 'F' || music.at(0) == 'G')
		C++;
	for (int i = 1; i < music.length(); i++){
		if (music.at(i - 1) == '|'){
			if (music.at(i) == 'A' || music.at(i) == 'D' || music.at(i) == 'E')
				A++;
			else if (music.at(i) == 'C' || music.at(i) == 'F' || music.at(i) == 'G')
				C++;
		}
	}

	if (A == C){
		if (music.at(music.length() - 1) == 'A' || music.at(music.length() - 1) == 'D' || music.at(music.length() - 1) == 'E')
			cout << "A-minor";
		else if (music.at(music.length() - 1) == 'C' || music.at(music.length() - 1) == 'F' || music.at(music.length() - 1) == 'G')
			cout << "C-major";
	}
	else if (A>C)
		cout << "A-minor";
	else
		cout << "C-major";
	
	return 0;
}
