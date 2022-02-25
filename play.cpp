#include "pch.h"
#include <iostream>
using namespace std;

void split(int n, int arr[])
{
	arr[0] = n / 1000;
	arr[1] = (n / 100) % 10;
	arr[2] = (n / 10) % 10;
	arr[3] = n % 10;
}
bool hasZero(int n)
{
	int num[4];
	split(n, num);
	if ((num[0] * num[1] * num[2] * num[3]) == 0)
		return false;
	else
		return true;
}
bool repeat(int n) {
	int arr[4];
	split(n, arr);
	int i = 0;
	if (arr[i] == arr[i + 1] or arr[i] == arr[i + 2] or arr[i] == arr[i + 3] or arr[i + 1] == arr[i + 2] or arr[i + 1] == arr[i + 3] or arr[i + 2] == arr[i + 3])
		return false;
	else return true;

}

int main()
{
	cout << "1102015" << endl;
	cout << "林俊霖" << endl;
	int a = 0, b = 0;
	int all[3024] = { 0 };
	int num = 1234;
	for (int i = 0; num < 9876; num++)
	{
		if (hasZero(num) && repeat(num))
		{
			all[i] = num;
			i++;
		}
	}

	while (a != 4) {
		int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
		int c;
		int targetarray[4];
		for (int i = 0; i < 3024; i++) {
			if (all[i] != -1) {
				c = all[i];
				cout << c << endl;
				all[i] = -1;
				break;
			}
		}

		cout << "A:" << endl; cin >> a;
		cout << "B:" << endl; cin >> b;
		if (a == 0 && b == 0) {
			split(c, targetarray);
			for (int i = 0; i < 4; i++) {
				compare[targetarray[i]] = -1;
			}
		}
	}
}
