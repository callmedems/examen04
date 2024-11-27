#include "ContentManager.h"

void ContentManager::addContent(const string& categoria, const string& contenido) {
    contenidosPorCategoria[categoria].insert(contenido);
}