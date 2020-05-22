class Solution {
public:
    int trap(vector<int>& heights) {
      int size = heights.size();
      int sum_area = 0;
      stack<int> stk;
      for (int h_i = 0; h_i < size; ++ h_i) {
        int height = heights[h_i];
        int pre_h = 0;
        while(!stk.empty()) {
          int t_i = stk.top();  
          int t_h = heights[t_i];
          sum_area += (min(t_h, height) - pre_h) * (h_i - t_i - 1);
          if (t_h <= height) {
            stk.pop();
          } else {
            stk.push(h_i);
            break;
          }
          pre_h = t_h;
        }  
        if (stk.empty()) {
          stk.push(h_i);
        }
      }
      return sum_area;
    }
};
