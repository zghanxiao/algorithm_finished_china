class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        // write your code here
      int size = A.size();
      vector<int> sum(size + 1, 0);
      
      for (int iter = 0; iter < size; ++ iter) {
        sum[iter + 1] = sum[iter] + A[iter];
      }
      
      sort(sum.begin(), sum.end());
      
      int left = 0;
      int right = 0;
      
      int total_sum = 0;
      for (int iter = 0; iter <= size; ++ iter) {
        while(left < iter && sum[left] < sum[iter] - end) {
          left ++;
        } 
        
        while (right < iter && sum[right] <= sum[iter] - start) {
          right ++;
        }
        
        if (right - left >= 0) {
           total_sum += right - left ;
        }
      }
      return total_sum;
    }
};
