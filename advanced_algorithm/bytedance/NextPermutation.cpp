class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    int i = size - 1;
    for (; i >= 1; i --) {
      if (nums[i] > nums[i - 1]) {
        break; 
      }
    }
    
    if (i != 0) {
      int s_i = i;
      for (; s_i < size; s_i ++ ) {
        if (nums[s_i] <= nums[i - 1]) {
          break;    
        }  
      }
      swap(nums[s_i - 1], nums[i - 1]);
    }
    reverse(nums.begin() + i, nums.end());
    return;
  }
};
