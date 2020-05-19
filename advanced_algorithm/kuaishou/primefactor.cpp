class Solution {
public:
    /**
     * @param N: a number
     * @return: the number of prime numbers.
     */
    vector<int> prime;
    
    Solution() {
      prime.clear();
    }
    
    void init_prime(int N, unordered_set<int>& prime_set) {
      // get all the prime for checking N.
      if (prime.size() <= 2) {
        if (N >= 2) {
          prime.push_back(2);
          prime_set.insert(2);
        }
        
        if (N >= 3) {
          prime.push_back(3);
          prime_set.insert(3);
        }
      }
      
      if (N <= 3) {
        return;
      }
      
      int last = prime[prime.size() - 1];
      for (int iter = last; iter <= N; iter += 2) {
        bool flag = true;
        for (int pr_i = 0; pr_i < prime.size(); ++ pr_i) {
          if(iter % prime[pr_i] == 0) {
            flag = false;
            break;
          }
        }  
        if (flag) {
          prime.push_back(iter);
          prime_set.insert(iter);
        }
      }
    }
    
    
    int Count_PrimeNum(int N) {
      unordered_set<int> prime_set;
      init_prime(N, prime_set);
      int tot_sum = 0;
      vector<int> cnt_arr(N + 1, 0);
      for (int iter = 2; iter <= N; ++ iter) {
        if (prime_set.find(iter) != prime_set.end()) {
          cnt_arr[iter] = 1;
          tot_sum += cnt_arr[iter];
          continue;
        }
        
        for (int pr_i = 0; pr_i < prime.size() && prime[pr_i] <= iter; ++ pr_i) {
          int prime_val = prime[pr_i];
          if (iter % prime_val == 0) {
            cnt_arr[iter] = cnt_arr[prime_val] + cnt_arr[iter / prime_val];
            tot_sum += cnt_arr[iter];
            break;
          } 
        }
        
      }
      return tot_sum;
    }
};
