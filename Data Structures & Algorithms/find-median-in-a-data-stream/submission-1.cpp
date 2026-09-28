class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> rminh;
    priority_queue<int> lmaxh;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lmaxh.empty() || lmaxh.top() > num){
            lmaxh.push(num);
        }
        else{
            rminh.push(num);
        }
        if(lmaxh.size() > rminh.size() + 1){
            rminh.push(lmaxh.top());
            lmaxh.pop();
        }
        if(rminh.size() > lmaxh.size()){
            lmaxh.push(rminh.top());
            rminh.pop();
        }
    }
    
    double findMedian() {
        if(lmaxh.size() > rminh.size()){
            return lmaxh.top();
        }
        return (lmaxh.top() + rminh.top()) / 2.0;
    }
};
