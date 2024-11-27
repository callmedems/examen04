#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <unordered_map>
#include <set>
#include <string>
#include <vector>

class UserManager {
public:
    //Esta funcion crea un booleano, es decir, creamos un true or false, para validar la creacion del usuario
    bool addUser(const std::string& usuario);

    // Lo mismo pero añadir interés
    bool addInterest(const std::string& usuario, const std::string& categoria);

    // En este vector se guardan los intereses del usuario
    std::vector<std::string> getInterests(const std::string& usuario) const;

    // Este booleano verifica que un usuario exista o no, se guarda el usuario como constante
    bool userExists(const std::string& usuario) const;

private:
    // Se ubica a cada usuario en el hash map y se conecta con sus intereses
    std::unordered_map<std::string, std::set<std::string>> interesesPorUsuario;
};

#endif 
