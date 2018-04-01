#include <iostream>
#include <iomanip>
using namespace std;

/* 驱动函数:对桶排序进行驱动
 * 返回值:无
 * 参数:A[]:想要进行排序的数组；tmpArray[]:用于排序的桶；Max:数组中的最大元素；N:数组中的元素个数
 */
void BSort(int A[], int tmpArray[], int Max, int N) {
	// 将所有的元素放入排序桶中 
	for(int i = 0; i < N; i++)
		tmpArray[A[i]]++;
	
	// 将桶中的元素取出放回原数组
	// 因为放入桶中时就已经被排序
	// 所以只需要按顺序取出并放回原数组，就已经排好序 
	int index = 0;
	for(int i = 0; i < Max + 1; i++) {
		for(int j = 0; j < tmpArray[i]; j++) {
			A[index] = i;
			index++;
		}
	}
}

/* 桶排序:对目标数组进行桶排序
 * 返回值:无
 * 参数:A[]:想要进行桶排序的数组；N:数组中元素的个数
 */
void BucketSort(int A[], int Max, int N) {
	// 申请桶数组
	// 并对其进行初始化 
	int *tmpArray = new int[Max + 1];
	for(int i = 0; i < Max + 1; i++)
		tmpArray[i] = 0;
	
	// 进行桶排序驱动 
	BSort(A, tmpArray, Max, N);
	
	// 删除桶数组 
	delete tmpArray;
	tmpArray = NULL;
}

int main() {
	int A[10] = {3, 5, 1, 2, 9, 8, 4, 7, 6, 10};
	BucketSort(A, 10, 10);
	
	for(int i = 0; i < 10; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}













