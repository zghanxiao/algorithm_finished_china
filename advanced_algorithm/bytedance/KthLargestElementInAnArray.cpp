class Solution {
public:
    int partition(vector<int> & nums, int ori_l, int ori_r) {
      int size = nums.size();
      if (size <= 1) {
        return size - 1;
      }
      
      int pivot = nums[ori_l]; 
      int l = ori_l + 1; 
      int r = ori_r;
      
      while(l <= r) {
        while(l <= ori_r && nums[l] <= pivot) {
          ++l; 
        }   
        while(r >= ori_l + 1 && nums[r] > pivot) {
          --r; 
        }
        
        if (l < r) {
          swap(nums[l], nums[r]);
        }
        
      }
      swap(nums[ori_l], nums[r]);
      return r;
    } 
 
    int findKthLargest(vector<int> & nums, int k) {
      int size = nums.size();
      int l = 0, r = size - 1;
      int target = size - k;
      while(true) {
        int pos = partition(nums, l, r);  
        if (pos == target) {
          break;
        } else if (pos > target) {
          r = pos - 1;
        } else {
          l = pos + 1; 
        }
      }
      return nums[target];
    }
};
