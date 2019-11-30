class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
      int size = values.size();
      // dp has two side max or min
      vector<int> dp(size + 1);
      for (int iter = size - 1; iter >= 0; -- iter) {
        if (iter < size - 1) {
          dp[iter] = max(values[iter] - dp[iter + 1], values[iter] + 
            values[iter + 1] - dp[iter + 2]);
        } else if (iter == size - 1) {
          dp[iter] = values[iter] + dp[iter + 1];
        }
      }
      return dp[0] > 0;
    }
};
