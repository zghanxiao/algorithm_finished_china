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
  
  vector<int> find(int remain, int zero_size, bool start_with_one) {
    vector<int> res;
    int peek = getSum(zero_size);
    while(peek) {
      if (!start_with_one) {
        --remain; 
      } 
      
      if (remain == 0) {
        break;
      }
      
      int remove_digit = (remain - 1) / peek;
      res.push_back(start_with_one? remove_digit + 1: remove_digit);    
      remain -= remove_digit * peek;
      peek /= 10;
      start_with_one = false;
    }
    return res;
  }
  
  // will return full tree
  // end_depth >= start_depth
  // start_depth is not zero
  int peekVal(int start_depth, int end_depth, int start_digit, bool pre_peek = true) {
    int remove_digit = 0;
    if (pre_peek) { 
      remove_digit = start_depth == 1? start_digit - 1 : start_digit;
    } else {
      remove_digit = 9 - start_digit;
    }
    int sum = 0;
    for (int iter = end_depth; iter >= start_depth; -- iter) {
      sum *= 10;
      sum += 1;
      if (iter == start_depth) {
        sum *= remove_digit;  
      }
    }
    if (pre_peek) {
      sum += start_depth == 1? 0: 1;
    }
    return sum;
  }
  
  int findKthNumber(int n, int k) { 
    vector<int> vec = numToVec(n);
    int size = vec.size();
    int sum = 0;
    vector<int> total_res;  
    
    int iter = 0;
    for (; iter < size; ++ iter) {
      int digit = vec[iter]; 
      int peek_val = peekVal(iter + 1, size, digit, true);
      if (k <= sum + peek_val) {
        int remain = k - sum; 
        int zero_size = size - (iter + 1);
        vector<int> find_res = find(remain, zero_size, iter == 0);
        for(int res_num: find_res) {
          total_res.push_back(res_num);  
        }
        return vecToNum(total_res);
      }
      sum += peek_val;
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
      int peek_val = peekVal(vec_i + 1, size, digit, false);
      
      if (k <= sum + peek_val) {
        int remain = k - sum;
        int zero_size = size - 1 - vec_i;
        vector<int> res = find(remain, zero_size, true);  
        res[0] = digit  + res[0];
        for (int res_num: res) {
          total_res.push_back(res_num);
        }
        return vecToNum(total_res);
      }
      sum += peek_val;
    }
    return vecToNum(total_res);
  }
};
