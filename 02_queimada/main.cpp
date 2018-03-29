#include <iostream>
#include <vector>

using namespace std;

const int linha = 20;
const int coluna = 60;

struct Par{
    int l;
    int c;

    Par(int l,int c){
        this->l = l;
        this->c = c;
    }
};

vector<Par> vizinhos(Par par){//Esse método tem a ordem de queimar

    vector<Par> vizinhos;

    vizinhos.push_back(Par(par.l,par.c + 1));
    vizinhos.push_back(Par(par.l,par.c - 1));
    vizinhos.push_back(Par(par.l + 1,par.c));
    vizinhos.push_back(Par(par.l - 1,par.c));

    return vizinhos;
}

void esperar(){
    char c;
    cin >> noskipws >> c;//capta o 'enter'
}

void mostrar(char mat[linha][coluna]){
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            cout << mat[l][c];
        }
        cout << "\n";
    }
}

void limparTela(){

    for(int i = 0; i < 2; i++){
        cout << endl;
    }
}

vector<Par> embaralhar(vector<Par> vet){
    for(int i = 0; i < (int)vet.size(); i++){
            int aleatorio = rand() % vet.size();//Vou percorrer de zero até o tamanho do meu vetor
            swap(vet[i],vet[aleatorio]);
    }

    return vet;//retorno meu vetor embaralhado
}

int queimar(int l,int c, char mat[linha][coluna],int nivel){

    int cont = 0;

    if(l < 0 or l >= linha)
        return 0;
    if(c < 0 or c >= coluna)
        return 0;
    if(mat[l][c] == '#'){
        cont = 1;//a árvore se queima,conto com ela
        mat[l][c] = '0' + nivel;//Ao invés de mostrar a árvore queimada,vou mostrar um nível de 0 - 9
        limparTela();
        mostrar(mat);
        esperar();

        int contNivel = nivel + 1;//Mostra número de 0 a 9

        for(Par par : embaralhar(vizinhos(Par(l,c)))){//queimo aleatóriamente quando chamo a função 'embaralhar'
            cont += queimar(par.l,par.c,mat,contNivel);//conto os adjacentes queimados
            if(contNivel > 9){
                contNivel = 0;
            }
            mat[l][c] = '.';//Após mostrar a profundidade, a árvore é queimada!
        }
    }


    return cont;
}

int main(){

    char mat[linha][coluna];

    //Preenche a matriz
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            mat[l][c] = ' ';//vamos iniciar tudo com '.' para gerar as árvores automaticamente
        }
    }

    int qtd = linha * coluna * 1.5;//quantidade de árvores a serem geradas

    for(int sorteio = 0; sorteio < qtd; sorteio++){
        mat[rand() % linha][rand() % coluna] = '#';//sorteio uma árvore em um local da minha linha e
    }

    limparTela();
    mostrar(mat);

    //cout << "Digite linha e coluna para fogo" << endl;
    //int lin = 0,col = 0; //começo a queimar na linha 0 coluna 2
    //cin >> lin >> col;

    int nivel = 0;

    int cont = queimar(0, 0, mat, nivel);//Iniciando a queimada da posição (0,0);
    //mostrar(mat);
    cout << "Número de árvores queimadas: " << cont << endl;

    return 0;
}
