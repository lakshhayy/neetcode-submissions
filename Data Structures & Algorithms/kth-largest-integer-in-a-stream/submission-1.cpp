class KthLargest {
public: 
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;

    KthLargest(int k, vector<int>& nums) {
        x=k;

        for(int num : nums) {
            pq.push(num);

            if(pq.size() > x) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > x){
            pq.pop();
        }

        return pq.top();
    }
};
