class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
      // write your code here
      vector<bool> flag(n + 1, false);
      flag[0] = true;
      int flag_cnt = 0;
      for (int coin_i = 0; coin_i < value.size(); ++ coin_i) {
        int coin_val = value[coin_i];      
        int coin_cnt = amount[coin_i];
        for (int flag_i = n; flag_i >= coin_val; -- flag_i) {
          for (int cnt_i = 1; cnt_i <= coin_cnt; ++ cnt_i) {
            int total_cnt_val = coin_val * cnt_i;
            if (flag_i >= total_cnt_val && flag[flag_i - total_cnt_val]) {
              if (!flag[flag_i]) {
                flag_cnt ++;
              }
              flag[flag_i] = true;
              break;
            }
          }
        } 
      }
      
      return flag_cnt;
    }
};
