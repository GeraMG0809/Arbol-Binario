#include<iostream>

template <class T>
class Nodo {
private:
    T* Elm;
    Nodo<T>* Izquierda;
    Nodo<T>* Derecha;

public:
    Nodo();
    Nodo(const T&);
    ~Nodo();

    T* getElmPun();
    T getElm();
    Nodo<T>*& getIzquierda();
    Nodo<T>*& getDerecha();

    void setElmPun(T*);
    void setElm(const T&);
    void SetDerecha(Nodo<T>*);
    void SetIzquierda(Nodo<T>*);
};

template <class T>
Nodo<T>::Nodo() : Elm(nullptr), Izquierda(nullptr), Derecha(nullptr) {}

template <class T>
Nodo<T>::Nodo(const T& elm) {
    Elm = new T(elm);
    Izquierda = nullptr;
    Derecha = nullptr;
}

template <class T>
Nodo<T>::~Nodo() {
    delete Elm;
}

template <class T>
T* Nodo<T>::getElmPun() {
    return Elm;
}

template <class T>
T Nodo<T>::getElm() {
    return *Elm;
}

template <class T>
Nodo<T>*& Nodo<T>::getIzquierda() {
    return Izquierda;
}

template <class T>
Nodo<T>*& Nodo<T>::getDerecha() {
    return Derecha;
}

template <class T>
void Nodo<T>::setElmPun(T* Puntero) {
    Elm = Puntero;
}

template <class T>
void Nodo<T>::setElm(const T& data) {
    if (Elm == nullptr) {
        Elm = new T(data);
    } else {
        *Elm = data;
    }
}

template <class T>
void Nodo<T>::SetDerecha(Nodo<T>* puntero) {
    Derecha = puntero;
}

template <class T>
void Nodo<T>::SetIzquierda(Nodo<T>* puntero) {
    Izquierda = puntero;
}
