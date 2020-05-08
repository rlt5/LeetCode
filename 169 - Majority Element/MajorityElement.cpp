class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for ( int num : nums ){
            umap[num] = 0;
        }
        for ( int num : nums ){
            umap[num]++;
        }
        int majority = nums.size()/2;
        for ( auto num : umap){
            if ( num.second > majority ){
                return num.first;
            }
        }
        return 0;
    }
};