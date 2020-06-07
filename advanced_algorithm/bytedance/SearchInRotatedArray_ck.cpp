class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    
    bool check(vector<int> & A, int index, int left, int right, int target) {
      if (A[left] > A[right]) {
        if (A[index] >= A[left]) {
          return target >= A[left] && target <= A[index];
        } 
        if (A[index] <= A[right]) {
          return !(target > A[index] && target <= A[right]); 
        } 
        return false;
      } else {
        return A[index] >= target;  
      }
    }
    
    
    int biMinSearch(vector<int> &A, int left, int right, int target) {
   
      while(left < right) {
        int mid = left + (right - left) / 2;  
        if (A[mid] == target &&(mid == 0 || A[mid] != A[mid - 1])) {
          return mid;
        }
        if (check(A, mid, left, right, target)) {
          right = mid;    
        } else {
          left = mid + 1;    
        }
      } 
      return left == right && check(A, right, left, right, target) ? right : right + 1;
    } 
    
    
    int search(vector<int> &A, int target) {
      // write your code here
      int size = A.size();  
      int res = biMinSearch(A, 0, size - 1, target);
      if (res >= 0 && res <= size - 1 && A[res] == target) {
        return res;
      } else {
        return -1;
      }
    }
};
