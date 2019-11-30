class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
      // write your code here
      int size = A.size();
      vector<vector<long long> > dp(size + 1, vector<long long>(2, 0)); 
      for (int dp_i = 1; dp_i <= size; ++ dp_i) {
        dp[dp_i][0] = max(dp[dp_i - 1][0], dp[dp_i - 1][1]);
        dp[dp_i][1] =  dp[dp_i - 1][0] + A[dp_i - 1];
      }
      return max(dp[size][0], dp[size][1]);
    }
};
