//dp

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      S = std::abs(S);
      const int n = nums.size();
      const int sum = std::accumulate(nums.begin(), nums.end(), 0);
      if (sum < S || (S + sum) % 2 != 0) return 0;
      const int target = (S + sum) / 2;
      vector<int> dp(target + 1, 0);
      dp[0] = 1;
      for (int num : nums)
        for (int j = target; j >= num; --j)
          dp[j] += dp[j - num];
      
      return dp[target];
    }
};

//https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-494-target-sum/
