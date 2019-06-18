#include "HinhChuNhat.h"
#include <iostream>
#include "SoNguyen.h"
#include "SoThuc.h"

using namespace std;



CHinhChuNhat::CHinhChuNhat()
{
}
CHinhChuNhat::~CHinhChuNhat()
{
}
void CHinhChuNhat::Nhap()
{
	cout << "Dai = ";
	cin >> Dai;
	cout << "Rong = ";
	cin >> Rong;
}
void CHinhChuNhat::Xuat()
{
	cout << "\n\nTHONG TIN HINH CHU NHAT";
	cout << "\nDai = "<<Dai;
	cout << "\nRong = "<<Rong;
}
CSoThuc CHinhChuNhat::ChuVi()
{
	return ((Dai + Rong) * 2);
}
CSoThuc CHinhChuNhat::DienTich()
{
	return (Dai*Rong);
}

CSoNguyen CHinhChuNhat::LoaiHinh()
{
	return 1;
}