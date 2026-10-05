class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = 0;
        int c = 0;
        for(int i=0; i<gas.size(); i++){
            g+=gas[i];
            c+=cost[i];
        }
        if(g < c){
            return -1;
        }
        int ind = 0;
        int sum = 0;

        for(int i=0; i<gas.size(); i++){
            sum = sum + gas[i] - cost[i];

            if(sum < 0){
                ind = i+1;
                sum = 0;
            }
        }
        return ind;
    }
};
