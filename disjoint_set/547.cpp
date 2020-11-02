/*
 * @Author: cc
 * @Date: 2020-11-02 21:30:45
 * @LastEditTime: 2020-11-02 21:31:40
 * @LastEditors: cc
 * @FilePath: \leetcode\disjoint_set\547.cpp
 * @Solution: 简单的并查集，只要是朋友就并入一个集合中，求一共有几个集合。
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

class Solution {
public:
    vector<int> father;

    void init(vector<int> &father, int n)
    {
        father = vector<int>(n, 0);
        for(int i=0; i<n; ++i) father[i] = i;
    }

    int get(int x)
    {
        if(x == father[x]) return x;
        return x = get(father[x]);
    }

    void merge(int a, int b)
    {
        a = get(a);
        b = get(b);
        if(a != b) father[a] = b;
    }


    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        init(father, n);
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(M[i][j] == 1)
                {
                    merge(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; ++i)
        {
            if(get(i) == i) cnt++;
        }
        return cnt;
    }
};