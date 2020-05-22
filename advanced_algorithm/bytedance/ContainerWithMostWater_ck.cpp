class Solution {
public:
    // o(n)
    int maxArea(vector<int>& heights) {
      int size = heights.size();
      int max_area = 0;
      for (int l = 0, r = size - 1; l < r;) {
        if (heights[l] < heights[r]) {
          max_area = max(max_area, heights[l] * (r - l));
          ++ l;
        } else {
          max_area = max(max_area, heights[r] * (r - l));
          -- r;
        }
      }
      return max_area;
    }      
};
