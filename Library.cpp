#include "Library.h"
#include <iostream>
#include <string>
#include<conio.h>
using namespace std;

int GiaiMa(char a)//chuyễn chuỗi Thành số
{
	return a - '0';
}

char MaHoa(int n)// chuyen so sang char
{
	return (char)(n + '0');
}

//chuyển số kiểu int sang chuỗi
string MaHoa1(int n)
{
	string k;
	if (n < 0)
	{
		n = abs(n);
		while (n != 0)
		{
			k = k.insert(0, 1, MaHoa(n % 10));
			n = n / 10;
		}
		return InsertAm(k);
	}
	else if (n == 0)
		return "0";
	else
	{
		while (n != 0)
		{
			k = k.insert(0, 1, MaHoa(n % 10));
			n = n / 10;
		}
		return k;
	}
}

string MaHoa2(string a, string b)
{
	return (a + '.' + b);
}

//so sánh độ dài chuỗi
int SoSanhLoong(string a, string b)
{
	if (a.length() > b.length())
		return 1;
	else if (a.length() < b.length())
		return -1;
	else
		return 0;
}

//thêm dấu âm đầu chuổi
string InsertAm(string a)
{
	return (a.insert(0, 1, '-'));
}

//bỏ dấu âm đầu chuổi
string DelAm(string a)
{
	if (a[0] == '-')
		a = a.substr(1, a.length());
	return a;
}

//kiểm tra chuổi có 1 phần tử và phần tử đó bằng 0
bool Check0(string a)
{
	for (int i = 0; i < a.length(); i++)
		if (a[i] != '0')
			return false;
	return true;
}

string Insert0vacham(string &a)
{
	a = a.insert(0, 1, '.');
	return Insert0dau(a);
}

//bỏ số 0 đầu đầu chuổi cho số thực
string Insert0dau(string a)
{
	if (a[0] == '.')
		a = a.insert(0, 1, '0');
	else
		a;
	return a;
}

string Del0(string a)
{
	//int n = 0;
	if (Check0(a))
		a = "0";
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '0')
			{
				if (a[i + 1] == '.')
					{
					a = a.erase(0, i);
					break;
					}
				else
				{
					if (a[i + 1] != '0')
					{
						a = a.erase(0, i + 1);
						break;
					}
				}
			}
			else
			{
				a;
				break;
			}
		}
		//a = (a.substr(n, a.length() - n));
	}
	return a;
}

//bỏ số 0 dầu chuổi cho số nguyên
string Del0Dau(string a)
{
	int n  = 0 ;
	if (CheckPhay(a))
	{
		if (Check0(a) == true)
			a = "0";
		else
		{
			for (int i = 0; i < a.length(); i++)
			{
				if (a[i] != '0')
				{
					n = i;
					break;
				}
			}
			a = (a.substr(n, a.length() - n));
		}
	}
	else
	{
		if (Check0(a) == true)
		{
			a = "0";
		}
		else
		{
			for (int i = 0; i < a.length(); i++)
			{
				if (a[0] != '0')
				{
					return a;
				}
				else
				{
					if (a[i] != '0')
					{
						n = i - 1;
						break;
					}
				}
			}
			a = (a.substr(n, a.length() - n));
		}
	}
	return a;
}

//Kiểm tra số có phải là số âm hay không
bool CheckAm(string a)
{
	if (a[0] == '-')
		return true;
	return false;
}

//ham kiem tra dau phay
bool CheckPhay(string a)
{
	for (int i = a.length(); i > 0; i--)
		if (a[i] == '.')
			return false;
	return true;
}

//ham xoa dau phay
string DelPhay(string &a)
{
	int n;
	if (CheckPhay(a))
		a;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '.')
			{
				n = i;
				break;
			}
		}
		a = (a.substr(0, n) + (a.substr(n + 1, a.length() - n)));
	}
	return a;
}

//xoa so 0 đầu của số thực
string Del0Duoi(string &a)
{
	if (CheckPhay(a))
		a;
	else
	{
		int n;
		for (int i = a.length() - 1; i >= 0; i--)
		{
			if (a[i] != '0')
			{
				if (a[i] == '.')
					n = i;
				else
					n = i + 1;
				break;
			}
		}
		a = a.substr(0, n);
	}
	return a;
}

string Del0DauThuc(string &a)
{
	int n;
	if (Check0(a) == true)
		a = '0';
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] != '0')
			{
				n = i-1;
				break;
			}
		}
		a = (a.substr(n, a.length() - n));
	}
	return a;
}

//Lay Gia Tri Truoc Dau Phay
string LayGTTPhay(string a)
{
	int n;
	if (CheckPhay(a))
		a;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '.')
			{
				n = i;
				break;
			}
		}
		a = (a.substr(0, n));
	}
	return a;
}

//Lay Gia Tri Sau Dau Phay
string LayGTSPhay(string a)
{
	int n;
	if (CheckPhay(a))
		a;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '.')
			{
				n = i;
				break;
			}
		}
		a = (a.substr(n + 1, a.length() - n - 1));
	}
	return a;
}

//lấy số lượng chử sau dấu phẩy nhiều hơn
int SauPhayMAX(string a, string b)
{
	int a_len = -1, b_len = -1;
	if (CheckPhay(a))
		a_len = 0;
	else
	{
		for (int i = a.length(); i > 0; i--)
		{
			if (a[i] == '.')
				break;
			else
				a_len++;
		}
	}
	if (CheckPhay(b))
		b_len = 0;
	else
	{
		for (int i = b.length(); i > 0; i--)
		{
			if (b[i] == '.')
				break;
			else
				b_len++;
		}
	}
	if (a_len > b_len)
		return a_len;
	else
		return b_len;
}

//lấy số lượng chử số sau dấu phẩy ít hơn
int SauPhayMIN(string a, string b)
{
	int a_len = -1, b_len = -1;
	if (CheckPhay(a))
		a_len = 0;
	else
	{
		for (int i = a.length(); i > 0; i--)
		{
			if (a[i] == '.')
				break;
			else
				a_len++;
		}
	}
	if (CheckPhay(b))
		b_len = 0;
	else
	{
		for (int i = b.length(); i > 0; i--)
		{
			if (b[i] == '.')
				break;
			else
				b_len++;
		}
	}
	if (a_len > b_len)
		return b_len;
	else
		return a_len;
}

//Insert Phay cộng trừ
string InsertPhay1(string a, string b, string c)
{
	int d = SauPhayMAX(b, c);
	a = a.substr(0, a.length() - d) + '.' + a.substr(a.length() - d, d);
	return a;
}

//Insert Phay nhân
string InsertPhay2(string a, string b, string c)
{
	int d = SauPhayMAX(b, c) * 2;
	a = a.substr(0, a.length() - d) + '.' + a.substr(a.length() - d, d);
	return a;
}

string InsertPhayCan(string a, double d)
{
	a = a.substr(0, d) + '.' + a.substr(d,a.length() - d);
	return a;
}

//làm cho 2 chuổi có độ dài bằng nhau
void ChuanHoa(string &a, string &b)//thêm số 0 ở đầu
{
	if (!CheckPhay(a) && !CheckPhay(b))
	{
		if (a.length() > b.length())
			b = b.insert(b.length(), SauPhayMAX(a, b) - SauPhayMIN(a, b), '0');
		else if (a.length() < b.length())
			a = a.insert(a.length(), SauPhayMAX(a, b) - SauPhayMIN(a, b), '0');
	}
	if (!CheckPhay(a) && CheckPhay(b))
		b = b.insert(b.length(), SauPhayMAX(a, b) - SauPhayMIN(a, b), '0');
	else if (CheckPhay(a) && !CheckPhay(b))
		a = a.insert(a.length(), SauPhayMAX(a, b) - SauPhayMIN(a, b), '0');
	DelPhay(a); DelPhay(b);
	if (a.length() > b.length())
		b = b.insert(0, a.length() - b.length(), '0');
	else if (a.length() < b.length())
		a = a.insert(0, b.length() - a.length(), '0');
	//cout << a << " " << b;
}

//So sánh chuổi nào có giá trị lớn hơn
int SoSanhLonHon(string a, string b)
{
	ChuanHoa(a, b);
	for (int i = 0; i < a.length(); i++)
	{
		if (i != a.length() - 1)
		{
			if (GiaiMa(a[i]) > GiaiMa(b[i]))
				return 1;
			else if (GiaiMa(a[i]) < GiaiMa(b[i]))
				return -1;
			else
				continue;
		}
		else
		{
			if (GiaiMa(a[i]) > GiaiMa(b[i]))
				return 1;
			else if (GiaiMa(a[i]) < GiaiMa(b[i]))
				return -1;
			else
				return 0;
		}
	}
}

//lấy ra chuổi có giá trị bé hơn
string LayMax(string a, string b)
{
	ChuanHoa(a, b);
	for (int i = 0; i < a.length(); i++)
	{
		if (i != a.length() - 1)
		{
			if (GiaiMa(a[i]) > GiaiMa(b[i]))
				return a;
			else if (GiaiMa(a[i]) < GiaiMa(b[i]))
				return b;
			else
				continue;
		}
		else
		{
			if (GiaiMa(a[i]) >= GiaiMa(b[i]))
				return a;
			else
				return b;
		}
	}
}

//Lấy ra chuổi có giá trị bé hơn
string LayMin(string a, string b)
{
	ChuanHoa(a, b);
	for (int i = 0; i < a.length(); i++)
	{
		if (i != a.length() - 1)
		{
			if (GiaiMa(a[i]) > GiaiMa(b[i]))
				return b;
			else if (GiaiMa(a[i]) < GiaiMa(b[i]))
				return a;
			else
				continue;
		}
		else
		{
			if (GiaiMa(a[i]) > GiaiMa(b[i]))
				return b;
			else
				return a;
		}
	}
}

//So Sánh Dấu của a và b
int SoSanhDau(string a, string b)
{
	if (a[0] != '-'&&b[0] != '-')//a,b>0
		return 1;
	else if (a[0] == '-'&&b[0] == '-')//a,b<0
		return -1;
	else if (a[0] != '-'&&b[0] == '-')//a>0>b
		return 2;
	else if (a[0] == '-'&&b[0] != '-')//a<0<b
		return -2;
	else
		return 0;
}

//cộng 2 chuổi với nhau
string Sum(string a, string b)
{
	ChuanHoa(a, b);
	string sum;
	int temp = 0;
	for (int i = a.length() - 1; i >= 0; i--)   // duyet va cong
	{
		temp = GiaiMa(a[i]) + GiaiMa(b[i]) + temp;    // tinh tong tung doi mot
		sum.insert(0, 1, MaHoa(temp % 10));         // gan phan don vi vao
		temp = temp / 10;     // lay lai phan hang chuc
	}
	if (temp > 0)  // neu hang chuc > 0 thi them vao KQ
	{
		sum.insert(0, 1, MaHoa(temp));
	}
	return sum;
}

//trừ 2 chuổi với nhau
string Sub(string a, string b)
{
	ChuanHoa(a, b);
	string sub;
	int temp = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		if (GiaiMa(a[i]) >= (GiaiMa(b[i]) + temp))
		{
			temp = GiaiMa(a[i]) - (GiaiMa(b[i]) + temp);
			sub.insert(0, 1, MaHoa(temp));
			temp = 0;
		}
		else
		{
			temp = (GiaiMa(a[i]) + 10) - (GiaiMa(b[i]) + temp);
			sub.insert(0, 1, MaHoa(temp));
			temp = 1;
		}
	}
	return sub;
}

//nhân 2 chuỗi với nhau
string Mul(string &a, string &b)
{
	ChuanHoa(a, b);
	string mul = "0";
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int temp = 0;
		string Temp = "";
		Temp = Temp.insert(0, (a.length() - 1) - i, '0');
		for (int j = b.length() - 1; j >= 0; j--)
		{
			temp = GiaiMa(a[i])*GiaiMa(b[j]) + temp;
			Temp = Temp.insert(0, 1, MaHoa(temp % 10));
			temp = temp / 10;
			if (j == 0 && temp != 0)
				Temp = Temp.insert(0, 1, MaHoa(temp));
		}
		mul = Sum(mul, Temp);
	}
	return mul;
}

//chia số thực
string DivThuc(string a, string b)
{
	ChuanHoa(a, b);
	string chia;
	string Temp1;
	string Temp3;
	for (int i = 0; i < a.length(); i++)
	{
		Temp1 = Temp1.insert(Temp1.length(), 1, a[i]);
		if (SoSanhLonHon(Del0Dau(Temp1), b) == -1)
			chia = chia.insert(chia.length(), 1, '0');
		else
		{
			int j = 1;
			while (Temp1 != Temp3)
			{
				string Temp2 = Mul(b, MaHoa1(j));
				if (SoSanhLonHon(Temp1, Temp2) == -1)
				{
					chia = chia.insert(chia.length(), 1, MaHoa((j - 1) % 10));
					Temp2 = Mul(b, MaHoa1(j - 1));
					Temp3 = Sub(Temp1, Temp2);
					Temp1 = Temp3;
				}
				else if (SoSanhLonHon(Temp1, Temp2) == 0)
				{
					chia = chia.insert(chia.length(), 1, MaHoa((j) % 10));
					Temp2 = Mul(b, MaHoa1(j));
					Temp3 = Sub(Temp1, Temp2);
					Temp1 = Temp3;
				}
				j++;
			}
		}
	}
	chia = chia.insert(chia.length(), 1, '.');
	int d = 0;
	while (d != 10)
	{
		Temp1 = Temp1.insert(Temp1.length(), 1, '0');
		if (SoSanhLonHon(Del0Dau(Temp1), b) == -1)
			chia = chia.insert(chia.length(), 1, '0');
		else
		{
			int j = 1;
			while (Temp1 != Temp3)
			{
				string Temp2 = Mul(b, MaHoa1(j));
				if (SoSanhLonHon(Temp1, Temp2) == -1)
				{
					chia = chia.insert(chia.length(), 1, MaHoa((j - 1) % 10));
					Temp2 = Mul(b, MaHoa1(j - 1));
					Temp3 = Sub(Temp1, Temp2);
					Temp1 = Temp3;
				}
				else if (SoSanhLonHon(Temp1, Temp2) == 0)
				{
					chia = chia.insert(chia.length(), 1, MaHoa((j) % 10));
					Temp2 = Mul(b, MaHoa1(j));
					Temp3 = Sub(Temp1, Temp2);
					Temp1 = Temp3;
				}
				j++;
			}
		}
		d++;
	}
	return (chia);
}


//chia lay nguyen
string Div(string a, string b)
{
	ChuanHoa(a, b);
	string chia;
	string SoChia;
	string PhanDu;
	for (int i = 0; i < a.length(); i++)
	{
		SoChia = SoChia.insert(SoChia.length(), 1, a[i]);
		if (SoSanhLonHon(Del0Dau(SoChia), b) == -1)
			chia = chia.insert(chia.length(), 1, '0');
		else
		{
			int j = 1;
			while (SoChia != PhanDu)
			{
				string SoNhan = Mul(b, MaHoa1(j));
				if (SoSanhLonHon(SoChia, SoNhan) == -1)
				{
					chia = chia.insert(chia.length(), 1, MaHoa((j - 1) % 10));
					SoNhan = Mul(b, MaHoa1(j - 1));
					PhanDu = Sub(SoChia, SoNhan);
					SoChia = PhanDu;
				}
				else if (SoSanhLonHon(SoChia, SoNhan) == 0)
				{
					chia = chia.insert(chia.length(), 1, MaHoa((j) % 10));
					SoNhan = Mul(b, MaHoa1(j));
					PhanDu = Sub(SoChia, SoNhan);
					SoChia = PhanDu;
				}
				j++;
			}
		}
	}
	return Del0Dau(chia);
}

//chia lay du
string div(string a, string b)
{
	ChuanHoa(a, b);
	string chia;
	string SoChia;
	string PhanDu;
	if (SoSanhLonHon(a, b) == -1)
		SoChia = a;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			SoChia = SoChia.insert(SoChia.length(), 1, a[i]);
			if (SoSanhLonHon(Del0Dau(SoChia), b) == -1)
				chia = chia.insert(chia.length(), 1, '0');
			else
			{
				int j = 1;
				while (SoChia != PhanDu)
				{
					string SoNhan = Mul(b, MaHoa1(j));
					if (SoSanhLonHon(SoChia, SoNhan) == -1)
					{
						chia = chia.insert(chia.length(), 1, MaHoa((j - 1) % 10));
						SoNhan = Mul(b, MaHoa1(j - 1));
						PhanDu = Sub(SoChia, SoNhan);
						SoChia = PhanDu;
					}
					else if (SoSanhLonHon(SoChia, SoNhan) == 0)
					{
						chia = chia.insert(chia.length(), 1, MaHoa((j) % 10));
						SoNhan = Mul(b, MaHoa1(j));
						PhanDu = Sub(SoChia, SoNhan);
						SoChia = PhanDu;
					}
					j++;
				}
			}
		}
	}
	return SoChia;
}

string LayCan(string n)
{
	string T = Del0(LayGTTPhay(n));
//	cout << "\nT " << Del0(T);
	int q = LayGTTPhay(n).length() % 2;
	if (q  == 0)
		q = LayGTTPhay(n).length() / 2;
	else
		q = 1 + (LayGTTPhay(n).length() / 2);
	//cout << "\nq = " << q;
	ChuanHoaCan(n);
	string KQ = "0";
	string SoChia;
	string Temp;
	string PhepThu;
	int i;
	if (n.length() % 2 != 0)
		i = 0;
	else
		i = 1;
	//cout << "\ni = " << i;
	Temp = n.substr(0,i+1);
	//cout << "\nTemp = " << Temp;
	for (int z = i; z < n.length(); z += 2)
	{
		SoChia = Del0Dau(SoChia) + Temp;
		//cout << "\nSoChia = " << SoChia;
		int j = 0;
		while (1)
		{
			PhepThu = Del0Dau(Mul(Sum(Mul(KQ, MaHoa1(20)), MaHoa1(j)), MaHoa1(j)));
			//cout << "\nPhep Thu = " << PhepThu;
			if (SoSanhLonHon(Del0Dau(PhepThu), SoChia) == 0)
			{
				j;
				break;
			}
			else if (SoSanhLonHon(Del0Dau(PhepThu), SoChia) == 1)
			{
				j -= 1;
				break;
			}
			else
				j++;
		}
		//cout << "\n j = " << j;
		PhepThu = Del0Dau(Mul(Sum(Mul(KQ, MaHoa1(20)), MaHoa1(j)), MaHoa1(j)));
		KQ = Del0Duoi(KQ.insert(KQ.length(), 1, MaHoa(j)));
		//cout << "\nKQ = " << KQ;
		//cout << "\nPhep Thu = " << PhepThu;
		SoChia = Del0Dau(Sub(SoChia, PhepThu));
		//cout << "\nSoChia Sau Sub = " << SoChia;
		Temp = n.substr(z+1, 2);
	}
	//cout << "\nTemp = " << Temp;
	if (SoSanhLonHon(SoChia, "0") == 0 && T != "0")
		KQ = Del0Duoi(Del0Dau(KQ));
	else
	{
		int d = 0;
		Temp = Temp.insert(Temp.length(), 2, '0');
		while (d != 9)
		{
			SoChia = SoChia + Temp;
			//cout << "\nSoChia = " << SoChia;
			int j = 0;
			while (1)
			{
				PhepThu = Del0Dau(Mul(Sum(Mul(KQ, MaHoa1(20)), MaHoa1(j)), MaHoa1(j)));
				//cout << "\nPhep Thu = " << PhepThu;
				if (SoSanhLonHon(Del0Dau(PhepThu), SoChia) == 0)
				{
					j;
					break;
				}
				else if (SoSanhLonHon(Del0Dau(PhepThu), SoChia) == 1)
				{
					j -= 1;
					break;
				}
				else
					j++;
			}
			//cout << "\n j = " << j;
			PhepThu = Del0Dau(Mul(Sum(Mul(KQ, MaHoa1(20)), MaHoa1(j)), MaHoa1(j)));
			KQ =Del0Duoi(KQ.insert(KQ.length(), 1, MaHoa(j)));
			//cout << "\nKQ = " << KQ;
			SoChia = Del0Dau(Sub(SoChia, PhepThu));
			//cout << "\nSoChia Sau Sub = " << SoChia;
			d++;
		}
		if (T == "0")
		{
			KQ = Del0Duoi(InsertPhayCan((KQ.erase(0,2)),q));
			//cout << "\nKQ =  " << KQ;
		}
		else
			KQ = Del0Duoi(InsertPhayCan(Del0Dau(KQ), q));
	}
	return KQ;
}

string ChuanHoaCan(string& n)
{
	if (CheckPhay(n))
		n;
	else
	{
		if (LayGTSPhay(n).length() % 2 == 0)
			n = DelPhay(n);
		else
			n = (DelPhay(n)).insert(DelPhay(n).length(), 1, '0');
	}
	return n;
}
































