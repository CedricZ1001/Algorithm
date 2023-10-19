## Vector

- vector 是表示可变大小数组的序列容器。
- 就像数组一样，vector 也采用的连续存储空间来存储元素。也就是意味着可以采用下标对 vector 的元素进行访问，和数组一样高效。但是又不像数组，它的大小是可以动态改变的，而且它的大小会被容器自动处理。
- 本质讲，vector 使用动态分配数组来存储它的元素。当新元素插入时候，这个数组需要被重新分配大小为了增加存储空间。其做法是，分配一个新的数组，然后将全部元素移到这个数组。就时间而言，这是一个相对代价高的任务，因为每当一个新的元素加入到容器的时候，vector 并不会每次都重新分配大小。
- vector 分配空间策略：vector 会分配一些额外的空间以适应可能的增长，因为存储空间比实际需要的存储空间更大。不同的库采用不同的策略权衡空间的使用和重新分配。但是无论如何，重新分配都应该是对数增长的间隔大小，以至于在末尾插入一个元素的时候是在常数时间的复杂度完成的。
- 因此，vector 占用了更多的存储空间，为了获得管理存储空间的能力，并且以一种有效的方式动态增长。
- 与其它动态序列容器相比（deque, list and forward_list）， vector 在访问元素的时候更加高效，在末尾添加和删除元素相对高效。对于其它不在末尾的删除和插入操作，效率更低。比起 list 和 forward_list 统一的迭代器和引用更好。

#### Vector 的定义

```
Class template
std::vector
template <class T, class Alloc = allocator<T> > class vector;//generic template
```

#### Vector 的初始化

```
#include<vector>
vector<int> vec;		//声明一个int型向量
vector<int> vec(5);		//声明一个初始大小为5的int向量
vector<int> vec(10, 1);	//声明一个初始大小为10且值都是1的向量
vector<int> vec(tmp);	//声明并用tmp向量初始化vec向量
vector<int> tmp(vec.begin(), vec.begin() + 3);	//用向量vec的第0个到第2个值初始化tmp
int arr[5] = {1, 2, 3, 4, 5};
vector<int> vec(arr, arr + 5);		//将arr数组的元素用于初始化vec向量
//说明：当然不包括arr[4]元素，末尾指针都是指结束元素的下一个元素，
//这个主要是为了和vec.end()指针统一。
vector<int> vec(&arr[1], &arr[4]); //将arr[1]~arr[4]范围内的元素作为vec的初始值
//在创建好空容器的基础上，还可以通过调用 reserve() 成员函数来增加容器的容量：vec.reserve(20);
```

# std::vector 方法总览

## 1. Iterators（迭代器）

| 方法       | 功能描述                                       |
|------------|----------------------------------------------|
| `begin()`  | 返回指向容器中第一个元素的迭代器。             |
| `end()`    | 返回指向容器中最后一个元素之后的迭代器，不是最后一个元素。 |
| `rbegin()` | 返回指向容器最后一个元素的反向迭代器。         |
| `rend()`   | 返回指向容器开头之前位置的反向迭代器。         |
| `cbegin()` | 返回指向容器中第一个元素的常量迭代器（只读）。 |
| `cend()`   | 返回指向容器最后一个元素之后位置的常量迭代器（只读）。 |
| `crbegin()`| 返回指向容器最后一个元素的常量反向迭代器（只读）。 |
| `crend()`  | 返回指向容器开头之前位置的常量反向迭代器（只读）。 |

## 2. Capacity（容量）

| 方法             | 功能描述                               |
|-----------------|--------------------------------------|
| `size()`        | 返回容器中的元素数。                  |
| `max_size()`    | 返回容器可能容纳的最大元素数。        |
| `capacity()`    | 返回当前分配的存储空间能容纳的元素数。|
| `empty()`       | 检查容器是否不包含任何元素。          |
| `reserve()`     | 请求更改容器的容量大小。              |
| `shrink_to_fit()`| 请求移除未使用的容量，减少内存使用。 |

## 3. Element access（元素访问）

| 方法           | 功能描述                                           |
|---------------|--------------------------------------------------|
| `operator[]`  | 访问指定索引处的元素，不检查边界。                 |
| `at()`        | 访问指定索引处的元素，如果索引越界会抛出一个 `std::out_of_range` 异常。 |
| `front()`     | 访问第一个元素。                                  |
| `back()`      | 访问最后一个元素。                                |
| `data()`      | 返回一个指针，指向存储容器元素的内存。           |

## 4. Modifiers（修改器）

| 方法           | 功能描述                             |
|---------------|------------------------------------|
| `assign()`    | 用新内容替换当前内容。              |
| `push_back()` | 在容器的末尾添加一个新元素。        |
| `pop_back()`  | 删除容器的最后一个元素。            |
| `insert()`    | 在容器中指定的位置插入一个或多个元素。 |
| `erase()`     | 从容器中删除一个元素或一系列元素。    |
| `swap()`      | 交换两个向量的内容。                |
| `clear()`     | 从容器中删除所有元素。              |
| `emplace()`   | 在指定位置构造元素。                |
| `emplace_back()`| 在容器末尾构造元素。              |

# 具体使用方法
```
//push_back和pop_back用法简单
vector<int> arr;
for (int i = 0; i < 5; i++)
{
    arr.push_back(i);
}
for (int i = 0; i < 5; i++)
{
    arr.pop_back();
}

arr.emplace(10);

//在arr的头部插入值为10的元素
vector<int> arr;
arr.insert(arr.begin(), 10);

vector<int> arr{1, 2, 3, 4, 5};
//删除arr开头往后偏移两个位置的元素，即arr的第三个元素，3
arr.erase(arr.begin() + 2);
//删除arr.begin()到arr.begin()+2之间的元素，删除两个;即删除arr.begin()而不到arr.begin()+2的元素
arr.erase(arr.begin(), arr.begin() + 2);

//将arr修改为范围[arrs.begin, arrs.end]内的元素
vector<int> arr = {5, 4, 3, 2, 1};
vector<int> arrs = { 1, 2, 3, 4, 5 };
arr.assign(arrs.begin(), arrs.end());

//扩容
vector<int> arr;
for (int i = 0; i < 20; i++)
{
    arr.push_back(i);
    cout << arr.size() << " " << arr.capacity() << endl;
}
```
