class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sum = 0;
    int size = prices.size();
    for (int i = 1; i < size; ++ i ) {
      int diff = prices[i] - prices[i - 1];
      if (diff > 0) {
        sum += diff;
      }
    } 
    return sum;
  }
};
