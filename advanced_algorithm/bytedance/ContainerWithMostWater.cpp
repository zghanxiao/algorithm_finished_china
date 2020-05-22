class Solution {
public:
    int maxArea(vector<int>& heights) {
      vector<pair<int, int> > vec;      
      int max_area = -1;
      
      for (int h_i = 0; h_i < heights.size(); ++ h_i) {
        int height = heights[h_i]; 
        if (vec.size() == 0) {
           vec.push_back(make_pair(height, h_i));
        } else {
          for (int v_i = 0; v_i < vec.size(); ++ v_i) {
            pair<int, int> p= vec[v_i];
            int pre_h = p.first;  
            int pre_i = p.second;
            if (pre_h <= height) {
              max_area = max(max_area, pre_h * (h_i - pre_i)); 
            } else {
              max_area = max(max_area, height * (h_i - pre_i));
              break;
            }
          }
          
          if (height > vec[vec.size() - 1].first) {
            vec.push_back(make_pair(height, h_i));
          }
        } 
      }
      return max_area;
    }
};
