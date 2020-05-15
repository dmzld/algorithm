#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

// 병합 과정
void mergeSort(int start, int mid, int end) {
	vector<int> temp;
	
	int md = mid + 1, st = start;

    // start나 mid가 끝점에 도달하면 종료
	while (start <= mid && md <= end) 
		nums[start] > nums[md] ? temp.push_back(nums[md++]) : temp.push_back(nums[start++]);

    // 나머지 남은 것들을 temp에 쭉 삽입
	while (start <= mid)
		temp.push_back(nums[start++]);
	while (md <= end)
		temp.push_back(nums[md++]);

    // temp에 있는 것을 본래의 nums 벡터로 옮김
	for (int i = st; i <= end; i++)
		nums[i] = temp[i-st];
}

// 분할과정 및 병합 함수 호출
void mergeSortSplit(int start, int end) {	
	if (start < end) {
		int mid = (start + end) / 2;

		mergeSortSplit(start, mid);
		mergeSortSplit(mid+1, end);
		mergeSort(start, mid, end);
	}
}

int main() {
	int n;

	scanf("%d", &n);
	nums.resize(n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);

	mergeSortSplit(0, n-1);
	
	for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++)
		printf("%d\n", *i);

	return 0;
}
