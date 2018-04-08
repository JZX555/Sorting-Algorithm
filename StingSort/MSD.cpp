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

/* 小于函数:判断前d位相等的字符串的大小
 * 参数:s1:进行比较的字符串1，s2:进行比较的字符串2，d:不同字符开始出现的索引
 * 返回值:若s1<s2返回true，否则返回false
 */
bool Less(string s1, string s2, int d) {
	return s1.substr(d).compare(s2.substr(d)) < 0;
}

/* 转换函数:返回字符串中对于索引的字符
 * 参数:s:想要进行转换的字符串，i:字符索引
 * 返回值:对应索引的字符，若超出字符串长度返回-1
 */
char CharAt(string s, int i) {
	if (i < s.length())
		return s[i];
	else
		return -1;
}

/* 插入排序:将前d位相同的字符串进行插入排序
 * 参数:a:想要进行插入排序的字符串数组，lo:排序的开始位置，hi:排序的终止位置，d:不同字符出现的索引
 * 返回值:无
 */
void InsertionSort(string *a, int lo, int hi, int d) {
	for (int i = lo; i <= hi; i++)
		for (int j = i; j > lo && Less(a[j], a[j - 1], d); j--)
			exch(a[j], a[j - 1]);
}

/* 高位优先排序驱动
 * 参数:a:进行排序的数组，Aux:用于储存本次排序结果的中间数组，Count:用于储存索引的数组，lo:排序的起始位置，hi:排序终止位置，d:进行排序的字符下标
 * 返回值:无
 */
void MSD(string *a, string *Aux, int *Count,int lo, int hi, int d) {
	int const M = 3, R = 256;

	// 小的子数组进行插入排序
	// 与快速排序相同
	if (hi <= lo + M) {
		InsertionSort(a, lo, hi, d);
		return;
	}

	// 初始化索引数组
	for (int i = 0; i < R + 2; i++)
		Count[i] = 0;

	// 统计频数
	// 特别说明:Count[0]:无用；Count[1]:长度为d的字符串个数；
	for (int i = lo; i <= hi; i++)
		Count[CharAt(a[i], d) + 2]++;

	// 转换频数为索引
	for (int i = 0; i < R + 1; i++)
		Count[i + 1] += Count[i];

	// 数组分类
	for (int i = lo; i <= hi; i++)
		Aux[Count[CharAt(a[i], d) + 1]++] = a[i];

	// 回写
	for (int i = lo; i <= hi; i++)
		a[i] = Aux[i - lo];

	// 递归排序
	// 特别说明:Count[0]:长度为d的字符串索引的终止坐标
	for (int i = 0; i < R; i++)
		MSD(a, Aux, Count, lo + Count[i], lo + Count[i + 1] - 1, d + 1);
}

/* 高位优先排序:将目标字符串进行高位优先排序
 * 参数:a:想要进行高位优先排序的数组，N:数组中元素的个数
 * 返回值:无
 */
void MSD(string *a, int N) {
	int R = 256;
	int *Count = new int[R + 2];
	string *Aux = new string[N];

	MSD(a, Aux, Count, 0, N - 1, 0);

	Aux = NULL;
	delete Aux;
	Aux = NULL;
	delete Count;
	Count = NULL;
}