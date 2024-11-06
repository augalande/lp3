/*
Write a program to implement Huffman Encoding using a greedy strategy. 
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct HuffmanNode
{
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d,int f)
    {
        data=d;
        frequency=f;
        left=right=nullptr;
    }
};

struct Compare
{
    bool operator() (HuffmanNode* left,HuffmanNode* right) // VVVIMP operator()
    {
        return left->frequency > right->frequency;
    }
};

void compute(HuffmanNode* root,string code,unordered_map<char,string> &huffmanCodes)
{
    if(root==nullptr)
    {
        return ;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        huffmanCodes[root->data]=code;
        cout<<root->data<<": "<<code<<endl;
        return;
    }

    compute(root->left,code+"0",huffmanCodes);
    compute(root->right,code+"1",huffmanCodes);
}

void buildHuffmanTree(string text)
{
    unordered_map<char,int> freqMap;
    for(char ch:text)
    {
        freqMap[ch]++;
    }

    priority_queue<HuffmanNode*,vector<HuffmanNode*>,Compare> pq;
    for(auto pair:freqMap)
    {
        pq.push(new HuffmanNode(pair.first,pair.second));
    }

    while(pq.size()>1)
    {
        HuffmanNode* left=pq.top();
        pq.pop();

        HuffmanNode* right=pq.top();
        pq.pop();

        HuffmanNode* newNode=new HuffmanNode('\0',left->frequency+right->frequency);
        newNode->left=left;
        newNode->right=right;

        pq.push(newNode);
    }

    HuffmanNode* root=pq.top();

    unordered_map<char,string> huffmanCodes;
    compute(root,"",huffmanCodes);

    cout<<"Encoded Huffman String: "<<endl;

    float count_ch=0,count_bits=0;
    for(char ch:text)
    {
        cout<<huffmanCodes[ch];
        count_bits+=huffmanCodes[ch].size();
        count_ch+=1;
    }
    cout<<endl;

    cout<<"Average Bits/Character:- "<<(count_bits/count_ch);
}

int main()
{
    string text;
    cout<<"Enter a String: "<<endl;
    getline(cin,text);

    buildHuffmanTree(text);
    return 0;
}

/*
Output:-
Enter a String: 
mississippi
s: 0
m: 100
p: 101
i: 11
Encoded Huffman String: 
100110011001110110111
Average Bits/Character:- 1.90909
*/

/*
Overall Time Complexity
Combining these steps, the overall time complexity is:
O(n+mlogm)
(traversing string+building min heap)
where:
n is the length of the input string,
m is the number of unique characters.

Overall Space Complexity
Combining these, the overall space complexity is:
O(n+m)
(string input+freqmap/hufmancodes)
where:
n is the length of the input string,
m is the number of unique characters.
*/