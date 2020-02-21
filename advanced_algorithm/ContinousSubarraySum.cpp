class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
      // write your code here
      
      vector<int> res(2, 0);
      int size = A.size();
      // if size == 0, return 0, 0;
      
      if (size == 0) {
        return res;
      }
      
      vector<int> sum(size + 1, 0);
      for (int iter = 0; iter < size; ++ iter) {
        sum[iter + 1] = sum[iter] + A[iter];
      }
      
      int min_val = INT_MAX, min_index = -1;
      int max_diff = INT_MIN;
      
      
      for (int iter = 0; iter <= size; ++ iter) {
        if (iter != 0) {
          int diff = sum[iter] - min_val;
          if (diff > max_diff) {
            max_diff = diff;
            res[0] = min_index;
            res[1] = iter - 1;
          } 
        }
        if ( sum[iter] < min_val) {
          min_val = sum[iter];
          min_index = iter;
        }
      }
      return res;
    }
};
