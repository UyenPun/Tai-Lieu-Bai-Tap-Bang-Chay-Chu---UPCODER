#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define SIZE_BANGCHU 20

void XuatBangChu(string bangchu)
{
	string daydaucong(SIZE_BANGCHU + 2, '+');

	cout << daydaucong << endl;
	cout << "+" << bangchu << "+" << endl;
	cout << daydaucong;
}

int main()
{
	string chu = "UPCODER";
	string bangchu(SIZE_BANGCHU, ' ');
	//time_t start1 = clock();

	//XuatBangChu(bangchu);

	int dodai_chu = chu.length();

	// Cách 1
	/*
	int idx = 0;
	for(int i = 1; i <= dodai_chu + SIZE_BANGCHU; ++i)
	{
		if(idx < dodai_chu)
			bangchu.push_back(chu[idx++]);
		else
			bangchu.push_back(' ');

		bangchu.erase(bangchu.begin());

		//cout << endl;
		//XuatBangChu(bangchu);
		
	}*/
	//time_t end1 = clock();

	//cout << "\n\n-----------------------\n\n";

	string bangchu_2(SIZE_BANGCHU, ' ');

	//time_t start2 = clock();
	XuatBangChu(bangchu_2);

	// Cách 2
	int idx_2 = 0;
	int count = 0;
	int start_idx = SIZE_BANGCHU - 1;
	for(int i = 1; i <= dodai_chu + SIZE_BANGCHU; ++i)
	{
		if(idx_2 < dodai_chu)
		{
			bangchu_2[start_idx + count] = chu[idx_2++];
			count++;
			//bangchu.push_back(chu[idx++]);
		}
		else
			//bangchu.push_back(' ');
			bangchu_2[start_idx + count] = ' ';

		//bangchu.erase(bangchu.begin());

		cout << endl;
		XuatBangChu(bangchu_2);
		

		for(int j = start_idx; j < start_idx + count; ++j)
		{
			if(j <= 0 || j >= SIZE_BANGCHU) 
				continue;

			bangchu_2[j - 1] = bangchu_2[j];
		}
		start_idx--;
	}
	//time_t end2 = clock();

	//cout << "\nTime1 = " << end1 - start1;
	//cout << "\nTime2 = " << end2 - start2;
	
	system("pause");
	return 0;
}