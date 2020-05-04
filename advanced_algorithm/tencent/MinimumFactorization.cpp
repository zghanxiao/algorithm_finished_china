class Solution {
public:
    /**
     * @param a: a positive integer
     * @return: the smallest positive integer whose multiplication of each digit equals to a
     */
    
    bool safe_add(int a, int b, int & res) {
      if (a > INT_MAX - b) {
        return false; 
      }
      res = a + b;
      return true;
    }
    
    bool safe_mul(int a, int b, int & res) {
      if (a == 0 || b == 0) {
        res = 0;
        return true;
      }
      
      if (a > INT_MAX / b) {
        return false; 
      }
      
      res = a * b;
      return true;
    }
    
    int smallestFactorization(int a) {
      // Write your code here
      
      int sum = 0;
      int base = 1;
      for (int iter = 9; a != 1 && iter >= 2; --iter) {
        if (a % iter  == 0) {
          while(a % iter == 0){
            a /= iter;
            int inc;
            if(!safe_mul(base, iter, inc) || 
                 !safe_add(inc, sum, sum) ||
                 !safe_mul(base, 10, base)) {
              return 0;
            }
          }
        }
      }
      
      if (a!= 1) {
        return 0;
      }
      
      return sum; 
    }
};
