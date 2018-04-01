#include <iostream>
#include <iomanip>
using namespace std;

void ShellSort(int A[], int N) {
	int Increment; // 储存增量系数 
	int tmp;
	
	// 增量序列递减
	// ht = N / 2
	// hk = hk+1 / 2 
	for(Increment = N / 2; Increment > 0; Increment /= 2) {
		// 分成Increment个组 
		// 给每个组进行插入排序 
		for(int i = Increment; i < N; i++) {
			tmp = A[i];
			int j;
			for(j = i; j >= Increment; j -= Increment) {
				if(tmp < A[j - Increment])
					A[j] = A[j - Increment];
				else
					break;
			}
			A[j] = tmp;
		}
	}
} 

int main() {
	int A[10] = {5, 6, 2, 64, 48, 14, 17, 99, 35, 47};
	ShellSort(A, 10);
	for(int i = 0; i < 10; i++)
		cout << A[i] << "  ";
	cout << endl;
	
	return 0;
} 
