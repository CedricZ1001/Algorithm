void SelectionSort(int* h, size_t len){
	if (h == NULL) return;
	if (len <= 1) return;

	int minindex, i, j;
	//i是次数，也即排好的个数;j是继续排
    for (i = 0; i < len - 1; ++i)
    {
        minindex = i;
        for (j = i + 1; j < len; ++j)
        {
            if (h[j] < h[minindex]) minindex = j;
        }
        swap(h[i], h[minindex]);
    }


 }
int main() {
	int a[5] = { 9,8,7,5,4 };
	SelectionSort(a, 5);
	int k = 0;
	while (k < 5) {
		cout << a[k] << ' ';
		++k;
	}


}
