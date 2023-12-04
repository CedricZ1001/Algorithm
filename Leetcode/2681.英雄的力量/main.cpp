// 动态规划 每个子序列 的最大值 最小值

int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n);
        vector<int> preSum(n+1);
        int result = 0;
        mod = 1e9 + 7;
        for(int i =0;i<n;i++){
            dp[i]=(nums[i] + preSum[i]) % mod;
            preSum[i + 1]=(preSum[i] + dp[i]) % mod;
            res = (int)((result+(long long)nums[i]*nums[i] % mod *dp[i])%mod);
            if(result<0)
                result += mod;
        }
        return result;
    }