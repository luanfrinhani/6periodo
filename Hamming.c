#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int analisa(int valor, int d){
	int i = 0, aux, resp, va;
	for (i=0;i<=d;i++){
		aux = valor%10;
		resp = valor/10;
		va = aux;
		valor = resp;
	}
	if (va == 1){
		return 1;
	}
	return 0;
}

int converte(int *vetor, int tam){
	int i = 0, soma = 0, j = 0;
	for (i = tam - 1;i>=0;i--){
		soma = soma + pow(2,j)*vetor[i];
		j++;
	}
	return soma;
}
int main(){
	int cont = 0, tam = 0, paridade, contC, aux, lim, i, soma = 0, convertido;
	int conta_res = 0;
	char codigo[32];
	int contadores[32];
	int resultado[32];
	int comparacoes[32][32];
	int binarios[32] = {1,10,11,100,101,110,111,1000,1001,1010,1011,1100,
	1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,
	11001,11010,11011,11100,11101,11110,11111};
	printf("Entre com o codigo recebido: \n");
	scanf("%s", &codigo);
	for (int i = 0;i<50;i++) { //conta o tamanho e a qtdd de 1s
		if (codigo[i] == '1') {
			cont++;
			tam++;
		}
		else if (codigo[i] == '0') {
			tam++;
		}
		else {
			break;
		}
	}
	if (cont % 2 == 0) { //escolhendo paridade par ou impar
		paridade = 0;
	}
	else {
		paridade = 1;
	}
	lim = sqrt(tam)+1;
	for (i = 0;i<lim;i++) {
		aux = pow(2,i);
		contC = 1;
		comparacoes[i][0] = aux;
		for (int j = aux;j<tam;j++) {
			if (analisa(binarios[j],i) == 1) {
			comparacoes[i][contC] = j+1;
			contC++;
			}
		}
		contadores[i] = contC;
	}
	for (int k = i-1;k>=0;k--) {
		soma = 0;
		for (int j = contadores[k]-1;j>=0;j--) {
			soma = soma + codigo[comparacoes[k][j]-1];
		}
		if (paridade == 0) {
			if (soma % 2 == 0) {
				resultado[conta_res] = 0;
				conta_res++;
			}
			else {
				resultado[conta_res] = 1;
				conta_res++;
			}
		}
		else {
			if (soma % 2 == 0) {
			resultado[conta_res] = 1;
			conta_res++;
			}
			else {
				resultado[conta_res] = 0;
				conta_res++;
			}
		}
	}
	convertido = converte(resultado, conta_res);
	if (codigo[convertido-1] == '1') {
		codigo[convertido-1] = '0';
	}
	else {
		codigo[convertido-1] = '1';
	}
	printf("\nO codigo correto eh: %s", codigo);
	return 0;
	
}