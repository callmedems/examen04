#include "grap.h"
#include <iostream> 
#include <queue>
using namespace std; 


// nuevo usuario al grafo.
void Graph::addUser(const string& usuario) {
    adjList.emplace(usuario, vector<string>());
}

// Agrega AMISTAD
void Graph::addfriend(const string& usuario1, const string& usuario2) {
    //  ambos usuarios existEN
    if (!exist(usuario1)) {
        addUser(usuario1);
    }
    if (!exist(usuario2)) {
        addUser(usuario2);
    }

    // Agrega la conexion
    adjList[usuario1].push_back(usuario2);
    adjList[usuario2].push_back(usuario1);
}

bool Graph::exist(const string& usuario) const {//user exoste en el grafo
    return adjList.find(usuario) != adjList.end();
}

// BFSS
set<string> Graph::bfs(const string& usuario) const {
    set<string> visitados;
    queue<string> cola;

    if (!exist(usuario)) {
        return visitados; 
    }

    // Busqued
    visitados.insert(usuario);
    cola.push(usuario);

    while (!cola.empty()) {
        string actual = cola.front();
        cola.pop();

        // Busca los amigos del user
        for (const auto& amigo : adjList.at(actual)) {
            if (visitados.find(amigo) == visitados.end()) {
                visitados.insert(amigo);
                cola.push(amigo);
            }
        }
    }

    // Remueve el usuario inicial
    visitados.erase(usuario);

    return visitados;
}

