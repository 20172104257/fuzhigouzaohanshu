// 构造函数与复制构造函数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
class CComplex {
public:
	double real, imag;
	CComplex() {
		real = 10;
		imag = 20;
		cout << "构造函数" << real << "+" << imag << "i" << endl;
	}
	void setvalue(double r, double i) {
		real = r;
		imag = i;
	}
	CComplex(CComplex & c) {
		real = c.real * 2;
		imag = c.imag * 2;
		cout << "复制构造函数" << real << "+" << imag << "i" << endl;
	}
	void display() {
		cout << real << "+" << imag << "i" << endl;
	}
};
CComplex fun(CComplex ot) {
	ot.display();
	return ot;
}
int main()
{
	CComplex oc1, oc3;
	oc1.display();
	oc1.setvalue(500, 600);
	CComplex oc2(oc1);
	oc2.display();
	oc3 = fun(oc1);//把oc1赋值给fun函数的ot，输出第一行CComplex ot——复制构造函数1000+1200i;之后，
				   //ot.display---1000+1200i;
				   //return ot---在复制构造函数再运行一次，就是复制构造函数2000+2400i;
	oc3.display();
	return 0;
}