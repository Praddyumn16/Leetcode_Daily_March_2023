class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 0 , high = INT_MAX;

        while(low <= high) {
            double mid = (low + high) / 2.0;
            if(!mid) break;
            long long curr = 0; 
            for(auto a : piles)
                curr += ceil(a / mid);
            if(curr <= h) 
                high = mid - 1;
            else
                low = mid + 1;
        }

        return (!low ? 1 : low);
    }
};