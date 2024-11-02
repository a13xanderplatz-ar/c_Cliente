// Hello World program 
// ANSI Codes
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#include <iostream>


//#comandos macro
#ifdef _WIN32
    //#include <windows.h>//solo para windows aunque lo comente o borre igual va funcionar
    #define CLEAR_COMMAND "cls"//comando para limpiar pantlla
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>//ayuda en el desenpeño de la pantalla 
    #include <termios.h>
    #define CLEAR_COMMAND "clear"//comando para limpiar pantalla
#endif


#include <iostream>
#include "c_Cliente.hpp"

int main() {
    int id;
    char* nombre;
    char* direccion;
    char* telefono;
    char buffer[256]; // Buffer temporal para almacenar la entrada del usuario

    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> id;
    std::cin.ignore();  // Ignorar el salto de línea residual

    // Nombre
    std::cout << "Ingrese el nombre del cliente: ";
    std::cin.getline(buffer, 256);
    int lenNombre = 0;
    while (buffer[lenNombre] != '\0') lenNombre++; // Calcular longitud manualmente
    nombre = new char[lenNombre + 1];
    for (int i = 0; i < lenNombre; i++) {
        nombre[i] = buffer[i];
    }
    nombre[lenNombre] = '\0'; // Agregar el carácter nulo

    // Dirección
    std::cout << "Ingrese la direccion del cliente: ";
    std::cin.getline(buffer, 256);
    int lenDireccion = 0;
    while (buffer[lenDireccion] != '\0') lenDireccion++; // Calcular longitud manualmente
    direccion = new char[lenDireccion + 1];
    for (int i = 0; i < lenDireccion; i++) {
        direccion[i] = buffer[i];
    }
    direccion[lenDireccion] = '\0';

    // Teléfono
    std::cout << "Ingrese el telefono del cliente: ";
    std::cin.getline(buffer, 256);
    int lenTelefono = 0;
    while (buffer[lenTelefono] != '\0') lenTelefono++; // Calcular longitud manualmente
    telefono = new char[lenTelefono + 1];
    for (int i = 0; i < lenTelefono; i++) {
        telefono[i] = buffer[i];
    }
    telefono[lenTelefono] = '\0';

    // Crear un cliente con los datos ingresados
    c_Cliente* cliente1 = new c_Cliente(id, nombre, direccion, telefono);

    // Mostrar la información del cliente
    std::cout << "\nInformacion del Cliente:\n";
    std::cout << "ID: " << cliente1->getId() << std::endl;
    std::cout << "Nombre: " << cliente1->getNombre() << std::endl;
    std::cout << "Direccion: " << cliente1->getDireccion() << std::endl;
    std::cout << "Telefono: " << cliente1->getTelefono() << std::endl;

    // Liberar la memoria reservada para nombre, direccion, y telefono
    delete[] nombre;
    delete[] direccion;
    delete[] telefono;

    // Liberar la memoria para cliente1
    delete cliente1;

    return 0;
}


