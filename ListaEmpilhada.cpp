#include <iostream>
using namespace std;

#define MAX 5

struct PilhaVetor {
	int qtde;
	int elementos[MAX];
};

struct No {
	int dado;
	struct No *prox;
};

struct PilhaPonteiro {
	No *topo;
};

PilhaVetor* initVetor() {
	PilhaVetor *p = new PilhaVetor;
	p->qtde = 0;
	return p;
}

PilhaPonteiro* initPonteiro() {
	PilhaPonteiro *p = new PilhaPonteiro;
	p->topo = NULL;
	return p;
}

void pushVetor(PilhaVetor *p, int v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
}

void pushPonteiro(PilhaPonteiro *p, int v) {
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

string popVetor(PilhaVetor *p) {
	int podeDesempilhar = (p->qtde > 0);
	string v;
	if (podeDesempilhar) {
		v = std::to_string(p->elementos[p->qtde-1]);
		p->qtde--;
	}
	else
	{
		return "END";
	}
	return v;	
}

string popPonteiro(PilhaPonteiro *p) {
	string ret;
	int podeDesempilhar = (p->topo != NULL);
	if (podeDesempilhar) {
	   No *no = p->topo;
	   ret = std::to_string(no->dado);
	   p->topo = p->topo->prox;
	   free(no);
	}
	else
	{
		ret = "END";
	}
	return ret;
}

void printVetor(PilhaVetor *p) {
	cout << "Qtde de elementos na pilha: " << p->qtde << endl;
	for(int i=p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "--------------" << endl;
}

void printPonteiro(PilhaPonteiro* p) {
	No* n;
	n = p->topo;
	while (n != NULL) {
		cout << n->dado << endl;
		n = n->prox;
	}
	cout << "--------------------" << endl;
}

void desempilharVetor(PilhaVetor* p) {
	
	string value;
	value = popVetor(p);
	
	while(value != "END")
	{
		cout << "Valor desempilhado: "<< value << endl;
		value = popVetor(p);
	}
	cout << "---------------------------------" << endl;
}

void desempilharPonteiro(PilhaPonteiro* p) {
	
	string value;
	value = popPonteiro(p);
	
	while(value != "END")
	{
		cout << "Valor desempilhado: "<< value << endl;
		value = popPonteiro(p);
	}
	cout << "---------------------------------" << endl;
}

int main(int argc, char** argv)
{
	PilhaVetor *pilhaVetor;
	pilhaVetor = initVetor();
	
	PilhaPonteiro *pilhaPar;
	pilhaPar = initPonteiro();
	
	PilhaPonteiro *pilhaImpar;
	pilhaImpar = initPonteiro();
	
	int number;
	
	cout << "Digite "<< MAX <<" numeros inteiros de forma crescente" << endl;
	
	for(int i = 0; i < MAX; i++) {
		cout << i+1 <<" Numero: ";
		cin >> number;
		if(i != 0) {
			while(number <= pilhaVetor->elementos[i-1])
			{
				cout << i+1 <<" Numero, deve ser maior que o anterior: ";
				cin >> number;
			}
		}
		pushVetor(pilhaVetor, number);
		
		if((number%2) == 0) {
			pushPonteiro(pilhaPar, number);
		}else {
			pushPonteiro(pilhaImpar, number);
		}
	}
	
	cout << "Todos" << endl;
	desempilharVetor(pilhaVetor);
	cout << "Par" << endl;
	desempilharPonteiro(pilhaPar);
	cout << "Impar" << endl;
	desempilharPonteiro(pilhaImpar);
	
	/*
	printVetor(pilhaVetor);
	cout << "PAR: " << endl;
	printPonteiro(pilhaPar);
	cout << "Impar: "<< endl;
	printPonteiro(pilhaImpar);
	*/
	
	return 0;
}