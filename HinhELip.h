#pragma once
#include "HinhHoc.h"
#include "SoNguyen.h"
#include "SoThuc.h"
#include <iostream>

using namespace std;


class CHinhELip:public CHinhHoc
{
protected:
	CSoThuc R1, R2;//R1 = ban kinh lon, R2 = ban kinh be
public:
	CHinhELip();
	~CHinhELip();
	virtual void Nhap();
	virtual void Xuat();
	virtual CSoNguyen LoaiHinh();
	virtual CSoThuc ChuVi();
	virtual CSoThuc DienTich();
};

