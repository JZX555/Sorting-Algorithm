#include <iostream>
#include <string>
using namespace std;

/* 交换函数:交换两个字符串
 * 参数:s1:进行交换的字符串1，s2:进行交换的字符串2
 * 返回值:无
 */
void exch(string &s1, string &s2) {
	string tmp = s1;
	s1 = s2;
	s2 = tmp;
}

/* 三向快速排序驱动
 * 参数:a:进行排序的数组，lo:排序的起始位置，hi:排序的终止位置，d:进行排序的字符下标
 * 返回值:无
 */
void Quick3Sort(string *a, int lo, int hi, int d) {
	// 排序终止条件
	if (hi <= lo)
		return;

	// lt:小子串的结束位置，gt:大子串的开始位置
	// v:枢纽元
	int lt = lo, gt = hi;
	int v = CharAt(a[lo], d);
	int i = lo + 1;

	// 以枢纽元为界进行区分
	while (i <= gt) {
		int t = CharAt(a[i], d);
		if (t < v)
			exch(a[lt++], a[i++]);
		else if (t > v)
			exch(a[i], a[gt--]);
		else
			i++;
	}

	// 对小子串进行排序
	Quick3Sort(a, lo, lt - 1, d);
	// 对当前字符串进行进一步排序
	if (v >= 0)
		Quick3Sort(a, lt, gt, d + 1);
	// 对大子串进行排序
	Quick3Sort(a, gt + 1, hi, d);
}

/* 三向快速排序:对目标数组进行三向快速排序
 * 参数:a:进行排序的字符串数组，N:字符串的个数
 * 返回值:无
 */
void Quick3Sort(string *a, int N) {
	Quick3Sort(a, 0, N - 1, 0);
}