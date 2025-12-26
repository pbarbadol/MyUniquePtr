# MyUniquePtr 🛠️

Implementación propia de un puntero inteligente (*Smart Pointer*) en C++, replicando el comportamiento y la eficiencia de `std::unique_ptr` de la librería estándar.

Este proyecto tiene como objetivo demostrar un entendimiento profundo de la gestión de memoria manual, el ciclo de vida de los objetos y las capacidades modernas de C++.

## 🎓 Motivación y Contexto

Este desarrollo nace como una iniciativa personal para revisitar y consolidar los pilares fundamentales de la ingeniería de software adquiridos durante mi **Grado en Ingeniería Informática**.

Es, en parte, un tributo técnico a dos de las asignaturas que más impacto tuvieron en mi formación y a las que guardo especial cariño:
*   **Introducción a la Programación**: Donde aprendí la lógica detrás del código.
*   **Estructura de Datos**: Donde comprendí la importancia de gestionar la memoria y los recursos eficientemente.

Implementar esto desde cero ("from scratch") es la mejor manera de demostrar que se entiende lo que ocurre "bajo el capó" de las herramientas que usamos a diario.

## ⚙️ Características Técnicas (Checklist)

El código cumple con los estándares de **C++ Moderno (C++11/14/17)**:

*   **Patrón RAII (Resource Acquisition Is Initialization)**: Garantiza que la memoria dinámica se libere automáticamente en el destructor cuando el objeto sale del ámbito (*scope*), evitando fugas de memoria (*memory leaks*).
*   **Templates (Programación Genérica)**: La clase es capaz de manejar cualquier tipo de dato o clase personalizada.
*   **Semántica de Movimiento (Move Semantics)**:
    *   Implementación de *Move Constructor* y *Move Assignment Operator*.
    *   Permite transferir la propiedad del recurso de manera eficiente sin realizar copias costosas o peligrosas.
*   **Prohibición de Copia**: Siguiendo la filosofía de un puntero "único", se han suprimido (`= delete`) el constructor de copia y el operador de asignación por copia para evitar errores de *double free*.
*   **Sobrecarga de Operadores**: Soporte transparente para los operadores de desreferencia (`*`) y acceso a miembros (`->`), comportándose como un puntero nativo.
*   **Variadic Templates**: Implementación de un *helper* `my_make_unique` que utiliza *Perfect Forwarding* para construir objetos de forma segura y limpia.

## 🚀 Cómo ejecutar el proyecto

Este proyecto no tiene dependencias externas, solo requiere un compilador compatible con C++ moderno (GCC, Clang, MSVC).

```bash
# 1. Clonar el repositorio
git clone https://github.com/TU_USUARIO/MyUniquePtr.git
cd MyUniquePtr

# 2. Compilar (ejemplo con g++)
g++ main.cpp -o main

# 3. Ejecutar
./main

// Creación segura con el helper (sin usar 'new' explícitamente)
auto ptr = my_make_unique<std::string>("Hola Mundo");

// Uso como puntero normal
std::cout << *ptr << std::endl; 
std::cout << ptr->length() << std::endl;

// Transferencia de propiedad (el puntero original queda vacío)
auto ptr2 = std::move(ptr);