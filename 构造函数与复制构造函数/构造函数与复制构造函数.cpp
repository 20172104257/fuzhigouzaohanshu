// 构造函数与复制构造函数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Ccomplex
{
public:
	int real, image;
	Ccomplex()
	{
		real = 100;
		image = 200;
		cout << "默认函数" << real << "+" << image << endl;
	}
	void setvalue(int a, int b)
	{
		real = a;
		image = b;
	}
	Ccomplex(const Ccomplex &x)
	{
		real = x.real * 2;
		image = x.image * 2;
		cout << "复制构造函数" << real << "+" << image << endl;
	}
	void display()
	{
		cout << real << "+" << image << endl;
	}
};
Ccomplex fun(Ccomplex ot)
{
	ot.display();
	return ot;
}
int main()
{
	Ccomplex os1, ot;     //默认函数100+200
						  //默认构造函数100+200
	os1.display();        //100+200
	os1.setvalue(30, 40);
	os1.display();        //30+40
	Ccomplex os2(os1);    //复制构造函数60+80
	os2.display();        //60+80
	fun(os2);             //复制构造函数120+160
						  //120+160 
						  //复制构造函数240+320
	Ccomplex os3;         //默认函数100+200
	os3 = fun(os2);       //复制构造函数120+160
						  //120+160
						  //复制构造函数240+320
	os3.display();        //240+320
	return 0;
}