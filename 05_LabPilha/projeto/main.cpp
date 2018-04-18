#include "ed_base.h"
#include "ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;



const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';


void showMat(matchar& mat, vector<Par> pilha, Par inicio, Par fim){
    mat_draw(mat);
    for(Par par : pilha)
        mat_focus(par, 'c');
    if(pilha.size() > 0)
        mat_focus(pilha.back(), 'k');
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
}


vector<Par> getNeib(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
//    vizinhos.push_back(Par(par.l - 1, par.c - 1));
//    vizinhos.push_back(Par(par.l - 1, par.c + 1));
//    vizinhos.push_back(Par(par.l + 1, par.c + 1));
//    vizinhos.push_back(Par(par.l + 1, par.c - 1));
    return vizinhos;
}

int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : getNeib(par))
        if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
            cont++;
    return cont;
}

vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

void furar(matchar &mat, Par par){
    if(!mat.equals(par, PAREDE) || countOpen(mat, par) > 1)
        return;
    mat.get(par) = ABERTO;
    for(Par vizinho : shuffle(getNeib(par)))
        furar(mat, vizinho);
}

bool findPath(matchar& mat, Par inicio, Par final){
    vector<Par> pilha;
    pilha.push_back(inicio);
    mat.get(inicio) = EMBUSCA;

    while(pilha.size() != 0){
        Par topo = pilha.back();
        if(topo == final){
            showMat(mat, pilha, inicio, final);
            ed_show();
            return true;
        }
        vector<Par> viz_abertos;
        showMat(mat, pilha, inicio, final);
        for(Par par : getNeib(topo)){
            if(mat.get(par) == ABERTO){
                viz_abertos.push_back(par);
                mat_focus(par, 'r');
            }
        }
        ed_show();
        if(viz_abertos.size() == 0){
            pilha.pop_back();
            showMat(mat, pilha, inicio, final);
            ed_show();
        }else{
            Par escolhido = viz_abertos[rand() % viz_abertos.size()];
            mat.get(escolhido) = EMBUSCA;
            pilha.push_back(escolhido);
            showMat(mat, pilha, inicio, final);
            ed_show();
        }
    }
    //Mostra a matriz
    showMat(mat, pilha, inicio, final);
    ed_show();
    return false;
}

//verifique se posso furar
bool furar_lab(matchar& mat, Par p){
    int cont = 0;
    if(!mat.equals(p,PAREDE)){
        return false;
    }for(auto &vizinho : getNeib(p)){
        if(mat.equals(vizinho,PAREDE)){
            cont++;
        }
    }
    return cont >= 3;//pois ele precisa testar as posições que poderão ser furadas
}

//rand
int aleatorio(int escolhido){
    return rand() % escolhido;
}

void showLab(matchar& mat, vector<Par> pilha){
    mat_draw(mat);
    vector<Par> auxiliar;
    while (pilha.size() != 0) {
       mat_focus(pilha.back(),'g');
       pilha.pop_back();
    }
    ed_show();
    while(auxiliar.size() != 0){
        pilha.push_back(auxiliar.back());
        auxiliar.pop_back();
    }
}

void lab_pilha(matchar& mat, vector<Par> pilha){
    mat.get(Par(1,1)) = ABERTO;
    pilha.push_back(Par(1,1));
    while(pilha.size() != 0){
        vector<Par> buraco;//Indica onde posso furar
        for(auto vizinho : getNeib(pilha.back())){
            if(furar_lab(mat,vizinho)){
                buraco.push_back(vizinho);
            }if(buraco.size() == 0){
                pilha.pop_back();
                showLab(mat,pilha);
            }else{
                Par p_escolhido = buraco[aleatorio(buraco.size())];
                mat.get(p_escolhido) = ABERTO;
                pilha.push_back(p_escolhido);
                showLab(mat,pilha);
            }
        }
    }
}

#include <cstdlib>
#include <ctime>

int main(){

      srand(time(NULL));
      vector<Par> pilha;
      matchar mat(10, 15, PAREDE);
      furar(mat, Par(1, 1));//chama a função recursiva

      lab_pilha(mat,pilha);
      mat_draw(mat);
      ed_show();

      Par inicio = mat_get_click(mat, "digite o local de inicio");

      Par final = mat_get_click(mat, "digite o local de fim");

      mat_draw(mat);

      ed_show();

      findPath(mat, inicio, final);
      ed_lock();//impede que termine abruptamente
      return 0;

    return 0;
}


