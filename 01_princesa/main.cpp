#include <iostream>
#include <list>

using namespace std;

void alimentaLista(list<int>& participantes,int quantidade){
    for(int i = 0; i < quantidade; i++){
        participantes.push_back(i + 1);
    }
}

void imprimirLista(list<int> lista){
    for(auto elemento : lista){
        cout << elemento;
    }
    cout << "\n";
}


int main()
{

    int quantidade = 0;
    int escolhido = 0;
    int salto = 0;



    cout << "Informe o numero de participantes: ";
    cin >> quantidade;

    cout << "Informe o elemento inicial: ";
    cin >> escolhido;

    cout << "Informe o salto desejado: ";
    cin >> salto;

    list<int> participantes;

    alimentaLista(participantes,quantidade);

    imprimirLista(participantes);




    while(participantes.front() != escolhido){

        participantes.push_back(participantes.front());
        participantes.pop_front();
    }


    while(participantes.size() > salto){
        participantes.push_back(participantes.front());
        participantes.pop_front();
        participantes.pop_front();
        imprimirLista(participantes);
    }

    return 0;
}
