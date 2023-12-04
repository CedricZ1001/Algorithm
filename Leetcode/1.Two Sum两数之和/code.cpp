#include<vector>
#include<unordered_map>
using namespace std;
/*1.One brute force approach is to consider every pair of elements and check if
their sum equals the target. This can be done using nested loops, where the
outer loop iterates from the first element to the second-to-last element, and
the inner loop iterates from the next element to the last element. However,
this approach has a time complexity of O(n^2).
2.A more efficient approach is to use a hash table (unordered_map in C++).
We can iterate through the array once, and for each element, check if the
target minus the current element exists in the hash table. If it does, we have
found a valid pair of numbers. If not, we add the current element to the hash
table.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/*1.Create an empty hash table to store elements and their indices.
2.Iterate through the array from left to right.
3.For each element nums[i], calculate the complement by subtracting it from the target: complement = target - nums[i].
4.Check if the complement exists in the hash table. If it does, we have found a solution.
5.If the complement does not exist in the hash table, add the current element nums[i] to the hash table with its index as the value.
6.Repeat steps 3-5 until we find a solution or reach the end of the array.
7.If no solution is found, return an empty array or an appropriate indicator.
This approach has a time complexity of O(n) since hash table lookups take constant time on average. 
It allows us to solve the Two Sum problem efficiently by making just one pass through the array.*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
