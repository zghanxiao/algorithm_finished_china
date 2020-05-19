// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution :public SolBase {
public:
    int rand_val[7]; 
    
    Solution() {
      memset(rand_val, 0, sizeof(rand_val));
    }
    
    int rand10() {
       int index = rand7();
       int ret_val = rand_val[index] % 10;
       rand_val[index] += 7;
       rand_val[index] %= 70;
       return ret_val;
    }
};
