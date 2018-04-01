#include <iostream>
#include <iomanip>
using namespace std;

#define Cutoff 3

/* 交换函数:交换两个变量的值
 * 返回值:无
 * 参数:x:参与交换的变量1；y:参与交换的变量2
 */
void Swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

/* 插入排序:对目标数组进行插入排序（升序）
 * 返回值:无
 * 参数:A[]:想要进行排序的数组；N:数组中元素的个数
 */
void InsertionSort(int A[], int N) {
	for(int i = 1; i < N; i++) {
		int j, tmp = A[i];
		for(j = i; j > 0 && A[j - 1] > tmp; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}
}

/* 枢纽元函数:选取规定范围内的枢纽元
 * 返回值:int:选取枢纽元的值
 * 参数:A[]:想要进行选取的数组；Left:选取范围的左边界；Right:选取范围的右边界
 */
int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2; // 储存选取范围的中点 
	
	// 对边界以及中点进行排序
	// 使之满足:A[Left] <= A[Center] <= A[Right]
	if(A[Left] > A[Center])
		Swap(A[Left], A[Center]);
	
	if(A[Left] > A[Right])
		Swap(A[Left], A[Right]);
		
	if(A[Center] > A[Right])
		Swap(A[Center], A[Right]);
	
	// 将枢纽元值进行隐藏 
	Swap(A[Center], A[Right - 1]);
	// 返回枢纽元的值 
	return A[Right - 1]; 
}

/* 驱动函数:对快速选择进行驱动
 * 返回值:无
 * 参数:A[]:想要进行旋转的数组；Left:选取范围的左边界；Right:选取范围的右边界
 */
void QSelect(int A[], int K, int Left, int Right) {
	int Pivot; // 储存枢纽元
	
	// 判断是否需要进行分治递归 
	if(Left + Cutoff <= Right) {
		Pivot = Median3(A, Left, Right); // 获取枢纽元 
		int i = Left, j = Right - 1; // 储存左右指针 
		
		while(true) {
			// 使指针跳过满足要求的值 
			while(A[++i] < Pivot) ;
			while(A[--j] > Pivot) ;
			
			// 将不满足条件的值对换 
			if(i < j)
				Swap(A[i], A[j]);
				
			// 结束 
			else
				break;
		}
		
		Swap(A[i], A[Right - 1]); // 将枢纽元放在对应的位置 
		
		// 若k <= i，表明第k个值在枢纽元左边
		// 反知则在枢纽元的右边
		// 则根据情况对左或对右边在进行排序
		// 直到k == i + 1，也就是枢纽元就是第k个元素 
		if(K <= i)
			QSelect(A, K, Left, i - 1);
			
		else if(K > i + 1)
			QSelect(A, K, i + 1, Right);
	}
	
	// 当元素过扫，直接进行插入排序 
	else
		InsertionSort(A + Left, Right - Left + 1);
}

/* 快速旋转:选择目标数组中指定第K大的元素
 * 返回值:int:选择出的元素
 * 参数:A[]:想要进行选择的元素；K:想要选取的元素的大小排序；N:数组中元素的个数
 */
int QuickSelect(int A[], int K, int N) {
	QSelect(A, K, 0, N - 1); // 进行快速选择驱动 
	
	return A[K - 1]; // 返回对应元素值 
}

int main() {
	int A[10] = {10, 9, 8, 7, 5, 6, 4, 3, 2, 1};
	int x = QuickSelect(A, 6, 10);
	
	cout << x << endl;
}

















