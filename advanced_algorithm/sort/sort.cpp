class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    
    int partition(vector<int> & nums, int left, int right) {
      if (left > right) {
        return -1;
      } else if (left == right) {
        return left;
      }
     
      int pivot = nums[left];
      int left_iter = left + 1;
      int right_iter = right;
     
      for (;left_iter <= right_iter && left_iter <= right && 
        right_iter >= left + 1;) {
        while(left_iter <= right && nums[left_iter] < pivot ) {
          left_iter ++;    
        }
        
        while(right_iter >= left + 1 && nums[right_iter] >= pivot) {
          right_iter --;
        }
        
        if (left_iter <= right_iter) {
          swap(nums[left_iter], nums[right_iter]);
        }
      }
      swap(nums[left], nums[left_iter - 1]);
      return left_iter - 1;
    }
    
    
    void quickSortHelper(vector<int> &A, int left, int right) {
       if (left >= right) {
         return;
       }
       int res = partition(A, left, right); 
       quickSortHelper(A, left, res - 1);
       quickSortHelper(A, res + 1, right);
    }    
    
    void mergeSortHelper(vector<int> &A, int left, int right) {
      if (left >= right) {
        return;
      } 
      int mid = left + (right - left) / 2;
      mergeSortHelper(A, left, mid);
      mergeSortHelper(A, mid + 1, right);
      merge(A, left, mid, right);
    }
    
    void merge(vector<int> &A, int left, int mid, int right) {
      int A_size = mid - left + 1;
      int B_size = right - mid;
      vector<int> B(B_size);
      for (int vec_i = mid + 1; vec_i <= right; ++ vec_i) {
        B[vec_i - mid - 1] = A[vec_i];
      }
      
      int new_i = right;
      int A_i = mid;
      int B_i = B_size - 1;
      
      for (; B_i > -1; ) {
        A[new_i -- ] = A_i > left - 1 &&  A[A_i] > B[B_i] ? A[A_i --] :B[B_i --];
      }
    }
    
    
    void sortIntegers2(vector<int> &A) {
      // write your code here
      int size = A.size();
      //quickSortHelper(A, 0, size - 1);
      mergeSortHelper(A, 0, size - 1);
    }
};
