bool cmp_less(const pair<int, int>  &p1, const pair<int, int> & p2) {
  return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second;    
}
class Solution {
public:
    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &intervals, int rooms, vector<vector<int>> &asks) {
      // Write your code here.
      vector<pair<int, int> > events;
      
      for (vector<int> interval: intervals) {
        events.push_back(make_pair(interval[0], 2));
        events.push_back(make_pair(interval[1], 1));
      }
      
      int ask_i = 0;
      for (vector<int> ask: asks) {
        ask_i ++;
        events.push_back(make_pair(ask[0], 3 + ask_i));
        events.push_back(make_pair(ask[1], 0 - ask_i));
      }
      
      sort(events.begin(), events.end(), cmp_less);
      
      // 0 init, 1 inside, 3 true 4 false
      vector<int> res(asks.size() + 1, 0);
      unordered_set <int> one_set;
      int cnt = 0;
      for (pair<int, int> event:events) {
        if (event.second > 3) { 
          int ask_i = event.second - 3;
          res[ask_i] = 1;
          one_set.insert(ask_i);
          if (cnt >= rooms) {
            for (auto ask_i: one_set) {
              res[ask_i] = 4;
            }
            one_set.clear();
          }
        } else if (event.second == 2) {
          ++ cnt;   
          if (cnt >= rooms) {
            for (auto ask_i: one_set) {
              res[ask_i] = 4;
            }
            one_set.clear();
          }
        } else if (event.second == 1){
          -- cnt; 
        } else {
          int ask_i = 0 -  event.second;
          if (res[ask_i] != 4) {
            res[ask_i] = 3;
            one_set.erase(ask_i);
          }
        }
      }
      
      vector<bool> res_flags; 
      for (int ask_i = 1; ask_i <= asks.size(); ++ ask_i) {
        bool flag = res[ask_i] == 3 ? true: false;
        res_flags.push_back(flag);
      }
      
      return res_flags;
    }
};
