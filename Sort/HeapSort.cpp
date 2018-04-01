#include <iostream>
#include <iomanip>
using namespace std;

#define LeftChild(i) (2 * (i) + 1)

/* 重构函数:重构堆
 * 返回值:无
 * 参数:A[]:进行重构的数组；i:想要重构节点的编号；N:堆中元素的个数
 */
void PercDown(int A[], int i, int N) {
	int Child;
	int tmp;
	
	for(tmp = A[i]; LeftChild(i) < N; i = Child) {
		Child = LeftChild(i); // 获取当前节点的左子树的坐标 
		
		// 判断是否需要更新子坐标 
		if(Child != N - 1 && A[Child] < A[Child + 1])
			Child++;
			
		// 大元素上移 
		if(tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	
	A[i] = tmp; // 更新最后的子节点 
}

/* 堆排序
 * 返回值:无
 * 参数:A[]:想要进行排序的数组；N:数组中元素的个数
 */
void HeapSort(int A[], int N) {
	int tmp;
	
	// 将目标数组构建成 Max堆 
	for(int i = N / 2; i >= 0; i--)
		PercDown(A, i, N);
	
	for(int i = N - 1; i > 0; i--) {
		// 进行模拟的DeleteMax操作
		// 将最大元素移动到末尾
		// 堆的大小减一 
		tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		
		// 重构一次堆 
		PercDown(A, 0, i);
	}
}

int main() {
	int A[10] = {15, 51, 61, 32, 99, 7641, 2346, 9787, 656, 135};
	HeapSort(A, 10);
	
	for(int i = 0; i < 10; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}
