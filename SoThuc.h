#pragma once
#include<iostream>
#include "SoNguyen.h"
using namespace std;
#include<string>
class CSoThuc
{
public:
	string a;
	//hàm khởi tạo
	CSoThuc();
	CSoThuc(string b);
	CSoThuc(CSoThuc& x);
	CSoThuc(CSoNguyen& x);
	CSoThuc(int x);
	CSoThuc(double x);
	CSoThuc(string b,string c);
	CSoThuc(int x, int y);
	CSoThuc(CSoNguyen& x, CSoNguyen& y);
	
	//hàm hũy
	~CSoThuc();

	//Ham Lay can
	CSoThuc Can();

	//toán tử nhập xuất
	friend istream& operator >> (istream& in, CSoThuc& so);
	friend ostream& operator <<(ostream& out, CSoThuc& so);
	//toán tử gán
	CSoThuc operator = (string so2);
	CSoThuc operator = (CSoNguyen& so2);
	CSoThuc operator = (int so2);
	CSoThuc operator = (CSoThuc& so2);
	CSoThuc operator = (double so2);

	///toán tử số học
	//với kiểu số thực
	CSoThuc operator + (const CSoThuc& so2);
	CSoThuc operator - (const CSoThuc& so2);
	CSoThuc operator * (const CSoThuc& so2);
	CSoThuc operator / (CSoThuc& so2);
	//với kiểu int
	CSoThuc operator + (const int so2);
	CSoThuc operator - (const int so2);
	CSoThuc operator * (const int so2);
	CSoThuc operator / (const int so2);
	//voi kieu so nguyen
	CSoThuc operator + (const CSoNguyen so2);
	CSoThuc operator - (const CSoNguyen so2);
	CSoThuc operator * (const CSoNguyen so2);
	CSoThuc operator / (const CSoNguyen so2);
	//với kiểu double
	CSoThuc operator + (const double so2);
	CSoThuc operator - (const double so2);
	CSoThuc operator * (const double so2);
	CSoThuc operator / (const double so2);

	///toán tử phức hợp
	//với kiểu số thực
	CSoThuc& operator += (CSoThuc& so2);
	CSoThuc& operator -= (CSoThuc& so2);
	CSoThuc& operator *= (CSoThuc& so2);
	CSoThuc& operator /= (CSoThuc& so2);
	CSoThuc& operator %= (CSoThuc& so2);
	//với kiểu int
	CSoThuc& operator += (int so2);
	CSoThuc& operator -= (int so2);
	CSoThuc& operator *= (int so2);
	CSoThuc& operator /= (int so2);
	//với kiểu double
	CSoThuc& operator += (double so2);
	CSoThuc& operator -= (double so2);
	CSoThuc& operator *= (double so2);
	CSoThuc& operator /= (double so2);
	//với kiểu số nguyên
	CSoThuc& operator += (CSoNguyen& so2);
	CSoThuc& operator -= (CSoNguyen& so2);
	CSoThuc& operator *= (CSoNguyen& so2);
	CSoThuc& operator /= (CSoNguyen& so2);

	///toán tử tăng, giảm
	//tăng giảm tiền tố
	CSoThuc& operator ++ ();
	CSoThuc& operator -- ();
	//tăng giảm hậu tố
	CSoThuc& operator ++ (int);
	CSoThuc& operator -- (int);

	///Toán Tử so sánh
	//với số thực
	bool operator == (CSoThuc so2);
	bool operator != (CSoThuc so2);
	bool operator > (CSoThuc so2);
	bool operator < (CSoThuc so2);
	bool operator >= (CSoThuc so2);
	bool operator <= (CSoThuc so2);

	//với số nguyên
	bool operator == (CSoNguyen so2);
	bool operator != (CSoNguyen so2);
	bool operator > (CSoNguyen so2);
	bool operator < (CSoNguyen so2);
	bool operator >= (CSoNguyen so2);
	bool operator <= (CSoNguyen so2);

	//với số int
	bool operator == (int so2);
	bool operator != (int so2);
	bool operator > (int so2);
	bool operator < (int so2);
	bool operator >= (int so2);
	bool operator <= (int so2);
};

