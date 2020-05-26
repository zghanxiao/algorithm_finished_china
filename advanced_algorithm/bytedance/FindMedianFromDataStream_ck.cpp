class MedianFinder {
public:
    /** initialize your data structure here. */
  
    priority_queue<int, vector<int>, greater<int> > min_h;
    priority_queue<int, vector<int>> max_h;
  
    MedianFinder() {
      while(!max_h.empty()){
        max_h.pop();
      }   
      while(!min_h.empty()) {
        min_h.pop();
      }
    }
    
    // maitain min_h.size() == max_h.size() || min_h.size() + 1 == max_h.size()
    //solution's three insertion and 2 pop is not good
    // my version is two push and one pop at most
    void addNum(int num) {
      
      if (min_h.size() == max_h.size()) {
        if (!min_h.empty() && num > min_h.top()) {
          min_h.push(num);
          num = min_h.top();
          min_h.pop();
        }
        max_h.push(num);
      } else {
        if (num < max_h.top()) {
          max_h.push(num);
          num = max_h.top();
          max_h.pop();
        }
        min_h.push(num);
      } 
    }
    
    double findMedian() {
      if (max_h.size() == 0) {
        return 0.0;
      }
      
      if (max_h.size() > min_h.size()) {
        return (double)(max_h.top());
      } else {
        return ((double)(max_h.top()) + (double)(min_h.top())) / 2.0;
      }    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
