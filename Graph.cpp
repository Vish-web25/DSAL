#include <iostream>
using namespace std;

class Graph
{
    int adj[20][20];
    int n;
    bool visited[20] = {false};

public:
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

        int edges;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;   // Remove this line for directed graph
        }
    }

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



    void DFS(int start)
    {

        visited[start] = true;

        cout << start << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[start][i] == 1 && !visited[i])
            {
                DFS(i);
            }
        }
    }

};

int main()
{
    Graph g;
   int choice,start;
   do
    {
        cout << "\n===== Binary Tree Menu =====";
        cout << "\n1. Create a Graph";
        cout << "\n2. Display Graph:";
        cout << "\n3. DFS traversal";
        cout << "\n4. Exit";
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
               cout << "\nEnter starting vertex: ";
              cin >> start;
              g.DFS(start);
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
