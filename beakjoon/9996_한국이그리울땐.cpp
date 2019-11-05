#include <iostream>
#include <string>

using namespace std;

int main(){	
	
	int N;
	string pattern;
	int star_idx;
	string file_name;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> pattern;

	for (int j = 0; j < pattern.length(); j++){
		if (pattern.at(j) == '*'){
			star_idx = j;
			break;
		}
	}
	for (int i = 0; i < N; i++){
		
		bool incorrect = false;
		
		cin >> file_name;
		
		for (int j = 0; j < star_idx; j++){
			if (j >= file_name.length()){
				incorrect = true;
				break;
			}
			if (pattern.at(j) != file_name.at(j)){
				incorrect = true;
			}
		}
		if (!incorrect){
			int file_idx = file_name.length() - 1; // last idx
			for (int j = pattern.length() - 1; j > star_idx; j--){
				if (file_idx < 0 || file_idx < star_idx){
					incorrect = true;
					break;
				}
				if (pattern.at(j) != file_name.at(file_idx)){
					incorrect = true;
				}
				file_idx--;
			}
		}

		if (incorrect)
			cout << "NE\n";
		else
			cout << "DA\n";
	}



	return 0;
}
