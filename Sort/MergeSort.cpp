void  MergeArray(int* arr, size_t left, size_t mid, size_t right, int* temp)
{
  if (arr == NULL) return;

    size_t i = left, j = mid + 1, k = 0;
  while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
         {
             temp[k++] = arr[i++];
             continue;
         }

         temp[k++] = arr[j++];
     }

     while (i <= mid)
         temp[k++] = arr[i++];

     while (j <= right)
         temp[k++] = arr[j++];

     memcpy(&arr[left], temp, k * sizeof(int));

     return;
}

void MMergeSort(int* arr, size_t left, size_t right, int* temp)
{
      if (left < right)
     {
         size_t mid = (left + right) / 2;
         MMergeSort(arr, left, mid, temp);
         MMergeSort(arr, mid + 1, right, temp);
         MergeArray(arr, left, mid, right, temp);
     }
 }

void MergeSort(int* h, size_t len)
{
    if (h == NULL) return;
    if (len <= 1) return;
    int* temp = (int*)calloc(len, sizeof(int));
	if (temp != NULL) {
		MMergeSort(h, 0, len - 1, temp);
		memcpy(h, temp, sizeof(int) * len);
		free(temp);
	}
 }

int main() {
	int a[5] = { 9,8,7,5,4 };
	MergeSort(a, 5);
	int k = 0;
	while (k < 5) {
		cout << a[k] << ' ';
		++k;
	}


}
