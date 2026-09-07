// Disjoint Set Implementation
// https://www.youtube.com/watch?v=aBxjDBC4M1U

#include<bits/stdc++.h>
using namespace std;

 class DisjointSet{
    public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);   // vector with (n+1) size works for both 0 & 1-based indexeing, only difference is <n (For 0) and <=n (For 1)
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if(node == parent[node])
        return node;
        return parent[node] = findUPar(parent[node]);  // path compression step i.e. updating parent[node] to ultimate parent via backtracking
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v= findUPar(v);
        if(ulp_u == ulp_v)  // same parent, no need to do anything
            return;
        // always connect smaller rank tree under larger rank tree 
        if(rank[ulp_u] < rank[ulp_v])
          parent[ulp_u] = ulp_v;
          // NO NEED OF SEPARATE CONDITION FOR EQUAL RANKS, AS WE CAN CONNECT ANY ONE UNDER OTHER AND INCREASE THE RANK OF THAT PARENT BY 1
        else if(rank[ulp_v] < rank[ulp_u])
          parent[ulp_v] = ulp_u;
          // if ranks are same then connect any one under other and increase the rank of that parent by 1
        else{
            parent[ulp_v] = ulp_u;   // OR parent[ulp_u] = ulp_v;
            rank[ulp_u]++;           // rank[ulp_v]++;
        }       
    }

    void unionBySize(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v= findUPar(v);
        if(ulp_u == ulp_v)
        return;

        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]++;
        }
    }
 };

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);    
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3) == ds.findUPar(7))
    cout << "Same\n";
    else
    cout << "Not Same\n";
    ds.unionByRank(3,7);    
    if(ds.findUPar(3) == ds.findUPar(7))
    cout << "Same\n";
    else
    cout << "Not Same\n";
    return 0;
}
