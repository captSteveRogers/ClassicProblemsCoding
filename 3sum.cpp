class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res{};
        vector<int> v{};
        if(nums.size()==0)
            return res;
        sort(nums.begin(), nums.end());
        for(auto i=nums.begin(); i!=nums.end(); i++){
            auto j=i+1;
            auto k=nums.end()-1;
            
            if(i>nums.begin() && *i==*(i-1))
                continue;
            
            while(j<k){
                if(k<nums.end()-1 && *k==*(k+1)){
                    k--;
                    continue;
                }
                
                if(*i + *j + *k > 0)
                    k--;
                else if(*i + *j + *k < 0)
                    j++;
                else{
                    v.push_back(*i);
                    v.push_back(*j);
                    v.push_back(*k);
                    res.push_back(v);
                    v.clear();
                    j++;
                    k--;
                }
            }
        } 
        return res;
    }
};