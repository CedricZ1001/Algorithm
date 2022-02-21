void ShellSort(int* h, size_t len)
{
 if (h == NULL) return;
 if (len <= 1) return;

    for (int div = len / 2; div >= 1; div /= 2)
        for (int k = 0; k < div; ++k)
            for (int i = div + k; i < len; i += div)
                 for (int j = i; j > k; j -= div)
                     if (h[j] < h[j - div]) swap(h[j], h[j - div]);
                  else break;

     return;
}

int main() {
	int a[5] = { 9,8,7,5,4 };
	ShellSort(a, 5);
	int k = 0;
	while (k < 5) {
		cout << a[k] << ' ';
		++k;
	}


}
