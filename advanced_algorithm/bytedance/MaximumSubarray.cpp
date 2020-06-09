class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int sum = INT_MIN;
      int temp_sum = 0;
      for (int num: nums) {
        temp_sum += num;
        sum = max(sum, temp_sum);
        temp_sum = max(temp_sum, 0);
      }    
      return sum;
    }
};
