#pragma once
#include "HinhHoc.h"
#include "SoNguyen.h"
#include "SoThuc.h"
#include <iostream>

class CHinhTamGiac:public CHinhHoc
{
public:
protected:
	CSoThuc C1, C2, C3;//canh 1, canh 2, canh 3
public:
	void Nhap();
	void Xuat();
	CSoNguyen LoaiHinh();
	CSoThuc ChuVi();
	CSoThuc DienTich();

	CHinhTamGiac();
	~CHinhTamGiac();
};

