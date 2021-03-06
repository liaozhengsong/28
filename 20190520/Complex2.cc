 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-20 11:16:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

// <<重温微积分>>
// <<随机过程>>
// <<矩阵论>>
// <<机器学习>>
// <<计算理论>>
class Complex
{
public:
	Complex(double real, double image)
	: _real(real)
	, _image(image)
	{}

	void print() const
	{
		cout << _real << " + " << _image << "i" << endl;
	}

	friend Complex operator+(const Complex & lhs, const Complex & rhs);
private:
	double _real;
	double _image;// -1 = i ^ 2
};

//内置类型数据的运算符无法重载
//int operator+(int x, int y)
//{
//	return x - y;
//}

//运算符重载之友元函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	cout << "friend Complex operator+()" << endl;
	return Complex(lhs._real + rhs._real, 
			       lhs._image + rhs._image);
}
 
int main(void)
{
	Complex c1(1, 2);
	Complex c2(3, 4);

	Complex c3 = c1 + c2;
	c3.print();

	return 0;
}
