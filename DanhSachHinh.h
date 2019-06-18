#pragma once
#include "HinhChuNhat.h"
#include "HinhVuong.h"
#include "HinhTron.h"
#include <iostream>
#include <conio.h>
#include "SoNguyen.h"
#include "SoThuc.h"

using namespace std;
class CDanhSachHinh
{
private:
	int SL;
	CHinhHoc* *DS;
public:
	void Nhap();
	void Xuat();
	CSoThuc TongDienTich();//(a)
	CSoThuc TongDienTichHCN();//(c)
	CSoNguyen SLHT();//(d)
	void HinhVuongChuViMin();//(e)
	void HinhCoChuViMin();//(b)
	//---------------------------------------------------------------
	///BIG EXAM
	void HinhCoSMax();//(A)-> hinh co dien tich lon nhat
	CSoThuc TongChuVi();//(B)->Tinh tong chu vi cua cac hinh co trong mang
	CSoThuc ChuViTrungBinhCuaCacHinhTron();//(C)->Tinh chu vi trung binh cua cac hinh tron co trong mang
	void SortMangGiamDanTheoDienTich();//(D) -> sap xep mang giam dan theo dien tich

	CDanhSachHinh();
	~CDanhSachHinh();
};

