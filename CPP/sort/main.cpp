#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void BublingSort(int* arr, int len)
{
    if (len == 0)
    {
        return;
    }
    std::cout << "冒泡排序" << std::endl;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
            for (size_t i = 0; i < len; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "----------------" << std::endl;

    }
}

void SelectSort(int* arr, int length)
{
    std::cout << "选择排序" << std::endl;
    for (int i = 0; i < length; ++i)
    {
        int min_pos = i;
        for (int j = i + 1; j < length; ++j)
        {
            if (arr[min_pos] > arr[j])
            {
                min_pos = j;
            }
        }
        if (min_pos != i)
        {
            int tmp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = tmp;
        }
        for (size_t i = 0; i < length; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}


void InsertSort(int* arr, int len)
{
    if (len == 0)
    {
        return;
    }

    std::cout << "插入排序" << std::endl;

    for (int i = 1; i < len; ++i)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j - 1] > arr[j])
            {
                std::swap(arr[j], arr[j - 1]);
            }
            for (size_t i = 0; i < len; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            --j;
        }
    }
}


void QuickSort(int *arr, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    int cur_left = left;
    int cur_right = right;
    int tmp_value = arr[cur_left];

    while(cur_left < cur_right)
    {
        while(cur_left < cur_right && arr[cur_right] > tmp_value) //参考值4 找到比4小的下标
        {
            --cur_right;
        }
        if(cur_left < cur_right)//赋值元素 坐标右移
        {
            arr[cur_left++] = arr[cur_right];
        }
        //for (size_t i = 0; i < 7; i++)
        //{
        //    std::cout << arr[i] << " ";
        //}
        //std::cout << std::endl;
        while(cur_left < cur_right && arr[cur_left] < tmp_value)
        {
            ++cur_left;
        }
        if(cur_left < cur_right)
        {
           arr[cur_right--] = arr[cur_left];
        }
        //for (size_t i = 0; i < 7; i++)
        //{
        //    std::cout << arr[i] << " ";
        //}
        //std::cout << std::endl;
    }

    arr[cur_left] = tmp_value; // 每次递归都确定了一个正确的位置
    for (size_t i = 0; i < 7; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    QuickSort(arr, left, cur_left - 1);
    QuickSort(arr, cur_left + 1, right);

}


int partition(vector<int>& data,int l,int r)
{
	int x = data[r];	//基准
	if(l >= r)
		return l;
	while(l < r){
		while(l < r && data[l] < x){
			l++;
		}
		if(l < r){
			data[r] = data[l];
			r--;
		}
		while(l < r && data[r] > x){
			r--;
		}
		if(l < r){
			data[l] = data[r];
			l++;
		}
	}
	data[l] = x;
	return l;
}

int quickSortNorecusive(vector<int>& data,int l,int r)
{
	stack<int> st;
	if(l < r)
	{
		int tmp = partition(data,l,r);
		if(tmp-1 > l)	//左边不止一个元素
		{
			st.push(tmp-1);
			st.push(l);
		}
		if(tmp+1 < r)
		{
			st.push(r);
			st.push(tmp+1);
		}
		while(!st.empty()){
			int start = st.top();
			st.pop();
			int end = st.top();
			st.pop();
			
			int tmp = partition(data,start,end);
		    if(tmp-1 > start)	//左边不止一个元素
			{
				st.push(tmp-1);
				st.push(start);
			}
		    if(tmp+1 < end)
			{
				st.push(end);
				st.push(tmp+1);
			}
		}
	}
}

int main() {
    vector<int> vec{4,5,3,7,1,9,8};
    int arr[]{4,5,3,7,1,9,8};
    int length = sizeof(arr) / sizeof(arr[0]);
    // for (size_t i = 0; i < length; i++)
    // {
    //     std::cout << arr[i] << ",";
    // }
    // std::cout << std::endl;
    // std::cout << "----------------" << std::endl;
    //BublingSort(arr, length);
    //SelectSort(arr, length);
    //InsertSort(arr, length);
    // quicksort(arr, 0, 6);
    cout<<vec.size()<<endl;
    quickSortNorecusive(vec,0,vec.size()-1);
    // for (size_t i = 0; i < length; i++)
    // {
    //     std::cout << arr[i] << ",";
    // }
    for(auto &c : vec)
		cout << c << " ";
	cout << endl;
    return 0;
}

