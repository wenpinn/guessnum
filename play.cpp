#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int M[4] = { 0,0,0,0 };
int P[4] = { 0,0,0,0 };
string hint;

int guess(int *list) {
	int i = rand() % 3024;
	cout << list[i] << endl;
	int j = list[i];
	return j;
}

void split(int num) {    //分割數字存在陣列 M
	M[0] = num / 1000;
	M[1] = (num % 1000) / 100;
	M[2] = (num % 100) / 10;
	M[3] = num % 10;
}

void split2(int O) {    //分割數字存在陣列 P 以與陣列 M 比較
	P[0] = O / 1000;
	P[1] = (O % 1000) / 100;
	P[2] = (O % 100) / 10;
	P[3] = O % 10;
}

int noZero() {    //檢測數字是否有0
	if (M[0] * M[1] * M[2] * M[3] == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int noRepeat() {    //檢測數字是否有重複
	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };    //所有可能數字 0為方便後續
	for (int i = 0; i < 4; i++) {
		if (compare[M[i]] == -1) {    //遇到-1則回傳0
			return 0;
		}
		else {
			compare[M[i]] = -1;    //用過的設為-1
		}
	}
	return 1;
}

void all(int *list) {    //列出所有可能數字
	int k = 0;
	for (int N = 1234; N <= 9876; N++) {
		split(N);    //分割方便處裡
		if (noZero() and noRepeat()) {    //排除有0和有重複數字
			list[k] = N;
			k++;
		}
	}
}

void process(int A, int B, int first, int rest ,int *list) {
	int i, j, x;
	int a, b;
	if (rest != 0) {
		split(rest);
	}
	else {
		split(first);
	}
	for (i = 0; i < 3024; i++) {
		if (list[i] != 0) {
			split2(list[i]);
			a = 0;
			b = 0;
			for (j = 0; j < 4; j++) {
				if (M[j] == P[j]) {    //檢測A
					a++;
				}
			}
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (k != l and M[k] != 0 and P[l] != 0 and M[k] == P[l]) {
						b++;
					}
				}
			}
			if (a != A or b != B) {
				list[i] = 0;
			}
		}
	}
}

int main() {
  
  cout << "1102011" << endl;
  cout << "林駿宇" << endl;
  
	int first, rest = 0;
	int list[3024] = { 0 };
	int i = 0;
	srand(time(NULL));
	all(list);
	first = guess(list);
	while (cin >> hint) {
		cout << endl;
		if (hint != "4A0B" and hint != "4a0b") {
			process(hint[0] - 48, hint[2] - 48, first, rest, list);
			while (list[i] == 0) {
				i++;
			}
			cout << list[i] << endl;
			rest = list[i];
		}
		else {
			cout << "Congrets !" << endl;
			break;
		}
	}
  return 1;
}
