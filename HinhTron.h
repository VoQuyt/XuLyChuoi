#pragma once
#include "HinhHoc.h"
#include "HinhELip.h"
#include "SoNguyen.h"
#include "SoThuc.h"
#include <iostream>

using namespace std;

class CHinhTron:public CHinhELip
{
public:
	CHinhTron();
	~CHinhTron();
	CSoNguyen LoaiHinh();
	void Nhap();
	void Xuat();
	CSoThuc ChuVi();
	CSoThuc DienTich();
};

