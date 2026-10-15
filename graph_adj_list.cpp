#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<int> adj[20];
    int n;

public:

    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        int edges;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);   // Remove this line for directed graph
        }
    }

    void displayList()
    {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";

            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    void BFS(int start)
    {
        bool visited[20] = {false};

        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int i = 0; i < adj[current].size(); i++)
            {
                int vertex = adj[current][i];

                if (!visited[vertex])
                {
                    visited[vertex] = true;
                    q.push(vertex);
                }
            }
        }
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
        cout << "\n2. Display Graph (Adjacency List)";
        cout << "\n3. BFS Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayList();
            break;

        case 3:
            cout << "\nEnter starting vertex: ";
            cin >> start;

            g.BFS(start);
            break;

        case 4:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}
