#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "Node.h"
#include "Registro.h"
using namespace std;

template<typename T>
class ListaCircular{
    private:
        Nodo<T> * head;
    public:

        ListaCircular(){
            this->head = nullptr;
        }
        Nodo<T>* getHead(){
            return this->head;
        } 
        void pushBack(T value){

            if(!this->head){
                this->head=new Nodo<T>(value);
                this->head->m_sig=this->head;
            }
            
            else{

                Nodo<T>*aux=this->head;

                while(aux->m_sig!=this->head){
                    aux=aux->m_sig;
                }

                aux->m_sig=new Nodo<T>(value);
                aux->m_sig->m_sig=this->head;
            
            }
            
        }

        void recursive_push_back(T data)
        {
            if (!this->head)
            {
                this->head = new Nodo<T>(data);
                this->head->m_sig = this->head; 
            }
            else
            {
                recursive_push_back(data,this->head);
            }
        }

        void recursive_push_back(T data, Nodo<T>* & node)
        {
            if (node->m_sig != this->head)
            {
                recursive_push_back(data, node->m_sig);
            }
            else
            {
                Nodo<T> * new_node = new Nodo<T>(data);
                node->m_sig = new_node;
                new_node->m_sig = this->head;
            }
        }


        void push_front(T data)
        {
            if (!this->head)
            {
                this->head = new Nodo<T>(data);
                this->head->m_sig = this->head;
            }
            else
            {
                Nodo<T> * new_node = new Nodo<T>(data);
                Nodo<T> * aux = this->head;
                for(;aux->m_sig != this->head;aux = aux->m_sig);
                aux->m_sig = new_node;
                new_node->m_sig = this->head;
                this->head = new_node;
            }
            
        
        }

        void recursive_push_front(T data)
        {
            if (!this->head)
            {
                this->head = new Nodo<T>(data);
                this->head->m_sig = this->head;
            }
            else
            {
                recursive_push_front(data, this->head);
            }
        }

        void recursive_push_front(T data, Nodo<T>* & node)
        {
            if (node->m_sig != this->head)
            {
                recursive_push_front(data,node->m_sig);
            }
            else
            {
                Nodo<T> * new_node = new Nodo<T>(data);
                node->m_sig = new_node;
                new_node->m_sig = this->head;
                this->head = new_node;
            }
        }

        void insert(T data, int pos)
        {
            if(pos == 0)
            {
                push_front(data);
            }
            else
            {
                Nodo<T> * new_node = new Nodo<T>(data);
                Nodo<T> * aux = this->head;
                int c {1};
                while(c != pos)
                {
                    aux = aux->m_sig;
                    c++; 
                }
                new_node->m_sig = aux->m_sig;
                aux->m_sig = new_node;
            }
        }

        void add_alphabet(T data)
        {
            if (!this->head) this->pushBack(data);
            else
            {
                Nodo<T> * new_node = new Nodo<T>(data);
                Nodo<T> * aux = this->head;
                if(aux->m_dato > data)
                {
                    push_front(data);
                    return;
                }
                aux = aux->m_sig;
                for(;aux->m_sig != this->head; aux = aux->m_sig)
                {   
                    if (aux->m_dato > data) break;
                }
                if(aux->m_dato < data)
                {
                    aux = aux->m_sig;
                }
                new_node->m_sig = aux->m_sig;
                aux->m_sig = new_node;
            }
        }
        void print(){

            if(!this->head){
                return;
            }
            Nodo<T>*aux=this->head->m_sig;
            cout<<this->head->m_dato << " - ";
            while(aux!=this->head){
                cout << aux->m_dato<<" - ";
                aux = aux->m_sig;

            }
            cout<<endl;
            
        }
    
        void printRecursive(Nodo<T>*aux){

            if(!aux){
                return;
            }

            cout<<aux->m_dato<<" - ";
            aux=aux->m_sig;
            if(aux!=this->head){
                printRecursive(aux);
            }
            return;



        }
        void printRecursive(){
            printRecursive(this->head);
        }    
    
        bool Find(T value){

            if(!this->head){
                return false;
            }

            Nodo<T>*aux=this->head->m_sig;
            while(aux!=this->head){
                if(aux->m_dato==value){
                    return true;
                }
                aux=aux->m_sig;
            }
            return (this->head->m_dato==value);

        }

        bool FindRecursive(Nodo<T>*aux,T num){
            if(aux == this->head){
                return false; 
            }
            else if(aux->m_dato == num){
                return true;
            }
            return FindRecursive(aux->m_sig, num);
        }
        bool FindRecursive(T num){
            if (!this->head) return false;
            else if (this->head->m_dato == num) return true;
            else { return FindRecursive(this->head->m_sig,num); }
        }

        
        int max()
        {
            Nodo<T>*aux = this->head;
            int max {0};
            for(;aux->m_sig != this->head;aux = aux->m_sig)
            {
                if (aux->m_dato > max)
                {
                    max = aux->m_dato;
                }
            }
            if(aux->m_dato > max)
            {
                max = aux->m_dato;
            }
            return max;

        }

        int recursive_max()
        {
            if(!this->head) return 0;
            int tmp {INT16_MIN};
            if (this->head->m_dato > tmp)
            {
                tmp = this->head->m_dato;
            } 
            return recursive_max(this->head->m_sig,tmp); 
        }

        int recursive_max(Nodo<T> * node,int tmp)
        {

            if(node != this->head)
            {
                if (node->m_dato > tmp)
                {
                    tmp = node->m_dato;
                }
                return recursive_max(node->m_sig,tmp);
            }
            return tmp;
        }



};

#endif