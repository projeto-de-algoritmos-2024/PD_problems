/**
 * Bellman Ford
 *
 * Given a weighted and directed graph of v vertices and edges, Find the shortest distance of
 * all the vertex's from the source vertex, src and return a list of integers where the ith
 * integer denotes the distance of the ith node from the source node. If a vertices can't be
 * reach from the s then mark the distance as 10^8.
 *
 * Note: If there exist a path to a negative weighted cycle from the source node then return
 * {-1}.
 *
 * Difficulty Level: Medium
 * https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (unsigned int i = 0; i < V; i++)
        {
            for (vector<int> edge : edges)
            {
                int from = edge[0];
                int to = edge[1];
                int weight = edge[2];

                if (dist[from] != 1e8 && dist[from] + weight < dist[to])
                {
                    if (i == V - 1)
                        return {-1}; // negative cycle detected
                    
                    dist[to] = dist[from] + weight;
                }
            }
        }
        return dist;
    }
};