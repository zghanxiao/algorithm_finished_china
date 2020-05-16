/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool cmp(const Interval & int1, const Interval & int2) {
  return int1.start < int2.start || int1.start == int2.start && int1.end < int2.end;
}
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        int size = intervals.size();
        if (size == 0) {
          return true;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int pre_end = -1;
        for (Interval interval: intervals) {
          int start = interval.start;        
          int end = interval.end;        
          if (pre_end > start) {
            return false;  
          }
          pre_end = end;
        }
        return true;
    }
};
