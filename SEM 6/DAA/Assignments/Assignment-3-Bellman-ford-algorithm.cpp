
/*
Name : Omkar Gurav
TE IT S3 Batch
Roll No : 8048

Write a program to implement Bellman-Ford Algorithm using Dynamic Programming and verify the time complexity.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;
 

struct Edge {
    int source, dest, weight;
};
 

void bellmanFord(vector<Edge> const &edges, int source, int N)
{
 
    vector<int> distance (N, INT_MAX);
    distance[source-1] = 0;
 
    int u, v, w, k = N;
 
    while (--k)
    {
        for (Edge edge: edges)   //Ranged Based for Loop
        {
            u = edge.source;
            v = edge.dest;
            w = edge.weight;
 
            if (distance[u-1] != INT_MAX && distance[u-1] + w < distance[v-1])
            {
                distance[v-1] = distance[u-1] + w;
            }
        }
    }
 
    for (Edge edge: edges)
    {
        u = edge.source;
        v = edge.dest;
        w = edge.weight;
 
        if (distance[u-1] != INT_MAX && distance[u-1] + w < distance[v-1])
        {
            cout << "\n\nNegative-weight cycle is found!!";
            return;
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        cout << "\n\nThe shortest distance of vertex " << i+1 << " from the source is "
             << setw(2) << distance[i] << ".";
    }
}
 

int main()
{
    vector<Edge> edges;
 
    int N,source,ans,k=0,Source,Destination,Weight;
 
    cout << "\n\nEnter number of vertices : ";
    cin >> N;

    do
    {
        cout << "\n\nEnter edge (format : source, destination, weight) : ";
        cin >> Source >> Destination >> Weight;

        edges.push_back({Source,Destination,Weight});
        k++;

        cout << "\n\n Do you want to add edge ? (Type 0 for no / 1 for yes) : ";
        cin >> ans;
    }
    while(ans == 1);

    cout << "\n\nEnter source vertex : ";
    cin >> source ;

    bellmanFord(edges, source, N);
 
    return 0;
}



/*Output

CASE 1 :

Enter number of vertices : 5


Enter edge (format : source, destination, weight) : 5 2 4


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 5 4 2


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 2 1 3


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 4 2 1


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 4 3 1


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 1 4 3


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 1 3 6


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 3 4 2


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 0


Enter source vertex : 5


The shortest distance of vertex 1 from the source is  6.

The shortest distance of vertex 2 from the source is  3.

The shortest distance of vertex 3 from the source is  3.

The shortest distance of vertex 4 from the source is  2.

The shortest distance of vertex 5 from the source is  0.




CASE 2 :

Enter number of vertices : 4


Enter edge (format : source, destination, weight) : 1 2 4


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 1 3 5


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 3 2 7


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 2 4 7


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 1


Enter edge (format : source, destination, weight) : 4 3 -15


 Do you want to add edge ? (Type 0 for no / 1 for yes) : 0


Enter source vertex : 1

Negative-weight cycle is found!!

*/