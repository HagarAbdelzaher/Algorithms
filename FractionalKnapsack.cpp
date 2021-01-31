#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n , W , remainingWeight=0 , totalProfit=0 , chosenIndex , maximum;
    vector<double> profits , weights;
    vector<pair<double,bool>> ratios;

    /* the Example used here is  the following:

    the total number of elements (n)=7
    W=15

    objects: 1 2  3  4 5 6 7
    profits: 5 10 15 7 8 9 4
    weights: 1 3  5  4 1 3 2

     */
    n=7;
    W=15;
    profits={5,10,15,7,8,9,4};
    weights={1,3,5,4,1,3,2};

    for(int i=0 ; i<n;i++)
    {
        double element = profits[i]/weights[i];
        bool b = false;
        ratios.push_back(make_pair(element , b));
    }
    remainingWeight = W;
    while(remainingWeight!=0)
    {
        //get element with max ratio
        maximum=-100;
        for(int i=0 ; i<n ; i++)
        {
            if(ratios[i].first>=maximum && !ratios[i].second)
            {
                maximum = ratios[i].first;
                chosenIndex=i;
            }
        }

        ratios[chosenIndex].second = true;

        if(remainingWeight-weights[chosenIndex]>=0)
        {
            totalProfit+= profits[chosenIndex];
            remainingWeight-=weights[chosenIndex];
        }
        else
        {
            double takenWeight = remainingWeight;
            totalProfit = totalProfit+ (profits[chosenIndex] *(takenWeight/weights[chosenIndex]));
        }
    }
    cout<<"the total profit is"<<endl;
    cout<<totalProfit<<endl;


}
