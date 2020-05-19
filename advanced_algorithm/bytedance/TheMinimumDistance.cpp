class Solution {
public:
    /**
     * @param mazeMap: a 2D grid
     * @return: return the minium distance
     */
    void init(vector<vector<int>> &matrix, int row_size, int col_size, unordered_map<int, vector<pair<int, int> > >  &adj_map, vector<int> & start, vector<int> & end) {
      for(int row_i = 0; row_i < row_size; ++ row_i) {
        for (int col_i = 0; col_i < col_size; ++ col_i) {
          int val = matrix[row_i][col_i];
          if (val == -2) {
            start[0] = row_i;
            start[1] = col_i;
          } else if (val == -3) {
            end[0] = row_i;  
            end[1] = col_i;
          } else if (val > 0) {
            if (adj_map.find(val) == adj_map.end()) {
              adj_map[val] = vector<pair<int, int> >();
            } 
            adj_map[val].push_back(make_pair(row_i, col_i));
          }
        }  
      }
    }
    
    bool check(int row_i, int col_i, int row_size, int col_size) {
      return row_i >= 0 && row_i < row_size && col_i >= 0 && col_i < col_size;     
    }
    
    
    int bfs(vector<vector<int> > & matrix, int row_size, int col_size, vector<int> & start, vector<int> & end, vector<vector<int> > & visited, unordered_map<int, vector<pair<int, int> > >  &adj_map) {
      unordered_set<int> num_visited;
      queue<pair<int, int>> pos_queue;
      
      int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      
      pos_queue.push(make_pair(start[0], start[1]));
      visited[start[0]][start[1]] = 0;
      while(!pos_queue.empty()) {
        pair<int, int> front = pos_queue.front();
        pos_queue.pop();
        
        int val = matrix[front.first][front.second]; 
        int depth = visited[front.first][front.second];
        
        if (front.first == end[0] && front.second == end[1]) {
          return visited[front.first][front.second]; 
        }
        
        int new_row_i = -1, new_col_i = -1;
        for (int dir_i = 0; dir_i < 4; ++ dir_i) {
          new_row_i = front.first + dir[dir_i][0];    
          new_col_i = front.second + dir[dir_i][1];
          if (check(new_row_i, new_col_i, row_size, col_size) && matrix[new_row_i][new_col_i] != -1 && visited[new_row_i][new_col_i] == -1) {
            visited[new_row_i][new_col_i] = depth + 1;
            pos_queue.push(make_pair(new_row_i, new_col_i));   
          }  
        }
        
        if (val > 0 && num_visited.find(val) == num_visited.end()) {
          num_visited.insert(val);
          for (pair<int, int> p: adj_map[val]) {
            if (visited[p.first][p.second] == -1) {
              visited[p.first][p.second] = depth + 1;   
              pos_queue.push(make_pair(p.first, p.second));
            }
          }
        }
      }
      return -1;
    }
    
    int getMinDistance(vector<vector<int>> &matrix) {
      // write your code here
      
      int row_size = matrix.size();
      if (row_size == 0) {
        return -1;
      }
      
      int col_size = matrix[0].size();
      if (col_size == 0) {
        return -1;
      }
      
      vector<vector<int> > visited(row_size, vector<int>(col_size, -1));
      
      unordered_map<int, vector<pair<int, int> > >  adj_map;
      vector<int> start(2, -1);
      vector<int> end(2, -1);
      
      init(matrix, row_size, col_size, adj_map, start, end);
      return bfs(matrix, row_size, col_size, start, end, visited, adj_map);
    }
};
