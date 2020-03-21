class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
      // write your code here
      string res;
      if (a == "0" && b == "0") {
        res = "0";
        return res;
      }
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      
      int a_size = a.size();
      int b_size = b.size();
      int max_ab_size = max(a_size, b_size);
      
      int c = 0;
      
      for (int i = 0; i < max_ab_size ; ++ i ) {
        int a_val = i < a_size ? a[i] - '0' : 0;
        int b_val = i < b_size ? b[i] - '0' : 0;
        int num = a_val + b_val + c;
        c = num / 2;
        res.push_back(num % 2 + '0'); 
      }
      
      if (c) {
        res.push_back('1');
      }
      reverse(res.begin(), res.end());
      
      return res;
    }
};
