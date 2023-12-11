//方法一：顺序遍历数组
//思路与算法
//我们可以顺序遍历数组nums的下标i，检查 i mod 10=nums[i]是否成立。
//如果成立，则该下标即为值相等的最小索引，我们返回该下标作为答案。若遍历完整个数组均未找到符合要求的下标，则返回−1。


class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i<n;i++){
            if(i % 10 ==nums[i]){
                return i;
            }
        }
        return -1;
    }
};