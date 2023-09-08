#include<iostream>
using namespace std;

void QuickSort(int* h,int left,int right) {

	if (h == NULL) return;
	if (left >= right) return;

	srand((unsigned)time(NULL));
	int len = right - left;
	int kindex = rand() % (len + 1) + left;
	swap(h[left], h[kindex]);

	int key = h[left], i = left, j = right;
	while (i < j) {
		while (h[j] >= key && i < j) --j;
		if (i < j) h[i] = h[j];
		while (h[i] < key && i < j) ++i;
		if (i < j) h[j] = h[i];
	}
	h[i] = key;

	int k=0;
	while (k < 5) {
		cout << h[k]<<' ';
		++k;
	}
	cout << endl;
	QuickSort(h, left, i - 1);
	QuickSort(h, j + 1, right);



}

int main() {
	int a[5] = { 9,8,7,5,4 };
	QuickSort(a, 0, 4);


}
