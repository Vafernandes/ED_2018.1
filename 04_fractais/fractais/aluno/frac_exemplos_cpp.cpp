#include <lib/pen.h>


void emboa(Pen& p, int lado){

    if(lado < 20)//condiçãod e parada
        return;
    p.setColor(255,258,200);

    p.walk(lado);//ação
    p.right(90);//ação

    emboa(p, lado - 10);//recursividade,nesse caso,meu lado diminui 10 a cada chamada
    //votando
    p.setColor(255, 255, 255);
    p.left(90);
    p.walk(-lado);

}

//============================================== ÁRVORE ======================================

void arvore(Pen& p, int lado){

    float ang = 35;
    float dec = 15;//decremento de 20

    if(lado < 10)
        return;

    p.setThickness(2);//começa com a espessura de 3

    p.walk(lado);
    p.right(ang);
    arvore(p, lado - dec);

    p.setColor(0,255,0);//pinto as extremidades de verde

    p.left(ang);//viro o dobro do ângulo,um para ficar no 0 e o outro para chegar a 35 graus pela esquerda
    arvore(p, lado - dec);//Após desenhar o lado esquerdo

    p.left(ang);//viro o dobro do ângulo,um para ficar no 0 e o outro para chegar a 35 graus pela esquerda
    arvore(p, lado - dec);//Após desenhar o lado esquerdo

    p.right(ang);//volto para o ang 0

    p.walk(-lado);//volto o tamanho do lado para chegar no ponto em que minha função começou

    p.setColor(160,90,20);//termino minha árvore com um tom de marro
    p.setThickness(5);//termino com a espessura de 5

}

//========================================== Triângulo ================================

void triangulo(Pen& p, int lado){

    if(lado < 10)
        return;

    for(int i = 0; i < 3; i++){

        p.setColor(rand() % 255,rand() % 255, rand() % 255);

        p.walk(lado);
        p.left(120);
        triangulo(p, lado / 2);


    }


}

//============================================ Floco De Neve ================================

void flocoDeNeve(Pen& p, int lado){

    if(lado < 3)
        return;
    p.setColor(10,150,255);
    p.setThickness(3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    flocoDeNeve(p, lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    flocoDeNeve(p, lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    flocoDeNeve(p, lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    flocoDeNeve(p, lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    flocoDeNeve(p, lado / 3);



}

//=============================================== Trigo ==============================

void trigo(Pen& p,int lado){

    if(lado < 0.1)
        return;
    p.setColor(200,150,100);
    for(int i = 0; i < 4; i++){
        p.walk(lado);
        p.right(45);
        trigo(p, lado / 2.5);
        p.left(90);
        trigo(p, lado / 2.5);
        p.right(45);

    }

    p.walk(-lado * 4);


}

//========================================== Quadrado espiral =====================================

void quadradoEspiral(Pen& p, int lado){

        if(lado < 5)
            return;

            p.walk(lado);
            p.right(90);

            p.walk(lado);
            p.right(90);

            p.walk(lado);
            p.right(90);

            p.walk(lado);

            p.up();

            p.walk(lado);
            p.rotate(60);
            p.down();
            quadradoEspiral(p, lado - 5);

}

//========================================== circulo ==================================

void circulo(Pen &p, int lado){
    if(lado < 1)
        return;

    p.circle(lado);
    for(int i = 0; i < 6; i++){
        p.right(60);
        p.up();
        p.walk(lado);
        p.down();
        circulos(p, lado * 0.4 );
        p.up();
        p.walk(-lado);
        p.down();
    }
}

void fractal(){

    Pen p(800, 600);
    //p.setThickness(3); //espessura da linha

    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 300);

    //faz o pincel apontar pra direita

    p.setHeading(90);

    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);

    int lado = 100;

//================================Funções======================================

    //emboa(p, lado);
    //arvore(p, lado);
    //triangulo(p,lado);
    //flocoDeNeve(p,lado);
    //trigo(p,lado);
    //quadradoEspiral(p,lado);
    //circulo(p,lado);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
