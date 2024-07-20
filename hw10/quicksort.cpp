#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

/*
    mode = 1 then original
    mode = 2 then longer first
    mode = 3 then shorter first

    mode2 = true then leftmost
    mode2 = false then median of 3
*/

int median(int x, int y, int z)
{
    if (x > y)
    {
        if (y > z) return y;
        else if (x > z) return z;
        else return x;
    }
    else
    {
        if (x > z) return x;
        else if (y > z) return z;
        else return y;
    }
}

void qsort(vector <int> case0, int left, int right, int mode, bool mode2)
{
	int i, j, pivot;

	if(left < right)
    {
		i = left;
		j = right + 1;

		if(!mode2)
		{
			int m = median(case0[left],case0[right],case0[(left+right)/2]);
			if(m == case0[(left+right)/2])
                swap(case0[left],case0[(left+right)/2]);
			else
                if(m == case0[right])
                    swap(case0[left],case0[right]);
		}

		pivot = case0[left];

		do
        {
			do i++; while (case0[i] < pivot);
			do j--; while (case0[j] > pivot);
			if (i < j) swap(case0[i], case0[j]);
		} while (i < j);

		swap(case0[left],case0[j]);

		switch(mode){
			case 1:
				qsort(case0, left,j-1, mode, mode2);
				qsort(case0, j+1,right, mode, mode2);
			break;
			case 2:
				if((j-1) - left > right - (j+1))
                {
					qsort(case0, left, j-1, mode, mode2);
					qsort(case0, j+1, right, mode, mode2);
				}
				else
                {
					qsort(case0, j+1, right, mode, mode2);
					qsort(case0, left, j-1, mode, mode2);
				}
			break;
			case 3:
				if((j-1) - left < right - (j+1))
                {
					qsort(case0, left, j-1, mode, mode2);
					qsort(case0, j+1, right, mode, mode2);
				}
				else
                {
					qsort(case0, j+1, right, mode, mode2);
					qsort(case0, left, j-1, mode, mode2);
				}
			break;
		}
	}
}

int main(){

    vector <int> case1, case2, case3, case4, case5, case6;

	int data;

	ifstream file("hw10.txt");

	while(file >> data)
    {
		case1.push_back(data);
		case2.push_back(data);
		case3.push_back(data);
		case4.push_back(data);
		case5.push_back(data);
		case6.push_back(data);
	}

	file.close();

	clock_t start, end;
	double cpu_time_used;

	start = clock();

	qsort(case1, 0, case1.size()-1, 1, true);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	cout << "leftmost and original = " << cpu_time_used << "\n";

	start = clock();

	qsort(case2, 0, case2.size()-1, 2, true);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	cout << "leftmost and longer first = " << cpu_time_used << "\n";

	start = clock();

	qsort(case3, 0, case3.size()-1, 3, true);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	cout << "leftmost and shorter first = " << cpu_time_used << "\n";

	start = clock();

	qsort(case4, 0, case4.size()-1, 1, false);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	cout << "median of three and original = " << cpu_time_used << "\n";

	start = clock();

	qsort(case5, 0, case5.size()-1, 2, false);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	cout << "median of three and longer first = " << cpu_time_used << "\n";

	start = clock();

	qsort(case6, 0, case6.size()-1, 3, false);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	cout << "median of three and shorter first = " << cpu_time_used << "\n";

	return 0;
}
