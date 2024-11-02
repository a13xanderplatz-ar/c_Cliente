#ifndef C_CLIENTE_HPP
#define C_CLIENTE_HPP

class c_Cliente {
private:
    int id;
    char* nombre;
    char* direccion;
    char* telefono;

    // Función auxiliar para copiar strings
    char* copiarString(const char* str);

public:
    // Constructor
    c_Cliente(int _id, const char* _nombre, const char* _direccion, const char* _telefono);

    // Destructor
    ~c_Cliente();

    // Constructor de copia
    c_Cliente(const c_Cliente& otro);

    // Operador de asignación
    c_Cliente& operator=(const c_Cliente& otro);

    // Getters
    int getId() const;
    const char* getNombre() const;
    const char* getDireccion() const;
    const char* getTelefono() const;

    // Setters
    void setId(int _id);
    void setNombre(const char* _nombre);
    void setDireccion(const char* _direccion);
    void setTelefono(const char* _telefono);
};

#endif