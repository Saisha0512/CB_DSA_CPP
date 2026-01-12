# include <iostream>
# include <vector>
# include <climits>
# include <set>
typedef long long ll;
using namespace std;

vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &graph, ll n, ll src){
    // Vector to store distances : 
    vector<ll> dist(n, LLONG_MAX);
    set<pair<ll, ll>> s; // {Dist, Node}
    dist[src] = 0;
    s.insert({0, src});

    while (!s.empty()){
        // Take out the node with the minimum distance (whose nbrs are left to be visited) : 
        auto curr = *(s.begin());
        s.erase(s.begin());

        ll node = curr.second, path = curr.first;
        for (auto &p : graph[node]){
            // Neighbour : 
            ll dest = p.first, wt = p.second;

            if (path + wt < dist[dest]){
                // Erase the old pair from the set : 
                auto it = s.find({dist[dest], dest});
                if (it != s.end()){}

                // Update the values of the dest node & insert it in the set again : 
                dist[dest] = path + wt;
                s.insert({dist[dest], dest});
            }
        }
    }

    return dist;
}

int main(){
    ll n, m, src;
    cin >> n >> m >> src;
    vector<vector<pair<ll, ll>>> graph(n);

    while (m --){
        ll x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }

    vector<ll> dist = dijkstra(graph, n, src);
    for (ll i = 0; i < n; i ++){
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}