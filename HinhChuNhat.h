#pragma once
#include "HinhHoc.h"
#include "SoNguyen.h"
#include "SoThuc.h"
#include <iostream>

using namespace std;

class CHinhChuNhat:public CHinhHoc
{
protected:
	CSoThuc Dai, Rong;
public:
	CHinhChuNhat();
	~CHinhChuNhat();
	virtual void Nhap();
	virtual void Xuat();
	virtual CSoNguyen LoaiHinh();
	CSoThuc ChuVi();
	CSoThuc DienTich();
};

