class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>small;
    priority_queue<int, vector<int>, greater<int> >large;
    int cnt;
    MedianFinder() {
        cnt=0;
      
    }
    
    void addNum(int num) {
        if(cnt%2==0){
            small.push(num);
            if(!large.empty() && large.top()<small.top()){
                int p =  large.top();
                large.pop();
                int q = small.top();
                small.pop();
                large.push(q);
                small.push(p);
            }
        }
        else{
            large.push(num);
            if(!small.empty() && small.top()>large.top()){
                 int p =  large.top();
                large.pop();
                int q = small.top();
                small.pop();
                large.push(q);
                small.push(p);
            }
        }
        cnt++;
    }
    
    double findMedian() {
        if(cnt%2==0){
            int p = small.top();
            int q = large.top();
            double d = (p+q)*1.0/2;
            return d;
        }
        return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */