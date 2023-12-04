class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int> &nums) {
        int n = nums.size(), suf[n + 1]; suf[n] = 0;
        unordered_set<int> s;
        for (int i = n - 1; i; i--) {
            s.insert(nums[i]);
            suf[i] = s.size();
        }

        s.clear();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
            ans[i] = s.size() - suf[i + 1];
        }
        return ans;
    }
};
