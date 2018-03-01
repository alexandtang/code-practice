
/*
*  @https://www.hackerrank.com/challenges/dijkstrashortreach
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int > pi;

int main() {
    // Unbind 
    std::ios::sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--){
        int N,M;
        cin >> N >> M;
        map<int ,int> nodes[N+1];
        // read the edges
        for(int i=0;i<M;++i){
            int e1,e2,d;
            cin >> e1 >> e2 >> d;
            if(nodes[e1].count(e2)==0 || nodes[e1][e2]>d){
                nodes[e1][e2] = d;
                nodes[e2][e1] = d;            
            }
        }
        int S;
        cin >> S;
        bool vis[N+1];
        int dis[N+1];
        memset(vis,false,sizeof(vis));
        for(int i=0;i<=N;++i){
            dis[i]=100000;
        }
        dis[S] = 0;
        // Use min heap so that the min value can be popped earlier 
        priority_queue<pi, vector<pi>, greater<pi> > q;
        q.push(pi(0,S));
        while(!q.empty()){
            int curr = q.top().second;
            int curr_cost = q.top().first;
            q.pop();
            if(dis[curr]<curr_cost) continue;
            if(vis[curr]) continue;
            vis[curr] = true;
            for(auto &m: nodes[curr]){                
                int fir = m.first;
                int sec = m.second;   
                if(!vis[fir] && dis[curr] + sec < dis[fir]){
                   dis[fir] = dis[curr]+sec; 
                   q.push(pi(dis[fir],fir));
               }      
               
            }
            
        }
        for(int i=1;i<=N;++i){
            if(i!=S){
                if(dis[i]==100000)
                    cout << "-1 ";
                else
                    cout << dis[i] << " ";
            }                
        }
        cout << endl;
         
    }
    return 0;
}
