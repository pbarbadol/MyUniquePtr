#include <iostream>
#include <string>
#include <utility>
#include "MyUniquePtr.h"

//Clase de ejemplo para probar MyUniquePtr.h
class Persona {
    public:
        Persona(std::string nombre, int edad) : nombre_(nombre), edad_(edad) {
            std::cout << "  [CTOR]" << nombre_ << " (" << edad_ << ")" << std::endl;
        }

        ~Persona() {
            std::cout << "  [DTOR] " << nombre_ << " ha sido liberado.\n";
        }
        void presentarse() const {
            std::cout << "  Hola, soy " << nombre_ << " y tengo " << edad_ << " anios.\n";
        }

    private:
        std::string nombre_ = "No se ha establecido un nombre";
        int edad_ = 0;

    };


    int main() {
    std::cout << "=== Proyecto MyUniquePtr (C++11/14 Style) ===\n\n";

    // 1. Uso básico con make_unique (Variadic Templates en acción)
    std::cout << "1. Creando puntero con my_make_unique:\n";
    auto p1 = my_make_unique<Persona>("Pablo", 23);
    p1->presentarse();

    // 2. Semántica de Movimiento
    std::cout << "\n2. Transfiriendo propiedad (Move Semantics):\n";
    MyUniquePtr<Persona> p2 = std::move(p1);
    
    if (p1.get() == nullptr) std::cout << "  p1 es nulo (correcto).\n";
    if (p2.get() != nullptr) std::cout << "  p2 tiene el objeto.\n";
    
    p2->presentarse();

    // 3. Array de punteros (Polimorfismo con Templates)
    std::cout << "\n3. Destrucción automatica al salir del scope:\n";
    {
        auto p3 = my_make_unique<Persona>("Temporal", 99);
        p3->presentarse();
        std::cout << "  (Saliendo del bloque scope...)\n";
    } // p3 muere aquí

    std::cout << "\n=== Fin del programa ===\n";
    return 0;
}