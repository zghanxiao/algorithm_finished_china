class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: nothing
     */
     
    bool check(vector<int> & nums, int index, int target) {
      return nums[index] <= target; 
    }
    
    int bfsMin(vector<int> &nums, int left , int right, int target) {
      while(left < right) {
        int mid = left + (right - left) / 2;
        
        if (check(nums, mid, target)) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }    
      return left == right && check(nums, right, target) ? right: right + 1;
    }
   
    void nextPermutation(vector<int> &nums) {
      // write your code here
      int size = nums.size();
      
      if (size <= 1) {
        return; 
      }
      
      int iter = -1;
      for (iter = size - 1; iter >= 1; iter --) {
        if (nums[iter] > nums[iter - 1]) {
          break;
        }  
      } 
      
      if (iter == 0) {
        reverse(nums.begin(), nums.end());
        return;
      }
      int pos = bfsMin(nums, iter, size - 1, nums[iter - 1]);
      swap(nums[iter - 1], nums[pos - 1]); 
      reverse(nums.begin() + iter, nums.end());
      return;
    }
};
