/**
 * Cheng Shi, shicheng107@hotmail.com
 */

#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

typedef pair<string, vector<string> > GraphNode;
typedef unordered_map<string, vector<string> > Graph;
typedef function<void(const string &)> Func;

class GraphHelper
{
private:
    const Graph &m_graph;
    unordered_set<string> m_visitHistory;
    Func m_func;

public:
    GraphHelper(const Graph &other, Func f);
    void SearchGraphDepth();
    void SearchGraphBreadth();

private:
    void SearchGraphNodeDepth(const string &nodeLabel);
};

GraphHelper::GraphHelper(const Graph &other, Func f)
    : m_graph(other), m_func(f)
{}

void GraphHelper::SearchGraphDepth()
{
    m_visitHistory.clear();
    for (auto it = m_graph.begin(); it != m_graph.end(); ++it)
        SearchGraphNodeDepth(it->first);
}

void GraphHelper::SearchGraphNodeDepth(const string &nodeLabel)
{
    if (m_graph.find(nodeLabel) == m_graph.end())
        return;
    if (m_visitHistory.find(nodeLabel) != m_visitHistory.end())
        return;
    m_func(nodeLabel);
    m_visitHistory.insert(nodeLabel);
    auto result = m_graph.find(nodeLabel);
    if (result != m_graph.end())
    {
        const vector<string> &neighbors = result->second;
        for (auto it = neighbors.begin(); it != neighbors.end(); ++it)
            SearchGraphNodeDepth(*it);
    }
}

void GraphHelper::SearchGraphBreadth()
{
    m_visitHistory.clear();
    if (m_graph.empty())
        return;
    queue<string> searchList;
    searchList.push(m_graph.begin()->first);

    while (!searchList.empty())
    {
        string nodeLabel = searchList.front();
        searchList.pop();
        if (m_visitHistory.find(nodeLabel) != m_visitHistory.end())
            continue;
        m_func(nodeLabel);
        m_visitHistory.insert(nodeLabel);
        auto result = m_graph.find(nodeLabel);
        if (result != m_graph.end())
        {
            const vector<string> &neighbors = result->second;
            for (auto it = neighbors.begin(); it != neighbors.end(); ++it)
                searchList.push(*it);
        }
    }
}

void Output(const string &s)
{
    cout << s << endl;
}

int main(int argc, const char** argv)
{
    Graph g;
    g.insert(make_pair("0", vector<string>({ "1", "2" })));
    g.insert(make_pair("1", vector<string>({ "0", "3", "4" })));
    g.insert(make_pair("2", vector<string>({ "0", "4", "5" })));
    g.insert(make_pair("3", vector<string>({ "1", "6" })));
    g.insert(make_pair("4", vector<string>({ "1", "2" })));
    g.insert(make_pair("5", vector<string>({ "2", "6" })));
    g.insert(make_pair("6", vector<string>({ "3", "5" })));
    GraphHelper gh(g, Output);
    gh.SearchGraphDepth();
    cout << endl;
    gh.SearchGraphBreadth();

    cin.get();
	return 0;
}
