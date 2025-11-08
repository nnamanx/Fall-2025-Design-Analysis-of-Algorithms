#include <stdio.h>   
#include <string.h>  

#define MAX 110  // Maximum number of vertices
#define INF 0x3F3F3F3F       
#define MIN(a,b) ((a) < (b) ? (a) : (b))  

int main(void) {

    int i, j, w = 0, mind;   
    int n, s, f;              
    int m[MAX][MAX];           // Adjacency matrix for graph
    int used[MAX];             // Marks whether a vertex is finalized (1 = yes, 0 = no)
    int d[MAX];                // Shortest distances from start to each vertex

    if (scanf("%d %d %d", &n, &s, &f) != 3) {
        return 0; // Exit if input is invalid
    }

    // Read adjacency matrix
    // Each value m[i][j] represents cost from vertex i to vertex j
    // If m[i][j] == -1, there is no direct edge
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (scanf("%d", &m[i][j]) != 1)
                return 0;  // Exit on invalid input
            if (m[i][j] == -1)
                m[i][j] = INF;  // Replace -1 with infinity
        }
    }

    memset(used, 0, sizeof(used));   // Initially, no vertex is finalized
    memset(d, 0x3F, sizeof(d));      // Fill distance array with "infinity" (0x3F3F3F3F)
    
    d[s] = 0;                        // Distance to start vertex is zero

    // Dijkstra: This loop runs n-1 times to find shortest paths
    for (i = 1; i < n; i++) {
        
        mind = INF;  // Start with "infinite" minimum
        w = -1;      // w will store index of vertex with smallest distance

        // Step 1: Find the unused vertex with the smallest distance
        for (j = 1; j <= n; j++) {
            
            if (!used[j] && d[j] < mind) {
                
                mind = d[j];
                w = j;
            }
        }

        // If no vertex was found (disconnected graph), stop
        if (w == -1 || mind == INF)
            break;

        // Step 2: Mark this vertex as used
        used[w] = 1;

        // Step 3: Relax distances for all neighbors of w
        for (j = 1; j <= n; j++) {
            
            // Only update if vertex j is unused, and both current and edge distances are valid
            if (!used[j] && d[w] != INF && m[w][j] != INF) {
                
                int nd = d[w] + m[w][j];  // New possible distance via vertex w
                d[j] = MIN(d[j], nd);     // Keep the smaller one
            }
        }
    }

    // If distance to finish vertex is still INF, it means unreachable
    if (d[f] == INF) d[f] = -1;

    printf("%d\n", d[f]);

    return 0; 
}
