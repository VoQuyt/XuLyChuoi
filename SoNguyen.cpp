#include "SoNguyen.h"
#include "Library.h"
#include <string>


//Ham khoi tao va ham huy
CSoNguyen::CSoNguyen()
{
	this->a = '0';
}
CSoNguyen::CSoNguyen(string b)
{
	this->a = b;
}
CSoNguyen::CSoNguyen(CSoNguyen& x)
{
	*this = x;
}
CSoNguyen::CSoNguyen(int x)
{

	this->a = MaHoa1(x);
}
//Hàm hủy
CSoNguyen::~CSoNguyen()
{
}

//-----------------------------------------------------------------------------
/// Nhap Xuat Cac Chuoi
//ham nhap
istream& operator >> (istream& in, CSoNguyen& so)
{
	cout << "Nhap so nguyen:  ";
	rewind(stdin);
	getline(in, so.a);
	return in;
}
//ham xuat
ostream& operator <<(ostream& out, CSoNguyen& so)
{
	out << so.a;
	return out;
}

//-------------------------------------------------------------------------------
/// Các Hàm toán tử số học
//cộng số nguyên với số nguyên
CSoNguyen CSoNguyen:: operator + (const CSoNguyen& so2)
{
	CSoNguyen Tong;
	if (SoSanhDau(this->a, so2.a) == 1)
		Tong.a = Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
	else if (SoSanhDau(this->a, so2.a) == -1)
		Tong.a = InsertAm(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else
			Tong.a = '0';
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else
			Tong.a = '0';
	}
	return Tong;
}
//trừ sô nguyên với số nguyên
CSoNguyen CSoNguyen::operator - (const CSoNguyen& so2)
{
	CSoNguyen Tru;
	if (SoSanhDau(a, so2.a) == 1)//a,b>0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else
			Tru.a = '0';//a=b
	}

	else if (SoSanhDau(a, so2.a) == -1)//a,b<0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else
			Tru.a = '0';//a=b
	}
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		Tru.a = Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		Tru.a = InsertAm(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
	}
	return Tru;
}
//nhân số nguyên với số nguyên
CSoNguyen CSoNguyen::operator * (const CSoNguyen& so2)
{
	CSoNguyen Tich;
		if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
		{
			Tich.a = "0";
		}
		else
		{
			if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
				Tich.a = Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
			else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
				Tich.a = InsertAm(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		return Tich;
}
//chia số nguyên với số nguyên
CSoNguyen CSoNguyen::operator / (const CSoNguyen& so2)
{
	CSoNguyen Thuong;
	if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
	{
		if (Check0(DelAm(so2.a)))
			Thuong.a = "MATH ERROR";
		else
			Thuong.a = "0";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
		{
			if ((SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1))
				Thuong.a = "0";
			else
				Thuong.a = LayGTTPhay(Div(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
		}
		else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
		{
			if ((SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1))
				Thuong.a = "0";
			else
				Thuong.a = InsertAm(LayGTTPhay(Div(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
	}
	return Thuong;
}
//chia % số nguyên với sô nguyên
CSoNguyen CSoNguyen:: operator % (const CSoNguyen& so2)
{
	CSoNguyen Du;
	if (Check0(so2.a))
	{
		Du.a = "MATH ERROR";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == 1 || SoSanhDau(a, so2.a) == 2)
		{
			Du.a = Del0Dau(div(DelAm(a), DelAm(so2.a)));
		}
		else if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == -2)
		{
			Du.a = InsertAm(Del0Dau(div(DelAm(a), DelAm(so2.a))));
		}
	}
	return Du;
}

//số nguyên với số int
CSoNguyen CSoNguyen::operator + (int So2)
{
	CSoNguyen so2 = So2;
	CSoNguyen Tong;
	if (SoSanhDau(this->a, so2.a) == 1)
		Tong.a = Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
	else if (SoSanhDau(this->a, so2.a) == -1)
		Tong.a = InsertAm(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else
			Tong.a = '0';
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)
		{
			Tong.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)
		{
			Tong.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else
			Tong.a = '0';
	}
	return Tong;
}
CSoNguyen CSoNguyen::operator - (int So2)
{
	CSoNguyen so2 = So2;
	CSoNguyen Tru;
	if (SoSanhDau(a, so2.a) == 1)//a,b>0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else
			Tru.a = '0';//a=b
	}

	else if (SoSanhDau(a, so2.a) == -1)//a,b<0
	{
		if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == 1)//a>b
		{
			Tru.a = InsertAm(Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))))));
		}
		else if (SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1)//a<b
		{
			Tru.a = Del0Dau(Sub(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
		else
			Tru.a = '0';//a=b
	}
	else if (SoSanhDau(a, so2.a) == 2)//a>0>b
	{
		Tru.a = Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
	}
	else if (SoSanhDau(a, so2.a) == -2)//a<0<b
	{
		Tru.a = InsertAm(Sum(LayMax(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))), LayMin(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
	}
	return Tru;
}
CSoNguyen CSoNguyen::operator / (int So2)
{
	CSoNguyen so2 = So2;
	CSoNguyen Thuong;
	if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
	{
		if (Check0(DelAm(so2.a)))
			Thuong.a = "MATH ERROR";
		else
			Thuong.a = "0";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
		{
			if ((SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1))
				Thuong.a = "0";
			else
				Thuong.a = LayGTTPhay(Div(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
		}
		else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
		{
			if ((SoSanhLonHon(DelAm(a), DelAm(so2.a)) == -1))
				Thuong.a = "0";
			else
				Thuong.a = InsertAm(LayGTTPhay(Div(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
		}
	}
	return Thuong;
}
CSoNguyen CSoNguyen::operator * (int So2)
{
	CSoNguyen so2 = So2;
	CSoNguyen Tich;
	if (Check0(DelAm(a)) || Check0(DelAm(so2.a)))
	{
		Tich.a = "0";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == 1)
			Tich.a = Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a))));
		else if (SoSanhDau(a, so2.a) == -2 || SoSanhDau(a, so2.a) == 2)
			Tich.a = InsertAm(Del0Dau(Mul(Del0Dau(DelAm(a)), Del0Dau(DelAm(so2.a)))));
	}
	return Tich;
}
CSoNguyen CSoNguyen::operator % (int So2)
{
	CSoNguyen so2 = So2;
	CSoNguyen Du;
	if (Check0(so2.a))
	{
		Du.a = "MATH ERROR";
	}
	else
	{
		if (SoSanhDau(a, so2.a) == 1 || SoSanhDau(a, so2.a) == 2)
		{
			Du.a = Del0Dau(div(DelAm(a), DelAm(so2.a)));
		}
		else if (SoSanhDau(a, so2.a) == -1 || SoSanhDau(a, so2.a) == -2)
		{
			Du.a = InsertAm(Del0Dau(div(DelAm(a), DelAm(so2.a))));
		}
	}
	return Du;
}

//----------------------------------------------------------------------------------
///Các hàm toán tử gán
//gán số nguyên với chuỗi
CSoNguyen CSoNguyen:: operator = (string so2)
{
	a = so2;
	return a;
}
//gán số nguyên với số nguyên
CSoNguyen CSoNguyen:: operator = (CSoNguyen& so2)
{
	this->a = so2.a;
	return a;
}
//gán số nguyên với int
CSoNguyen CSoNguyen:: operator = (int so2)
{
	a = MaHoa1(so2);
	return a;
}


//------------------------------------------------------------------------------------
///Toán Tử Phức Hợp
//số nguyên với số nguyên
CSoNguyen& CSoNguyen::operator += (CSoNguyen& so2)
{ 
	
	*this = *this + so2;
	return *this;
}
CSoNguyen& CSoNguyen::operator -= (CSoNguyen& so2)
{
	*this = *this - so2;
	return *this;
}
CSoNguyen& CSoNguyen::operator *= (CSoNguyen& so2)
{
	*this = *this * so2;
	return *this;
}
CSoNguyen& CSoNguyen::operator /= (CSoNguyen& so2)
{
	*this = *this / so2;
	return *this;
}
CSoNguyen& CSoNguyen::operator %= (CSoNguyen& so2)
{
	*this = *this % so2;
	return *this;
}
//số nguyên với int
CSoNguyen& CSoNguyen::operator += (int so2)
{
	*this = *this + MaHoa1(so2);
	return *this;
}
CSoNguyen& CSoNguyen::operator -= (int so2)
{
	*this = *this - MaHoa1(so2);
	return *this;
}
CSoNguyen& CSoNguyen::operator *= (int so2)
{
	*this = *this * MaHoa1(so2);
	return *this;
}
CSoNguyen& CSoNguyen::operator /= (int so2)
{
	*this = *this / MaHoa1(so2);
	return *this;
}
CSoNguyen& CSoNguyen::operator %= (int so2)
{
	*this = *this % MaHoa1(so2);
	return *this;
}



//---------------------------------------------------------------------------------------
///toán tử tăng, giảm
//tiền tố
CSoNguyen& CSoNguyen::operator ++ ()
{
	*this += 1;
	return *this;
}
CSoNguyen& CSoNguyen::operator -- ()
{
	*this -= 1;
	return *this;
}
//hậu tố
CSoNguyen& CSoNguyen::operator ++ (int)
{
	CSoNguyen *KQ =new CSoNguyen(*this);
	*this += 1;
	return *KQ;
}
CSoNguyen& CSoNguyen::operator -- (int)
{
	CSoNguyen *KQ = new CSoNguyen(*this);
	*this -= 1;
	return *KQ;
}


//-------------------------------------------------------------------------------------
///Toán tử so Sánh
//với số nguyên
bool CSoNguyen::operator == (CSoNguyen so2)
{
	if (SoSanhLonHon(a, so2.a) == 0)
		return true;
	return false;
}
bool CSoNguyen::operator != (CSoNguyen so2)
{
	if (SoSanhLonHon(a, so2.a) != 0)
		return true;
	return false;
}
bool CSoNguyen::operator > (CSoNguyen so2)
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
bool CSoNguyen::operator < (CSoNguyen so2)
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
bool CSoNguyen::operator >= (CSoNguyen so2)
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
bool CSoNguyen::operator <= (CSoNguyen so2)
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
bool CSoNguyen::operator == (int So2)
{
	CSoNguyen so2 = So2;
	if (SoSanhLonHon(a, so2.a) == 0)
		return true;
	return false;
}
bool CSoNguyen::operator != (int So2)
{
	CSoNguyen so2 = So2;
	if (SoSanhLonHon(a, so2.a) != 0)
		return true;
	return false;
}
bool CSoNguyen::operator > (int So2)
{
	CSoNguyen so2 = So2;
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
bool CSoNguyen::operator < (int So2)
{
	CSoNguyen so2 = So2;
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
bool CSoNguyen::operator >= (int So2)
{
	CSoNguyen so2 = So2;
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
bool CSoNguyen::operator <= (int So2)
{
	CSoNguyen so2 = So2;
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















