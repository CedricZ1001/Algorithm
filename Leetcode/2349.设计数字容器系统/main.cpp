// 方法一：平衡树（有序集合）
// 由于数据范围很大，我们可以用一个哈希表 mmm 记录每个下标对应的元素，另一个哈希表套平衡树 ms\textit{ms}ms 记录每个元素对应的下标集合。
// 对于 change 操作，如果 index\textit{index}index 处已有数字，则先从 ms[m[index]]\textit{ms}[m[\textit{index}]]ms[m[index]] 中删掉 index\textit{index}index。然后将 index\textit{index}index 和 number\textit{number}number 记录到 mmm 和 ms\textit{ms}ms 中。


class NumberContainers {
    unordered_map<int,int> m;
    unordered_map<int, set<int>> ms;
public:  
    void change(int index, int number) {
        auto it = m.find(index);
        if (it != m.end()) {
            ms[it->second].erase(index); // 移除旧数据
            it->second = number; // 优化：直接在迭代器上赋值
        } else m[index] = number;
        ms[number].insert(index); // 添加新数据

    }
    
    int find(int number) {
        auto it = ms.find(number);
        return it == ms.end() || it->second.empty() ? -1 : *it->second.begin ();
    }

    
};

// 方法二：懒删除堆
// 另一种做法是用堆：

// 对于 change 操作，直接往 ms\textit{ms}ms 中记录，不做任何删除操作；
// 对于 find 操作，查看堆顶下标对应的元素是否和 number\textit{number}number 相同，若不相同则意味着对应的元素已被替换成了其他值，堆顶存的是个垃圾数据，直接弹出堆顶；否则堆顶就是答案。
class NumberContainers {
    unordered_map<int, int> m;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> ms;

public:
    void change(int index, int number) {
        m[index] = number;
        ms[number].push(index); // 直接添加新数据，后面 find 再删除旧的
    }

    int find(int number) {
        auto it = ms.find(number);
        if (it == ms.end()) return -1;
        auto &q = it->second;
        while (!q.empty() && m[q.top()] != number) q.pop();
        return q.empty() ? -1 : q.top();
    }
};

