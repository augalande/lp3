/*
Write a program to solve a 0-1 Knapsack problem using dynamic programming
or branch andbound strategy. 
*/
#include<bits/stdc++.h>
using namespace std;

int N;
int W;
vector<vector<int>> dp;


struct Item
{
    int weight;
    int value;

    Item(int w,int v)
    {
        weight=w;
        value=v;
    }
};

int solve(vector<Item> &items, int ind,int w)
{
    // If weight left is 0
    if(w==0)
    {
        return 0;
    }

    //If ind(index) becomes negative
    if(ind<0)
    {
        return 0;
    }

    if(dp[ind][w]!=-1)
    {
        return dp[ind][w];
    }

    int ans1=0,ans2=0;  // Initialise to Zero vvvimp step
    // Don't Pick
    ans1=solve(items,ind-1,w);

    //Pick
    if(w-items[ind].weight>=0)
    {
        ans2=solve(items,ind-1,w-items[ind].weight) + items[ind].value;
    }

    int ans=max(ans1,ans2);
    dp[ind][w]=ans;

    return ans;
}

int main()
{
    vector<Item> items;

    cout<<"Enter Number of Items: "<<endl;
    cin>>N;

    cout<<"Enter Total Capacity of Bag: "<<endl;
    cin>>W;

    dp.resize(N+1,vector<int>(W+1,-1));

    for(int i=0;i<N;i++)
    {
        int w,v;
        cout<<"Enter Weight and Value of Item "<<i+1<<": "<<endl;
        cin>>w;
        cin>>v;
        Item o(w,v);
        items.push_back(o);
    }

    cout<<"Maxixmum Value: "<<solve(items,N-1,W);

}

//items={{3,30},{4,50},{5,60}} N=3 W=8 Ans=90
//items={{10,60},{20,100},{30,120}} N=3 W=50 Ans=220

/*
Output:-
Enter Number of Items: 
3
Enter Total Capacity of Bag: 
8
Enter Weight and Value of Item 1: 
3
30
Enter Weight and Value of Item 2: 
4
50
Enter Weight and Value of Item 3: 
5
60
Maxixmum Value: 90
*/

/*
TC:- O(N*W)
SC:- O(N*W) DP table
Recusive Space:- O(N)
*/