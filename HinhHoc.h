#pragma once
#include "SoNguyen.h"
#include "SoThuc.h"
#include <iostream>

using namespace std;
class CHinhHoc
{
public:
	CHinhHoc();
	~CHinhHoc();
	virtual CSoNguyen LoaiHinh() = 0;
	virtual void Nhap() = 0;
	virtual void Xuat() = 0;
	virtual CSoThuc ChuVi() = 0;
	virtual CSoThuc DienTich() = 0;
};

