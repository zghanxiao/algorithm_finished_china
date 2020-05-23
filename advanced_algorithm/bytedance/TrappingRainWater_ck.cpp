class Solution {
public:
    // one extra variable water height w_h;
    int trap1(vector<int>& heights) {
      int size = heights.size();
      int l = 0, r = size - 1;
      int w_h = 0;
      int tot_area = 0;
      for (;l < r;) {
        int lower_h = min(heights[l], heights[r]);
        tot_area -= min(lower_h, w_h);
        if (lower_h > w_h) {
          tot_area += (lower_h - w_h) * ( r - l - 1);   
          w_h = lower_h;
        }
        
        if (heights[l] < heights[r]) {
          ++ l;
        } else {
          -- r; 
        }
      }
      return tot_area;
    }
  
    // solution version: 
    // maintaining two water level variables
    // but easy to write
    int trap(vector<int>& heights) {
      int size = heights.size();
      int l = 0, r = size - 1;
      int left_max = 0;
      int right_max = 0;
      int tot_sum = 0;
      for (;l < r;) {
        if (heights[l] < heights[r]) {
          if (heights[l] > left_max) {
            left_max = heights[l];
          } else {
            tot_sum += left_max - heights[l];
          }
          ++ l;
        } else {
          if (heights[r] > right_max) {
            right_max = heights[r];
          } else {
            tot_sum += right_max - heights[r];
          }
          -- r;
        }
      }      
      return tot_sum;
    }
};
