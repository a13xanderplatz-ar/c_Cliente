#include "c_Cliente.hpp"

char* c_Cliente::copiarString(const char* str) {
    if (str == nullptr) return nullptr;
    int len = 0;
    while (str[len] != '\0') len++;
    char* nuevo = new char[len + 1];
    for (int i = 0; i < len; i++) {
        nuevo[i] = str[i];
    }
    nuevo[len] = '\0';
    return nuevo;
}

c_Cliente::c_Cliente(int _id, const char* _nombre, const char* _direccion, const char* _telefono) {
    id = _id;
    nombre = copiarString(_nombre);
    direccion = copiarString(_direccion);
    telefono = copiarString(_telefono);
}

c_Cliente::~c_Cliente() {
    delete[] nombre;
    delete[] direccion;
    delete[] telefono;
}

c_Cliente::c_Cliente(const c_Cliente& otro) {
    id = otro.id;
    nombre = copiarString(otro.nombre);
    direccion = copiarString(otro.direccion);
    telefono = copiarString(otro.telefono);
}

c_Cliente& c_Cliente::operator=(const c_Cliente& otro) {
    if (this != &otro) {
        delete[] nombre;
        delete[] direccion;
        delete[] telefono;

        id = otro.id;
        nombre = copiarString(otro.nombre);
        direccion = copiarString(otro.direccion);
        telefono = copiarString(otro.telefono);
    }
    return *this;
}

int c_Cliente::getId() const { 
    return id; 
}

const char* c_Cliente::getNombre() const { 
    return nombre; 
}

const char* c_Cliente::getDireccion() const { 
    return direccion; 
}

const char* c_Cliente::getTelefono() const { 
    return telefono; 
}

void c_Cliente::setId(int _id) { 
    id = _id; 
}

void c_Cliente::setNombre(const char* _nombre) {
    delete[] nombre;
    nombre = copiarString(_nombre);
}

void c_Cliente::setDireccion(const char* _direccion) {
    delete[] direccion;
    direccion = copiarString(_direccion);
}

void c_Cliente::setTelefono(const char* _telefono) {
    delete[] telefono;
    telefono = copiarString(_telefono);
}