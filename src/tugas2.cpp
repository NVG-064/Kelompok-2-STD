#include <bits/stdc++.h>
using namespace std;

#define N 7
#define UND INT_MAX

#define M 6 // (maximum_vertex_value) - 1

// history count
int dataHistory[M] = {};

// Returns longest distance from 0 to N-1.
int longestDistaceByForward(int graph[N][N]) {

	// cost[i] is going to store longest distance from node i to node N-1.
	int cost[N];

	cost[N-1] = 0;

	// Calculating longest path for rest of the nodes
	for (int i = N-2 ; i >= 0 ; i--)
	{

		// Initialize distance from i to destination (N-1)
		cost[i] = 0;

		// Check all nodes of next stages to find longest distance from i to N-1.
		for (int j = i ; j < N ; j++)
		{
			// Reject if no edge exists
			if (graph[i][j] == UND)
				continue;

			// We apply recursive equation to distance to target through j. and compare with minimum distance so far.
			cost[i] = max(cost[i], graph[i][j] + cost[j]);
            dataHistory[i] = cost[i]; // To save the history
		}
	}

	return cost[0];
}

// Driver code
int main()
{
	// Graph stored in the form of an adjacency Matrix
	int graph[N][N] =
	{{UND, 8, 15, UND, UND, UND, UND},
	{UND, UND, 10, 21, 25, UND, UND},
	{UND, UND, UND, 20, UND, 25, UND},
	{UND, UND, UND, UND, 9, 10, 50},
	{UND, UND, UND, UND, UND, UND, 21},
	{UND, UND, UND, UND, UND, UND, 30},
	{UND, UND, UND, UND, UND, UND, UND}};

    system("cls");
    cout << "\t\tJarak Terjauh menggunakan Metode Forward";
    cout << "\n\t\t\t     Oleh Kelompok 2\n\n";
	cout << "Jarak terjauh: " << longestDistaceByForward(graph);

    cout << "\n\n";
    for (int x = M-1; x >= 0; x--){
        cout << "Hasil perhitungan cost ke-" << x+1 << ": " << dataHistory[x] << endl;
    }
	return 0;
}
