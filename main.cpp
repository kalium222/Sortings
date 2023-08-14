#include <iostream>
#include "sort.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;


bool compare(vector<int> &list)
{
    vector<vector<int>> all_list;
    for(int i=0;i<7;i++)
    {
        vector<int> temp;
        for(int j=0;j<(int)list.size();j++)
        {
            temp.push_back(list[j]);
        }
        all_list.push_back(temp);
    }
    bool flag=false;
    bubble_sort(all_list[0], std::less<int>());
    selection_sort(all_list[1], std::less<int>());
    insertion_sort(all_list[2], std::less<int>());
    merge_sort(all_list[3], std::less<int>());
    quick_sort_extra(all_list[4], std::less<int>());
    quick_sort_inplace(all_list[5], std::less<int>());
    sort(all_list[6].begin(), all_list[6].end(), std::less<int>());
    for(int i=0;i<(int)list.size();i++)
    {
        for(int j=0;j<6;j++)
        {
            if(all_list[j][i]!=all_list[6][i])
            {
                cout<<j<<" is incorrect"<<endl;
                flag=true;
            }
        }
    }
    return flag;
}

int main()
{
    int test_round=1000;
    ifstream ifile;
    ifile.open("test.txt");
    int index=0;
    vector<int> list;
    while(ifile)
    {
        string s;
        getline(ifile, s);
        istringstream is(s);
        while(is)
        {
            int temp;
            is>>temp;
            list.push_back(temp);
        }
        list.pop_back();
        if(compare(list))
        {
            cout<<"in "<<index<<" round"<<endl;
        }
        index++;
        list.clear();
        cout<<index<<" round is testing"<<endl;
    }
}