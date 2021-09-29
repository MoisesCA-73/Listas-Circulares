#ifndef NODE_H
#define NODE_H

template<typename T>
class Nodo
{
    public:

        T m_dato;
        Nodo<T> * m_sig;

    public:
        Nodo(T d){
            m_dato = d; 
            m_sig = nullptr;
        } 
};

#endif