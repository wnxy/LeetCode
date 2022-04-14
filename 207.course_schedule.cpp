/**
 * @file 207.course_schedule.cpp
 * @author your name (you@domain.com)
 * @brief 课程表安排，有向无环图的拓扑排序
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indegree.resize(numCourses);
        // 邻接表存储，统计顶点入度
        for(const auto& info: prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            ++indegree[info[0]];
        }
        queue<int> q;
        // 将入度为0的顶点入队
        for(int i = 0; i < indegree.size(); ++i)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            int node = q.front();
            res.emplace_back(node);
            q.pop();
            // 将与node顶点相连的顶点的入度减一
            for(int n: edges[node])
            {
                --indegree[n];
                if(indegree[n] == 0)
                {
                    q.push(n);
                }
            }
        }
        if(res.size() != numCourses)
        {
            return {};
        }
        return res;
        // return res.size() != numCourses? {}: res;
    }

private:
    vector<vector<int>> edges;     // 邻接表存储图
    vector<int> indegree;          // 存储每个顶点的入度
};

class Solution1 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info: prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        for(int i = 0; i < numCourses && valid; ++i)
        {
            if(visited[i] == 0)
            {
                dfs(i);
            }
        }
        if(valid == false) return {};
        vector<int> res;
        while(!stk.empty())
        {
            res.emplace_back(stk.top());
            stk.pop();
        }
        return res;
    }

    void dfs(int i)
    {
        visited[i] = 1;
        for(int v: edges[i])
        {
            if(visited[v] == 0)
            {
                dfs(v);
                stk.push(v);
                if(valid == false)
                {
                    return;
                }
            }
            else if(visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        visited[i] = 2;
    }

private:
    vector<vector<int>> edges;      // 图的邻接表
    // 0：标志未访问，1：标志访问中，2：标志已访问
    vector<int> visited;            // 标记图中每个顶点的访问状态
    stack<int> stk;
    bool valid = true;              // 标志图是否有效（有无环）
};

int main()
{
    vector<vector<int>> prerequisites = {{1, 0}};
    int numCourses = 2;
    Solution1 solution;
    vector<int> res = solution.findOrder(numCourses, prerequisites);
    return 0;
}