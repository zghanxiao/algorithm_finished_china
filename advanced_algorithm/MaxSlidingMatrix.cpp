class Solution {
public:
    /**
     * @param matrix: an integer array of n * m matrix
     * @param k: An integer
     * @return: the maximum number
     */
    int maxSlidingMatrix(vector<vector<int>> &matrix, int k) {
        // write your code here
      int row_size = matrix.size();
      if (row_size == 0 || row_size < k) {
        return 0;
      } 
      
      int col_size = matrix[0].size();
      if (col_size == 0 || row_size < k) {
        return 0;
      }
      
      vector<vector<int> > sum((row_size + 1), vector<int>((col_size + 1), 0));
      for (int row_i = 1; row_i <= row_size; ++ row_i) {
        for (int col_i = 1; col_i <= col_size; ++ col_i) {
          sum[row_i][col_i] = matrix[row_i - 1][col_i - 1] + 
              sum[row_i - 1][col_i] + sum[row_i][col_i - 1] - 
                  sum[row_i - 1][col_i - 1];
        }    
      }
      
      int max_kkrec_sum = INT_MIN;
      for (int row_i = k; row_i <= row_size; ++ row_i) {
        for (int col_i = k; col_i <= col_size; ++ col_i) {
          int kkrec_sum = sum[row_i][col_i] - sum[row_i][col_i - k] - 
              sum[row_i - k][col_i] + sum[row_i - k][col_i - k];
          max_kkrec_sum = max(max_kkrec_sum, kkrec_sum); 
        }
      }
      return max_kkrec_sum;
    }
};
