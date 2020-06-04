class Solution {
public:
    vector<int> numToVec(int n) {
      vector<int> vec;
      if (n != 0) {
        while(n) {
          vec.push_back(n % 10); 
          n /= 10;  
        }  
      } else {
        vec.push_back(0);
      }
      reverse(vec.begin(), vec.end());
      return vec;
    }
  
    int vecToNum(vector<int> & vec) {
      int sum = 0;
      for (int digit: vec) {
        sum *= 10;
        sum += digit;
      } 
      return sum;
    }
  
    int getSum(int zero_size) {
      int sum = 1;
      for (int zero_i = 1; zero_i <= zero_size; ++ zero_i)  {
        sum = sum * 10  + 1;
      } 
      return sum;
    }
  
    vector<int> find(int remain, int zero_size, bool ini) {
      vector<int> res;
      int peek = 1; 
      for (int zero_i = 1; zero_i <= zero_size; ++ zero_i) {
        peek = peek * 10 + 1;   
      }
      
      while(peek) {
        if (!ini) {
          --remain; 
        } 
        
        if (remain == 0) {
          break;
        }
        
        int remove_digit = (remain - 1) / peek;
        //cout << "remove_digit" << remove_digit << endl;
        res.push_back(ini ? remove_digit + 1: remove_digit);    
        remain -= remove_digit * peek;
        peek /= 10;
        ini = false;
      }
      return res;
    }
  
    int findKthNumber(int n, int k) { 
      vector<int> vec = numToVec(n);
      int size = vec.size();
      
      int sum = 0;
      int head_digit = -1;
      vector<int> total_res;  
      
      int iter = 0;
      for (; iter < size; ++ iter) {
        //cout << "iter " << iter << endl;
        int digit = vec[iter]; 
        if (iter == 0) {
          head_digit = digit;
        }
        
        int zero_size = size - (iter + 1); 
        int empty_inc = iter == 0? 0: 1;
        int peek = getSum(zero_size);
        int remove_digit = iter == 0 ? (digit - 1): digit;
        int mul_peek = peek * remove_digit;
        int tot_peek = mul_peek + empty_inc;
        if (sum + tot_peek >= k) {
          int remain = k - sum; 
          vector<int> find_res = find(remain, zero_size, iter == 0);
          for(int res_num: find_res) {
            total_res.push_back(res_num);  
          }
          return vecToNum(total_res);
        }
        sum += tot_peek;
        total_res.push_back(digit);
      }
      
      sum ++;
      if (k == sum) {
        return vecToNum(total_res);  
      }
      
      total_res.clear();
      
      if (vec.size() == 1) {
        return vecToNum(vec);
      } else {
        vec.resize(vec.size() - 1);   
        size --;
      }
      
      total_res = vec;
      for (int vec_i = size - 1; vec_i >= 0; -- vec_i) {
        total_res.pop_back();
        int digit = vec[vec_i];
        int zero_size = size - 1 - vec_i;
        int peek = getSum(zero_size);
        int total_peek = peek * (9 - digit);
        if (k <= sum + total_peek) {
          int remain = k - sum;
          vector<int> res = find(remain, zero_size, true);  
          res[0] = digit  + res[0];
          for (int res_num: res) {
            total_res.push_back(res_num);
          }
          cout << endl;
          return vecToNum(total_res);
        }
        sum += total_peek;
      }
      return vecToNum(total_res);
    }
};
