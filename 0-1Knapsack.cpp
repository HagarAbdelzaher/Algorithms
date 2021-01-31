#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //size and weights
    long  n=8 , w=30;
    vector<pair<long,long>> v;
    vector<string> names(w);
    v.push_back(make_pair(0,0));
    long m[n+1][w+1];

    // input
    vector <string> items = {"Gaming PC", "Apple Watch", "Iphone 12", "DVD-Set", "Samsung Galaxy S12+", "Apple Mac Box Air", "Mac Pro" , "extra"};
    vector<long> prices = {8,3,5,1,4,20,7,22};
    vector <long> profits = {14 , 5 , 8 , 3, 6, 28 , 10 , 27};
    for(int i=0 ; i<n ; i++)
    {
        string name = items[i];
        int x = prices[i];
        int y = profits[i];
        v.push_back(make_pair(x,y));
        names[x]=name;
    }
    sort(v.begin() , v.end());

    for(int i=0 ; i<w+1 ; i++)
    {
        m[0][i]=0;
    }
    for(int i=0 ; i<n+1 ; i++)
    {
        m[i][0]=0;
    }

//filling the Knapsack Table
    for(int j=1 ; j<=w ; j++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            if(v[i].first> j)
            {
                m[i][j]=m[i-1][j];
            }
            else
            {
                m[i][j]=max( m[i-1][j] , m[i-1][j- v[i].first] + v[i].second );
            }
        }
    }


    // Back tracking
    vector<int> output;
    int j=w , i=n;
     int remainingWeight = w;
    while (remainingWeight!=0 && i>=0 && j>=0)
    {
        if(m[i][j]!=m[i-1][j])
        {
            remainingWeight = j-v[i].first;
            output.push_back(v[i].first);
            j=remainingWeight;
        }
        i--;
    }


    // output table
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<w+1 ; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //output items
    for(int i=0 ; i<output.size() ; i++)
        cout<<names[output[i]]<<" ";
}


