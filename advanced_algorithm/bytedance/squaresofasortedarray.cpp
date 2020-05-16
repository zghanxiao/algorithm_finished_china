class Solution {
public:
    /**
     * @param A: The array A.
     * @return: The array of the squares.
     */
    vector<int> SquareArray(vector<int> &A) {
      // 
      
      int size = A.size();
      int iter = 0;
      for (; iter < size; ++ iter) {
        if (A[iter] < 0) {
          A[iter] = 0 - A[iter];
        } else {
          break;
        }
      }
      
      int head1 = 0;
      int tail1 = iter - 1;
      if (head1 < tail1) {
        reverse(A.begin() + head1, A.begin() + tail1 + 1);  
      }
      
      int head2 = iter; 
      int tail2 = size - 1;
      vector<int> new_vec;
      
      int iter1 = head1;
      int iter2 = head2;
      for (;iter1 <= tail1 || iter2 <= tail2;) {
        if (iter1 > tail1) {
          new_vec.push_back(A[iter2] * A[iter2]);    
          iter2 ++;
        } else if (iter2 > tail2) {
          new_vec.push_back(A[iter1] * A[iter1]);
          iter1 ++;
        } else {
          if (A[iter1] < A[iter2]) {
            new_vec.push_back(A[iter1] * A[iter1]);    
            iter1 ++;
          } else {
            new_vec.push_back(A[iter2] * A[iter2]);
            iter2 ++;
          } 
        }
      }
      
      return new_vec;
    }
};
