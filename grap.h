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
    void addEdge(const std::string& usuario1, const std::string& usuario2);
    void addUser(const string& usuario); //usuario 
    void addfriend(const string& usuario1, const string& usuario2);//agregar amistad
    set<string> bfs(const string& usuario) const; //algortimo bfs
    bool exist (const string& usuario) const;//usuario dentro del grafo
    vector<string>getFriends(const string& usuario) const;//ver lista de amigos


private:
    unordered_map<string, vector<string>> adjList;// estructura del grafo 
};

#endif
