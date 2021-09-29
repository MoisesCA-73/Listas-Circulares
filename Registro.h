#include<iostream>
using namespace std;
class Registro{

    private:
        string cadena;
        int contador;

    public:
        Registro(){
            this->cadena=" ";
            this->contador=0;
        }

        Registro(string cadena,int contador){
            this->cadena=cadena;
            this->contador=contador;
        }

        string getCadena() const{
            return this->cadena;
        }

        int getContador() const{
            return this->contador;
        }
        void setCadena(string cadena){
            this->cadena=cadena;
        }

        void setCadena(int contador){
            this->contador=contador;
        }



};