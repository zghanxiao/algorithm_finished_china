#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  /*
   * @param A: An integer matrix
   * @return: The index of the peak
   */
  bool valid(int curr_row_i, int curr_col_i, int row_size, int col_size) {
    return curr_row_i >= 0 && curr_col_i >= 0 && curr_row_i < row_size &&
      curr_col_i < col_size;
  }

  pair<int, int> checkPeakOrBigger(int max_row_i, int max_col_i, int row_size, int col_size,
      vector<vector<int> > &A, vector<vector<bool> > & visited, bool debug = false)
      {
    int dir[4][2] = { { 0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    // Check Peak
    int peak_cnt = 0; 
    pair<int, int> res_pair;
    bool valid_flag = false;
    for (int dir_i = 0; dir_i < 4; ++ dir_i) {

      int delta_row_i = dir[dir_i][0];
      int delta_col_i = dir[dir_i][1];
      int check_row_i = max_row_i + delta_row_i;
      int check_col_i = max_col_i + delta_col_i;

      if (valid(check_row_i, check_col_i, row_size, col_size) 
          && A[check_row_i][check_col_i] < A[max_row_i][max_col_i]) {
        ++ peak_cnt;
      }
      
      if (valid(check_row_i, check_col_i, row_size, col_size) && !visited[check_row_i][check_col_i] &&
          A[check_row_i][check_col_i] > A[max_row_i][max_col_i]) {
        valid_flag = true;
        res_pair.first = delta_row_i;
        res_pair.second = delta_col_i;
      }
    }

    if (peak_cnt == 4) {
      return make_pair(0, 0);
    }

    // Search Bigger
    if (!valid_flag) {
      res_pair.first = INT_MIN;
      res_pair.second = INT_MIN;
    }
    return res_pair;
  }

  bool getNewRectangle(int & start_row_i, int & start_col_i, int & end_row_i,
      int & end_col_i, int new_row_i, int new_col_i) {

        int mid_row_i = (start_row_i + end_row_i) / 2;
        int mid_col_i = (start_col_i + end_col_i) / 2;

        if (new_row_i < mid_row_i && new_col_i < mid_col_i) {
            // upper left
            end_row_i = mid_row_i;
            end_col_i = mid_col_i;
        } else if ( new_row_i < mid_row_i && new_col_i > mid_col_i) {
           // upper right
           end_row_i= mid_row_i;
           start_col_i = mid_col_i;
        } else if ( new_row_i > mid_row_i && new_col_i < mid_col_i) {
           // lower left
           start_row_i = mid_row_i;
           end_col_i = mid_col_i;
        } else if ( new_row_i > mid_row_i && new_col_i > mid_col_i) {
          // lower right
          start_row_i = mid_row_i;
          start_col_i = mid_col_i;
        } else {
          // invalid
          return false;
        }
        return true;
  }

  void visitAndCompare(int row_i, int col_i, vector<vector<bool> > & visited, vector<vector<int> > & A,
      int &max_val, int & max_row_i, int & max_col_i) { 
    visited[row_i][col_i] = true;
    if (A[row_i][col_i] > max_val) {
      max_val = A[row_i][col_i];
      max_row_i = row_i;
      max_col_i = col_i;
    }
  }

  pair<int, int> findWindowPane(int start_row_i, int start_col_i, int end_row_i,
       int end_col_i, int row_size, int col_size, vector<vector<int> > &A,
       vector<vector<bool> > & visited) {

    bool debug = row_size == 182 && col_size == 210; 
    int row_i, col_i;
    int max_val = INT_MIN;
    int max_row_i = -1, max_col_i = -1;
    int mid_row_i = (start_row_i + end_row_i) / 2;
    int mid_col_i = (start_col_i + end_col_i) / 2;
    
    // top edge
    for (row_i = start_row_i, col_i = start_col_i; col_i <= end_col_i; ++ col_i) {
      visitAndCompare(row_i, col_i, visited, A, max_val, max_row_i, max_col_i);
    }

    // bottom edge
    for (row_i = end_row_i, col_i = start_col_i; col_i <= end_col_i; ++ col_i) {
      visitAndCompare(row_i, col_i, visited, A, max_val, max_row_i, max_col_i);
    }

    // left column
    for (col_i = start_col_i, row_i = start_row_i; row_i <= end_row_i; ++ row_i) {
      visitAndCompare(row_i, col_i, visited, A, max_val, max_row_i, max_col_i);
    }

    // right column
    for (col_i = end_col_i, row_i = start_row_i; row_i <= end_row_i; ++ row_i) {
      visitAndCompare(row_i, col_i, visited, A, max_val, max_row_i, max_col_i);
    }

    pair<int, int> res_pair;
    while (end_row_i >= start_row_i  && end_col_i >= start_col_i) {

      mid_row_i = (start_row_i + end_row_i) / 2;
      mid_col_i = (start_col_i + end_col_i) / 2;

      // middle row
      for (row_i = mid_row_i, col_i = start_col_i; col_i <= end_col_i; ++ col_i) {
        visitAndCompare(row_i, col_i, visited, A, max_val, max_row_i, max_col_i);
      }

      // middle column
      for (col_i = mid_col_i, row_i = start_row_i; row_i <= end_row_i; ++ row_i) {
        visitAndCompare(row_i, col_i, visited, A, max_val, max_row_i, max_col_i);
      }

      pair<int, int> res = checkPeakOrBigger(max_row_i, max_col_i, row_size, col_size, A, visited, debug);

      if (res.first == INT_MIN && res.second == INT_MIN) {
        return make_pair(-1, -1);
      } else if (res.first == 0 && res.second == 0) {
        return make_pair(max_row_i, max_col_i);
      }

      int new_row_i = max_row_i + res.first;
      int new_col_i = max_col_i + res.second;

      if(!getNewRectangle(start_row_i, start_col_i, end_row_i, end_col_i, new_row_i, new_col_i)) {
        return make_pair(res_pair.first, res_pair.second);
      }
    }
    return make_pair(res_pair.first, res_pair.second);
  }

  static int static_cnt;
  vector<int> findPeakII(vector<vector<int> > &A) {
    // write your code here
    ++ static_cnt;
    
    vector<int> res;

    int row_size = A.size();

    if (row_size <= 2 ) {
      return res;
    }

    int col_size = A[0].size();

    if (col_size <= 2) {
      return res;
    }
    
    vector<vector<bool> > visited(row_size, vector<bool>(col_size, false));

    int start_row_i = 0;
    int start_col_i = 0;
    int end_row_i = row_size - 1;
    int end_col_i = col_size - 1;

    
    pair<int, int> pair_res = findWindowPane(start_row_i, start_col_i, end_row_i,
        end_col_i, row_size, col_size, A, visited);
        
    res.push_back(pair_res.first);
    res.push_back(pair_res.second);
    return res;
  }
};

int Solution::static_cnt = 0;

int main() {
  /*int A[3][3] = {
    {1, 5, 3},
    {4,10, 9},
    {2, 8, 7}
  };
  */

  /*
   int A[5][5] = {
      {1, 2, 3, 6,  5},
      {16,41,23,22, 6},
      {15,17,24,21, 7},
      {14,18,19,20,10},
      {13,14,11,10, 9}
    };
   */
  /*
  cout << "main_0" << endl;
  int A[6][4] = {
    {1,2,4,3},
    {5,6,8,7},
    {9,10,12,11},
    {13,14,16,15},
    {21,22,24,23},
    {17,18,20,19}
  };
  */

  //buggy test case TLE [[1,2,4,3],[5,6,8,7],[9,10,12,11],[13,14,16,15],[21,22,24,23],[17,18,20,19]]

  int A[5][4] = {
    {5,6,8,7},
    {9,10,12,11},
    {13,14,16,15},
    {21,22,24,23},
    {17,18,20,19}
  };
  /*
  int A[6][6] =  {
    {0,2,0,1,3,2},
    {2,4,12,3,4,3},
    {0,5,11,7,12,0},
    {8,9,10,9,13,12},
    {11,13,9,15,16,11},
    {0,7,8,0,15,0}
  }; 
  */
  // buggy test case TLE int A[6][6] =  [[0,2,0,1,3,2],[2,4,12,3,4,3],[0,5,11,7,12,0],[8,9,10,9,13,12],[11,13,9,15,16,11],[0,7,8,0,15,0]
  vector<vector<int> > v;

  for (int row_i = 0; row_i < 5; ++ row_i) {
    vector<int>row;
    for (int col_i = 0; col_i < 4; ++ col_i) {
      row.push_back(A[row_i][col_i]);
    }
    v.push_back(row);
  }

  Solution s;
  vector<int> res = s.findPeakII(v);
  if (res.size() < 2) {
    cout << "error" << endl;
  } else {
    cout << "res[0]" << res[0] << endl;
    cout << "res[1]" << res[1] << endl;
  }

	cout <<"hello world findPeakTwo" <<endl;
  cout << "main_04" << endl;
  cout << "main_1" << endl;
}
