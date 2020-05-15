class Solution {
public:
    /**
     * @param m: the number of eggs
     * @param n: the number of floors
     * @return: the number of drops in the worst case
     */
    int dp[1000] [100];
    int dropEggs2(int m, int n) {
      // write your code here
      for (int egg_i = 1; egg_i <= m; ++ egg_i) {
        for (int dp_i = 1; dp_i <= n; ++ dp_i ) {
          if (dp_i == 1) {
            dp[egg_i][1] = 1;    
          } else {
            if (egg_i != 1) {
              dp[egg_i][dp_i] = dp[egg_i][dp_i - 1] + dp[egg_i - 1][dp_i - 1] + 1;
            } else {
              dp[egg_i][dp_i] = dp[egg_i][dp_i - 1] + 1;
            }
          }
          if (dp[egg_i][dp_i] >= n) {
            if (egg_i == m) {
              return dp_i;
            }
            break;
          }
        }
        cout << endl;
      }
      return -1;
    }
};
