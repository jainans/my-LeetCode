class FrontMiddleBackQueue {
public:
    deque<int>dq1;
    deque<int>dq2;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        if(dq1.size()==dq2.size())
            dq1.push_front(val);
        else
        {
            int p = dq1.back();
            dq1.pop_back();
            dq2.push_front(p);
            dq1.push_front(val);
        }
    }
    
    void pushMiddle(int val) {
        if(dq1.size()!=dq2.size())
        {
             int p = dq1.back();
            dq1.pop_back();
            dq2.push_front(p);
        }
        dq1.push_back(val);
    }
    
    void pushBack(int val) {
        dq2.push_back(val);
        if(dq1.size()!=dq2.size())
        {
             int p = dq2.front();
            dq2.pop_front();
            dq1.push_back(p);
        }
        
    }
    
    int popFront() {
        if(dq1.empty())
            return -1;
        int p = dq1.front();
        dq1.pop_front();
        if(dq1.size()!=dq2.size()){
            int q = dq2.front();
            dq2.pop_front();
            dq1.push_back(q);
        }
        return p;
    }
    
    int popMiddle() {
        if(dq1.empty())
            return -1;
        int p = dq1.back();
        dq1.pop_back();
        if(dq1.size()!=dq2.size())
        {
            int q = dq2.front();
            dq2.pop_front();
            dq1.push_back(q);
        }
        return p;
    }
    
    int popBack() {
        if(dq1.empty())
            return -1;
        if(dq2.empty())
        {
            int p = dq1.front();
            dq1.pop_back();
            return p;
        }
        int p = dq2.back();
        dq2.pop_back();
        if(dq1.size()>dq2.size()+1){
            int y= dq1.back();
            dq1.pop_back();
            dq2.push_front(y);
        }
        return p;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */