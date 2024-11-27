#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <unordered_map> 
#include <set>
#include <string>
#include <vector>

using namespace std; 

class ContentManager{
    public: 
        // con esto agregamos contenido a una categoría específica
        void addContent(const string& categoria, const string& contenido);

        // lista de los contenidos acomodados por su categoría
        vector<string> obtenerContenidoPorCategoria(const string& categoria) const; 

    private: 
        // aqui va el unordered map
        unordered_map<string, set<string>> contenidosPorCategoria;
};

#endif //CONTENTMANAGER_H