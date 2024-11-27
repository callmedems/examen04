#include <iostream>
#include <string>
#include "RecommendationSystem.h" // RecommendationSystem ya llama a las clases
// Graph.h, UserManager.h, ContentManager.h

using namespace std; 

void showMenu(RecommendationSystem& sistema) {
    int opcion = 0;

    while (opcion != 6) {
        // mostrar el menú de opciones
        cout << "==== Menú ====";
        cout << "1. Crear amistad.\n";
        cout << "2. Agregar contenido.\n";
        cout << "3. Agregar interés a un usuario.\n";
        cout << "4. Ver recomendaciones.\n";
        cout << "5. Agregar usuario.\n";
        cout << "6. Salir.\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore(); // con este podemos limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                // se crea la amistad
                string usuario1, usuario2;
                cout << "Ingrese el nombre del usuario: ";
                getline(cin, usuario1);
                cout << "Ingrese el nombre del amigo a agregar: ";
                getline(cin, usuario2);

                if (sistema.addFriend(usuario1, usuario2)) {
                    cout << "Se ha creado la amistad de " << usuario1 << " con " << usuario2 << ".\n";
                } else {
                    cout << "No se pudo crear la amistad. Verifique que ambos usuarios existan.\n";
                }
                break;
            }
            case 2: {
                // Agregar contenido
                string categoria, contenido;
                cout << "Ingrese el nombre de la categoría: ";
                getline(cin, categoria);
                cout << "Ingrese el contenido a agregar: ";
                getline(cin, contenido);

                sistema.addContent(categoria, contenido);
                cout << "Contenido agregado exitosamente.\n";
                break;
            }
            case 3: {
                // agregar interés a un usuario
                string usuario, categoria;
                cout << "Ingrese el nombre del usuario: ";
                getline(cin, usuario);
                cout << "Ingrese la categoría de interés: ";
                getline(cin, categoria);

                if (sistema.addInterest(usuario, categoria)) {
                    cout << "Se agregó " << categoria << " a los intereses de " << usuario << ".\n";
                } else {
                    cout << "No se pudo agregar el interés. Verifique que el usuario exista.\n";
                }
                break;
            }
            case 4: {
                // Ver recomendaciones
                string usuario;
                cout << "Ingrese el nombre del usuario: ";
                getline(cin, usuario);

                if (sistema.userExists(usuario)) {
                    vector<string> recomendaciones = sistema.recommendContent(usuario);
                    if (recomendaciones.empty()) {
                        cout << "No hay recomendaciones disponibles para " << usuario << ".\n";
                    } else {
                        cout << "Recomendaciones para " << usuario << ":\n";
                        for (const auto& contenido : recomendaciones) {
                            cout << "- " << contenido << "\n";
                        }
                    }
                } else {
                    cout << "El usuario no existe.\n";
                }
                break;
            }
            case 5: {
                // agregar usuario
                string usuario;
                cout << "Ingrese el nombre del usuario a agregar: ";
                getline(cin, usuario);

                if (sistema.addUser(usuario)) {
                    cout << "Usuario " << usuario << " agregado exitosamente.\n";
                } else {
                    cout << "El usuario ya existe.\n";
                }
                break;
            }
            case 6: {
                // salir del menú
                cout << "Saliendo del programa.\n";
                break;
            }
            default: {
                cout << "Opción inválida. Por favor, intente nuevamente.\n";
                break;
            }
        }
    }
}