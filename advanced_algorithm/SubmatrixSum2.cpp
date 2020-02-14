class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
      // write your code here
      vector<vector<int>> vecVec;
      int row_size = matrix.size();
      
      if (row_size == 0) {
        return vecVec;
      }
      
      int col_size = matrix[0].size();
      
      
      for (int col_i = 0; col_i < col_size; ++ col_i) {
        for (int row_i = 0; row_i < row_size; ++ row_i) {
          matrix[row_i][col_i] += (row_i != 0? matrix[row_i -1][col_i]: 0);
        }
      }
      
      vecVec.resize(2);
      vecVec[0].resize(2);
      vecVec[1].resize(2);
     
      int col_sum[col_size + 1];
      for (int end_i = 0; end_i < row_size; ++ end_i) {
        for (int start_i = -1; start_i < end_i; ++ start_i) {
          memset(col_sum, 0, sizeof(col_sum));
          for (int col_i = 0; col_i < col_size; ++ col_i) {
            col_sum[col_i + 1] = col_sum[col_i] + matrix[end_i][col_i] - (start_i != -1?matrix[start_i][col_i] : 0);    
          }
          unordered_map<int, int> map;
          for (int col_i = 0; col_i <= col_size; ++ col_i) {
             if (map.find(col_sum[col_i]) == map.end()) {
               map[col_sum[col_i]] = col_i;
             } else {
                vecVec[0][0] = start_i + 1;
                vecVec[0][1] = map[col_sum[col_i]];
                vecVec[1][0] = end_i;
                vecVec[1][1] = col_i - 1; 
                return vecVec;
             }
          }
        }
      }
      return vecVec;
    }
};
