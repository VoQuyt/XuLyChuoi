#include "SoThuc.h"
#include "Library.h"
using namespace std;
#include<string>


//---------------------------------------------------------------------------------------------------
//hàm khởi tạo
CSoThuc::CSoThuc()
{
	a = "0.0";
}
CSoThuc::CSoThuc(string b)
{
	a = b;
}
CSoThuc::CSoThuc(CSoThuc& x)
{
	*this = x;
}
CSoThuc::CSoThuc(CSoNguyen& x)
{
	*this = x.a;
}
CSoThuc::CSoThuc(int x)
{
	this->a = MaHoa1(x);
}
CSoThuc::CSoThuc(double x)
{
	this->a = to_string(x);
}
CSoThuc::CSoThuc(string b, string c)
{
	*this = MaHoa2(b, c);
}
CSoThuc::CSoThuc(int x, int y)
{
	*this = MaHoa2(MaHoa1(x), MaHoa1(y));
}
CSoThuc::CSoThuc(CSoNguyen& x, CSoNguyen& y)
{
	*this = MaHoa2(x.a,y.a);
}
//hàm hũy
CSoThuc::~CSoThuc()
{
}

//Lay Can
CSoThuc CSoThuc:: Can()
{ 
	return LayCan(Del0Dau(a));
}

//--------------------------------------------------------------------------------------------------------
//hàm nhập
istream& operator >> (istream& in, CSoThuc& so)
{
	cout << "Nhap So Thuc:  ";
	rewind(stdin);
	getline(in, so.a);
	return in;
}
//ham xuat
ostream& operator <<(ostream& out, CSoThuc& so)
{
	out << so.a;
	return out;
}


//-------------------------------------------------------------------------------------------------------
//toán tử gán
CSoThuc CSoThuc:: operator = (string so2)
{
	a = so2;
	return a;
}
CSoThuc CSoThuc:: operator = (CSoNguyen& so2)
{
	a = so2.a;
	return a;
}
CSoThuc CSoThuc:: operator = (int so2)
{
	a = MaHoa1(so2);
	return a;
}
CSoThuc CSoThuc:: operator = (CSoThuc& so2)
{
	a = so2.a;
	return a;
}
CSoThuc CSoThuc:: operator = (double so2)
{
	a = to_string(so2);
	return a;
}


//-----------------------------------------------------------------------------------------------
///toán tử số học
//với kiểu số thực
CSoThuc CSoThuc:: operator + (const CSoThuc& so2)
{
	CSoThuc Tong;
	if (SoSanhDau(this->a, so2.a) == 1)
		Tong.a = Del0Duoi(Del0(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))),a,so2.a)));
	else if (SoSanhDau(this->a, so2.a) == -1)
		Tong.a = InsertAm(Del0Duoi(Del0(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = InsertAm(Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a))));
		}
		else
			Tong.a = '0';
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = InsertAm(Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a))));
		}
		else
			Tong.a = '0';
	}
	return Tong;
}
CSoThuc CSoThuc:: operator - (const CSoThuc& so2)
{
	CSoThuc Tru;
	if (SoSanhDau(a, so2.a) == 1)//a,b>0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = InsertAm(Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a))));
		}
		else
			Tru.a = '0';//a=b
	}

	else if (SoSanhDau(a, so2.a) == -1)//a,b<0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = InsertAm(Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = Del0Duoi(Del0(InsertPhay1((Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))),a,so2.a)));
		}
		else
			Tru.a = '0';//a=b
	}
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		Tru.a =	Del0Duoi(Del0(InsertPhay1(Sum(LayMax((DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))),a,so2.a)));
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		Tru.a = InsertAm(Del0Duoi(Del0(InsertPhay1(Sum(LayMax((DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	}
	return Tru;
}
CSoThuc CSoThuc:: operator / (CSoThuc& so2)
{
	CSoThuc Thuong;
	if (Check0(Del0Duoi(so2.a)) || (Check0(Del0Duoi(a))))
	{
		if (Check0(Del0Duoi(so2.a)))
			Thuong.a = "MATH ERROR";
		else
			Thuong.a = "0";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
		{
			Thuong.a = (Del0Duoi(Del0(DivThuc(DelAm(a), (DelAm(so2.a))))));
		}
		else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
		{
			Thuong.a = InsertAm(Del0(DivThuc((DelAm(a)), (DelAm(so2.a)))));
		}
	}
	return Thuong;
}
CSoThuc CSoThuc:: operator * (const CSoThuc& so2)
{
	CSoThuc Tich;
	if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
	{
		Tich.a = "0";
	}
	else
	{
		if (LayGTTPhay(a) == "0"&&LayGTTPhay(so2.a) == "0" && SoSanhLonHon(Mul(LayGTSPhay(a),LayGTSPhay(so2.a)),MaHoa1(10))==-1)
		{
			Tich.a = Del0Duoi((Del0(InsertPhay1((Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
		}
		else
		{
			if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
				Tich.a = Del0Duoi((Del0(InsertPhay2((Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
			else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
				Tich.a = InsertAm((Del0(Del0Duoi(InsertPhay2((Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)))));
		}
	}
	return Tich;
}
//với kiểu số int 
CSoThuc CSoThuc::operator + (const int So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tong;
	if (SoSanhDau(this->a, so2.a) == 1)
		Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
	else if (SoSanhDau(this->a, so2.a) == -1)
		Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tong.a = '0';
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tong.a = '0';
	}
	return Tong;
}
CSoThuc CSoThuc::operator - (const int So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tru;
	if (SoSanhDau(a, so2.a) == 1)//a,b>0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tru.a = '0';//a=b
	}

	else if (SoSanhDau(a, so2.a) == -1)//a,b<0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else
			Tru.a = '0';//a=b
	}
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	}
	Tru = Insert0dau(Tru.a);
	return Tru;
}
CSoThuc CSoThuc::operator * (const int So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tich;
	if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
	{
		Tich.a = "0";
	}
	else
	{
		if (LayGTTPhay(a) == "0"&&LayGTTPhay(so2.a) == "0" && SoSanhLonHon(Mul(LayGTSPhay(a), LayGTSPhay(so2.a)), MaHoa1(10)) == -1)
		{
			Tich.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
		}
		else
		{
			if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
				Tich.a = Del0Duoi(Insert0dau(InsertPhay2(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
			else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
				Tich.a = InsertAm(Insert0dau(Del0Duoi(InsertPhay2(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
		}
	}
	return Tich;
}
CSoThuc CSoThuc::operator / (const int So2)
{
	CSoThuc so2 = So2;
	CSoThuc Thuong;
	if (Check0(Del0Duoi(so2.a)) || (Check0(Del0Duoi(a))))
	{
		if (Check0(Del0Duoi(so2.a)))
			Thuong.a = "MATH ERROR";
		else
			Thuong.a = "0";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
		{
			Thuong.a = Insert0dau(Del0Dau(Del0Duoi(DivThuc(DelAm(a), DelAm(so2.a)))));
		}
		else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
		{
			Thuong.a = InsertAm(Insert0dau(Del0Dau(Del0Duoi(DivThuc(DelAm(a), DelAm(so2.a))))));
		}
	}
	return Thuong;
}

//với kiểu CSoNguyen
CSoThuc CSoThuc::operator + (CSoNguyen So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tong;
	if (SoSanhDau(this->a, so2.a) == 1)
		Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
	else if (SoSanhDau(this->a, so2.a) == -1)
		Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tong.a = '0';
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tong.a = '0';
	}
	return Tong;
}
CSoThuc CSoThuc::operator - (CSoNguyen So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tru;
	if (SoSanhDau(a, so2.a) == 1)//a,b>0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tru.a = '0';//a=b
	}

	else if (SoSanhDau(a, so2.a) == -1)//a,b<0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else
			Tru.a = '0';//a=b
	}
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	}
	Tru = Insert0dau(Tru.a);
	return Tru;
}
CSoThuc CSoThuc::operator * (CSoNguyen So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tich;
	if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
	{
		Tich.a = "0";
	}
	else
	{
		if (LayGTTPhay(a) == "0"&&LayGTTPhay(so2.a) == "0" && SoSanhLonHon(Mul(LayGTSPhay(a), LayGTSPhay(so2.a)), MaHoa1(10)) == -1)
		{
			Tich.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
		}
		else
		{
			if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
				Tich.a = Del0Duoi(Insert0dau(InsertPhay2(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
			else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
				Tich.a = InsertAm(Insert0dau(Del0Duoi(InsertPhay2(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
		}
	}
	return Tich;
}
CSoThuc CSoThuc::operator / (CSoNguyen So2)
{
	CSoThuc so2 = So2;
	CSoThuc Thuong;
	if (Check0(Del0Duoi(so2.a)) || (Check0(Del0Duoi(a))))
	{
		if (Check0(Del0Duoi(so2.a)))
			Thuong.a = "MATH ERROR";
		else
			Thuong.a = "0";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
		{
			Thuong.a = Insert0dau(Del0Dau(Del0Duoi(DivThuc(DelAm(a), DelAm(so2.a)))));
		}
		else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
		{
			Thuong.a = InsertAm(Insert0dau(Del0Dau(Del0Duoi(DivThuc(DelAm(a), DelAm(so2.a))))));
		}
	}
	return Thuong;
}

//với kiểu số double
CSoThuc CSoThuc::operator + (const double So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tong;
	if (SoSanhDau(this->a, so2.a) == 1)
		Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
	else if (SoSanhDau(this->a, so2.a) == -1)
		Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tong.a = '0';
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tong.a = '0';
	}
	return Tong;
}
CSoThuc CSoThuc::operator - (const double So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tru;
	if (SoSanhDau(a, so2.a) == 1)//a,b>0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else
			Tru.a = '0';//a=b
	}

	else if (SoSanhDau(a, so2.a) == -1)//a,b<0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))), a, so2.a)));
		}
		else
			Tru.a = '0';//a=b
	}
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		Tru.a = Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		Tru.a = InsertAm(Del0Duoi(Insert0dau(InsertPhay1(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
	}
	Tru = Insert0dau(Tru.a);
	return Tru;
}
CSoThuc CSoThuc::operator * (const double So2)
{
	CSoThuc so2 = So2;
	CSoThuc Tich;
	if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
	{
		Tich.a = "0";
	}
	else
	{
		if (LayGTTPhay(a) == "0"&&LayGTTPhay(so2.a) == "0" && SoSanhLonHon(Mul(LayGTSPhay(a), LayGTSPhay(so2.a)), MaHoa1(10)) == -1)
		{
			Tich.a = Del0Duoi(Insert0dau(InsertPhay1(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
		}
		else
		{
			if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
				Tich.a = Del0Duoi(Insert0dau(InsertPhay2(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a)));
			else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
				Tich.a = InsertAm(Insert0dau(Del0Duoi(InsertPhay2(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))), a, so2.a))));
		}
	}
	return Tich;
}
CSoThuc CSoThuc::operator / (const double So2)
{
	CSoThuc so2 = So2;
	CSoThuc Thuong;
	if (Check0(Del0Duoi(so2.a)) || (Check0(Del0Duoi(a))))
	{
		if (Check0(Del0Duoi(so2.a)))
			Thuong.a = "MATH ERROR";
		else
			Thuong.a = "0";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
		{
			Thuong.a = (Del0Dau(Del0Duoi(DivThuc(DelAm(a), DelAm(so2.a)))));
		}
		else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
		{
			Thuong.a = InsertAm((Del0Dau(Del0Duoi(DivThuc(DelAm(a), DelAm(so2.a))))));
		}
	}
	return Thuong;
}


//--------------------------------------------------------------------------------------------
///Toán tử phức hợp
//với kiểu số thực
CSoThuc& CSoThuc::operator += (CSoThuc& so2)
{
	*this = *this + so2;
	return *this;
}
CSoThuc& CSoThuc::operator -= (CSoThuc& so2)
{
	*this = *this - so2;
	return *this;
}
CSoThuc& CSoThuc::operator *= (CSoThuc& so2)
{
	*this = *this * so2;
	return *this;
}
CSoThuc& CSoThuc::operator /= (CSoThuc& so2)
{
	*this = *this / so2;
	return *this;
}

//với kiểu int
CSoThuc& CSoThuc::operator += (int So2)
{
	CSoThuc so2 = So2;
	*this = *this + so2;
	return *this;
}
CSoThuc& CSoThuc::operator -= (int So2)
{
	CSoThuc so2 = So2;
	*this = *this - so2;
	return *this;
}
CSoThuc& CSoThuc::operator *= (int So2)
{
	CSoThuc so2 = So2;
	*this = *this * so2;
	return *this;
}
CSoThuc& CSoThuc::operator /= (int So2)
{
	CSoThuc so2 = So2;
	*this = *this / so2;
	return *this;
}
//với kiểu double
CSoThuc& CSoThuc::operator += (double So2)
{
	CSoThuc so2 = So2;
	*this = *this + so2;
	return *this;
}
CSoThuc& CSoThuc::operator -= (double So2)
{
	CSoThuc so2 = So2;
	*this = *this - so2;
	return *this;
}
CSoThuc& CSoThuc::operator *= (double So2)
{
	CSoThuc so2 = So2;
	*this = *this * so2;
	return *this;
}
CSoThuc& CSoThuc::operator /= (double so2)
{
	CSoThuc So2 = so2;
	*this = *this / So2;
	return *this;
}
//với kiểu số nguyên
CSoThuc& CSoThuc::operator += (CSoNguyen& so2)
{
	*this = *this + so2;
	return *this;
}
CSoThuc& CSoThuc::operator -= (CSoNguyen& so2)
{
	*this = *this - so2;
	return *this;
}
CSoThuc& CSoThuc::operator *= (CSoNguyen& so2)
{
	*this = *this * so2;
	return *this;
}
CSoThuc& CSoThuc::operator /= (CSoNguyen& so2)
{
	CSoThuc So2 = so2;
	*this = *this / So2;
	return *this;
}


///toán tử tăng, giảm
//tiền tố
CSoThuc& CSoThuc::operator ++ ()
{
	*this += 1;
	return *this;
}
CSoThuc& CSoThuc::operator -- ()
{
	*this -= 1;
	return *this;
}
//hậu tố
CSoThuc& CSoThuc::operator ++ (int)
{
	CSoThuc *KQ = new CSoThuc(*this);
	*this += 1;
	return *KQ;
}
CSoThuc& CSoThuc::operator -- (int)
{
	CSoThuc *KQ = new CSoThuc(*this);
	*this -= 1;
	return *KQ;
}


//--------------------------------------------------------------------------------------------
///Toán Tử So Sánh
//với kiểu số thực
bool CSoThuc::operator == (CSoThuc so2)
{
	if (SoSanhLonHon(a, so2.a) == 0)
		return true;
	return false;
}
bool CSoThuc::operator != (CSoThuc so2)
{
	if (SoSanhLonHon(a, so2.a) != 0)
		return true;
	return false;
}
bool CSoThuc::operator > (CSoThuc so2)
{
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == -2)
		return false;
	else
		return true;
}
bool CSoThuc::operator < (CSoThuc so2)
{
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == -1)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == 2)
		return false;
	else
		return true;
}
bool CSoThuc::operator >= (CSoThuc so2)
{
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a) == 0)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a) == 0)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == -2)
		return false;
	else
		return true;
}
bool CSoThuc::operator <= (CSoThuc so2)
{	
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == -1||SoSanhLonHon(a,so2.a))
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1||SoSanhLonHon(a,so2.a))
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == 2)
		return false;
	else
		return true;
}
//với kiểu số nguyên
bool CSoThuc::operator == (CSoNguyen so2)
{
	if (SoSanhLonHon(a, so2.a) == 0)
		return true;
	return false;
}
bool CSoThuc::operator != (CSoNguyen so2)
{
	if (SoSanhLonHon(a, so2.a) != 0)
		return true;
	return false;
}
bool CSoThuc::operator > (CSoNguyen so2)
{
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == -2)
		return false;
	else
		return true;
}
bool CSoThuc::operator < (CSoNguyen so2)
{
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == -1)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == 2)
		return false;
	else
		return true;
}
bool CSoThuc::operator >= (CSoNguyen so2)
{
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a) == 0)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a) == 0)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == -2)
		return false;
	else
		return true;
}
bool CSoThuc::operator <= (CSoNguyen so2)
{
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == -1 || SoSanhLonHon(a, so2.a))
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a))
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == 2)
		return false;
	else
		return true;
}
//với số int
bool CSoThuc::operator == (int So2)
{
	CSoThuc so2 = So2;
	if (SoSanhLonHon(a, so2.a) == 0)
		return true;
	return false;
}
bool CSoThuc::operator != (int So2)
{
	CSoThuc so2 = So2;
	if (SoSanhLonHon(a, so2.a) != 0)
		return true;
	return false;
}
bool CSoThuc::operator > (int So2)
{
	CSoThuc so2 = So2;
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == -2)
		return false;
	else
		return true;
}
bool CSoThuc::operator < (int So2)
{
	CSoThuc so2 = So2;
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == -1)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == 2)
		return false;
	else
		return true;
}
bool CSoThuc::operator >= (int So2)
{
	CSoThuc so2 = So2;
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a) == 0)
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a) == 0)
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == -2)
		return false;
	else
		return true;
}
bool CSoThuc::operator <= (int So2)
{
	CSoThuc so2 = So2;
	if (SoSanhDau(a, so2.a) == 1)
	{
		if (SoSanhLonHon(a, so2.a) == -1 || SoSanhLonHon(a, so2.a))
			return true;
		return false;
	}
	else if (SoSanhDau(a, so2.a) == -1)
	{
		if (SoSanhLonHon(a, so2.a) == 1 || SoSanhLonHon(a, so2.a))
			return false;
		return true;
	}
	else if (SoSanhDau(a, so2.a) == 2)
		return false;
	else
		return true;
}































