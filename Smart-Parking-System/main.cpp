#include<algorithm>
#include<iostream>
#include<vector>
#include "hungarian.h" //function hungarian is imported here. Hungarian function is a linear assignment solver for matrix having time complexity = O(n^3). Here the function is specifically designed for a square matrix and doesn't work on other hungarian inputs like graphical assignment problems
using namespace std;


void print(vector<vector<int>> D1)
{
    
    for(int i=0; i< D1.size(); i++)
    {   
        cout<<"P"<<i+1<<"->";
        for(int j=0;j<D1[i].size();j++)
            cout<<" | "<<D1[i][j];
        cout<<" |\n";
    }   
}

vector<vector<int>> Dnew(vector<vector<int>> D, int M, vector<int> S) //this is will create D1 which will be a square matrix of size= Size of S and will contain virtual cars having their distances equal to 0
{
    vector<vector<int>> D1 (S.size(), vector<int> (S.size()));
   
    for(int i=0;i<S.size();i++)
        for(int j=0;j<M;j++)
            D1[j][i]=D[j][S[i]];
    
    if(M < S.size()) //since M is less than size of S we need to add virtual cars each having distance 0 from all the parking stops
    {
        for (int i=0;i<S.size();i++)
            for(int j=M;j<S.size() ;j++)
                D1[j][i]=0;
    } 

    return D1;

}

vector<int> subi(vector<vector<int>> D,int i, int M) // create the sub array (containing index) of parking spot for car i. It choses the index of 1st M best spots. 
{
    vector<int> temp=D[i];
    sort(temp.begin(),temp.end());
    vector<int> Si;
    
    for(int j=0;j<M;j++)
    {
        auto k=find(D[i].begin(),D[i].end(),temp[j]);
        Si.push_back(k-D[i].begin());
    }

    return Si;
}

vector<int> combine(vector<vector<int>> D, int M, int N) // combine all Si with unique elements
{   
    vector<int> S;
    vector<int> Si;
    for(int i=0;i<M;i++)
    {
        Si=subi(D,i,M);

        for(int j=0;j<M;j++)
            {
                if(S.size()!=0)
                   {
                       auto k=find(S.begin(),S.end(),Si[j]);
                       if(k==S.end())
                            S.push_back(Si[j]);
                   } 
                else
                    S.push_back(Si[j]);
            } 
    }
    
    return S;
}

int cost(vector<vector<int>> D,int M, int N) //return total cost
{
    //print(Dnew(D,M,combine(D,M,N)));
    auto res=hungarian(Dnew(D,M,combine(D,M,N)));
    return res;
}

int main()
{
    int N, M; // M=no of parking carks and N=no of parking spots
    
    cout<<"Enter no of parking spots: ";
    cin>>N;
    cout<<"Enter no of cars: ";
    cin>>M;
    vector<vector<int>> D (M, vector<int> (N)); // Distance (Dij) between parking car- i and parking spot- j
    cout<<endl;
    for(int i=0;i<M;i++) // Taking distance between each car and parking spot
        for(int j=0;j<N;j++)
            {
                cout<<"Enter distance between car P"<<i+1<<" and Spot"<<j+1<<": ";
                cin>>D[i][j];
            }
    cout<<endl;
    cout<<"Input martix-\n";
    print(D);
    cout<<"...................";
    cout<<"\nTotal Cost: "<<cost(D,M,N);
    cout<<"\n...................";
    return 0;
}