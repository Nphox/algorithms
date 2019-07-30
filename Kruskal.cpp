#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

double weight_edge(pair<int, int> p1, pair<int, int> p2){
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int count_vertices;
    cout << "count_vertices: "; cin >> count_vertices;
    int x, y;


    vector<pair<int, int>> vertices;
    for(int i = 0; i < count_vertices; i++){
        cout << "input x, y: "; cin >> x; cin >> y;
        vertices.push_back(make_pair(x, y));
    }


    int count_edges = (count_vertices * count_vertices - count_vertices) / 2;
    vector<pair<double, pair<int, int>>> edges(count_edges);
    int index = 0;
    for(int i = 0; i < count_vertices; i++){
        for(int j = i + 1; j < count_vertices; j++){
            edges[index].first = weight_edge(vertices[i], vertices[j]);
            edges[index].second = make_pair(i, j);
            index++;
        }
    }
    sort(edges.begin(), edges.end());


    vector<int> tree_id(count_vertices);
    for (int i = 0; i < count_vertices; ++i){
        tree_id[i] = i;
    }


    double cost = 0;
    for (int i = 0; i < count_edges; ++i){
        int index_v1 = edges[i].second.first;
        int index_v2 = edges[i].second.second;
        double weight = edges[i].first;

        if (tree_id[index_v1] != tree_id[index_v2]){
            cost += weight;
            int old_id = tree_id[index_v2],  new_id = tree_id[index_v1];
            for (int j = 0; j < count_vertices; ++j){
                if (tree_id[j] == old_id){
                    tree_id[j] = new_id;
                }
            }
        }
    }


    printf("%.*f", 2, cost);
}