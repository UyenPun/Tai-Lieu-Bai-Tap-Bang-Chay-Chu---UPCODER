#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define SIZE_BANGCHU 56

void XuatBangChu(char bangchu[])
{
	for(int i = 1; i <= SIZE_BANGCHU + 2; ++i)
		printf("+");

	printf("\n+%s+\n", bangchu);

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
	char chu[] = "UPCODER";
	
	char bangchu[SIZE_BANGCHU + 1];
	KhoiTaoBangChu(bangchu);

	int dodai_chu = strlen(chu);
	
	//XuatBangChu(bangchu);

	// Cách 1
	time_t start1 = clock();
	for(int k = 1; k <= 10000; ++k)
	{
		int idx = 0;
		char kytuchen;
		for(int i = 1; i <= dodai_chu + SIZE_BANGCHU; ++i)
		{
			if(idx < dodai_chu)
				kytuchen = chu[idx++];
			else
				kytuchen = ' ';

			XoaODauTienVaChenVaoCuoiKyTuCuThe(bangchu, kytuchen);

			//printf("\n");
			//XuatBangChu(bangchu);
		}
	}
	
	time_t end1 = clock();

	// Cách 2

	char bangchu_2[SIZE_BANGCHU + 1];
	KhoiTaoBangChu(bangchu_2);

	time_t start2 = clock();
	for(int k = 1; k <= 10000; ++k)
	{
		int idx_2 = 0;
		int count = 0;
		int start_idx = SIZE_BANGCHU - 1;
		for(int i = 1; i <= dodai_chu + SIZE_BANGCHU; ++i)
		{
			if(idx_2 < dodai_chu)
			{
				bangchu_2[start_idx + count] = chu[idx_2++];
				count++;
			}
			else
				bangchu_2[start_idx + count] = ' ';


			//printf("\n");
			//XuatBangChu(bangchu_2);
		

			for(int j = start_idx; j < start_idx + count; ++j)
			{
				if(j <= 0 || j >= SIZE_BANGCHU) 
					continue;

				bangchu_2[j - 1] = bangchu_2[j];
			}
			start_idx--;
		}
	}
	
	time_t end2 = clock();

	printf("\ntime1 = %d miliseconds", end1 - start1);
	printf("\ntime2 = %d miliseconds", end2 - start2);

	getch();
	return 0;
}