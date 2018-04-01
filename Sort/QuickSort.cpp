#include <iostream>
#include <iomanip>
using namespace std;

#define Cutoff 3

/* 交换函数:交换两个变量的值
 * 返回值:无
 * 参数:x:想要交换的参数1；y:想要交换的参数2
 */ 
void Swap(int &x,int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

/* 插入排序:对数组进行插入排序（升序）
 * 返回值:无
 * 参数:A[]:想要进行排序的数组；N:数组中元素的个数
 */
void InsertionSort(int A[], int N) {
	int tmp;
	
	for(int i = 1; i < N; i++) {
		int j;
		tmp = A[i];
		for(j = i; j > 0 && A[j - 1] > tmp; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}
}

/* 枢纽元函数:选取数组中的枢纽元
 * 返回值:int:该数组选取范围内的枢纽元
 * 参数:A[]:想要选取枢纽元的数组；Left:选取范围的左边界；Rgiht:选取范围的右边界
 */
int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2; // 储存范围的中值 
	
	// 进行边界值与中值的比较与替换
	// 保证: A[Left] <= A[Center] <= A[Right]
	if(A[Left] > A[Center])
		Swap(A[Left], A[Center]);
		
	if(A[Left] > A[Right])
		Swap(A[Left], A[Right]);
		
	if(A[Center] > A[Right])
		Swap(A[Center], A[Right]);
	
	// 将中值与右边界 - 1 替换，因为A[Right]以及保证大于中值 
	// 同时可以对中值进行隐藏 
	Swap(A[Center], A[Right - 1]);
	// 返回中值 
	return A[Right - 1];
}

/* 驱动函数:对快速排序进行驱动
 * 返回值:无
 * 参数:A[]:想要进行排序的数组；Left:排序范围的左边界；Right:排序范围的右边界
 */
void QSort(int A[], int Left, int Right) {
	int Pivot; // 储存枢纽元 
	
	// 判断是否需要进行分治递归排序 
	if(Left + Cutoff <= Right) {
		Pivot = Median3(A, Left, Right); // 获取枢纽元 
		int i = Left, j = Right - 1;
		
		while(true) {
			// 越过满足大小需求的数
			// 注意一种会出错的情况:
			// 		while(A[i] < Pivot) i++;
			//  	while(A[j] > Pivot) j--;
			// 会出现错误，因为当A[i] = A[j] = Pivot时，会无限循环 
			while(A[++i] < Pivot);
			while(A[--j] > Pivot);
			if(i < j)
				Swap(A[i], A[j]); // 交换大小错误的元素 
			else
				break;
		}
		Swap(A[i], A[Right - 1]);
		
		QSort(A, Left, i - 1); // 对左半部分进行分治递归排序 
		QSort(A, i + 1, Right); // 对右半部分进行分治递归排序 
	}
	
	// 范围过小直接进行插入排序 
	else
		InsertionSort(A + Left, Right - Left + 1);
}

/* 快速排序:对目标数组进行快速排序（升序）
 * 返回值:无
 * 参数:A[]:向要进行排序的数组；N:数组中元素的个数
 */
void QuickSort(int A[], int N) {
	QSort(A, 0, N - 1); // 对该数组全范围进行排序 
}

int main() {
	int A[21] = {2, 64, 61, 84, 4, 55, 95, 614, 24, 345, 946, 542, 1, 98, 61, 57, 49, 32, 976, 613, 57};
	QuickSort(A, 21);
	
	for(int i = 0; i < 21; i++)
		cout << A[i] << " ";
	cout << endl;	
}
