#pragma once
#include<iostream>
using namespace std;
#include<string>
class CSoNguyen
{
	
public:
	string a;
	///Hàm Khởi Tạo mặc định
	CSoNguyen();
	CSoNguyen(string a);
	CSoNguyen(CSoNguyen& x);
	CSoNguyen(int x);
	///Hàm Hủy
	~CSoNguyen();
	
	///Toán Tử Nhập Xuất
	friend istream& operator >>(istream& in, CSoNguyen& so);
	friend ostream& operator <<(ostream& out, CSoNguyen& so);
	
	///Toán Tử Số Học
	//với số nguyên
	CSoNguyen operator + (const CSoNguyen& so2);
	CSoNguyen operator - (const CSoNguyen& so2);
	CSoNguyen operator / (const CSoNguyen& so2);
	CSoNguyen operator * (const CSoNguyen& so2);
	CSoNguyen operator % (const CSoNguyen& so2);

	//với số int
	CSoNguyen operator + (const int So2);
	CSoNguyen operator - (const int So2);
	CSoNguyen operator / (const int So2);
	CSoNguyen operator * (const int So2);
	CSoNguyen operator % (const int So2);
	
	///Toán Tử Gán
	CSoNguyen operator = (string so2);
	CSoNguyen operator = (CSoNguyen& so2);
	CSoNguyen operator = (int so2);

	///Toán Tử Phức Hợp
	//Với kiểu số nguyên
	CSoNguyen& operator += (CSoNguyen& so2);
	CSoNguyen& operator -= (CSoNguyen& so2);
	CSoNguyen& operator *= (CSoNguyen& so2);
	CSoNguyen& operator /= (CSoNguyen& so2);
	CSoNguyen& operator %= (CSoNguyen& so2);

	//với kiểu int
	CSoNguyen& operator += (int so2);
	CSoNguyen& operator -= (int so2);
	CSoNguyen& operator *= (int so2);
	CSoNguyen& operator /= (int so2);
	CSoNguyen& operator %= (int so2);

	///toán tử tăng, giảm
	//tăng giảm tiền tố
	CSoNguyen& operator ++ ();
	CSoNguyen& operator -- ();
	//tăng giảm hậu tố
	CSoNguyen& operator ++ (int);
	CSoNguyen& operator -- (int);

	///Toán Tử So Sánh
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

