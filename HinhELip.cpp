#include "HinhELip.h"
#include "HinhHoc.h"
#include "SoNguyen.h"
#include "SoThuc.h"
#include <iostream>

#define PI 3.14

using namespace std;


CHinhELip::CHinhELip()
{
}
CHinhELip::~CHinhELip()
{
}

void CHinhELip::Nhap()
{
	cout << "Ban kinh lon = ";
	cin >> R1;
	cout << "Ban kinh be = ";
	cin >> R2;
}
void CHinhELip::Xuat()
{
	cout << "\n\nTHONG TIN HINH ELIP";
	cout << "\nBan Kinh Lon = " << R1;
	cout << "\nBan Kinh Be = " << R2;
}
CSoThuc CHinhELip::ChuVi()
{
	return ((((R1*R1) + (R2*R2))/2).Can()*2*PI);
}
CSoThuc CHinhELip::DienTich()
{
	return (R1*R2*PI);
}

CSoNguyen CHinhELip::LoaiHinh()
{
	return 4;
}