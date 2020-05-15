#include <iostream>
#include <string>

using namespace std;

pair<int, int> king, stone; // col, row
int N;
string str;

bool meet(int col, int row){
	if (king.first + col == stone.first&&king.second + row == stone.second)
		return true;
	else
		return false;
}

int main(){
	char tmp, tmp2;
	cin >> tmp >> king.second >> tmp2 >> stone.second;
	king.first = tmp - 'A' + 1;
	stone.first = tmp2 - 'A' + 1;

	cin >> N;
	for (int i = 0; i < N; i++){
		bool move = true;
		cin >> str;

		if (str == "R"){
			if (king.first + 1 <= 8){
				if (meet(1, 0)){
					if (stone.first + 1 <= 8){
						king.first += 1;
						stone.first += 1;
					}
				}
				else{
					king.first += 1;
				}
			}
		}
		else if (str == "L"){
			if (king.first - 1 >= 1){
				if (meet(-1, 0)){
					if (stone.first - 1 >= 1){
						king.first -= 1;
						stone.first -= 1;
					}
				}
				else{
					king.first -= 1;
				}
			}
		}
		else if (str == "B"){
			if (king.second - 1 >= 1){
				if (meet(0, -1)){
					if (stone.second - 1 >= 1){
						king.second -= 1;
						stone.second -= 1;
					}
				}
				else{
					king.second -= 1;
				}
			}
		}
		else if (str == "T"){
			if (king.second + 1 <= 8){
				if (meet(0, 1)){
					if (stone.second + 1 <= 8){
						king.second += 1;
						stone.second += 1;
					}
				}
				else{
					king.second += 1;
				}
			}
		}
		else if (str == "RT"){
			if (king.first + 1 <= 8 && king.second + 1 <= 8){
				if (meet(1, 1)){
					if (stone.first + 1 <= 8 && stone.second + 1 <= 8){
						king.first += 1;
						king.second += 1;
						stone.first += 1;
						stone.second += 1;
					}
				}
				else{
					king.first += 1;
					king.second += 1;
				}
			}
		}
		else if (str == "LT"){
			if (king.first - 1 >= 1 && king.second + 1 <= 8){
				if (meet(-1, 1)){
					if (stone.first - 1 >= 1 && stone.second + 1 <= 8){
						king.first -= 1;
						king.second += 1;
						stone.first -= 1;
						stone.second += 1;
					}
				}
				else{
					king.first -= 1;
					king.second += 1;
				}
			}
		}
		else if (str == "RB"){
			if (king.first + 1 <= 8 && king.second - 1 >= 1){
				if (meet(1, -1)){
					if (stone.first + 1 <= 8 && stone.second - 1 >= 1){
						king.first += 1;
						king.second -= 1;
						stone.first += 1;
						stone.second -= 1;
					}
				}
				else{
					king.first += 1;
					king.second -= 1;
				}
			}
		}
		else if (str == "LB"){
			if (king.first - 1 >= 1 && king.second - 1 >= 1){
				if (meet(-1, -1)){
					if (stone.first - 1 >= 1 && stone.second - 1 >= 1){
						king.first -= 1;
						king.second -= 1;
						stone.first -= 1;
						stone.second -= 1;
					}
				}
				else{
					king.first -= 1;
					king.second -= 1;
				}
			}
		}
	}

	tmp = king.first - 1 + 'A';
	tmp2 = stone.first - 1 + 'A';
	cout << tmp << king.second << "\n";
	cout << tmp2 << stone.second << "\n\n";

	return 0;
}
