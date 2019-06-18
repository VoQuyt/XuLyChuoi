#include "HinhChuNhat.h"
#include "HinhVuong.h"
#include "HinhTron.h"
#include "HinhHoc.h"
#include "DanhSachHinh.h"
#include "HinhTamGiac.h"
#include <iostream>
#include <conio.h>
#include "SoNguyen.h"
#include "SoThuc.h"
#include "Library.h"
#include <string>

using namespace std;

void main()
{
	
	/*CDanhSachHinh *DSH = new CDanhSachHinh();
	DSH->Nhap();
	cout << "Hinh co dien tich lon nhat: "; DSH->HinhCoSMax();
	cout<<"\nTong Dỉn tich cua tat ca cac hinh "<<DSH->TongDienTich();*/

	//chào các bạn, hôm nay mình sẽ demo cho các bạn xem đồ án oop năm 2 của mình

	//như các bạn biết các kiểu dử liệu trong visual mà ta có như int, float, double...

	//(ở đây mình chỉ nói đến kiểu dử liệu số) thì chúng có chung một đặc điểm là có giới hạn số lượng phần tử.

	//bài đồ án này của mình sẽ khắc phục điểu đó, tức là nhập không giới hạn phần tử (trừ khi phần cứng không cho phép như bộ nhớ ram nhỏ...)

	//trong đồ án này mình làm 2 kiểu dử liệu, đó là kiểu dử liệu CSoNguyen và CSoThuc, nhưng để tiết kiệm thời gian thì mình sẽ demo kiểu CSoThuc, vì số thực nó tổng quát hơn số nguyên rất nhiều

	//trước khi vào phần demo thì mình sẽ show qua code một tý cho các bạn xem nhé!!! 

	//Thư viện library là thư viện mình tạo ra để nhằm hổ trợ trong quá trình tính toán của thư viện CSoThuc và CSoNguyen, bên cạnh đó mình củng nhờ một số hàm khác của thư viện string để hoàn thành bài tập này nửa! :)

	//demo nhé!!!!
	//giờ mình nhập số lớn để thể hiện sự khác biệt nhé

	//kiểu dử liệu này của mình có thể làm việc với tát cả các kiểu dử liệu khác như sử dụng để gán, so sánh,...
	//thậm chí nó có thể được gán cho một chuổi(chuổi này chuổi số thì được nhé, còn chuổi chử thì chắc chắn không thực hiện tính toán như bình thường được rồi!)

	//Thử tính toán xem nhé!!
	//các bạ có thể mang máy tính ra test thử xem
	//ở đây các bạn tránh nhầm lẩm giúp mình nek!

	//a ở đây tức là c tức là b
	//còn b tức là a
	//để mình đổi lại cho dể hiểu không thì các bạ lại rối rồi nói kết quả sai
	//giờ thì đúng rồi đấy!

	//còn j nửa không ta!!!
	//ak! mình còn cả hàm khai căn luôn nhé!

	/*CSoThuc a;
	cin >> a;
	cout << "can bac 2 cua a: " << a.Can();*/
	
	CSoNguyen a, b;
	cout << "nhap a: "; cin >> a;
	cout << "nhap b: "; cin >> b;
	cout << a + b;




	/*string c;
	cout << "Nhap chuoi c: ";
	rewind(stdin);
	getline(cin, c);
		CSoThuc a, b;
		cin >> b;
		a = c;
		cout << "\na + b = " << a + b << endl;
		cout << "\na - b = " << a - b << endl;
		cout << "\na * b = " << a * b << endl;
		cout << "\na / b = " << a / b << endl;*/



	








	//phần cuối cùng này mình xin bóc phốt visual tí cho vui! ^-^ hjhj


	/*CSoThuc a;
	float b;
	cin >> a;
	cout << "nhap so float b: "; cin >> b;

	cout << "CSoThuc: "<<a<<" * 0 = " << a * 0 << endl;
	cout << "Float: "<<b<<" * 0 = " << b * 0 << endl;*/

	//cảm ơn các bạn đã dành thời gian xem video của mình...!!!

	_getch();
}