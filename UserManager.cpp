
#include "UserManager.h"

//Esta funcion booleana se encarga de añadir usuarios al sistema y devuelve true si se hace exitosamente, false en caso contrario, como por ejemplo, que ya exista

bool UserManager::addUser(const std::string& usuario) {
    auto resultado = interesesPorUsuario.emplace(usuario, std::set<std::string>());
    return resultado.second;
}

std::vector<std::string> UserManager::getAllUsers() const {
    std::vector<std::string> usuarios;
    for (const auto& pair : interesesPorUsuario) {
        usuarios.push_back(pair.first);
    }
    return usuarios;
}

//Lo mismo pero ahora para añadir intereses y recibiendo como parámetros usuario y categoría, en caso de no encontrar al usuario devuelve false
bool UserManager::addInterest(const std::string& usuario, const std::string& categoria) {
    auto it = interesesPorUsuario.find(usuario); // Usa find para buscar si el usuario existe en el mapa
    if (it != interesesPorUsuario.end()) { //Si el usuario existe... se inserta la categoria en el conjunto asociado al usuario (se asume que el mapa acepta insert)
        it->second.insert(categoria);
        return true;
    }
    return false;
}

//Con esta funcion obtenemos la lista de intereses de un usuario, devuelve un vector vacio en caso de no encontrar al usuarip
std::vector<std::string> UserManager::getInterests(const std::string& usuario) const {
    std::vector<std::string> intereses;
    auto it = interesesPorUsuario.find(usuario); // it es la variable que actúa como iterador y permite recorrer el mapa o vector a manera de iterador, permite recorrer o acceder a elementos
    if (it != interesesPorUsuario.end()) {
        intereses.assign(it->second.begin(), it->second.end());
    }
    return intereses;
}

// Verificamos si un usuario existe en el sistema
bool UserManager::userExists(const std::string& usuario) const {
    return interesesPorUsuario.find(usuario) != interesesPorUsuario.end();
}
