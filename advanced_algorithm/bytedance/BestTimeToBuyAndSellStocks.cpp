class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int min_val = INT_MAX;
      int diff = 0;
      for (auto value: prices) {
        if (value < min_val) {
          min_val = value;  
        } else if (value - min_val > diff) {
          diff = value - min_val;
        }
      }
      return diff;
    }
};
