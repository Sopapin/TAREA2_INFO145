#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 500;
void crear_grafo_no_dirigido_peso(vector<vector<pair<int, int>>> &g, int N)//Se crea el grafo con los caminos indicados
{
    for (int i = 0; i < N; ++i)   //O(N)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}
vector<int> dijkstra(vector<vector<pair<int, int>>> &g, int inicio)//Busca el camino más corto
{
    vector<int> dist(g.size(), 1e9);//1e9 es como infinito, un número muy grande
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, inicio});
    dist[inicio] = 0;
    while (!q.empty()) //O(N)  (N cantidad de carreteras)
    {
        int priority = q.top().first, u = q.top().second; 
        q.pop();                              //O(log N)
        if (priority != dist[u])   
            continue;
        for (pair<int, int> p : g[u])   //O(|E|log N)    (E = Cantidad de adyacentes del nodo)
        {
            int v = p.first, m = p.second;
            if (dist[u] + m < dist[v])
            {
                dist[v] = dist[u] + m;
                q.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, c, q, l;
    cin >> N;
    vector<vector<pair<int, int>>> grafo_peso(MAX_N+1);
    crear_grafo_no_dirigido_peso(grafo_peso, N);     //O(N)
    cin >> c;   
    vector<int> resultado = dijkstra(grafo_peso, c);//O(N log N + |E|log N)
    cin >> q;
    for (int i = 0; i < q; ++i)  //O(q)  Siendo q el número de ubicaciones diferentes  //Se buscan los caminos más cortos hacia las distintas ubicaciones de q
    {
        cin >> l;
        cout << ((resultado[l] != 1e9) ? resultado[l] : -1) << endl; //Explicado en el informe
    }
    cout << endl;

    return 0;
}