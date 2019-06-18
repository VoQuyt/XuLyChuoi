#include "HinhVuong.h"
#include "HinhChuNhat.h"
#include <iostream>
#include "SoNguyen.h"
#include "SoThuc.h"

using namespace std;


CHinhVuong::CHinhVuong()
{
}
CHinhVuong::~CHinhVuong()
{
}



void CHinhVuong::Nhap()
{
	cout << "Canh = ";
	cin >> Dai;
	Rong = Dai;
}
void CHinhVuong::Xuat()
{
	cout << "\n\nTHONG TIN HINH VUONG";
	cout << "\nCanh = " << Dai;
}

CSoNguyen CHinhVuong::LoaiHinh()
{
	return 2;
}