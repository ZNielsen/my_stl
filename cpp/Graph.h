////////////////////////////////////////////////////////////////////////////////
//  File:   Graph.h
//
//  © Zach Nielsen 2020
//  A Graph Implementation
//
#ifndef _GRAPH_H_
#define _GRAPH_H_

////////////////////////////////////////////////////////////////////////////////
//  INCLUDES
////////////////////////////////////////////////////////////////////////////////
#include <unordered_set>
#include <queue>
#include <list>

////////////////////////////////////////////////////////////////////////////////
//  DEFINITIONS
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  PROTOTYPES
////////////////////////////////////////////////////////////////////////////////

template <class T>
struct Edge
{
   Vertex<T> &from;
   Vertex<T> &to;
   int weight;
};

template <class T>
struct Vertex
{
	T data;
	// Todo, replace with my linked list implementation
	std::list<Edge<T>> edges;
};

class Graph
{
	size_t _numVertexes;
	size_t _numEdges;

  public:

    static Vertex<T> BFS(const Vertex<T> & startVertex, const T &toFind);
    static Vertex<T> DFS(const Vertex<T> & startVertex, const T &toFind);

};

////////////////////////////////////////////////////////////////////////////////
//  CODE
////////////////////////////////////////////////////////////////////////////////

// This implementation does not care about edge weight
template <class T>
std::optional<Vertex<T>> Graph::BFS(const Vertex<T> & startVertex, const T &toFind)
{
    // Initialize our set of data to search and a hash of "seen" data
    std::queue<Verte<T>> q {};
    std::unordered_set<Vertex<T>> seen {};

    // Initialize the first vertex
    q.push(startVertex);

    while (!q.empty()) {
        const auto v = q.front();
        q.pop();
        seen.push(v);

        if (toFind == v.data) { return v; }

        for (const auto &edge : v.edges) {
            if (seen.count(edge.to) == 0) {
                q.push(edge.to);
            }
        }
    }
    return std::nullopt;
}

template <class T>
std::optional<Vertex<T>> Graph::DFS(const Vertex<T> &startVertex, const T &toFind)
{
    std::stack<Vertex<T>> toSearch {};
    std::unordered_set<Vertex<T>> seen {};

    toSearch.push(startVertex);

    while(!toSearch.empty()) {
        const auto v = toSearch.top();
        toSearch.pop();
        seen.push(v);

        if (toFind == v.data) { return v; }

        for (const auto &edge : v.edges) {
            if (seen.count(edge.to) == 0) {
                toSearch.push(edge.to);
            }
        }
    }

    return std::nullopt;
}


#endif // _GRAPH_H_ //
