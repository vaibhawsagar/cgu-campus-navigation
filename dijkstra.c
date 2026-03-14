#include <stdio.h>
#include <limits.h>

#define V 20

// Location names
char locations[V][100] = {
"CGU Front Gate",
"Diploma Department",
"CV Raman Department of MBA",
"Cricket Ground",
"DSW Playground",
"CV Raman Swimming Pool",
"Medical Dispensary",
"Boys Canteen",
"Girls Canteen",
"CV Raman Basketball Court",
"RIHC Auditorium",
"CV Raman Central Library",
"CSE Block",
"Mechanical Department",
"ETC Building",
"Admission Cell",
"Bosch Rexroth Center of Excellence",
"CGU Volleyball Court",
"CSE Fountain",
"CV Raman Global University Backgate"
};

// Show all campus locations
void showLocations()
{
    printf("\n===== CAMPUS LOCATIONS =====\n\n");

    for(int i = 0; i < V; i++)
    {
        printf("%2d -> %s\n", i, locations[i]);
    }

    printf("\n");
}


// Find minimum distance node
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index;

    for(int v = 0; v < V; v++)
    {
        if(!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j)
{
    if(parent[j] == -1)
    {
        printf("%s\n", locations[j]);
        return;
    }

    printPath(parent, parent[j]);
    printf("   |\n");
    printf("   v\n");
    printf("%s\n", locations[j]);
}

// Dijkstra algorithm
void dijkstra(int graph[V][V], int src, int dest)
{
    int dist[V];
    int visited[V];
    int parent[V];

    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for(int v = 0; v < V; v++)
        {
            if(!visited[v] && graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\n===== SHORTEST ROUTE =====\n\n");

    printf("Distance : %d meters\n\n", dist[dest]);

    printf("Path : ");
    printPath(parent, dest);
    printf("\n\n");
}



int main()
{
//      0  CGU Front Gate
//      1  Diploma Department
//      2  CV Raman Department of MBA
//       3  Cricket Ground
//       4  DSW Playground
//      5  CV Raman Swimming Pool
//      6  Medical Dispensary
//      7  Boys Canteen
//      8  Girls Canteen
//      9  CV Raman Basketball Court
//      10 RIHC Auditorium
//      11 CV Raman Central Library
//      12 CSE Block
//      13 Mechanical Department
//       14 ETC Building
//       15 Admission Cell
//      16 Bosch Rexroth Center of Excellence
//      17 CGU Volleyball Court
//      18 CSE Fountain
//      19 CV Raman Global University Backgate
    int graph[V][V] = {0};

    // CGU Front Gate connections
    graph[0][1] = graph[1][0] = 82;
    graph[0][2] = graph[2][0] = 92;
    graph[0][18] = graph[18][0] = 500;
    graph[0][8] = graph[8][0] = 550;


    // Diploma Department
    graph[1][3] = graph[3][1] = 100;
    graph[1][2] = graph[2][1] = 120;

    // Cricket Ground
    graph[3][4] = graph[4][3] = 270;
    graph[3][7] = graph[7][3] = 350;
    graph[3][11] = graph[11][3] = 400;

    // DSW Playground
    graph[4][5] = graph[5][4] = 110;
    graph[4][19] = graph[19][4] = 350;
    graph[4][18] = graph[18][4] = 200;
    graph[4][16] = graph[16][4] = 130;
    graph[4][14] = graph[14][4] = 300;

    // Swimming Pool
    graph[5][6] = graph[6][5] = 100;
    graph[5][7] = graph[7][5] = 130;

    // Medical Dispensary
    graph[6][7] = graph[7][6] = 230;

    // Boys Canteen
    graph[7][9] = graph[9][7] = 200;
    graph[7][18] = graph[18][7] = 400;
    graph[7][16] = graph[16][7] = 270;

    // MBA Department
    graph[2][11] = graph[11][2] = 350;
    graph[2][10] = graph[10][2] = 180;

    // Central Library
    graph[11][15] = graph[15][11] = 200;
    graph[11][19] = graph[19][11] = 100;

    // Admission Cell
    graph[15][14] = graph[14][15] = 100;
    graph[15][12] = graph[12][15] = 160;

    // ETC Building
    graph[14][13] = graph[13][14] = 150;

    // Mechanical Department
    graph[13][12] = graph[12][13] = 100;
    graph[13][18] = graph[18][13] = 180;

    // CSE Block
    graph[12][8] = graph[8][12] = 300;
    graph[12][18] = graph[18][12] = 70;
    graph[12][19] = graph[19][12] = 270;
    graph[12][17] = graph[17][12] = 280;

    // CSE Fountain
    graph[18][17] = graph[17][18] = 210;
    graph[18][8] = graph[8][18] = 300;
    graph[18][16] = graph[16][18] = 110;

    // Girls Canteen
    graph[8][17] = graph[17][8] = 94;

    // Volleyball Court
    graph[17][9] = graph[9][17] = 53;

    printf("Graph adjacency matrix created successfully.\n");

    int source, destination;

    printf("\n===== CGU CAMPUS NAVIGATION SYSTEM =====\n");

    showLocations();

    printf("Select Source Location: ");
    scanf("%d", &source);

    printf("Select Destination Location: ");
    scanf("%d", &destination);

    dijkstra(graph, source, destination);

    return 0;

    return 0;
}
