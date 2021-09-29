#include <iostream>
#include <fstream>
#include "CircularList.h"

//Josue Manuel Sumare Uscca
//Uberto Garcia Caceres
//Moises Alejandro Casaverde Aleman

using namespace std;

/*
ListaCircular<std::string> guardar(std::string file_name){
    
    std::ifstream file;
    file.open (file_name.c_str());
    ListaCircular<std::string> list;
    string word;
    while (file >> word)
    {
        list.pushBack(word);
    }
    return list;
}
*/
int main(){

    ListaCircular<int> test;
    
    test.add_alphabet(8);
    test.add_alphabet(4);
    test.add_alphabet(1);
    test.add_alphabet(7);
    test.add_alphabet(85);
    test.add_alphabet(1);


    cout << test.recursive_max() << '\n';
    test.print();
    cout<<test.FindRecursive(7)<<" ";

    ListaCircular<std::string> list;
    list.add_alphabet("hello");
    list.add_alphabet("zucc");
    list.add_alphabet("banana");
    list.add_alphabet("friend");
    list.add_alphabet("apple");
    list.add_alphabet("aaaaaaaaa");
    list.add_alphabet("sddd");


    list.print();


    return 0;
}