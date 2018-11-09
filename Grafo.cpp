#include"Grafo.h"
#include"Vertice.h"
#include"Aresta.h"
#include<iostream>
#include<string>

using namespace std;

Grafo::Grafo(int v){
    if(v > 0){
        this->numeroVertices = v;
        this->list = new Vertice[v];
    }
    else {
        this->numeroVertices = 0;
        this->list = NULL;
    }
}

Grafo::~Grafo(){
    //cout << "Destrutor Grafo...\n";
    delete [] this->list;
}

int Grafo::linhaVazia(int l){
    return (this->list[l].getInicio() == NULL);
}

void Grafo::inserirAresta(int s, int c, double p){
    if(s != c){
        Aresta *nova = new Aresta(p,c);
        if(this->linhaVazia(s)) {
            this->list[s].setFim(nova);
            this->list[s].setInicio(nova);
            //cout << "Saida: " << s << " - Destino: " << c << " - Custo: " << p << endl;
            return;
        }
        //cout << "Chegada antes: " << this->list[s].getFim()->getChegada() << endl;
        this->list[s].getFim()->setProx(nova);
        this->list[s].setFim(nova);
        //cout << "Saida: " << s << " - Destino depois: " << this->list[s].getFim()->getChegada() << " - Custo: " << p << endl;
    } 
}

void Grafo::imprimirMatriz(){
    cout << "[Origem] -> [Destino|Peso]" << endl;
    for(int i = 0; i < this->numeroVertices; i++){
        cout << "[" << i+1 << "]";
        this->list[i].getInicio()->imprime();
        cout << endl << endl;
    }
}

/*Grafo::Grafo(){
    this->vertices = 0;
    //this->matrizAdj = NULL;
}

Grafo::Grafo(int v){
    if(v > 0){
        this->vertices = v;
        this->matrizAdj = new int*[v];
        for(int i = 0; i < v; i++){
            this->matrizAdj[i] = new int[v];
        }
    }
    else {
        this->vertices = 0;
    }
}

Grafo::~Grafo(){
    for(int i = 0; i < this->vertices; i++){
        delete [] this->matrizAdj[i];
    }
    delete [] this->matrizAdj;
}

void Grafo::setVertices(int v){
    if(v > 0) this->vertices = v;
    else this->vertices = 0;
}

int Grafo::getVertices(){
    return this->vertices;
}

void Grafo::imprimirMatriz(){

    for(int k = 0; k < this->vertices; k++)
        cout << "\t" << k << "\t";
    cout << endl;

    for(int i = 0; i < this->vertices; i++){
        for(int k = 0; k < 16*this->vertices; k++)
            cout << "-";
        cout << endl;
        cout << "|";
        for(int j = 0; j < this->vertices; j++){
            cout << "\t" << this->matrizAdj[i][j] << "\t|";
        }
        cout << " " << i << endl;
    }
    for(int k = 0; k < 16*this->vertices; k++)
        cout << "-";
    cout << endl;
}

int Grafo::inserirVertice(int l, int c, int p){
    try{
        if(this->matrizAdj[l][c] != 0)
            throw string("Posicao ja existente");
        this->matrizAdj[l][c] = p;
    }catch(string s){
        cout << s << endl;
        return 0;
    } 
    return 1;    
}*/