#include "RecommendationSystem.h"
using namespace std;
// Constructor
RecommendationSystem::RecommendationSystem() {
    // Inicialización si es necesaria
}

// Agrega un nuevo usuario al sistema.
bool RecommendationSystem::addUser(const string& usuario) {
    bool userAdded = userManager.addUser(usuario);
    if (userAdded) {
        graph.addUser(usuario);
    }
    return userAdded;
}

// Agrega contenido a una categoría específica.
void RecommendationSystem::addContent(const string& categoria, const string& contenido) {
    contentManager.addContent(categoria, contenido);
}

// Crea una amistad entre dos usuarios.
bool RecommendationSystem::addFriend(const string& usuario1, const string& usuario2) {
    // Verifica que ambos usuarios existan
    if (userManager.userExists(usuario1) && userManager.userExists(usuario2)) {
        graph.addEdge(usuario1, usuario2);
        return true;
    }
    return false;
}

// Agrega un interés (categoría) a un usuario existente.
bool RecommendationSystem::addInterest(const string& usuario, const string& categoria) {
    return userManager.addInterest(usuario, categoria);
}

// Genera una lista de contenido recomendado para un usuario.
vector<string> RecommendationSystem::recommendContent(const string& usuario) {
    vector<string> recomendaciones;

    // Verifica si el usuario existe
    if (!userManager.userExists(usuario)) {
        return recomendaciones; // Retorna una lista vacía si el usuario no existe
    }

    // Obtiene los amigos del usuario utilizando BFS
    set<string> amigos = graph.bfs(usuario);

    // Conjunto para almacenar las categorías de interés de los amigos
    set<string> interesesAmigos;

    // Itera sobre los amigos para obtener sus intereses
    for (const auto& amigo : amigos) {
        vector<string> intereses = userManager.getInterests(amigo);
        interesesAmigos.insert(intereses.begin(), intereses.end());
    }

    // Conjunto para evitar contenido duplicado
    set<string> contenidoRecomendado;

    // Para cada categoría de interés de los amigos, obtiene el contenido relacionado
    for (const auto& categoria : interesesAmigos) {
        vector<string> contenidos = contentManager.getContentByCategory(categoria);
        contenidoRecomendado.insert(contenidos.begin(), contenidos.end());
    }

    // Convierte el conjunto a un vector para retornar
    recomendaciones.assign(contenidoRecomendado.begin(), contenidoRecomendado.end());

    return recomendaciones;
}

// Verifica si un usuario existe en el sistema.
bool RecommendationSystem::userExists(const string& usuario) const {
    return userManager.userExists(usuario);
}
