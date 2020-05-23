class Solution {
public:
  bool check(int r_i, int c_i, int r_size, int c_size) {
    return r_i < r_size && r_i >= 0 && c_i < c_size && c_i >= 0;
  }
  
  int trapRainWater(vector<vector<int>>& heights) {
    int r_size = heights.size();
    if (r_size == 0) {
      return 0;
    }
    int c_size = heights[0].size();
    if (c_size == 0) {
      return 0;
    }    
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>> >  pq; 
    
    vector<vector<int>> visited(r_size, vector<int>(c_size, false));
    
    for (int r_i = 0; r_i < r_size; r_i ++) {
      for (int c_i = 0; c_i < c_size; ) {
        pq.push(make_pair(heights[r_i][c_i], make_pair(r_i, c_i)));
        visited[r_i][c_i] = true;
        if (r_i == 0 || r_i == r_size - 1) {
          c_i ++;
        } else {
          if (c_size != 1 && c_i == 0) {
            c_i = c_size - 1;
          } else if (c_size == 1 || c_i == c_size - 1) {
            c_i = c_size;
          }
        }
      }
    }
    
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int tot_sum = 0;
    while(!pq.empty()) {
      pair<int, pair<int, int> > top = pq.top();     
      pq.pop();
      
      int t_h = top.first;
      int t_r_i = top.second.first;
      int t_c_i = top.second.second;
      
      for (int d_i = 0; d_i < 4; ++ d_i) {
        int n_r_i = t_r_i + dir[d_i][0];
        int n_c_i = t_c_i + dir[d_i][1];
        
        if(check(n_r_i, n_c_i, r_size, c_size) && !visited[n_r_i][n_c_i]) {
          int n_h = heights[n_r_i][n_c_i];
          int w_h = max(t_h, n_h);  
          tot_sum += w_h - n_h;
          visited[n_r_i][n_c_i] = true;
          pq.push(make_pair(w_h, make_pair(n_r_i, n_c_i)));
        }
      }
    }
    
    return tot_sum;
  }
};
