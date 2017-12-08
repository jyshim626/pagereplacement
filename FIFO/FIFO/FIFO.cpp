#include "stdafx.h"
#include <iostream>

using namespace std;

int getReplaceposition(int counter[], int n)
{
	int max = counter[0];
	int pos = 0;
	for (int i = 0; i<n; i++) {
		if (counter[i]>max)
		{
			pos = i;
			max = counter[i];
		}
	}

	return pos;
}

int main()
{
	int pages[20], frames[10], counter[10];
	int nPages, nFrames, pageFault = 0;

	cout << "Enter the number of frames: "; cin >> nFrames;

	cout << "Enter the number of pages: "; cin >> nPages;

	cout << "Enter the Page reference string: ";
	for (int i = 0; i<nPages; i++) {
		cin >> pages[i];
	}

	for (int i = 0; i<nFrames; i++)
	{
		frames[i] = 0;
		counter[i] = 0;
		//frame을 비우기 위해 0으로 초기화
	}

	for (int i = 0; i<nPages; i++)
	{
		int flag = 0;
		for (int j = 0; j<nFrames; j++)
		{
			//만약 page가 fram안에 이미 존재한다면 flag=1로 정의
			if (frames[j] == pages[i])
			{
				flag = 1;
				break;
			}
		}
		//만약 page가 fram안에 존재하지 않는다면 flag=0으로 정의
		if (flag == 0)
		{
			pageFault++;
			for (int j = 0; j<nFrames; j++)
			{
				if (frames[j] == 0)
				{
					frames[j] = pages[i];
					flag = 1;
					counter[j]++;
					break;
				}

			}
		}

		//fram안에 빈 공간이 없을 경우 
		if (flag == 0)
		{
			int pos = getReplaceposition(counter, nFrames);
			frames[pos] = pages[i];
			counter[pos] = 1;
			for (int k = 0; k<nFrames; k++)
			{
				if (k != pos)
					counter[k]++;
			}
		}

		cout << endl;
		for (int j = 0; j<nFrames; j++)
		{
			cout << frames[j] << "\t";
		}


	}

	cout << "\n\n Total Page Faults = " << pageFault;


	return 0;
}
