#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//程序调用自身的编程技巧称为递归
//递归常见的错误：stack overflow -> 栈溢出
//栈区：局部变量；函数形参
//堆区：动态开辟的内存：malloc；calloc
//静态区：全局变量：static修饰的变量
//函数都在栈区调用空间
//递归的两个必要条件
//1. 存在限制条件，当满足这个限制条件的时候，递归便不再继续
//2. 每次递归调用之后越来越接近这个限制条件


//练习一：接受一个整型值（无符号），按照顺序打印他的每一位，例如：输入：1234， 输出：1 2 3 4 
/*
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	unsigned int num = 0;
	scanf("%d", &num);
	//递归
	print(num);
	//printf(1234)
	//printf(123) 4
	//printf(12) 3 4 
	//printf(1) 2 3 4 
	return 0;
}
*/


//练习二： 编写函数不允许创建临时变量，求字符串的长度
//递归的方法
//把大事化小
//my_strlen("bit");
//1+my_strlen("it");
//1+1+my_strlen("t");
//1+1+1+my_strlen("");
//1+1+1+0
//3
/*
#include <string.h>
int my_strlen(char* str)
{
	if (*str != '\0')
		return 1 + my_strlen(str + 1);//第一个str+1是i；下一个是t ； 然后是\0
	//return 1:输出b  ；下一次return 1：输出i； 下一次return 1：输出t； 然后是返回return 0
	else
		return 0;
}

//这个函数创建了临时变量
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0') 
//	{
//		count++;
//		str++;
//	}
//	return count;
// }

int main()
{
	char arr[] = "bit";
	//int len = strlen(arr);//求字符串长度
	//printf("%d\n", len);
	//模拟实现了一个strlen函数
	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
	printf("len = %d\n", len);
	return 0;
}

*/


//递归与迭代
//练习三：求n的阶乘（不考虑溢出）
/*
int Fac1(int n)//普通方式
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int Fac2(int n)//递归的方式
{
	if (n <= 1)
		return 1;
	else
		return n * Fac2(n - 1);
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fac2(n);  //循环的方式
	printf("%d\n", ret);
	return 0;
}*/


//练习4：求第n个斐波那契数（不考虑溢出)
//斐波那契数列：就是前两个数之和等于第三个数
//1 1 2 3 5 8 13 21 34 55....
/*在这里递归的方法特别耗费时间；不是一个好的计算斐波那契数的方法
int count = 0;
int Fib(int n)
{
	if(n == 3)
	{
		count++; //测试第三个斐波那契数的计算次数
	}
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}*/

//这里用循环计算斐波那契数更快
/*
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	//TDD - 测试驱动开发
	ret = Fib(n);
	printf("ret = %d\n", ret);
	//printf("count = %d\n", count);
	return 0;
}
*/

//递归存在的问题：可能会栈溢出;

