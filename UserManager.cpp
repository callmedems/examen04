#include "UserManager.h"

//Esta funcion booleana se encarga de añadir usuarios al sistema y devuelve true si se hace exitosamente, false en caso contrario, como por ejemplo, que ya exista

bool UserManager::addUser(const std::string& usuario) {
    auto resultado = interesesPorUsuario.emplace(usuario, std::set<std::string>());
    return resultado.second; 
}


//Lo mismo pero ahora para añadir intereses y recibiendo como parámetros usuario y categoría, en caso de no encontrar al usuario devuelve false
bool UserManager::addInterest(const std::string& usuario, const std::string& categoria) {
    auto it = interesesPorUsuario.find(usuario);
    if (it != interesesPorUsuario.end()) {
        it->second.insert(categoria);
        return true;
    }
    return false; 
}

//Con esta funcion obtenemos la lista de intereses de un usuario, devuelve un vector vacio en caso de no encontrar al usuarip
std::vector<std::string> UserManager::getInterests(const std::string& usuario) const {
    std::vector<std::string> intereses;
    auto it = interesesPorUsuario.find(usuario);
    if (it != interesesPorUsuario.end()) {
        intereses.assign(it->second.begin(), it->second.end());
    }
    return intereses;
}

// Verificamos si un usuario existe en el sistema
bool UserManager::userExists(const std::string& usuario) const {
    return interesesPorUsuario.find(usuario) != interesesPorUsuario.end();
}
