/*
 * @Author: cc
 * @Date: 2020-11-02 19:03:06
 * @LastEditTime: 2020-11-02 19:10:51
 * @LastEditors: cc
 * @FilePath: \leetcode\disjoint_set\684.cpp
 * @Solution: 
 */

#include <iostream>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;



class Solution
{
public:
    vector<int> father;

    void init(vector<int> &father, int n)
    {
        father = vector<int>(n+10, 0);
        for (int i = 1; i <= n; ++i)
            father[i] = i;
    }

    int get(int x)
    {
        if (x == father[x])
            return x;
        return x = get(father[x]);
    }

    void merge(int a, int b)
    {
        a = get(a);
        b = get(b);
        if (a != b)
            father[a] = b;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> ans;
        init(father, n);
        for(int i=0; i<n; ++i)
        {
            if(get(edges[i][0]) != get(edges[i][1])) merge(edges[i][0], edges[i][1]);
            else
            {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                break;
            }
        }
        return ans;
    }
};