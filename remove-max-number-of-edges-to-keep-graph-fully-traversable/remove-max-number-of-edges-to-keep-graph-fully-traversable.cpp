class Solution {
public:

    int alice[100001];
    int bob[100001];
  
int finda(int a){
	if(alice[a]==-1)
	return a;
	return alice[a]=finda(alice[a]);
}
    int findb(int a){
	if(bob[a]==-1)
	return a;
	return bob[a]=findb(bob[a]);
}
void mergea (int a,int b){
	alice[a]=b;
}
    void mergeb (int a,int b){
	bob[a]=b;
}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for(int i=0;i<100001;i++){
	alice[i]=-1;
            bob[i]=-1;
}   
     int t3=0;//essential edges for both 
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                if(finda(edges[i][1])!=finda(edges[i][2])){
                   mergea(finda(edges[i][1]),finda(edges[i][2]));
                   mergeb(findb(edges[i][1]),findb(edges[i][2]));
                    t3++;
                }
            }
        }
        int t1=0; // essential edges for alice
         for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                if(finda(edges[i][1])!=finda(edges[i][2])){
                    mergea(finda(edges[i][1]),finda(edges[i][2]));
                    
                    t1++;
                   
                }
            }
        }
        int t2=0; //essential edges for bob
         for(int i=0;i<edges.size();i++){
            if(edges[i][0]==2){
                if(findb(edges[i][1])!=findb(edges[i][2])){
                    mergeb(findb(edges[i][1]),findb(edges[i][2]));
                    
                    t2++;
                }
            }
        }
   if(t1+t3<n-1||t3+t2<n-1)// if(t1+t3<n-1) then alice can not traverse the graph because tree requires n-1 edges to be spanned completely if(t2+t3<n-1)then bob can not traverse.
       return -1;
        
        cout<<t1<<" "<<t2<<" "<<t3<<endl;
      return edges.size()-t1-t2-t3;  //(t1+t2+t3) are essential edges
    }
};
