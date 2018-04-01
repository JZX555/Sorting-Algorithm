#include <iostream>
#include <iomanip>
using namespace std;

/* 合并函数:将已经排好序的两个数组合并成一个有序的数组
 * 返回值:无
 * 参数:A[]:用于排序的数组；tmpArray:用于暂时储存合并结果的数组；LPos:左数组的起始位置；RPos:右数组的起始位置；REnd:右数组的截止位置
 */ 
void Merge(int A[], int tmpArray[], int LPos, int RPos, int REnd) {
	// LEnd:储存左数组的截止位置
	// NumElements:储存元素总个数
	// tmpPos:储存中间数组的位置
	int LEnd, NumElements, tmpPos; 
	
	// 获取其对应的值 
	LEnd = RPos - 1;
	tmpPos = LPos;
	NumElements = REnd - LPos + 1;
	
	// 将有序的两个数组进行合并，直到其中一个合并完成 
	while(LPos <= LEnd && RPos <= REnd) {
		if(A[LPos] < A[RPos])
			tmpArray[tmpPos++] = A[LPos++];
		else
			tmpArray[tmpPos++] = A[RPos++];
	}
	
	// 合并完成另外一个 
	while(LPos <= LEnd)
		tmpArray[tmpPos++] = A[LPos++];
		
	while(RPos <= REnd)
		tmpArray[tmpPos++] = A[RPos++];
	
	// 将中间数组的数据返回给目标数组 
	for(int i = 0; i < NumElements; i++, REnd--)
		A[REnd] = tmpArray[REnd];
}

/* 驱动函数:驱动 MergeSort功能进行
 * 返回值:无
 * 参数:A[]:想要进行排序的数组；tmpArray:用于暂时储存合并结果的数组；Left:进行排序部分的左界；Right:进行排序部分的右界
 */
void MSort(int A[], int tmpArray[], int Left, int Right) {
	// 使用递归的方式对数组进行分治排序 
	// 一直分治递归到重合为止 
	if(Left < Right) {
		int Center = (Left + Right) / 2;
		
		MSort(A, tmpArray, Left, Center); // 对左半部分进行递归排序 
		MSort(A, tmpArray, Center + 1, Right); // 对右半部分进行递归排序 
		
		// 特别说明:
		//     因为 Merge的调用在 MSort最后，所以整个排序过程中只
		// 会有一个程序在调用 tmpArray，避免了程序出错，同时也允许
		// 我们只申请一次内存，可以避免申请内存占用大量的时间！ 
		Merge(A, tmpArray, Left, Center + 1, Right); // 将排序后的部分合并 
	}
}

/* 归并排序:将目标数组进行归并排序
 * 返回值:无
 * 参数:A[]:想要进行排序的数组；N:数组中元素的个数
 */
void MergeSort(int A[], int N) {
	int *tmpArray;
	
	// 申请中间数组 
	tmpArray = new int[N];
	if(tmpArray == NULL)
		cout << "归并排序失败!" << endl;
		
	else {
		// 将目标数组进行分治排序 
		// 并用 tmpArray暂时储存中间结果 
		MSort(A, tmpArray, 0, N - 1); 
		
		// 删除中间数组 
		delete tmpArray;
		tmpArray = NULL;
	}
}

int main() {
	int A[10] = {16, 619, 946 ,316, 497, 4161, 161, 949, 17, 678};
	MergeSort(A, 10);
	
	for(int i = 0; i < 10; i++)
		cout << A[i] << "  ";
	cout << endl;
	
	return 0;
}












