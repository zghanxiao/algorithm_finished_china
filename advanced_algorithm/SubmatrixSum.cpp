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
      
      // start_row_i, end_row_i, col_i
      int sum[row_size][row_size][col_size];
      
      int temp_row_sum[row_size + 1]; 
      for (int col_i = 0; col_i < col_size; ++ col_i) {
        memset(temp_row_sum, 0, sizeof(temp_row_sum));
        for (int row_i = 0; row_i < row_size; ++ row_i) {
          temp_row_sum[row_i + 1] = temp_row_sum[row_i] + matrix[row_i][col_i];
        }
        
        for (int end_i = 0; end_i <= row_size; ++ end_i) {
          for (int start_i = 0; start_i < end_i; ++ start_i ) {
            // start index: start_i
            // end index: end_i - 1
            int diff = temp_row_sum[end_i] - temp_row_sum[start_i];
            //cout << "diff:" << diff << " ";
            sum[start_i][end_i - 1][col_i] = diff;
          }
        }
      }
      
      int temp_col_sum[col_size + 1];
      unordered_map<int, int> map;
      vecVec.resize(2);
      vecVec[0].resize(2);
      vecVec[1].resize(2);
     
      for (int end_i = 0; end_i < row_size; ++ end_i) {
        for (int start_i = 0; start_i <= end_i; ++ start_i) {
          //cout << "start_i:" << start_i << " end_i:" << end_i << endl;
            
          memset(temp_col_sum, 0, sizeof(temp_col_sum));  
          
          for (int col_i = 0; col_i < col_size; ++ col_i) {
            temp_col_sum[col_i + 1] = temp_col_sum[col_i] + sum[start_i][end_i][col_i];
            // cout << temp_col_sum[col_i + 1] << " ";
          } 
          // cout << endl;
          
          
          map.clear();
          for (int col_i = 0; col_i <= col_size; ++ col_i) {
             if (map.find(temp_col_sum[col_i]) == map.end()) {
               map[temp_col_sum[col_i]] = col_i;
             } else {
                vecVec[0][0] = start_i;
                vecVec[0][1] = map[temp_col_sum[col_i]];
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
