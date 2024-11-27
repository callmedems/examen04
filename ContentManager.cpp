#include "ContentManager.h"

void ContentManager::addContent(const string& categoria, const string& contenido) {
    contenidosPorCategoria[categoria].insert(contenido);
}

vector<string> ContentManager::obtenerContenidoPorCategoria(const string& categoria) const {
    vector<string> contenidos; 
    auto it = contenidosPorCategoria.find(categoria);
    if (it != contenidosPorCategoria.end()) {
        contenidos.assign(it -> second.begin(), it -> second.end()); 
    }
    return contenidos;
}