class Solution {
public:
    /**
     * @param order: The order
     * @param pattern: The pattern
     * @return: Return the number of items do not meet the demand at least
     */
     
    int cal_remain_value(vector<int> & remain) {
      int sum = 0;
      for (int re_i = 0; re_i < remain.size(); re_i++) {
        sum += remain[re_i]; 
      }
      return sum;
    } 
    
    void bfs(vector<int> & order, int n, vector<vector<int>> & pattern, int m, int index, vector<int> remain, int & min_remain) {
      
      if (index == m) {
        int curr_remain_val = cal_remain_value(remain);  
        min_remain = min(min_remain, curr_remain_val);
        return;
      }
      
      vector<int> curr_pattern = pattern[index];
      int pat_max = n;
      for (int re_i = 0; re_i < n; ++ re_i) {
        if (curr_pattern[re_i]) {
          int pat_num = remain[re_i] / curr_pattern[re_i];
          pat_max = min(pat_max, pat_num);
        }
      }
      
      vector<int> new_remain(n, 0);
      
      for (int pattern_i = 0; pattern_i <= pat_max; pattern_i++) {
        for (int re_i = 0; re_i < n; ++ re_i) {
          new_remain[re_i] = remain[re_i] - pattern_i * curr_pattern[re_i];   
        }      
        bfs(order, n, pattern, m, index + 1, new_remain, min_remain);
      }
    } 
    
    int getMinRemaining(vector<int> &order, vector<vector<int>> &pattern) {
        // Write your code here
        int n = order.size(); 
        int m = pattern.size();
        vector<int> remain(n);
        int sum = 0;
        for (int iter = 0; iter < n; iter ++) {
          remain[iter] = order[iter]; 
          sum += order[iter];
        }
        int min_remain = sum;
        bfs(order, n, pattern, m, 0, remain, min_remain);
        return min_remain;
    }
};
