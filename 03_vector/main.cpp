#include <iostream>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
            //this->reserve(2 * _capacitade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int size(){
        return this->_size;
    }
    int capacity(){
        return this->_capacidade;
    }

    void reserve(int novaCapacidade){
        if(this->_capacidade < novaCapacidade)//A nova capacidade tem que ser maior que a capacidade existente,para evitar perda de dados

            return;

        int * novosElementos = new int[this->_size * 2];//Esse vetor 'novosElementos' irá salva os dados existentes no vetor
        // e multiplicando o size por * 2, significa que o vetor irá crescer mais

        for(int i = 0; i < this->_size; i++){
            novosElementos[i] = this->_data[i];//Atribuo os valores contidos em data no vetor de novosElementos
        }

        this->_data = novosElementos;//atualizo a capacidade

    }


};

#include <vector>
int main()
{

    Vetor pivet(5);

    pivet.push_back(8);
    pivet.push_back(2);
    pivet.push_back(1);

    for(auto p : pivet){
        cout << p << " ";
    }
    cout << endl;

    cout << "O elemento do índice[2] é: " << pivet.at(2);
    cout << endl;
    pivet.at(2) = 9;

    cout << "capacidade: " << pivet.capacity();
    cout << " size: " << pivet.size();
    cout << endl;
    for(auto p : pivet){
        cout << p << " ";
    }
    cout << endl;

    pivet.reserve(100);

    cout << "Nova capacidade: " << pivet.capacity() << endl;


//    int x = 3;
//    int y = 2;
//    x = y;
//    int z = x;
//    //lvalue & significa referencia
//    int& a = x;

    return 0;
}
