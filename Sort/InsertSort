
void InsertSort(int* h, size_t len)
{
	if (h == NULL) return;
    if (len <= 1) return;

    int i, j;
	//i是次数，也即排好的个数;j是继续排
    for (i = 1; i < len; ++i)
         for (j = i; j > 0; --j)
             if (h[j] < h[j - 1]) swap(h[j], h[j - 1]);
           else break;

     return;
 }
int main() {
	int a[5] = { 9,8,7,5,4 };
	InsertSort(a, 5);
	int k = 0;
	while (k < 5) {
		cout << a[k] << ' ';
		++k;
	}


}
