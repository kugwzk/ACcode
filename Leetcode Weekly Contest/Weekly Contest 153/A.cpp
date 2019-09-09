class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0, need = 0;
        if(start>destination)
            swap(start, destination);
        for(int i=0;i<distance.size();i++) {
            sum+=distance[i];
            if(i>=start&&i<destination) need+=distance[i];
        }
        cout<<need<<" "<<sum<<endl;
        return min(need, sum-need);
    }
};