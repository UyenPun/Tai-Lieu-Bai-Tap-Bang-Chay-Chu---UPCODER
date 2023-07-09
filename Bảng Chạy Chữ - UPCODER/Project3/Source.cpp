#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <Windows.h>
using namespace std;
#define SIZE_BANGCHU 100

int mamau = 14; // mặc định là màu vàng

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void XuatBangChu(char bangchu[])
{
	for(int i = 1; i <= SIZE_BANGCHU + 2; ++i)
		printf("+");

	printf("\n+");

	textcolor(mamau);
	printf("%s", bangchu);

	textcolor(7); // reset màu trở lại bình thường

	printf("+\n");

	for(int i = 1; i <= SIZE_BANGCHU + 2; ++i)
		printf("+");
}

void KhoiTaoBangChu(char bangchu[])
{
	for(int i = 0; i < SIZE_BANGCHU; ++i)
		bangchu[i] = ' ';

	bangchu[SIZE_BANGCHU] = '\0'; // ký tự kết thúc chuỗi
}

void XoaODauTienVaChenVaoCuoiKyTuCuThe(char bangchu[], char kytuchen)
{
	for(int i = 1; i < SIZE_BANGCHU; ++i)
	{
		bangchu[i - 1] = bangchu[i];
	}
	bangchu[SIZE_BANGCHU - 1] = kytuchen;
}

int main()
{
	// Cách tra cứu bảng mã màu
	/*for(int i = 1; i <= 300; ++i)
	{
		textcolor(i);
		printf("\ni = %d", i);
	}*/

	
	char chu[] = "TRAN DUONG THUY LINH - ANH YEU EM";
	char bangchu_2[SIZE_BANGCHU + 1];
	KhoiTaoBangChu(bangchu_2);

	int dodai_chu = strlen(chu);

	XuatBangChu(bangchu_2);

	// Cách 2

	int idx_2 = 0;
	int count = 0;
	int start_idx = SIZE_BANGCHU - 1;
	int dem = 0;

	while(true) // vòng lặp vô tận
	{
		XoaManHinh();
		Sleep(50);

		if(GetAsyncKeyState(VK_SPACE)) // nếu người dùng nhấn vào phím cách (space) => pause
		{
			//continue; // Nếu nhấn đè phím space thì dừng lại, thả ra thì nó chạy tiếp

			// để cho nó pause lại nhưng vẫn nằm trong vòng lặp không bị thoát ra thì cách xử lý là đưa nó vào trong luồng của 1 vòng lặp while(true) khác và nó bị kẹt ở đó
			while(true)
			{
				// nếu người dùng nhấn vào phím enter => play tiếp
				if(GetAsyncKeyState(VK_RETURN))
				{
					break; // Thoát ra khỏi vòng lặp while(true) con hiện tại để trở về vòng lặp while(true) cha ban đầu
				}
			}
		}
		else if(GetAsyncKeyState(VK_ESCAPE)) // nếu người dùng nhấn vào phím Esc thì thoát chương trình
			break;

		if(idx_2 < dodai_chu)
		{
			bangchu_2[start_idx + count] = chu[idx_2++];
			count++;
		}
		else
			bangchu_2[start_idx + count] = ' ';

		XuatBangChu(bangchu_2);

		for(int j = start_idx; j < start_idx + count; ++j)
		{
			if(j <= 0 || j >= SIZE_BANGCHU) 
				continue;

			bangchu_2[j - 1] = bangchu_2[j];
		}
		start_idx--;

		dem++;
		if(dem == dodai_chu + SIZE_BANGCHU)
		{
			dem = 0;
			idx_2 = 0;
			count = 0;
			start_idx = SIZE_BANGCHU - 1;

			// reset cho hiện ra màu khác trong đoạn từ 1 đến 300
			mamau = 1 + rand() % 300; // [a, b] => a + rand() % (b - a + 1)
		}
	}

	getch();
	return 0;
}