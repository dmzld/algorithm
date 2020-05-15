#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int heap[200005]; // maximun of element = 100000
int lastIdx = 0; // for heap element

void enqueue(int n){
	int curIdx = ++lastIdx;
	heap[curIdx] = n;

	while (true){ // child > parent
		if (curIdx == 1)
			break;
		
		int parentIdx = curIdx / 2;
		if (heap[curIdx] > heap[parentIdx]){
			int tmp = heap[curIdx];
			heap[curIdx] = heap[parentIdx];
			heap[parentIdx] = tmp;

			curIdx = parentIdx;
		}
		else
			break;
	}
}

int dequeue(){
	if (lastIdx == 0)
		return 0;

	int curIdx = 1;
	int head = heap[curIdx];
	heap[curIdx] = heap[lastIdx];
	heap[lastIdx] = 0;
	lastIdx--;
	
	while (true){
		int nextIdx = heap[curIdx * 2] > heap[curIdx * 2 + 1] ? curIdx * 2 : curIdx * 2 + 1;
		if (heap[curIdx] < heap[nextIdx]){
			int tmp = heap[curIdx];
			heap[curIdx] = heap[nextIdx];
			heap[nextIdx] = tmp;
			curIdx = nextIdx;
		}
		else
			break;
	}

	return head;
}

int main(){

	int N;
	scanf("%d", &N);
	
	while (N--){
		int x;
		scanf("%d", &x);
		if (x == 0){
			int res = dequeue();
			printf("%d\n", res);
		}
		else
			enqueue(x);
	}

	return 0;
}
