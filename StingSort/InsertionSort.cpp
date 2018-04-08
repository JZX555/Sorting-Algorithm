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