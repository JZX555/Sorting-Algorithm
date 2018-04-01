#include <iostream>
#include <iomanip>
using namespace std;

// 插入排序 
void InsertionSort(int A[], int N) {
	int tmp;
	
	// 从第二个开始，确保0到i都是有序的 
	for(int j, i = 1; i < N; i++) {
		tmp = A[i];
		for(j = i; j > 0 && tmp < A[j - 1]; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}
}

int main() {
	int A[10] = {5, 61, 51, 7, 18, 91, 56, 420, 47, 19};
	InsertionSort(A, 10);
	for(int i = 0; i < 10; i++)
		cout << A[i] << "  ";
	cout << endl;
	
	return 0;
}
