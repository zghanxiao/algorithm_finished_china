class Solution {
public:
    /**
     * @param n: the number of sectors
     * @param m: the number of colors
     * @return: The total number of plans.
     */
    int modMul(int a, int b, int mod_val) {
      long long temp_mul_res = (long long)(a % mod_val) * (long long)(b % mod_val);
      temp_mul_res %= mod_val;
      return (int)(temp_mul_res);
    }
    
    int modMinus(int a, int b, int mod_val) {
      return ( (a % mod_val) + mod_val - (b% mod_val) ) % mod_val;
    }
    
    int getCount(int n, int m) {
        // Write your code here
      int mod_val = pow(10, 9) + 7;
      vector<int> Dyings(n + 1, 0);
      
      Dyings[1] = m % mod_val;
      Dyings[2] = modMul(m,  modMinus(m, 1, mod_val), mod_val);        
    
      int mul = Dyings[2];
      for (int iter = 3; iter <= n; ++ iter) {
        mul = modMul(mul, modMinus(m, 1, mod_val), mod_val);
        Dyings[iter] = modMinus(mul, Dyings[iter - 1], mod_val);
      }
      return Dyings[n];       
    }
}; 
