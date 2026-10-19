#include <iostream>
using namespace std;

#define INF 999999
#define V 5

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[V] = {0};
    selected[0] = 1;

    int edges = 0, total = 0;

    cout << "Edge\tWeight\n";

    while (edges < V - 1) {
        int min = INF, x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << "\t" << graph[x][y] << endl;

        total += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    cout << "Total Minimum Cost: " << total;

    return 0;
}

