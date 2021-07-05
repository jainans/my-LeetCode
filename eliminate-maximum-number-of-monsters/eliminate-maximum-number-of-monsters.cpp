class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for(int i=0; i<dist.size(); i++){
            if(dist[i]%speed[i])
                dist[i] = dist[i]/speed[i];
            else
                dist[i] = (dist[i]/speed[i])-1;     
        }
        sort(dist.begin(), dist.end());
        int nas=0;
        int t=0;
        for(int i=0; i<dist.size(); i++){
            if(dist[i]>=t){
                nas++;
                t++;
            }
            else
                break;
        }
        return nas;
    }
};