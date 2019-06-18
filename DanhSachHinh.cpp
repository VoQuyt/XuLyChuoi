#include "DanhSachHinh.h"
#include "HinhChuNhat.h"
#include "HinhVuong.h"
#include "HinhTron.h"
#include "HinhELip.h"
#include "HinhTamGiac.h"
#include "HinhHoc.h"
#include <iostream>
#include <conio.h>
using namespace std;


CDanhSachHinh::CDanhSachHinh()
{
}
CDanhSachHinh::~CDanhSachHinh()
{
}


void CDanhSachHinh::Nhap()
{
	cout << "\nNhap So Luong Hinh: ";
	cin >> SL;
	DS = new CHinhHoc*[SL];
	for (int i = 0; i < SL; i++)
	{
		int Chon;
		cout << "\n(1->HCN), (2->HV), (3->HTG), (4->ELIP), (5->HT) Chon: ";
		cin >> Chon;
		if (Chon == 2)
			DS[i] = new CHinhVuong();
		else if (Chon == 1)
			DS[i] = new CHinhChuNhat();
		else if (Chon == 5)
			DS[i] = new CHinhTron();
		else if (Chon == 4)
			DS[i] = new CHinhELip();
		else if (Chon == 3)
			DS[i] = new CHinhTamGiac();
		else
		{
			cout << "\n(1->HCN), (2->HV), (3->HTG), (4->ELIP), (5->HT) ";
			cout << "\nChon Lai: ";
		}
		DS[i]->Nhap();
	}
}

void CDanhSachHinh::Xuat()
{
	for (int i = 0; i < SL; i++)
	{
		DS[i]->Xuat();
	}
}

CSoThuc CDanhSachHinh::TongDienTich()
{
	CSoThuc Tong = 0;
	for (int i = 0; i < SL; i++)
	{
		Tong = Tong + DS[i]->DienTich();
	}
	return Tong;
}

void CDanhSachHinh::HinhCoChuViMin()
{
	CSoThuc min = DS[0]->ChuVi();
	for (int i = 0; i < SL; i++)
	{
		if (min > DS[i]->ChuVi())
			min = DS[i]->ChuVi();
	}
	for (int i = 0; i < SL; i++)
		if (DS[i]->ChuVi() == min)
			DS[i]->Xuat();
}

CSoThuc CDanhSachHinh::TongDienTichHCN()
{
	CSoThuc Tong = 0;
	for (int i = 0; i < SL; i++)
	{
		if (DS[i]->LoaiHinh() == 1|| DS[i]->LoaiHinh() == 2)
			Tong = Tong + DS[i]->DienTich();
	}
	return Tong;
	
}

CSoNguyen CDanhSachHinh::SLHT()
{
	int d = 0;
	for (int i = 0; i < SL; i++)
	{
		if (DS[i]->LoaiHinh() == 3)
			d++;
	}
	return d;
}

void CDanhSachHinh::HinhVuongChuViMin()
{
	CSoThuc min;
	for (int i = 0; i < SL; i++)
	{
		if (DS[i]->LoaiHinh() == 2)
		{
			min = DS[i]->ChuVi();
			break;
		}
	}

	for (int i = 0; i < SL; i++)
	{
		if (DS[i]->LoaiHinh() == 2)
			if (min > DS[i]->ChuVi())
				min = DS[i]->ChuVi();
	}

	for (int i = 0; i < SL; i++)
	{
		if (DS[i]->LoaiHinh() == 2 && DS[i]->ChuVi() == min)
			DS[i]->Xuat();
	}
}

void CDanhSachHinh::HinhCoSMax()
{
	CSoThuc SMax = DS[0]->DienTich();
	for (int i = 1; i < SL; i++)
		if (DS[i]->DienTich() > SMax)
			SMax = DS[i]->DienTich();
	for (int i = 0; i < SL; i++)
		if (DS[i]->DienTich() == SMax)
			DS[i]->Xuat();
}

CSoThuc CDanhSachHinh::TongChuVi()
{
	CSoThuc Tong = 0;
	for (int i = 0; i < SL; i++)
	{
		Tong = Tong + DS[i]->ChuVi();
	}
	return Tong;
}

CSoThuc CDanhSachHinh::ChuViTrungBinhCuaCacHinhTron()
{
	CSoThuc TB, Tong = 0;
	for (int i = 0; i < SL; i++)
	{
		if (DS[i]->LoaiHinh() == 3)
			Tong = Tong + DS[i]->ChuVi();
	}
	TB = Tong / SLHT();
	return TB;
}

void CDanhSachHinh::SortMangGiamDanTheoDienTich()//sap xep mang giam dan theo dien tich
{
	for (int i = 0; i < SL-1; i++)
		for (int j = i + 1; j < SL; j++)
			if (DS[i]->DienTich() < DS[j]->DienTich())
				swap(DS[i], DS[j]);
	for (int i = 0; i < SL; i++)
		DS[i]->Xuat();
}















