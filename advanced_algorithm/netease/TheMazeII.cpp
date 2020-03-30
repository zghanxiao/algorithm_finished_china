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
    
    int get_reverse(int dir_i) {
      if (dir_i >= 2) {
        return dir_i - 2;
      } else {
        return dir_i + 2;
      }   
    }
    
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
      // write your code here
        
      bool visited[1001][1001][4];
      memset(visited, false, sizeof(visited));
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
        
      while(!q.empty()) {
        vector<int> top_point = q.front();
        q.pop();
        int row_i = top_point[0];
        int col_i = top_point[1];
        int dir_i = top_point[2];
        int depth = top_point[3];
        bool debug = col_i == 5;
        bool free_dir = false;
        
        
        if (row_i == start[0] && col_i == start[1] && dir_i == 4) {
          free_dir = true;
        }
        
        if (free_dir) {
          for (int try_new_dir_i = 0; try_new_dir_i < 4; ++ try_new_dir_i) {
            int try_new_row_i = row_i + dir[try_new_dir_i][0];
            int try_new_col_i = col_i + dir[try_new_dir_i][1]; 
            int try_new_depth = depth + 1;
            if (check(try_new_row_i, try_new_col_i, row_size, col_size, maze)) 
              {
              if(!visited[try_new_row_i][try_new_col_i][try_new_dir_i]) {
                visited[try_new_row_i][try_new_col_i][try_new_dir_i] = true;
                vector<int> try_new_point(4);
                init_new_point(try_new_point, try_new_row_i, try_new_col_i,
                  try_new_dir_i, try_new_depth);
                q.push(try_new_point);
              }
            }
          }
        } 
        else {
          int ori_new_row_i = row_i + dir[dir_i][0];
          int ori_new_col_i = col_i + dir[dir_i][1];
          int ori_dir_i = dir_i;
          int ori_new_depth = depth + 1; 
          
          if(!(check(ori_new_row_i, ori_new_col_i, row_size, col_size, maze))) {
            if (row_i == destination[0] && col_i == destination[1]) {
              //cout << "equal" << endl;
              return depth;      
            }
            
            for (int try_new_dir_i = 0; try_new_dir_i < 4; try_new_dir_i++) {
              if (try_new_dir_i == ori_dir_i || 
                  try_new_dir_i == get_reverse(ori_dir_i)) {
                continue;
              }
              int try_new_row_i = row_i + dir[try_new_dir_i][0];
              int try_new_col_i = col_i + dir[try_new_dir_i][1]; 
              if(check(try_new_row_i, try_new_col_i, row_size, col_size, maze)) 
                {
                if(!visited[try_new_row_i][try_new_col_i][try_new_dir_i]) {
                  visited[try_new_row_i][try_new_col_i][try_new_dir_i] = true;
                  vector<int> try_new_point(4);
                  init_new_point(try_new_point, try_new_row_i, try_new_col_i,
                      try_new_dir_i, ori_new_depth);
                  q.push(try_new_point);
                }
              }
            }
          } else {
            vector<int> ori_new_point(4);
            init_new_point(ori_new_point, ori_new_row_i, ori_new_col_i, dir_i,
                ori_new_depth);
            if(!visited[ori_new_row_i][ori_new_col_i][dir_i]) {
              visited[ori_new_row_i][ori_new_col_i][dir_i] = true;
              q.push(ori_new_point);
            }
          } 
        } 
      }
      return -1;
    }
};
