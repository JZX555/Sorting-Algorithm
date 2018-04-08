#include <iostream>
#include <string>
using namespace std;

/* 低位优先排序:将字符串进行低位优先排序(试用情况: 字符串的长度相同)
 * 参数:a:参与排序的字符串数组，N:字符串中元素的个数
 * 返回值:无
 */
void LSD(string *a, int N) {
	int W = a[0].length(), R = 256;
	string *Aux = new string[N];
	int *Count = new int[R + 1];

	for (int k = W - 1; k >= 0; k--) {
		// 初始化索引数组
		for (int i = 0; i < R + 1; i++)
			Count[i] = 0;

		// 计算位置k上字符频数
		for (int i = 0; i < N; i++)
			Count[a[i][k] + 1]++;

		// 将频数转换为索引
		for (int i = 0; i < R; i++)
			Count[i + 1] += Count[i];

		// 将元素分类
		for (int i = 0; i < N; i++)
			Aux[Count[a[i][k]]++] = a[i];

		// 回写
		for (int i = 0; i < N; i++)
			a[i] = Aux[i];
	}
	Aux = NULL;
	delete Aux;
	Aux = NULL;
	delete Count;
	Count = NULL;
}