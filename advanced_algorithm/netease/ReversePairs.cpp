class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long mergeSortHelper(vector<int> &A, int left, int right) {
      if (left >= right) {
        return 0;
      } 
      int mid = left + (right - left) / 2;
      long long left_cnt = mergeSortHelper(A, left, mid);
      long long right_cnt = mergeSortHelper(A, mid + 1, right);
      long long between_cnt = merge(A, left, mid, right);
      return left_cnt + right_cnt + between_cnt;
    }
    
    long long merge(vector<int> &A, int left, int mid, int right) {
      long long res = 0;
      int A_size = mid - left + 1;
      int B_size = right - mid;
      vector<int> B(B_size);
      for (int vec_i = mid + 1; vec_i <= right; ++ vec_i) {
        B[vec_i - mid - 1] = A[vec_i];
      }
      
      int new_i = right;
      int A_i = mid;
      int B_i = B_size - 1;
      
      long long A_cnt = 0;
      for (; B_i > -1; ) {
        if (A_i > left - 1 && A[A_i] > B[B_i]) {
          A[new_i -- ]  = A[A_i -- ];
          A_cnt ++;
        } else {
          A[new_i -- ]  = B[B_i -- ];
          res += A_cnt;
        }
      }
      return res;
    }
    
    
    long long reversePairs(vector<int> &A) {
        // write your code here
      int size = A.size();
      //quickSortHelper(A, 0, size - 1);
      return mergeSortHelper(A, 0, size - 1);
    }
};
