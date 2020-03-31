class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
     
    bool check(int row_i, int col_i, int row_size, int col_size, 
        vector<vector<int>> & maze) {
      return row_i >= 0 && row_i < row_size && col_i >= 0 && col_i < col_size &&
        maze[row_i][col_i] == 0;
    }
    
    void init_new_point(vector<int> & vec, int row_i, int col_i, int dir_i, int depth) {
      vec[0] = row_i;    
      vec[1] = col_i;
      vec[2] = dir_i;
      vec[3] = depth;
    }
    
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
      // write your code here
        
      int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
      queue<vector<int> > q;
      vector<int> point(4);
      init_new_point(point, start[0], start[1], 4, 0);
      q.push(point);
      
      int row_size = maze.size();
      if (row_size == 0) {
        return 0;
      }
      
      int col_size = maze[0].size();
      if (col_size == 0) {
        return 0;
      }
        
      vector<vector<int> > res(row_size, vector<int>(col_size, INT_MAX));
      
      while(!q.empty()) {
        vector<int> top_point = q.front();
        q.pop();
        int row_i = top_point[0];
        int col_i = top_point[1];
        int dir_i = top_point[2];
        int depth = top_point[3];
        
        if (res[row_i][col_i] <= depth) {
          continue;
        } else {
          res[row_i][col_i] = depth;    
        }
        
        for (int try_new_dir_i = 0; try_new_dir_i < 4; ++ try_new_dir_i) {
            
          int try_new_row_i = row_i;
          int try_new_col_i = col_i;
          int try_new_depth = depth;
          
          while(check(try_new_row_i, try_new_col_i, row_size, col_size, maze)) {
            try_new_row_i += dir[try_new_dir_i][0];
            try_new_col_i += dir[try_new_dir_i][1]; 
            try_new_depth ++;
          }
          try_new_row_i -= dir[try_new_dir_i][0]; 
          try_new_col_i -= dir[try_new_dir_i][1];
          try_new_depth -= 1;
          
          vector<int> try_new_point(4);
          init_new_point(try_new_point, try_new_row_i, try_new_col_i,
              try_new_dir_i, try_new_depth);
          q.push(try_new_point);
        }
        
      }
      return res[destination[0]][destination[1]] == INT_MAX? -1:
          res[destination[0]][destination[1]];
    }
};
