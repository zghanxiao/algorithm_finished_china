class Solution {
public:
  
    bool qEmpty(vector<int> & nums, int i) {
      return i == nums.size();  
    }
  
    int qSize(vector<int> & nums, int i) {
      return nums.size() - i;
    }
  
    int qTop(vector<int> & nums, int i) {
      return nums[i];  
    }
  
    bool qPopLen(vector<int> & nums, int &i, int len) {
      if(i + len > nums.size()){
        return false; 
      }   
      i += len;
      return true;
    }
  
    int qIndex(vector<int> &nums, int i, int new_i) {
      return nums[i + new_i];  
    }
  
    int findkth(vector<int>& nums1, vector<int> & nums2, int k, int i1, int i2) {
      while(k) {
        int q_size1 = qSize(nums1, i1);
        int q_size2 = qSize(nums2, i2);
        
        if (k > q_size1 + q_size2) {
          return -1;
        }
        
        if(q_size1 > q_size2) {
          swap(nums1, nums2);
          swap(i1, i2);
          swap(q_size1, q_size2);
        }
        
        if (k == 1) {
          int q_val1 = qEmpty(nums1, i1) ? INT_MAX:qTop(nums1, i1);
          int q_val2 = qTop(nums2, i2);
          return min(q_val1, q_val2);
        } 
        
        int cut_len1 = min(q_size1, k/2) , cut_len2 = k - cut_len1;
        
        if (cut_len1 == 0) {
          return qIndex(nums2, i2, cut_len2 - 1);  
        } else if (qIndex(nums1, i1, cut_len1 - 1) < qIndex(nums2, i2, cut_len2 - 1)) {
          qPopLen(nums1, i1, cut_len1); 
          k -= cut_len1;
        } else {
          qPopLen(nums2, i2, cut_len2);
          k -= cut_len2;
        }
      }
      return -1;
    }
  
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int tot_size = nums1.size() + nums2.size();
      double res = 0.0;
      if (tot_size % 2 == 0) {
        int res1 = findkth(nums1, nums2, tot_size/2, 0, 0); 
        int res2 = findkth(nums1, nums2, tot_size/2 + 1, 0, 0); 
        res = ((double)(res1) + (double)(res2))/2.0;
      } else if (tot_size % 2 == 1) {
        res = (double)(findkth(nums1, nums2, (tot_size + 1)/2, 0, 0)); 
      }
      return res;
    }
};
