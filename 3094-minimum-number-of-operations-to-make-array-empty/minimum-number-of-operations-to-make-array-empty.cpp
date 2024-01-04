class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        map<int,int>mp;
        for(int i=0;i<sz;i++){
            mp[nums[i]]++;
        }
        for(auto p:mp){
            cout<<p.first<<"->"<<p.second<<endl;
            if(p.second == 1){
                return -1;
            }
        }
        int cnt = 0;
        while(!mp.empty()){
            for(auto i = mp.begin();i!=mp.end();i++){
                if((i -> second)%3 == 0){
                    cnt = cnt+(i -> second)/3;
                    mp.erase(i);
                }
                else if((i -> second)%2 == 0){
                    if((i->second)%3 == 1){
                        cnt = cnt + (i->second - 4)/3 + 2;
                        mp.erase(i);
                    }
                    else if((i->second)%3 == 2){
                        cnt = cnt + (i->second - 2)/3 + 1;
                        mp.erase(i);
                    }
                }
                else{
                    if((i -> second)%3 == 1){
                        cnt = cnt + (((i -> second) - 4 )/3) + 2;
                        mp.erase(i);
                    }
                    else if((i -> second)%3 == 2){
                        cnt = cnt + ((i -> second)-2)/3 + 1;
                        mp.erase(i);
                    }
                }
                
                
            }
        }
        return cnt;
    }
};