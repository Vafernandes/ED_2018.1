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
    



    cout << "Informe o numero de participantes: ";
    cin >> quantidade;

    cout << "Informe o elemento inicial: ";
    cin >> escolhido;

    list<int> participantes;

    alimentaLista(participantes,quantidade);

    imprimirLista(participantes);

    //Define o participante inicial
    while(participantes.front() != escolhido){

        participantes.push_back(participantes.front());//adiciono o elemento do início da lista, na última posição da lista
        participantes.pop_front();//removo o elemento da primeira posição da lista
    }


    //Esse laço realiza a retirada de elementos com base no participante inicial
    while(participantes.size() > 1){
        participantes.push_back(participantes.front());
        participantes.pop_front();
        participantes.pop_front();
        imprimirLista(participantes);
    }

    return 0;
}
