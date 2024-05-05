#include <iostream>
#include <cstring>
using namespace std;

struct SinhVien
{
	int stt;
	int mssv;
	char* ten;
	char* ho;
	char* gender;
	int ngay, thang, nam;
	long int cccd;
	SinhVien* next;
};
struct Lop
{
	SinhVien* danhsachsv;
};
bool kiemtrangaysinh(int ngay, int thang, int nam)
{
	if (ngay < 1 || ngay > 31 || thang < 1 || thang >12 || nam < 1)
	{
		return false;
	}
	if (thang == 2)
	{
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		{
			if (ngay > 29)
			{
				return false;
			}
		}
		else
		{
			if (ngay > 28)
			{
				return false;
			}
		}
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
	{
		if (ngay > 30)
		{
			return false;
		}
	}
	else
	{
		if (ngay > 31)
		{
			return false;
		}
	}
	return true;
}
void taosv(int& STT, int& MSSV, char ten[], char ho[], char gender[], int& ngay, int& thang, int& nam, long int& cccd)
{
	cout << "Nhap vao so thu tu:";
	cin >> STT;
	cin.ignore();
	cout << "Nhap vao ho cua sinh vien:";
	cin.getline(ho, 10);
	cout << "Nhap vao ten cua sinh vien:";
	cin.getline(ten, 30);
	cout << "Nhap vao mssv:";
	cin >> MSSV;
	do
	{
		cin.ignore();
		cout << "Nhap vao gioi tinh sinh vien (Nam/Nu):";
		cin.getline(gender, 5);
	} while (strcmp(gender, "Nam") != 0 && strcmp(gender, "Nu") != 0 && strcmp(gender, "nam") != 0 && strcmp(gender, "nu") != 0);
	do
	{
		cout << "Nhap vao ngay thang nam sinh cua sinh vien:" << endl;
		cout << "Nhap vao ngay:";
		cin >> ngay;
		cout << "Nhap vao thang:";
		cin >> thang;
		cout << "Nhap vao nam:";
		cin >> nam;
		if (kiemtrangaysinh(ngay, thang, nam) == false)
		{
			cout << "Ngay sinh khong hop le,vui long nhap lai" << endl;
		}
	} while (kiemtrangaysinh(ngay, thang, nam) == false);
	cout << "Nhap vao so cccd cua sinh vien:";
	cin >> cccd;
}
void themsvvaolop(Lop& lop, int& STT, int& MSSV, char ten[], char ho[], char gender[], int& ngay, int& thang, int& nam, long int& cccd)
{
	SinhVien* temp = lop.danhsachsv;
	if (temp == nullptr)
	{
		lop.danhsachsv = new SinhVien;
		temp = lop.danhsachsv;
	}
	else
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new SinhVien;
		temp = temp->next;
	}
	temp->cccd = cccd;
	temp->gender = new char[strlen(gender) + 1];
	strcpy_s(temp->gender, strlen(gender) + 1, gender);
	temp->ho = new char[strlen(ho) + 1];
	strcpy_s(temp->ho, strlen(ho) + 1, ho);
	temp->ten = new char[strlen(ten) + 1];
	strcpy_s(temp->ten, strlen(ten) + 1, ten);
	temp->ngay = ngay;
	temp->thang = thang;
	temp->nam = nam;
	temp->next = nullptr;
	temp->stt = STT;
	temp->mssv = MSSV;
}
int main()
{
	int STT, MSSV, ngay, thang, nam;
	long int cccd;
	char ten[30], ho[10], gender[5];
	Lop CTT5;
	CTT5.danhsachsv = nullptr;
	taosv(STT, MSSV, ten, ho, gender, ngay, thang, nam, cccd);
	themsvvaolop(CTT5, STT, MSSV, ten, ho, gender, ngay, thang, nam, cccd);
	cout << "Thong tin hoc sinh trong lop CTT5:" << endl;
	cout << "So thu tu:" << CTT5.danhsachsv->stt << endl;
	cout << "Ho va ten:" << CTT5.danhsachsv->ho << " " << CTT5.danhsachsv->ten << endl;
	cout << "So can cuoc cong dan:" << CTT5.danhsachsv->cccd << endl;
	cout << "Ngay sinh:" << CTT5.danhsachsv->ngay << "/" << CTT5.danhsachsv->thang << "/" << CTT5.danhsachsv->nam << endl;
	cout << "ket thuc";
	Lop CTT3;
	CTT3.danhsachsv = nullptr;
	taosv(STT, MSSV, ten, ho, gender, ngay, thang, nam, cccd);
	themsvvaolop(CTT3, STT, MSSV, ten, ho, gender, ngay, thang, nam, cccd);
	cout << "Thong tin hoc sinh trong lop CTT3:" << endl;
	cout << "So thu tu:" << CTT3.danhsachsv->stt << endl;
	cout << "Ho va ten:" << CTT3.danhsachsv->ho << " " << CTT3.danhsachsv->ten << endl;
	cout << "So can cuoc cong dan:" << CTT3.danhsachsv->cccd << endl;
	cout << "Ngay sinh:" << CTT3.danhsachsv->ngay << "/" << CTT3.danhsachsv->thang << "/" << CTT3.danhsachsv->nam << endl;
	return 0;
}