#include <iostream>
#include <string>
#include <algorithm>
#include "RecommendationSystem.h" // RecommendationSystem ya llama a las clases
using namespace std;

string readCleanInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);

    // Eliminar caracteres no imprimibles (ej. \n, \r) y espacios extra
    input.erase(remove(input.begin(), input.end(), '\r'), input.end()); // Quitar \r
    input.erase(remove(input.begin(), input.end(), '\n'), input.end()); // Quitar \n
    return input;
}


void showMenu(RecommendationSystem& sistema) {
    int opcion = 0;

    while (opcion != 8) {
        // Mostrar el menú de opciones
        cout << "\n==== MENU ====\n";
        cout << "1. Crear amistad.\n";
        cout << "2. Agregar contenido.\n";
        cout << "3. Agregar interes a un usuario.\n";
        cout << "4. Ver recomendaciones.\n";
        cout << "5. Agregar usuario.\n";
        cout << "6. Ver amigos de un usuario.\n"; // Nueva opción
        cout << "7. Sugerir nuevos amigos \n"; // Nueva opción
        cout << "8. Salir.\n";
        cout << "Ingrese una opcion: ";

        string opcion_str;
        getline(cin, opcion_str);

        try {
            opcion = stoi(opcion_str);
        } catch (invalid_argument& e) {
            cout << "Entrada invalida. Por favor, ingrese un numero.\n";
            opcion = 0; // Valor que no corresponde a ninguna opción
            continue; // Volver al inicio del ciclo
        }

        switch (opcion) {
            case 1: {
                // Crear amistad
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
                cout << "Ingrese el nombre de la categoria: ";
                getline(cin, categoria);
                cout << "Ingrese el contenido a agregar: ";
                getline(cin, contenido);


                sistema.addContent(categoria, contenido);
                cout << "Contenido agregado exitosamente.\n";
                break;
            }
            case 3: {
                // Agregar interés a un usuario
                string usuario, categoria;
                cout << "Ingrese el nombre del usuario: ";
                getline(cin, usuario);
                cout << "Ingrese la categoria de interes: ";
                getline(cin, categoria);

                if (sistema.addInterest(usuario, categoria)) {
                    cout << "Se agrego " << categoria << " a los intereses de " << usuario << ".\n";
                } else {
                    cout << "No se pudo agregar el interes. Verifique que el usuario exista.\n";
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
                // Agregar usuario
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
                // Ver amigos de un usuario
                string usuario;
                cout << "Ingrese el nombre del usuario: ";
                getline(cin, usuario);



                if (sistema.userExists(usuario)) {
                    vector<string> amigos = sistema.getFriends(usuario);
                    if (amigos.empty()) {
                        cout << usuario << " no tiene amigos.\n";
                    } else {
                        cout << "Amigos de " << usuario << ":\n";
                        for (const auto& amigo : amigos) {
                            cout << "- " << amigo << "\n";
                        }
                    }
                } else {
                    cout << "El usuario no existe.\n";
                }
                break;
            }
            case 7: {
                // Sugerir nuevos amigos
                string usuario;
                cout << "Ingrese el nombre del usuario: ";
                getline(cin, usuario);


                if (sistema.userExists(usuario)) {
                    vector<string> sugerencias = sistema.suggestFriends(usuario);
                    if (sugerencias.empty()) {
                        cout << "No hay sugerencias de nuevos amigos para " << usuario << ".\n";
                    } else {
                        cout << "Sugerencias de nuevos amigos para " << usuario << ":\n";
                        for (const auto& sugerido : sugerencias) {
                            cout << "- " << sugerido << "\n";
                        }
                    }
                } else {
                    cout << "El usuario no existe.\n";
                }
                break;
            }
            case 8: {
                break;
            }
            default: {
                cout << "Opción invalida. Por favor, intente nuevamente.\n";
                break;
            }
        }
    }
}
