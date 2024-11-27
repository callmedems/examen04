#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include "ContentManager.h"
#include "UserManager.h"
#include "Graph.h"
#include <vector>
#include <string>
#include <set>

using namespace std;

class RecommendationSystem {
public:
    // Llamamos al constructor
    RecommendationSystem();

    // Agrega un nuevo usuario al sistema
    bool addUser(const string& usuario);

    // Agrega contenido a una categoría específica
    void addContent(const string& categoria, const string& contenido);

    // Crea una amistad entre dos usuarios
    bool addFriend(const string& usuario1, const string& usuario2);

    // Agrega un interés (categoría) a un usuario existente
    bool addInterest(const string& usuario, const string& categoria);

    // Genera una lista de contenido recomendado para un usuario
    vector<string> recommendContent(const string& usuario);

    // Verifica si un usuario existe en el sistema.
    bool userExists(const string& usuario) const;

private:
    ContentManager contentManager;
    UserManager userManager;
    Graph graph;
};

#endif 
