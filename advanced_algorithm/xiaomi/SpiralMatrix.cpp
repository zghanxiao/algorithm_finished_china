class Solution {
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    bool valid(int row_i, int col_i, int row_size, int col_size) {
      return row_i >= 0 && row_i < row_size && col_i >= 0 && col_i < col_size;    
    }
    
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
      // write your code here
      vector<int> res;
      int row_size = matrix.size();
      if(row_size == 0) {
        return res;
      }
      
      int col_size = matrix[0].size();
      if (col_size == 0) {
        return res;
      }
      
      vector<vector<bool>> visited(row_size, vector<bool>(col_size, false));
      
      int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      int row_i = 0; 
      int col_i = 0;
      int dir_i = 0;
      
      bool stop_flag = false;
      while(!stop_flag) {
        visited[row_i][col_i] = true;
        res.push_back(matrix[row_i][col_i]);
        for(int new_dir_i = dir_i;;) {
          int new_row_i = row_i + dir[new_dir_i][0];
          int new_col_i = col_i + dir[new_dir_i][1];
          if (valid(new_row_i, new_col_i, row_size, col_size) && !visited[new_row_i][new_col_i]) {
            row_i = new_row_i;
            col_i = new_col_i;
            dir_i = new_dir_i;
            break;
          }
          new_dir_i ++;
          new_dir_i %= 4;
          if (new_dir_i == dir_i) {
            stop_flag = true;
            break;
          }
        }  
      } 
      return res;
    }
};
