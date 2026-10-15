#include <iostream>
using namespace std;

class Graph
{
    int adj[20][20];
    int n;//number of vertices

    // Structure for storing edges
    struct Edge
    {
        int u, v, weight;
    };

    Edge edges[50];
    int edgeCount = 0;

public:

    // Create graph
    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        // Initialize adjacency matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }

        cout << "Enter number of edges: ";
        cin >> edgeCount;

        cout << "Enter edges (source destination weight):\n";

        for (int i = 0; i < edgeCount; i++)
        {
            int u, v, w;

            cin >> u >> v >> w;

            edges[i].u = u;
            edges[i].v = v;
            edges[i].weight = w;

            adj[u][v] = w;
            adj[v][u] = w;   // Undirected graph
        }
    }

    // Display adjacency matrix
    void displayMatrix()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }


    // Kruskal's Algorithm
    void kruskal()
    {
        // Bubble Sort edges according to weight
        for (int i = 0; i < edgeCount - 1; i++)
        {
            for (int j = 0; j < edgeCount - i - 1; j++)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        int parent[20];

        // Initially every vertex is its own parent
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int total = 0;
        int count = 0;

        cout << "\nMinimum Spanning Tree using Kruskal:\n";

        for (int i = 0; i < edgeCount; i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;

            // Check whether edge creates a cycle
            if (parent[u] != parent[v])
            {
                cout << u << " - " << v
                     << " : " << edges[i].weight << endl;

                total = total + edges[i].weight;
                count++;

                // Merge the two sets
                int oldParent = parent[v];
                int newParent = parent[u];

                for (int j = 0; j < n; j++)
                {
                    if (parent[j] == oldParent)
                    {
                        parent[j] = newParent;
                    }
                }

                // MST has n-1 edges
                if (count == n - 1)
                {
                    break;
                }
            }
        }

        cout << "Total weight of MST = " << total << endl;
    }
};


int main()
{
    Graph g;

    int choice, start;

    do
    {
        cout << "\n===== Graph Menu =====";
        cout << "\n1. Create a Graph";
        cout << "\n2. Display Graph (Adjacency Matrix)";
        cout << "\n3. Kruskal's Minimum Spanning Tree";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayMatrix();
            break;

        case 3:

            g.kruskal();
            break;

        case 5:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}
