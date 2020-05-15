#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
int N;
struct Info{
	int age;
	string name;
	int num;
};
vector<Info> p;

bool cmp(Info a, Info b){
	if (a.age == b.age)
		return a.num < b.num;
	return a.age < b.age;
}

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++){
		int age;
		string name;
		cin >> age >> name;

		p.push_back({ age, name, i });
	}

	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < N; i++)
		cout << p[i].age << " " << p[i].name << "\n";

	return 0;
}
