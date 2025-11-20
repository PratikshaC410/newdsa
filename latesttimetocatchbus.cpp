class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& pass, int capacity) {
        sort(buses.begin(), buses.end());
        sort(pass.begin(), pass.end());
        int ans = 1;
        int prevPass=-1;
        int i= 0;
        for(int busTime : buses){
            int seats = capacity;
            while(seats != 0 && i< pass.size() && pass[i] <= busTime){
                if(prevPass != pass[i]-1){
                    ans = max(ans, pass[i]-1);
                }
                seats--;
                prevPass = pass[i];
                i++;
            }
            if(seats > 0 && prevPass != busTime) ans = max(ans, busTime);
        }
        return ans;
    }
};