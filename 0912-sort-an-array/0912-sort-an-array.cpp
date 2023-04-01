class Solution {
public:
    void merge(vector<int>& nums, int left , int mid , int right) {
        int i = left , j = mid + 1;
        vector<int> temp;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) 
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i <= mid)
            temp.push_back(nums[i++]);
        while(j <= right)
            temp.push_back(nums[j++]);

        for(int i = left ; i <= right ; i++)
            nums[i] = temp[i - left];
    }

    void mergeSort(vector<int>& nums , int left , int right) {
        if(left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(nums , left , mid);
        mergeSort(nums , mid + 1 , right);
        merge(nums , left , mid , right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size() - 1);
        return nums;
    }
};