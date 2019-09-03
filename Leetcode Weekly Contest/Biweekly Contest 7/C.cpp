
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int>que;
        for(int i=0;i<sticks.size();i++) que.push(-sticks[i]);
        int ans = 0;
        while(!que.empty()) {
            int tmp =0 ;
            tmp += que.top();que.pop();
            if(!que.empty()) {
                tmp += que.top();que.pop();
            }
            else break;
            ans += tmp;
            que.push(tmp);
        }
        return -ans;
    }
};