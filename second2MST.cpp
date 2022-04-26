#include <bits/stdc++.h>
using namespace std;

int mst = 0, mst2 = INT_MAX;
vector<bool> taken;

struct DSU{
    vector<int> parent, size;
    
    void assign(int n) 
    {
        parent = vector<int>(n);
        size = vector<int>(n);
        for(int i = 0; i < n; i++)    make_set(i);
    }
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v)
    {
        if(v == parent[v])  return v;
        return parent[v] = find_set(parent[v]);
        // returns the parent of the set
    }
    bool union_set(int a1, int b1){
        int a = find_set(a1), b = find_set(b1);
        if(a != b){
            if(size[a] < size[b])   swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            // dsu_size[b] = 1;
            return 1;
        }
        else{
            // cycle exists
            return 0;
        }
    }
}dsu;

int main() {

    int n, m;
    cout << "\nEnter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;

    vector<array<int, 4>> edges(m);
    // {weight of edge, vertex1, vertex2, indexing}

    cout << "\nEnter the edges description : \n";
    for (int i = 0; i < m; i++) {
        // {vertex1, vertex2, weight of the edge}
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        --edges[i][1], --edges[i][2], edges[i][3] = i;
    }
    sort(edges.begin(), edges.end());

    taken = vector<bool>(m);

    // finding mst
    dsu.assign(n);
    for(int i = 0; i < m; i++) 
    {
        if (dsu.union_set(edges[i][1], edges[i][2]) == 0)  continue;

        taken[edges[i][3]] = 1;
        mst += edges[i][0];
    }

    for(int i = 0; i < m; i++) 
    {
        if (taken[i] == 0)   continue;
        // exclude current edge which is part of the mst

        dsu.assign(n);
        int cur = 0, cnt = 0;
        for (int j = 0; j < m; j++) {
            if (i == j || taken[j] == 0)  continue;

            cur += edges[j][0];
        }
        
        int nww = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (taken[j] || dsu.find_set(edges[j][2]) == dsu.find_set(edges[j][1]) || edges[j][0] == edges[i][0])  continue;            

            nww = min(nww, edges[j][0]);
        }

        if (nww == INT_MAX)  continue;
        
        cur += nww;
        if (cur == mst)  
            continue;
        mst2 = min(mst2, cur);
    }
    // time complx : O(E.V)
    // space complx : O(E)

    cout << "\nMST : " << mst << '\n';
    if (mst2 == INT_MAX)  
        cout << "Second best mst does not exist.\n";
    else    
        cout << "Second best MST : " << mst2 << "\n\n";

    return 0;
}