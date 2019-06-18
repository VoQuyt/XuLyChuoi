#include "HinhTron.h"
#include <iostream>
#include "SoNguyen.h"
#include "SoThuc.h"

using namespace std;

#define PI 3.14

CHinhTron::CHinhTron()
{
}
CHinhTron::~CHinhTron()
{
}
void CHinhTron::Nhap()
{
	
	cout << "Ban Kinh = ";
	cin >> R1;
	R2 = R1;
}
void CHinhTron::Xuat()
{
	cout << "\n\nTHONG TIN HINH TRON";
	cout << "\nBan Kinh = " << R1;
}
CSoThuc CHinhTron::ChuVi()
{
	return (R1*PI*2);
}
CSoThuc CHinhTron::DienTich()
{
	return(R1*R2*PI);
}
CSoNguyen CHinhTron::LoaiHinh()
{
	return 5;
}

