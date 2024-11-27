#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Graph {
public:
    void addUser(const string& usuario); //usuario 
    void addfrien(const string& usuario1, const string& usuario2);//agregar amistad
    set<string> bfs(const string& usuario) const; //algortimo bfs
    bool existe (const string& usuario) const;//usuario dentro del grafo

private:
    unordered_map<string, vector<string>> adjList;// estructura del grafo 
};

#endif
