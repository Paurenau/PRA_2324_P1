#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;  // Primer nodo
    int n;           // Tamaño de la lista

public:
    // --- Constructor ---
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    // --- Destructor ---
    ~ListLinked() override {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }

    // --- Insertar en una posición ---
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw out_of_range("Posición fuera de rango");

        if (pos == 0) {
            first = new Node<T>(e, first); // Inserta al inicio
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

            prev->next = new Node<T>(e, prev->next); // Inserta en medio o final
        }
        n++;
    }

    // --- Añadir al final ---
    void append(T e) override {
        insert(n, e);
    }

    // --- Añadir al principio ---
    void prepend(T e) override {
        insert(0, e);
    }

    // --- Eliminar por posición ---
    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw out_of_range("Posición fuera de rango");

        Node<T>* toDelete;
        T value;

        if (pos == 0) {
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

            toDelete = prev->next;
            prev->next = toDelete->next;
        }

        value = toDelete->data;
        delete toDelete;
        n--;
        return value;
    }

    // --- Obtener elemento por posición ---
    T get(int pos) const override {
        if (pos < 0 || pos >= n)
            throw out_of_range("Posición fuera de rango");

        Node<T>* current = first;
        for (int i = 0; i < pos; i++)
            current = current->next;

        return current->data;
    }

    // --- Buscar elemento ---
    int search(T e) const override {
        Node<T>* current = first;
        int i = 0;
        while (current != nullptr) {
            if (current->data == e)
                return i;
            current = current->next;
            i++;
        }
        return -1;
    }

    // --- Comprobar si está vacía ---
    bool empty() const override {
        return n == 0;
    }

    // --- Tamaño ---
    int size() const override {
        return n;
    }

    // --- Imprimir lista ---
    friend ostream& operator<<(ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        out << "[";
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr)
                out << ", ";
            current = current->next;
        }
        out << "]";
        return out;
    }
};

#endif
