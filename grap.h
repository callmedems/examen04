#ifdef GRAP_H
#define GRAP_H
#include <iostream> 
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
using namespace std; 

class Graph {
public:
    // Agrega un nuevo usuario al grafo sin conexiones iniciales.
    void addUser(const std::string& usuario);

    // Agrega una conexión (amistad) entre dos usuarios.
    void addEdge(const std::string& usuario1, const std::string& usuario2);

    // Realiza una búsqueda en amplitud y devuelve todos los amigos de un usuario.
    std::set<std::string> bfs(const std::string& usuario) const;

    // Verifica si un usuario existe en el grafo.
    bool userExists(const std::string& usuario) const;

private:
    // Lista de adyacencia para representar las relaciones de amistad.
    std::unordered_map<std::string, std::vector<std::string>> adjList;
};

#endif // GRAPH_H

#endif