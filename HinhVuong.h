#pragma once
#include "HinhChuNhat.h"
#include "HinhHoc.h"
#include "SoNguyen.h"
#include "SoThuc.h"
#include <iostream>

using namespace std;

class CHinhVuong :public CHinhChuNhat
{
public:
	CHinhVuong();
	~CHinhVuong();
	void Nhap();
	void Xuat();
	CSoNguyen LoaiHinh();
};

