class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        // write your code here
      vector<int> res_max(2, 0);
      int size = A.size();
      // if size == 0, return 0, 0;
      
      if (size == 0) {
        return res_max;
      }
      
      vector<int> res_min(2, 0);
      
      vector<int> sum(size + 1, 0);
      for (int iter = 0; iter < size; ++ iter) {
        sum[iter + 1] = sum[iter] + A[iter];
      }
      
      int min_val = INT_MAX, min_index = -1;
      int max_diff = INT_MIN;
      
      int max_val = INT_MIN, max_index = -1;
      int min_diff = INT_MAX;
      
      for (int iter = 0; iter <= size; ++ iter) {
        if (iter != 0) {
          int temp_max_diff = sum[iter] - min_val;
          if (temp_max_diff > max_diff) {
            max_diff = temp_max_diff;
            res_max[0] = min_index;
            res_max[1] = iter - 1;
          } 
          
          int temp_min_diff = sum[iter] - max_val;
          if (temp_min_diff < min_diff && iter - max_index != size) {
            min_diff = temp_min_diff;
            //res_min[0] = max_index;
            //res_min[1] = iter - 1;
           
            res_min[0] = (iter + size) % size;
            res_min[1] = (max_index - 1 + size) % size;
          }
        }
        
        if ( sum[iter] < min_val) {
          min_val = sum[iter];
          min_index = iter;
        }
        
        if ( sum[iter] > max_val) {
          max_val = sum[iter];
          max_index = iter;
        }
      }
      
      if (max_diff > sum[size] -  min_diff) {
        return  res_max;
      } else {
        return res_min;
      }
    }
};
