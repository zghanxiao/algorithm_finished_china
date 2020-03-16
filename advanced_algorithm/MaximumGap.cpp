class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the maximun difference
     */
    int maximumGap(vector<int> &nums) {
       // write your code here
       
      long long size = nums.size();
      if (size < 2) {
        return 0;
      }
      long long max_val = LLONG_MIN;
      long long min_val = LLONG_MAX;
      
       
      for (long long iter = 0; iter < size; ++ iter) {
        long long num = nums[iter]; 
        max_val = max(max_val, num);
        min_val = min(min_val, num);
      }
      
      long long avg_interval = (max_val - min_val + size  - 2) / (size - 1);
      
      vector<long long> min_arr(size - 1, LLONG_MAX);
      vector<long long> max_arr(size - 1, LLONG_MIN); 
      
      for (long long iter = 0; iter < size; ++ iter) {
        long long num = nums[iter];
        long long num_of_avg = (num - min_val) / avg_interval;
        if (num != min_val) {
          min_arr[num_of_avg] = min(min_arr[num_of_avg], num);
          max_arr[num_of_avg] = max(max_arr[num_of_avg], num);
        }
      } 
      
      long long max_diff = LLONG_MIN;
      for (long long iter = 1; iter < size - 1; ++ iter ) {
        long long diff  = min_arr[iter] - max_arr[iter - 1];
        max_diff = max(max_diff, diff);
      }
      return (int)max_diff;
    }
};
