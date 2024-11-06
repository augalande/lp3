/*
Write a program for analysis of quick sort by using deterministic and randomized
variant. 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

int partitionDeterministic(vector<int> &arr,int low, int high)
{
    int pivot=low;
    int i=low;
    int j=high;

    while(i<j)
    {
        while(i<high && arr[i]<=arr[pivot])
        {
            i++;
        }

        while(j>low && arr[j]>arr[pivot])
        {
            j--;
        }

        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}

void deterministicQuickSort(vector<int> &v,int low, int high, int &cmpDet,int &swpDet)
{
    if(low<high)
    {
        int partition_index=partitionDeterministic(v,low,high);
        cmpDet+=(high-low);
        swpDet+=2;

        deterministicQuickSort(v,low,partition_index-1,cmpDet,swpDet);
        deterministicQuickSort(v,partition_index+1,high,cmpDet,swpDet);
    }
}

int partitionRandomized(vector<int> &arr,int low, int high)
{
    int pivotIndex= low + rand()%(high-low+1);
    swap(arr[pivotIndex],arr[low]);

    int pivot=low;
    int i=low;
    int j=high;

    while(i<j)
    {
        while(i<high && arr[i]<=arr[pivot])
        {
            i++;
        }

        while(j>low && arr[j]>arr[pivot])
        {
            j--;
        }

        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}

void randomizedQuickSort(vector<int> &v,int low, int high, int &cmpRand,int &swpRand)
{
    if(low<high)
    {
        int partition_index=partitionRandomized(v,low,high);
        cmpRand+=(high-low);
        swpRand+=2;

        randomizedQuickSort(v,low,partition_index-1,cmpRand,swpRand);
        randomizedQuickSort(v,partition_index+1,high,cmpRand,swpRand);

    }
}


void print_array(vector<int> v)
{
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    srand(time(0));
    vector<int> v1,v2;
    cout<<"Enter Size of Array:- "<<endl;
    int n;
    cin>>n;

    cout<<"Enter Elements of Array:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }

    v2=v1;
    int ch;

    do{
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"1) Deterministic Quick Sort"<<endl;
    cout<<"2) Randomized Quick Sort"<<endl;
    cout<<"3) Exit"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Enter a Choice:-"<<endl;
    cin>>ch;

        if(ch==1)
        {
                int cmpDet=0;
                int swpDet=0;
                cout<<"Before Deterministic Quick Sort:-"<<endl;
                print_array(v1);
                deterministicQuickSort(v1,0,v1.size()-1,cmpDet,swpDet);
                cout<<"After Deterministic Quick Sort:-"<<endl;
                print_array(v1);
                cout<<"Total Comparisons:- "<<cmpDet<<endl;
                cout<<"Total Swaps:- "<<swpDet<<endl;
        }

        if(ch==2)
        {
                int cmpRand=0;
                int swpRand=0;
                cout<<"Before Randomized Quick Sort:-"<<endl;
                print_array(v2);
                randomizedQuickSort(v2,0,v2.size()-1,cmpRand,swpRand);
                cout<<"After Randomized Quick Sort:-"<<endl;
                print_array(v2);
                cout<<"Total Comparisons:- "<<cmpRand<<endl;
                cout<<"Total Swaps:- "<<swpRand<<endl;
        }

        if(ch==3)
        {
                exit(0);
        }

    }while(ch!=3);

    return 0;
}

/*
Output:-
Enter Size of Array:- 
7
Enter Elements of Array:-
4
9
7
3
6
0
2
--------------------------------------------------------------------
1) Deterministic Quick Sort
2) Randomized Quick Sort
3) Exit
--------------------------------------------------------------------
Enter a Choice:-
1
Before Deterministic Quick Sort:-
4 9 7 3 6 0 2 
After Deterministic Quick Sort:-
0 2 3 4 6 7 9 
Total Comparisons:- 12
Total Swaps:- 10
--------------------------------------------------------------------
1) Deterministic Quick Sort
2) Randomized Quick Sort
3) Exit
--------------------------------------------------------------------
Enter a Choice:-
2
Before Randomized Quick Sort:-
4 9 7 3 6 0 2 
After Randomized Quick Sort:-
0 2 3 4 6 7 9 
Total Comparisons:- 11
Total Swaps:- 8
--------------------------------------------------------------------
1) Deterministic Quick Sort
2) Randomized Quick Sort
3) Exit
--------------------------------------------------------------------
Enter a Choice:-
3
*/

/*
TC:- O(nlogn)  worst case O(n^2)
SC:- O(1)
Recursive Stack Space-O(n)
*/