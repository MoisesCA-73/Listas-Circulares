#include <iostream>
#include <fstream>
//Josue 973672214
//
//Moises 962936628
/*
UNANSE!!!!!!!!!!!!!!!!!
https://meet.google.com/zzt-qufo-zba?authuser=1
*/

using namespace std;

#include "Node.h"
#include "CircularList.h"

ListaCircular<string> guardar(std::string file_name){
    
    std::ifstream file;
    file.open (file_name.c_str());
    ListaCircular<string> list;
    string word;
    while (file >> word)
    {
        list.pushBack(word);
    }
    return list;
}

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
    cout<<test.Find(7)<<" ";

    ListaCircular<std::string> list;
    list.add_alphabet("hello");
    list.add_alphabet("zucc");
    list.add_alphabet("banana");
    list.add_alphabet("friend");
    list.add_alphabet("apple");

    list.print();


    return 0;
}