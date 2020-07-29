class Solution {
public:
    string replaceSpace(string s) {
        string out;
        for(auto i : s){
            if(i == ' ')
            {
                out+="%20";
            }
            else{
                out+=i;
            }
        }
        return out;
    }
};