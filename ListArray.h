#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <stdexcept>

#define MINSIZE 10  // tamaño inicial mínimo del array

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;   // puntero al array dinámico
    int n;    // número de elementos actuales
    int max;  // capacidad del array

    void resize(int new_capacity) {
        T* new_arr = new T[new_capacity];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_capacity;
    }

public:
    // Constructor
    ListArray() {
        arr = new T[MINSIZE];
        n = 0;
        max = MINSIZE;
    }

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Inserta el elemento e en la posición pos
    void insert(int pos, T e) {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición fuera de rango");

        if (n == max)
            resize(2 * max);

        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = e;
        n++;
    }

    // Inserta al final
    void append(T e) {
        insert(n, e);
    }

    // Inserta al principio
    void prepend(T e) {
        insert(0, e);
    }

    // Elimina y devuelve el elemento en pos
    T remove(int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");

        T eliminado = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        return eliminado;
    }

    // Devuelve el elemento en pos
    T get(int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");
        return arr[pos];
    }

    // Busca la posición del elemento e
    int search(T e) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e)
                return i;
        }
        return -1;
    }

    // Devuelve true si está vacía
    bool empty() {
        return n == 0;
    }

    // Devuelve el número de elementos
    int size() {
        return n;
    }
};

#endif
