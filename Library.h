#pragma once
#include <iostream>
#include <string>
using namespace std;

//chuyen chu sang so
int GiaiMa(char a);
// chuyen so sang chu
char MaHoa(int n);

//chuyen số kiểu int sang chuổi
string MaHoa1(int n);

//chuyển 2 biến cùng kiểu thành 1 số thực
string MaHoa2(string a,string b);

//so sang do dai chuoi
int SoSanhLoong(string a, string b);

//thêm dấu âm đầu chuổi
string InsertAm(string a);

//bỏ dấu âm đầu chuổi
string DelAm(string a);

//Kiểm tra số có phải là số âm hay không
bool CheckAm(string a);

//kiểm tra chuổi có 1 phần tử và phần tử đó bằng 0
bool Check0(string a);

//bỏ số 0 đầu đầu chuổi cho số thực
string Insert0dau(string a);

//insert 0 va . đầu chuổi
string Insert0vacham(string &a);

string Del0(string a);

//bỏ số 0 dầu chuổi
string Del0Dau(string a);

//bỏ số 0 đầu chuổi có chấm
string Del0DauThuc(string &a);

//Insert Phay cộng trừ
string InsertPhay1(string a, string b, string c);

//Insert Phay nhân
string InsertPhay2(string a, string b, string c);

//them dau phay cho phan tim can
string InsertPhayCan(string a, double d);

//ham kiem tra dau phay
bool CheckPhay(string a);

//ham xoa dau phay
string DelPhay(string &a);

//xoa so 0 bi du sau dau phay
string Del0Duoi(string &a);

//Lay Gia Tri Truoc Dau Phay
string LayGTTPhay(string a);

//Lay Gia Tri Sau Dau Phay
string LayGTSPhay(string a);

//lấy số lượng chử sau dấu phẩy nhiều hơn
int SauPhayMAX(string a, string b);

//lấy số lượng chử số sau dấu phẩy ít hơn
int SauPhayMIN(string a, string b);

//làm cho 2 chuổi có độ dài bằng nhau
void ChuanHoa(string &a, string &b);

//So sánh chuổi nào có giá trị lớn hơn
int SoSanhLonHon(string a, string b);

//lấy ra chuổi có giá trị bé hơn
string LayMax(string a, string b);

//Lấy ra chuổi có giá trị bé hơn
string LayMin(string a, string b);

//So Sánh Dấu của a và b
int SoSanhDau(string a, string b);

//cộng 2 chuổi với nhau
string Sum(string a, string b);

//trừ 2 chuổi với nhau
string Sub(string a, string b);

//nhân 2 chuỗi với nhau
string Mul(string &a, string &b);

//chia lấy nguyên
string Div(string a, string b);

//Chia lấy dư
string div(string a, string b);

//chia số thực
string DivThuc(string a, string b);

string LayCan(string n);

string ChuanHoaCan(string& n);