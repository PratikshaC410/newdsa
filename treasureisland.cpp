#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<char>>v;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        vector<char>temp;
        for(int j=0;j<m;j++)
        {
            char x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0},0});
    bool vis[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            vis[i][j] = false;
    }
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,1,0,-1};
    int ans = -1;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        if(vis[x][y])
            continue;
        if(v[x][y] == 'X')
        {
            ans = cost;
            break;
        }
        vis[x][y] = true;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m)
            {
                if(v[x][y]!='D')
                    q.push({{x+dx[i],y+dy[i]},cost+1});
            }
        }
    }
    if(ans == -1)
        cout<<"Not Possible to reach destination";
    else    
        cout<<ans;
}