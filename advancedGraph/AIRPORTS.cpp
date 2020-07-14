/*
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.
Input
The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output
Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
Case #1: 145 1
Case #2: 2090 2
*/

//code
// #include<bits/stdc++.h>
// using namespace std;
// struct edges{
//     int v1,v2,w;
// };
// int caseNo = 0;

// bool compare(edges i1,edges i2){
//     return i1.w < i2.w;
// }

// int getparent(int s,int* parent){
//     if(parent[s]==s){
//         return s;
//     }
//     return parent[s] = getparent(parent[s],parent);
// }

// int mst(edges* input,int v,set<int> &s , int e){
//     int* parent = new int[v+1];
//     for(int i = 0;i <= v; i++){
//         parent[i] = i;
//     }
//     int count = 0,ans = 0;
//     for(int i = 0; i < e ; i++) {
//         edges currentedge = input[i];
//         int sparent = getparent(currentedge.v1,parent);
//         int dparent = getparent(currentedge.v2,parent);
        
//         if(sparent != dparent){
            
//             ans+=currentedge.w;
//             count++;
//             parent[sparent] = dparent;
//             if(count == v - 1) {
//                 break;
//             }
//         }
//     }
//     for(int i = 1; i <= v; i++){
//         s.insert(getparent(parent[i] , parent));
//     }
//     delete [] parent;
//     return ans;
    
// }

// void solve(){
//     caseNo++;
//     int v,e,a;
//     cin>>v>>e>>a;
//     edges* input = new edges[e];
//     for(int i = 0; i < e; i++){
//         int x,y,z;
//         cin>>x>>y>>z;
//         input[i].v1 = x;
//         input[i].v2 = y;
//         if(z>=a){
//             input[i].w = 0;
//             input[i].v1 = y;
//         }
//         else{
//             input[i].w = z;
//         }   
//     }
//     sort(input,input+e,compare);
//     set<int> s;
//     int answer = mst(input,v,s , e);
//     cout<<"Case #"<<caseNo<<": "<<(answer +s.size()*a)<<" "<<s.size()<<endl;
    
//     delete [] input;
    
    
    
// }
// int main()
// {
// 	int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// 	return 0;
// }


#include<bits/stdc++.h>
using namespace std;

struct edge{
int src;
int dest;
int weight;
};

bool compare(edge e1 , edge e2)
{
    return e1.weight < e2.weight ;
}

int getParent(int *parent , int currentNode)
{
    if(parent[currentNode] == currentNode)
    {
        return currentNode ;
    }
    return getParent(parent , parent[currentNode]) ;
}

void   krushkal(edge *edges , int n , int c , int m , int t)
{
    int *parent = new int[n];
    for(int i= 0;i<n ; i++)
    {
        parent[i] = i;
    }
    int incl = 0;
    int k = 0;

    int roadCost = 0;
    while(incl < n-1 && k<m)
    {
        if(edges[k].weight >= c)
        {
            break ; 
        }
        int srcParent = getParent(parent ,edges[k].src );
        int destParent = getParent(parent , edges[k].dest) ;

        if(srcParent != destParent)
        {
            parent[srcParent] = destParent ;
            roadCost += edges[k].weight ;
            incl ++;
        }
        k ++;
    }
    int airPorts = 0;
    for(int i= 0; i<n ; i++)
    {
        if(parent[i] == i)
        {
            airPorts ++;
        }
    }
    int cost =  airPorts*c + roadCost ;
    cout<<"Case #"<<t<<": "<<cost<<" "<<airPorts<<endl;
}

int main(){

int t;
cin>>t;
for(int x = 1 ; x<=t ; x++)
{
    int n , m , c ;
    cin>>n>>m>>c;

    edge *edges = new edge[m];

    for(int i= 0; i<m ; i++)
    {
        int src  , dest , weight ;
         cin>>src>>dest>>weight ; 
         edges[i].src = src-1;
         edges[i].dest = dest -1;
         edges[i].weight = weight ; 
    }
    sort(edges , edges +m , compare);
    krushkal(edges , n , c , m , x);
}
return 0;
}
