class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a boolean
     */
    bool find(vector<int> & nums, unordered_map<int, vector<int> > & map, vector<int> & dp, int sum, int share_sum, int cnt, int total_sum) {
      if (cnt == 3) {
        return dp[nums.size()] == total_sum + share_sum;
      }
      
      total_sum += share_sum; 
      if (map.find(total_sum) == map.end()) {
        return false;
      }
      vector<int> vec =  map[total_sum];
      
      for (int val: vec) {
        int iter = val - 1;
        if (find(nums, map, dp, sum, share_sum, cnt + 1, total_sum + nums[iter + 1])){
        return true;
        }
      }
      return false;
    }
    
    bool splitArray(vector<int> &nums) {
      // write your code here
      int sum = 0;
      unordered_map<int, vector<int> > map;
      vector<int> zero_vec(1, 0);
      map[0] = zero_vec;
      int size = nums.size();
      vector<int> dp(size + 1, 0);
      
      for (int iter = 0; iter < size; ++ iter) {
        if (iter + 1 < size && nums[iter] == 0 && nums[iter + 1] == 0) {
          continue;
        }
        
        sum += nums[iter];    
        vector<int> vec;
        if (map.find(sum) == map.end()) {
          map[sum] = vec;
        }
        map[sum].push_back(iter + 1);
        dp[iter + 1] = sum;
      }
      
      int share_sum = 0;
      for (int iter = 0; iter < size; ++ iter) {
        share_sum = dp[iter + 1];  
        if(find(nums, map, dp, sum, share_sum, 0, 0)) {
          return true;   
        }
      }  
      return false;
    }
};
