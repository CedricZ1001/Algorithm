 void BubbleSort(int* h, size_t len)
 {
	if (h == NULL) return;
	if (len <= 1) return;
	//i是次数，j是具体下标 
	for (int i = 0; i < len - 1; ++i)
	    for (int j = 0; j < len - 1 - i; ++j)
	        if (h[j] > h[j + 1])
	             swap(h[j], h[j + 1]);
	
	return;
 }

int main() {
	int a[5] = { 9,8,7,5,4 };
	BubbleSort(a, 5);
	int k = 0;
	while (k < 5) {
		cout << a[k] << ' ';
		++k;
	}


}
