class Solution {
public:
    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    
    bool check(int row_i, int col_i, int row_size, int col_size) {
      return row_i < row_size && row_i >= 0 && col_i < col_size && col_i >= 0;
    }
    
    // flag's value  0 : two direction, 1 : up direction : -1 down direction
    void bfs(vector<vector<int> > & matrix, int row_size, int col_size, 
        int row_i, int col_i, int flag) {
            
      if (flag >= 0) {
        up_visited[row_i][col_i] = true;
      } 
      
      if (flag <= 0) {
        down_visited[row_i][col_i] = true;
      }
      
      int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
      int new_row_i, new_col_i;
      int inc_val = 0, dec_val = 0;
      for (int dir_i = 0; dir_i < 4; ++ dir_i) {
        new_row_i = dir[dir_i][0] + row_i;   
        new_col_i = dir[dir_i][1] + col_i;
        if (check(new_row_i, new_col_i, row_size, col_size)) {
          if (flag >= 0 && matrix[new_row_i][new_col_i] > matrix[row_i][col_i]) { 
            if (!up_visited[new_row_i][new_col_i]) {
              bfs(matrix, row_size, col_size, new_row_i, new_col_i, 1);
            }
            inc_val = max(inc_val, up_dp[new_row_i][new_col_i]);
          } 
          if (flag <= 0 && matrix[new_row_i][new_col_i] < matrix[row_i][col_i]) {
            if (!down_visited[new_row_i][new_col_i]) {
              bfs(matrix, row_size, col_size, new_row_i, new_col_i, -1);
            }
            dec_val = max(dec_val, down_dp[new_row_i][new_col_i]);
          }
        }
      }
      up_dp[row_i][col_i] = inc_val + 1;
      down_dp[row_i][col_i] = dec_val + 1;
      max_length = max(max_length, up_dp[row_i][col_i] + down_dp[row_i][col_i] - 1);
    }
    
    int up_dp[1001][1001];
    int down_dp[1001][1001];
    bool up_visited[1001][1001];
    bool down_visited[1001][1001];
    int max_length;
     
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
        // write your code here
      int row_size = matrix.size();
      if(row_size == 0 ) {
        return 0;
      }
      
      int col_size = matrix[0].size();
      
      memset(up_dp, 0, sizeof(up_dp));
      memset(down_dp, 0, sizeof(down_dp));
      memset(up_visited, false, sizeof(up_visited));
      memset(down_visited, false, sizeof(down_visited));
      
      max_length = 0;
      
      for (int row_i = 0; row_i < row_size; ++ row_i) {
        for (int col_i = 0; col_i < col_size; ++ col_i) {
          bfs(matrix, row_size, col_size, row_i, col_i, 0);
        }
      }
      
      return max_length;
    }
};
int main()
{
  return 0;
}
