class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    // write your code here
    
    int dp[1001][1001];
    int sum[1001];
    
    int stoneGame2(vector<int> &A) {
        // write your code here
                // write your code here
      int size = A.size();
      if (size == 0) {
          return 0;
      }
      int double_size = size * 2;
      A.resize(double_size);
      for (int iter = 0; iter < size; ++ iter) {
        A[iter + size] = A[iter];
      } 
      
      memset(dp, 0, sizeof(dp));
      memset(sum, 0, sizeof(sum));
      
      
      for (int sum_i = 0; sum_i < double_size ; ++ sum_i) {
        int val = A[sum_i];
        sum[sum_i + 1] = sum[sum_i] + val;
      } 
      
      // from start_i th element to  tail_i =  end_i + 1 element
      // sum[tail_i] - sum[start_i] 
      int min_val = INT_MAX;
      for (int k_i = 1; k_i <= size; ++ k_i) {
        for (int start_i = 0; start_i + k_i <= double_size; ++ start_i) {
          int tail_i = start_i + k_i;
          if (k_i > 1) {
            // split_i start index of the second segment
            dp[start_i][tail_i] = INT_MAX;
            for (int split_i = start_i + 1; split_i < tail_i; ++ split_i) {
              dp[start_i][tail_i] = min(dp[start_i][tail_i], 
                  dp[start_i][split_i] + dp[split_i][tail_i] + 
                      sum[tail_i] - sum[start_i]);
            }
          }
          if (k_i == size) {
            min_val = min(min_val, dp[start_i][tail_i]);
          }
        }
      } 
      return min_val;
    }
};
