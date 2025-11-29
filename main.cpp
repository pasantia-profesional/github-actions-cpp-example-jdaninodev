
#include "Tienda.h"
#include <iostream>
#include <limits>
using namespace std;

void mostrarMenu() {
    cout << "\n=== Menu Principal ===" << endl;
    cout << "1. Mostrar todos los productos" << endl;
    cout << "2. Buscar producto por ID" << endl;
    cout << "3. Crear nuevo producto" << endl;
    cout << "4. Actualizar producto" << endl;
    cout << "5. Eliminar producto" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Tienda tienda;
    tienda.inicializarProductos();
    cout << "Bienvenido al Sistema de Gestion de Tienda" << endl;
    int opcion;
    bool salir = false;
    while (!salir) {
        mostrarMenu();
        cin >> opcion;
        bool entradaInvalida = false;
        if (cin.fail()) {
            limpiarBuffer();
            cout << "Opcion invalida. Por favor ingrese un numero." << endl;
            entradaInvalida = true;
        }
        limpiarBuffer();
        if (!entradaInvalida) {
            switch (opcion) {
                case 1: {
                    tienda.mostrarTodosProductos();
                    break;
                }
                case 2: {
                    int id;
                    cout << "Ingrese el ID del producto: ";
                    cin >> id;
                    limpiarBuffer();
                    Producto* producto = tienda.leerProducto(id);
                    if (producto != nullptr) {
                        cout << "\nProducto encontrado:" << endl;
                        producto->mostrarInfo();
                    } else {
                        cout << "Producto no encontrado." << endl;
                    }
                    break;
                }
                case 3: {
                    int id, cantidad;
                    string nombre;
                    double precio;
                    cout << "Ingrese el ID del producto: ";
                    cin >> id;
                    limpiarBuffer();
                    cout << "Ingrese el nombre del producto: ";
                    getline(cin, nombre);
                    cout << "Ingrese el precio del producto: ";
                    cin >> precio;
                    limpiarBuffer();
                    cout << "Ingrese la cantidad del producto: ";
                    cin >> cantidad;
                    limpiarBuffer();
                    tienda.crearProducto(id, nombre, precio, cantidad);
                    break;
                }
                case 4: {
                    int id, cantidad;
                    string nombre;
                    double precio;
                    cout << "Ingrese el ID del producto a actualizar: ";
                    cin >> id;
                    limpiarBuffer();
                    cout << "Ingrese el nuevo nombre del producto: ";
                    getline(cin, nombre);
                    cout << "Ingrese el nuevo precio del producto: ";
                    cin >> precio;
                    limpiarBuffer();
                    cout << "Ingrese la nueva cantidad del producto: ";
                    cin >> cantidad;
                    limpiarBuffer();
                    tienda.actualizarProducto(id, nombre, precio, cantidad);
                    break;
                }
                case 5: {
                    int id;
                    cout << "Ingrese el ID del producto a eliminar: ";
                    cin >> id;
                    limpiarBuffer();
                    tienda.eliminarProducto(id);
                    break;
                }
                case 6: {
                    cout << "Gracias por usar el sistema. Adios!" << endl;
                    salir = true;
                    break;
                }
                default: {
                    cout << "Opcion invalida. Por favor seleccione una opcion del 1 al 6." << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
