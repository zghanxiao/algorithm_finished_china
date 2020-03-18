class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the maximun difference
     */
    bool valid(long long val) {
      return val != LLONG_MIN && val != LLONG_MAX;
    }
    
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
      if (!avg_interval) {
        return 0;
      } 
      
      vector<long long> min_arr(size, LLONG_MAX);
      vector<long long> max_arr(size, LLONG_MIN); 
      
      for (long long iter = 0; iter < size; ++ iter) {
        long long num = nums[iter];
        long long num_of_avg = (num - min_val) / avg_interval;
        if (num != min_val && num != max_val) {
          min_arr[num_of_avg] = min(min_arr[num_of_avg], num);
          max_arr[num_of_avg] = max(max_arr[num_of_avg], num);
        }
      } 
      
      long long max_diff = LLONG_MIN;
      long long last_max = min_val;
      for (long long iter = 0; iter < size; ++ iter ) {
        long long diff;
        
        if (iter != 0 && valid(min_arr[iter])) {
          diff  =  min_arr[iter] - last_max;
          max_diff = max(max_diff, diff);
        } 
        if (valid(max_arr[iter])) {
          last_max = max(max_arr[iter], last_max);
        }
      }
      if (valid(last_max)) {
        long long diff = max_val - last_max;
        max_diff = max(max_diff, diff);
      } 
      
      return (int)max_diff;
    }
};
