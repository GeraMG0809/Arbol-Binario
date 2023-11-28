#include"Nodo.cpp"
template <class T>
class ArbolBinario {
private:
    Nodo<T>* raiz;

    void insertaPriv(Nodo<T>*& , T& );
    void eliminaPriv(Nodo<T>*& );
    Nodo<T>*& localizarPriv(Nodo<T>*& , T& );
    Nodo<T>* menorPriv(Nodo<T>* ) const;
    Nodo<T>* mayorPriv(Nodo<T>* ) const;
    bool es_Hoja(Nodo<T>* ) const;
    int altura(Nodo<T>* ) const;
    void recorrido_inorder_Priv(Nodo<T>* );
    void recorrido_preorder_Priv(Nodo<T>* );
    void recorrido_postorder_Priv(Nodo<T>* );

public:
    ArbolBinario();
    void inicializa();
    bool vacio() const;
    void inserta(T& data);
    void elimina(T& data);
    Nodo<T>* localiza(T& data);
    Nodo<T>* menorPublic() const;
    Nodo<T>* mayorPublic() const;
    int getAltura() const;
    void preOrder();
    void inOrder();
    void postOrder();
};

template <class T>
ArbolBinario<T>::ArbolBinario() {
    raiz = nullptr;
}

template <class T>
void ArbolBinario<T>::inicializa() {
    raiz = nullptr;
}

template <class T>
bool ArbolBinario<T>::vacio() const {
    return raiz == nullptr;
}

template <class T>
void ArbolBinario<T>::insertaPriv(Nodo<T>*& pos, T& elem) {
    if (pos == nullptr) {
        pos = new Nodo<T>(elem);
    } else {
        if (elem < pos->getElm()) {
            insertaPriv(pos->getIzquierda(), elem);
        } else {
            insertaPriv(pos->getDerecha(), elem);
        }
    }
}


template <class T>
void ArbolBinario<T>::eliminaPriv(Nodo<T>*& pos) {
    if (pos == nullptr) {
        return;
    }
    if (pos->getIzquierda() == nullptr && pos->getDerecha() == nullptr) {
        delete pos;
        pos = nullptr;
    } else if (pos->getIzquierda() == nullptr) {
        Nodo<T>* temp = pos;
        pos = pos->getDerecha();
        delete temp;
    } else if (pos->getDerecha() == nullptr) {
        Nodo<T>* temp = pos;
        pos = pos->getIzquierda();
        delete temp;
    } else {
        Nodo<T>* pos_reemplazo = menorPriv(pos->getDerecha());
        pos->setElm(pos_reemplazo->getElm());
        eliminaPriv( pos_reemplazo);
    }
}

template <class T>
Nodo<T>*& ArbolBinario<T>::localizarPriv(Nodo<T>*& arbol, T& elem) {
    if (arbol == nullptr || arbol->getElm() == elem) {
        return arbol;
    }
    if (elem < arbol->getElm()) {
        return localizarPriv(arbol->getIzquierda(), elem);
    } else {
        return localizarPriv(arbol->getDerecha(), elem);
    }
}

template <class T>
Nodo<T>* ArbolBinario<T>::menorPriv(Nodo<T>* arbol) const {
    if (arbol == nullptr) {
        return nullptr;
    }
    while (arbol->getIzquierda() != nullptr) {
        arbol = arbol->getIzquierda();
    }
    return arbol;
}

template <class T>
Nodo<T>* ArbolBinario<T>::mayorPriv(Nodo<T>* arbol) const {
    if (arbol == nullptr) {
        return nullptr;
    }
    while (arbol->getDerecha() != nullptr) {
        arbol = arbol->getDerecha();
    }
    return arbol;
}

template <class T>
bool ArbolBinario<T>::es_Hoja(Nodo<T>* arbol) const {
    return arbol->getIzquierda() == nullptr && arbol->getDerecha() == nullptr;
}

template <class T>
int ArbolBinario<T>::altura(Nodo<T>* arbol) const {
    if (arbol == nullptr) {
        return -1;
    }
    int izquierda = altura(arbol->getIzquierda());
    int derecha = altura(arbol->getDerecha());
    if (izquierda > derecha) {
        return izquierda + 1;
    } else {
        return derecha + 1;
    }
}

template <class T>
void ArbolBinario<T>::recorrido_inorder_Priv(Nodo<T>* arbol) {
    if (arbol) {
        recorrido_inorder_Priv(arbol->getIzquierda());
        std::cout << "[" << arbol->getElm() << "]";
        recorrido_inorder_Priv(arbol->getDerecha());
    }
}

template <class T>
void ArbolBinario<T>::recorrido_preorder_Priv(Nodo<T>* arbol) {
    if (arbol) {
        std::cout << "[" << arbol->getElm() << "]";
        recorrido_preorder_Priv(arbol->getIzquierda());
        recorrido_preorder_Priv(arbol->getDerecha());
    }
}

template <class T>
void ArbolBinario<T>::recorrido_postorder_Priv(Nodo<T>* arbol) {
    if (arbol) {
        recorrido_postorder_Priv(arbol->getIzquierda());
        recorrido_postorder_Priv(arbol->getDerecha());
        std::cout << "[" << arbol->getElm() << "]";
    }
}

template <class T>
void ArbolBinario<T>::inserta(T& data) {
    insertaPriv(raiz, data);
}

template <class T>
void ArbolBinario<T>::elimina(T& data) {
    eliminaPriv(localizarPriv(raiz, data));
}

template <class T>
Nodo<T>* ArbolBinario<T>::localiza(T& data) {
    return localizarPriv(raiz, data);
}

template <class T>
Nodo<T>* ArbolBinario<T>::menorPublic() const {
    return menorPriv(raiz);
}

template <class T>
Nodo<T>* ArbolBinario<T>::mayorPublic() const {
    return mayorPriv(raiz);
}

template <class T>
int ArbolBinario<T>::getAltura() const {
    return altura(raiz);
}

template <class T>
void ArbolBinario<T>::preOrder() {
    recorrido_preorder_Priv(raiz);
}

template <class T>
void ArbolBinario<T>::inOrder() {
    recorrido_inorder_Priv(raiz);
}

template <class T>
void ArbolBinario<T>::postOrder() {
    recorrido_postorder_Priv(raiz);
}