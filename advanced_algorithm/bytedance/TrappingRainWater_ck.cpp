class Solution {
public:
    int trap(vector<int>& heights) {
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
};
