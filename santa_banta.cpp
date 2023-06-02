/*
Santa is still not married. He approaches a marriage bureau and asks them to hurry the process. The bureau checks the list of eligible girls of size N and hands it over to Santa. Santa being conscious about his marriage is determined to find a girl with maximum connections so that he can gather more information about her. Accordingly, he looks to figure out the maximum number of girls (from the list) who know each other to achieve the above purpose.

In order to finalize the girl, he needs to find the Kth prime. Where k = largest group of girls who know each other. Considering Santa's poor knowledge of Maths, he seeks Banta's help for the answer. Now you, a fan of Santa Banta Jokes, take this prestigious opportunity to solve the problem.

In case no of connections is zero, print "-1". Here the connection between girls is represented by a 2-D array g of dimension M*2, where M is the number of connections.
*/
vector<int> p;
    void precompute(){
        vector<int> v(2000001,1);
        for(int i=2;i<=2000000;i++){
            if(v[i]){
                for(int j=2*i;j<=2000000;j+=i) v[j]=0;
                p.push_back(i);
            }
        }
    }
    int dfs(int s,vector<vector<int>>&adj,vector<int>&vis){
        vis[s]=1;
        int ans(1);
        int x(0);
        for(auto&it:adj[s]){
            if(vis[it]) continue;
            x+=dfs(it,adj,vis);
        }
        return ans+x;
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
    
        int mx=0;
        vector<int> vis(n+1);
        for(int i=1;i<=n;i++)
            if(!vis[i]) 
               mx=max(mx,dfs(i,g,vis));
        
        if(mx==1) return -1;
    
        return p[mx-1];
    }