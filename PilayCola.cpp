#include <iostream>

using namespace std;

struct Nodo {
	
    int valor;
    Nodo* Siguiente;
};

void insertarPila(Nodo*& pila, int n) {
	
    Nodo* nuevo = new Nodo();
    nuevo->valor = n;
    nuevo->Siguiente = pila;
    pila = nuevo;
    cout << endl << "El elemento ha sido agregado a la pila" << endl;
}

void eliminarPila(Nodo*& pila, int& n) {
	
    Nodo* aux = pila;
    n = aux->valor;
    pila = aux->Siguiente;
    delete aux;
}

void mostrarPila(Nodo* pila) {
	
    Nodo* muestra = pila;
    while (muestra != NULL) {
        cout << muestra->valor << " -> ";
        muestra = muestra->Siguiente;
    }
    
}

void insertarCola(Nodo*& inicio, Nodo*& fin, int n) {
	
    Nodo* nuevo = new Nodo();
    nuevo->valor = n;
    nuevo->Siguiente = NULL;

    if (inicio == NULL) {
    	
        inicio = nuevo;
        fin = nuevo;
    } else {
    	
        fin->Siguiente = nuevo;
        fin = nuevo;
    }
    cout << endl << "El elemento ha sido agregado a la cola" << endl;
}

void eliminarCola(Nodo*& inicio, int& n) {
	
    Nodo* aux = inicio;
    n = aux->valor;
    inicio = aux->Siguiente;
    delete aux;
}

void mostrarCola(Nodo* inicio) {
	
    Nodo* muestra = inicio;
    while (muestra != NULL) {
        cout << muestra->valor << " -> ";
        muestra = muestra->Siguiente;
    }
    
}

int main() {
	
    Nodo* pila = NULL;
    Nodo* colaInicio = NULL;
    Nodo* colaFin = NULL;
    int opcion;
    int dato;

    do {
    	
    	cout << endl << "------ Menu principal -------" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Trabajar con Pila" << endl;
        cout << "2. Trabajar con Cola" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        if (opcion == 1) {
        	
            cout << "\nMenu con Pila:" << endl;
            do {
            	
                cout << endl << "1. Insertar" << endl;
                cout << "2. Eliminar" << endl;
                cout << "3. Mostrar" << endl;
                cout << "4. Volver al menu principal" << endl;
                cin >> opcion;

                switch (opcion) {
                	
                    case 1:
                    	
                        cout << endl << "Ingrese un numero: ";
                        cin >> dato;
                        insertarPila(pila, dato);
                        break;
                        
                    case 2:
                    	
                        if (pila != NULL) {
                        	
                            eliminarPila(pila, dato);
                            cout << endl<< "El numero " << dato << " ha sido eliminado" << endl;
                        } else {
                        	
                            cout << endl << "La pila esta vacia." << endl;
                        }
                        break;
                        
                    case 3:
                    	
                        if (pila != NULL) {
                        	
                            mostrarPila(pila);
                        } else {
                        	
                            cout << endl << "La pila esta vacia" << endl;
                        }
                        break;
                }
            } while (opcion != 4);
        } else if (opcion == 2) {
        	
            cout << "\nMenu con Cola:" << endl;
            do {
            	
                cout << endl << "1. Insertar" << endl;
                cout << "2. Eliminar" << endl;
                cout << "3. Mostrar" << endl;
                cout << "4. Volver al menu principal" << endl;
                cin >> opcion;

                switch (opcion) {
                	
                    case 1:
                    	
                        cout << endl << "Ingrese un numero: ";
                        cin >> dato;
                        insertarCola(colaInicio, colaFin, dato);
                        break;
                        
                    case 2:
                    	
                        if (colaInicio != NULL) {
                            eliminarCola(colaInicio, dato);
                            cout << endl << "El numero " << dato << " ha sido eliminado" << endl;
                        } else {
                            cout << endl << "La cola esta vacia." << endl;
                        }
                        break;
                        
                    case 3:
                    	
                        if (colaInicio != NULL) {
                            mostrarCola(colaInicio);
                        } else {
                            cout << endl << "La cola esta vacia" << endl;
                        }
                        break;
                }
            } while (opcion != 4);
        }
    } while (opcion != 3);

    return 0;
}

