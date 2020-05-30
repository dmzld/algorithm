#include <iostream>
#include <string>

using namespace std;

int N, in[100001], post[100001];
int idx[100001]; // idx of element of inorder

void preorder(int inB, int inE, int postB, int postE){
	if (inB > inE || postB > postE)
		return;

	int root = post[postE];
	cout << root << " ";

	// idx[root] - 1 : size of left sub tree & next last idx of inorder
	// 2 way using size of left or right tree
  
	// idx[root] - inB : size of left sub tree
	// preorder(inB, idx[root] - 1, postB, postB + (idx[root] - inB) - 1); // left
	// preorder(idx[root] + 1, inE, postB + (idx[root] - inB), postE - 1); // right

	// inE - idx[root] : size of right sub tree
	preorder(inB, idx[root] - 1, postB, postE - (inE - idx[root]) - 1); // left
	preorder(idx[root] + 1, inE, postE - (inE - idx[root]), postE - 1); // right


}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> in[i];	
	for (int i = 0; i < N; i++)
		cin >> post[i];
		
	for (int i = 1; i < N; i++)
		idx[in[i]] = i; // used to find out size of sub tree size

	preorder(0, N - 1, 0, N - 1);

	return 0;
}
