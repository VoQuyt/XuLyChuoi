#include "HinhTamGiac.h"
#include <iostream>
#include "SoNguyen.h"
#include "Library.h"
#include "SoThuc.h"

using namespace std;



CHinhTamGiac::CHinhTamGiac()
{
}
CHinhTamGiac::~CHinhTamGiac()
{
}

void CHinhTamGiac::Nhap()
{
	cout << "Canh 1 = ";
	cin >> C1;
	cout << "Canh 2 = ";
	cin >> C2;
	cout << "Canh 2 = ";
	cin >> C3;
}
void CHinhTamGiac::Xuat()
{
	cout << "\n\nTHONG TIN TAM GIAC ";
	cout << "\nCanh 1 = " << C1;
	cout << "\nCanh 2 = " << C2;
	cout << "\nCanh 3 = " << C3;
}
CSoThuc CHinhTamGiac::ChuVi()
{
	return ((C1 + C2 + C3)/2);
}
CSoThuc CHinhTamGiac::DienTich()
{
	return ((ChuVi()*((ChuVi() - C1)*(ChuVi() - C2)*(ChuVi() - C3))).Can());
}

CSoNguyen CHinhTamGiac::LoaiHinh()
{
	return 3;
}