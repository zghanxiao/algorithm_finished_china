class Solution {
public:
    /**
     * @param a: a positive integer
     * @return: the smallest positive integer whose multiplication of each digit equals to a
     */
    vector<int> prime;
    
    Solution() {
      prime.clear();
      prime.push_back(2);
      prime.push_back(3);
      prime.push_back(5);
    }
    
    void generate_prime(int a) {
      int prime_size = prime.size();
      int last = prime[prime_size -1];
      for (int iter = last + 2; iter * iter <= a; iter += 2) {
        bool flag = true;
        for (int pre_i = 1; pre_i < prime.size(); ++ pre_i) {
          if (iter % prime[pre_i] == 0) {
            flag = false;
            break;
          }
        }
        if (flag) {
          prime.push_back(iter);    
        }
      }
    }
    
    // 2, 3, 5, 7
    bool defactor(int a, unordered_map<int, int> &cnt) {
      generate_prime(a);    
      for (int pr_i = 0; pr_i < prime.size(); ++ pr_i) {
        int prime_val = prime[pr_i];
        if (a % prime_val == 0) {
          if (prime_val >= 10) {
            return false;
          }
          while(a % prime_val == 0) {
            a /= prime_val;
            if (cnt.find(prime_val) == cnt.end()) {
              cnt[prime_val] = 0;
            }
            cnt[prime_val] ++;
          }
        }  
      }
      
      if (a != 1) {
        if (a >= 10) {
          return false;
        }
        cnt[a] = 1;
      }
      return true;
    }
    
    bool build_num(int& sum, int digit, int num) {
       for (int num_i = 0; num_i < num; ++ num_i) {
         if (sum > INT_MAX/10) {
           return false;
         }
         sum *= 10;
         if (sum > INT_MAX - digit) {
           return false;
         }
         sum += digit;
       }
       return true;
    }
    
    int get_val(unordered_map<int, int> map, int key) {
      if (map.find(key) == map.end()) {
        return 0; 
      } else {
        return map[key];
      }
    }
    
    int smallestFactorization(int a) {
        // Write your code here
        unordered_map<int, int> cnt;
        if (!defactor(a, cnt)) {
          return 0;
        }
        unordered_map<int, int> new_cnt;
        new_cnt[2] = get_val(cnt, 2);
        new_cnt[3] = get_val(cnt, 3);
        new_cnt[5] = get_val(cnt, 5);
        new_cnt[7] = get_val(cnt, 7);
        
        new_cnt[8]= new_cnt[2] / 3;
        new_cnt[2] %= 3;
        
        int two_and_three = (new_cnt[2] + new_cnt[3]) % 2;
        
        int digit = 0;
        if (two_and_three) {
          if (new_cnt[2]) {
            digit = 2;
            new_cnt[2] --; 
          } else if (new_cnt[3]) {
            digit = 3;
            new_cnt[3] --;
          }
        }
        new_cnt[4] = new_cnt[2] / 2;
        new_cnt[2] %= 2; 
        
        new_cnt[6] = 0; 
        if (new_cnt[2] >= 1 && new_cnt[3] >= 1) {
          new_cnt[6] = 1;
          new_cnt[2] -= 1;
          new_cnt[3] -= 1;
        }
        
        new_cnt[9] = new_cnt[3] / 2;
        new_cnt[3] = 0;
        
        if (two_and_three) {
          if (digit == 2) {
            new_cnt[2] = 1;
            new_cnt[3] = 0;
          } else {
            new_cnt[2] = 0;
            new_cnt[3] = 1;
          }
        }
        
        int sum = 0;
        
        for (int iter = 2; iter <= 9; ++ iter) {
          if (!build_num(sum, iter, new_cnt[iter])) {
            return 0;
          }
        }
        
        return sum;
    }
};
