/*
 * @Author: cc
 * @Date: 2020-11-01 22:14:15
 * @LastEditTime: 2020-11-02 16:54:34
 * @LastEditors: cc
 * @FilePath: \leetcode\disjoint_set\959.cpp
 * @Solution: 将每一个小格子划分为4个三角形小格子，如果没有分割则用并查集合并；同时相邻的两个格子挨着的小三角也得合并。
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
        father = vector<int>(4 * n * n, 0);
        for (int i = 0; i < 4 * n * n; ++i)
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

    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        init(father, n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int k = 4 * (i * n + j);
                if (grid[i][j] == '/')
                {
                    merge(k, k + 3);
                    merge(k + 1, k + 2);
                }
                else
                {
                    merge(k, k + 1);
                    merge(k + 2, k + 3);
                }
                if (grid[i][j] == ' ')
                    merge(k + 1, k + 2);

                if (i > 0)
                    merge(k, k - 4 * n + 2);
                if (j > 0)
                    merge(k + 3, k - 3);
            }
        }
        int cnt = 0;
        for (int i = 0; i < 4 * n * n; ++i)
        {
            if (get(i) == i)
                cnt++;
        }
        return cnt;
    }
};