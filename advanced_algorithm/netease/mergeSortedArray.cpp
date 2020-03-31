class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    /*
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your codehere
        int new_i = m + n - 1;
        for (int A_i = m - 1, B_i = n - 1; new_i >= 0;)  {
          if (B_i < 0) {
            A[new_i --] = A[A_i -- ];   
          } else if (A_i < 0) {
            A[new_i --] = B[B_i --];
          } else if (A[A_i] >= B[B_i]) {
            A[new_i --] = A[A_i -- ];   
          } else { 
            A[new_i --] = B[B_i --];
          }
        }
    }
    */
    void mergeSortedArray(int A[], int m, int B[], int n) {
      int new_i = m + n - 1;
      int A_i = m - 1;
      int B_i = n - 1;
      for (; B_i > -1 ;) { 
        A[new_i --] = A_i != -1 && A[A_i] > B[B_i] ? A[A_i --] : B[B_i --];
      }
    }
};
