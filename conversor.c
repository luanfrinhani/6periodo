#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*char* conversordeBase(char *bits, int n, int m){
	int i = 0, cont = 0, j = 0, tam = 0;
	char *bits2 = (char*)calloc(8,sizeof(char));
	if (n < m){
		for (i=0;i<8;i++){				
			if (bits[i] == ','){
				bits2 = &bits[i+1];
				bits[i] = NULL;
				cont++;
			}
		}
		if (cont == 0){
			tam = strlen(bits);
			for (i=tam-1;i>=0;i--){
				bits2 = bits2 + (bits[i] - '0')*pow(n,j);
				j++;
			}
			return bits2;
		}
		else if (cont != 0){
			j = 1;
			for (i=tam-1;i>=0;i--){
				bits2 = bits2 + (bits[i] - '0')*pow(n,-j);
				j++;
			}
			for (i=tam-1;i>=0;i--){
				bits2 = bits2 + (bits[i] - '0')*pow(n,j);
				j++;
			}
			return bits2;
		}
	}
}*/
float binarioDecimal(char *entrada){
	int i = 0,tam = strlen(entrada),j = 0;
	float out = 0;
	for (i=tam-1;i>=0;i--){
		out = out + (entrada[i] - '0')*pow(2,j);
		j++;
	}
	return out;
}
char* decimalBinario(int entrada){
	char *saida,i = 7;
	saida = (char*)calloc(8,sizeof(char));
	int entrada2 = entrada;
	while(entrada2!=0){
		saida[i]= entrada2%2; //Converte cada posição do vetor de char em um inteiro, ou seja, cada posição do vetor string será um valor inteiro
		entrada2 = entrada2/2;
		i--;
	}
	return saida;
}
float binDeciVirgula(char* entrada){
	int i = 0, tam = strlen(entrada), j = 1;
	float out = 0;
	for (i=0;i<tam;i++){
		out = out + (entrada[i] - '0')*pow(2,-j);
		j++;
	}
	return out;
}
char* decBinVirgula(char *entrada){
	char *saida = (char*)calloc(8,sizeof(char));
	int entrada2 = 0, tam = strlen(entrada);
	entrada2 = entrada;
	entrada2 = entrada2*10;
	while(entrada2!=0){
		saida[tam] = entrada2%2;
		entrada2 = entrada2/2;
		tam--;
	}
	return saida;
}
char* conversorDe(char *entrada, int n, int m){
	int tam = strlen(entrada), cont = 0, j = 0, i = 0, k = 0;
	char *out = NULL;
	char *bits = (char*)calloc(tam,sizeof(char));
	if (n == 2 && m == 10){
		for (i=0;i<tam;i++){
			if (entrada[i] == ','){
				bits = &entrada[i+1];
				entrada[i] = NULL;
				cont++;
			}
		}
		int valor = 0;
		if (cont == 0){
			for (i=(tam-1);i>=0;i--){
				valor = valor + (entrada[i] - '0')*pow(2,j);
				j++;
			}
			out = (char*)calloc(tam,sizeof(char));
			sprintf(out,"%d",valor);
			return out;
		}
		else{
			char *out2 = (char*)calloc(1,sizeof(char));
			int tamM = strlen(entrada), tamD = strlen(bits);
			float valor1 = 0.0, valor2 = 0.0;
			for (i=(tamM-1);i>=0;i--){
				valor1 = valor1 + (entrada[i] - '0')*pow(2,j);
				j++;
			}
			j = 1;
			for (i=0;i<tamD;i++){
				valor2 = valor2 + (bits[i] - '0')*pow(2,-j);
				j++;
			}
			valor1 = valor1 + valor2;
			out = (char*)calloc(8,sizeof(char));
			sprintf(out,"%f",valor1);
			return out;
		}
	}
	else if (n == 10 && m == 2){
		for (i=0;i<tam;i++){
			if (entrada[i] == '.'){
				cont++;
			}
		}
		if (cont == 0){
			out = (char*)calloc(tam,sizeof(char));
			i = 7;
			int valor = atoi(entrada);
			while(valor!=0){
				if (valor%2 == 0){						
					out[i] = '0';
				}
				else if (valor%2 == 1){
					out[i] = '1';
				}
				valor = valor/2;
				i--;
			}
			return out;
		}
		else{
		    float valor = strtof(entrada,NULL);
		    int valor1 = valor;
		    float aux = valor - valor1;
			int tamM = strlen(entrada), tamD = strlen(bits), aux2 = 0;
			tam = tamM + tamD;
			out = (char*)calloc(tam,sizeof(char));
			i = 7;
			if (aux>=0.5){
				while(aux!=0.0){
					aux2 = aux*2;
					if (aux2 == 1){
						out[i] = '1';
					}
					else if (aux2 == 0){
						out[i] = '0';
					}
					aux = (2.0*aux) - aux2;
					i--;
				}
			}
			else if (aux<0.5){
				while(aux!=0.0){
					aux2 = aux*2;
					if (aux2 == 1){
						out[i] = '0';
					}
					else if (aux2 == 0){
						out[i] = '1';
					}
					aux = (2.0*aux) - aux2;
					i--;
				}
			}
			out[i] = ',';
			i--;
			while(valor1!=0){
				if (valor1%2 == 0){						
					out[i] = '0';
				}
				else if (valor1%2 == 1){
					out[i] = '1';
				}
				valor1 = valor1/2;
				i--;
			}
			return out;
		}
	}
	else if (n == 10 && m == 8){
		i = tam - 1;
		out = (char*)calloc(tam,sizeof(char));
		int valor = atoi(entrada);
		while(valor!=0){
			if (valor%8 == 0){
				out[i] = '0';
			}
			else if (valor%8 == 1){
				out[i] = '1';
			}
			else if (valor%8 == 2){
				out[i] = '2';
			}
			else if (valor%8 == 3){
				out[i] = '3';
			}
			else if (valor%8 == 4){
				out[i] = '4';
			}
			else if (valor%8 == 5){
				out[i] = '5';
			}
			else if (valor%8 == 6){
				out[i] = '6';
			}
			else if (valor%8 == 7){
				out[i] = '7';
			}
			else if (valor%8 == 8){
				out[i] = '8';
			}
			else if (valor%8 == 9){
				out[i] = '9';
			}
			valor = valor/8;
			i--;
		}
		return out;
	}
	else if (n == 8 && m == 10){
		int valor = 0;
		j = 0;
		for (i=(tam-1);i>=0;i--){
			valor = valor + (entrada[i] - '0')*pow(8,j);
			j++;
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		return out;
	}
	else if (n == 16 && m == 10){
		int valor = 0;
		j = 0;
		for (i=(tam-1);i>=0;i--){
			if (entrada[i] == 'A'){
				valor = valor + 10*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'B'){
				valor = valor + 11*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'C'){
				valor = valor + 12*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'D'){
				valor = valor + 13*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'E'){
				valor = valor + 14*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'F'){
				valor = valor + 15*pow(16,j);
				j++;
			}
			else{
				valor = valor + (entrada[i] - '0')*pow(16,j);
				j++;
			}
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		return out;
	}
	else if (n == 2 && m == 8){
		int valor = 0;
		for (i=(tam -1);i>=0;i--){
			valor = valor + (entrada[i] - '0')*pow(2,j);
			j++;
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		char *out1 = (char*)calloc(tam,sizeof(char));
		valor = atoi(out);
		i = tam - 1;
		while(valor!=0){
			if (valor%8 == 0){
				out1[i] = '0';
			}
			else if (valor%8 == 1){
				out1[i] = '1';
			}
			else if (valor%8 == 2){
				out1[i] = '2';
			}
			else if (valor%8 == 3){
				out1[i] = '3';
			}
			else if (valor%8 == 4){
				out1[i] = '4';
			}
			else if (valor%8 == 5){
				out1[i] = '5';
			}
			else if (valor%8 == 6){
				out1[i] = '6';
			}
			else if (valor%8 == 7){
				out1[i] = '7';
			}
			else if (valor%8 == 8){
				out1[i] = '8';
			}
			else if (valor%8 == 9){
				out1[i] = '9';
			}
			valor = valor/8;
			i--;
		}
		return out1;
	}
	else if (n == 8 && m == 16){
		int valor = 0;
		j = 0;
		for (i=(tam-1);i>=0;i--){
			valor = valor + (entrada[i] - '0')*pow(8,j);
			j++;
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		i = tam - 1;
		char *out2 = (char*)calloc(tam,sizeof(char));
		valor = atoi(out);
		while(valor!=0){
			if (valor%16 == 0){
				out2[i] = '0';	
			}
			else if (valor%16 == 1){
				out2[i] = '1';
			}
			else if (valor%16 == 2){
				out2[i] = '2';
			}
			else if (valor%16 == 3){
				out2[i] = '3';
			}
			else if (valor%16 == 4){
				out2[i] = '4';
			}
			else if (valor%16 == 5){
				out2[i] = '5';
			}
			else if (valor%16 == 6){
				out2[i] = '6';
			}
			else if (valor%16 == 7){
				out2[i] = '7';
			}
			else if (valor%16 == 8){
				out2[i] = '8';
			}
			else if (valor%16 == 9){
				out2[i] = '9';
			}
			else if (valor%16 == 10){
				out2[i] = 'A';
			}
			else if (valor%16 == 11){
				out2[i] = 'B';
			}
			else if (valor%16 == 12){
				out2[i] = 'C';
			}
			else if (valor%16 == 13){
				out2[i] = 'D';
			}
			else if (valor%16 == 14){
				out2[i] = 'E';
			}
			else if (valor%16 == 15){
				out2[i] = 'F';
			}
			valor = valor/16;
			i--;
		}
		return out2;
	}
	else if (n == 8 && m == 2){
		int valor = 0;
		j = 0;
		for (i=(tam-1);i>=0;i--){
			valor = valor + (entrada[i] - '0')*pow(8,j);
			j++;
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		char *out2 = (char*)calloc(tam,sizeof(char));
		i = tam - 1;
		valor = atoi(out);
		while(valor!=0){
			if (valor%2 == 0){						
				out2[i] = '0';
			}
			else if (valor%2 == 1){
				out2[i] = '1';
			}
			valor = valor/2;
			i--;
		}
		return out2; 

	}
	else if (n == 2 && m == 16){
		int valor  = 0;
		for (i=(tam-1);i>=0;i--){
			valor = valor + (entrada[i] - '0')*pow(2,j);
			j++;
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		char *out2 = (char*)calloc(tam,sizeof(char));
		valor = atoi(out);
		i = tam - 1;
		while(valor!=0){
			if (valor%16 == 0){
				out2[i] = '0';	
			}
			else if (valor%16 == 1){
				out2[i] = '1';
			}
			else if (valor%16 == 2){
				out2[i] = '2';
			}
			else if (valor%16 == 3){
				out2[i] = '3';
			}
			else if (valor%16 == 4){
				out2[i] = '4';
			}
			else if (valor%16 == 5){
				out2[i] = '5';
			}
			else if (valor%16 == 6){
				out2[i] = '6';
			}
			else if (valor%16 == 7){
				out2[i] = '7';
			}
			else if (valor%16 == 8){
				out2[i] = '8';
			}
			else if (valor%16 == 9){
				out2[i] = '9';
			}
			else if (valor%16 == 10){
				out2[i] = 'A';
			}
			else if (valor%16 == 11){
				out2[i] = 'B';
			}
			else if (valor%16 == 12){
				out2[i] = 'C';
			}
			else if (valor%16 == 13){
				out2[i] = 'D';
			}
			else if (valor%16 == 14){
				out2[i] = 'E';
			}
			else if (valor%16 == 15){
				out2[i] = 'F';
			}
			valor = valor/16;
			i--;
		}
		return out2;
	}
	else if (n == 16 && m == 2){
		int valor = 0;
		j = 0;
		for (i=(tam-1);i>=0;i--){
			if (entrada[i] == 'A'){
				valor = valor + 10*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'B'){
				valor = valor + 11*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'C'){
				valor = valor + 12*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'D'){
				valor = valor + 13*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'E'){
				valor = valor + 14*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'F'){
				valor = valor + 15*pow(16,j);
				j++;
			}
			else{
				valor = valor + (entrada[i] - '0')*pow(16,j);
				j++;
			}
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		char *out2 = (char*)calloc(tam,sizeof(char));
		i = tam -1;
	 	valor = atoi(out);
		while(valor!=0){
			if (valor%2 == 0){						
				out2[i] = '0';
			}
			else if (valor%2 == 1){
				out2[i] = '1';
			}
			valor = valor/2;
			i--;
		}
		return out2;
	}
	else if (n == 16 && m == 8){
		int valor = 0;
		j = 0;
		for (i=(tam-1);i>=0;i--){
			if (entrada[i] == 'A'){
				valor = valor + 10*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'B'){
				valor = valor + 11*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'C'){
				valor = valor + 12*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'D'){
				valor = valor + 13*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'E'){
				valor = valor + 14*pow(16,j);
				j++;
			}
			else if (entrada[i] == 'F'){
				valor = valor + 15*pow(16,j);
				j++;
			}
			else{
				valor = valor + (entrada[i] - '0')*pow(16,j);
				j++;
			}
		}
		out = (char*)calloc(tam,sizeof(char));
		sprintf(out,"%d",valor);
		char *out2 = (char*)calloc(tam,sizeof(char));
	 	valor = atoi(out);
	 	i = tam;
		while(valor!=0){
			if (valor%8 == 0){
				out2[i] = '0';
			}
			else if (valor%8 == 1){
				out2[i] = '1';
			}
			else if (valor%8 == 2){
				out2[i] = '2';
			}
			else if (valor%8 == 3){
				out2[i] = '3';
			}
			else if (valor%8 == 4){
				out2[i] = '4';
			}
			else if (valor%8 == 5){
				out2[i] = '5';
			}
			else if (valor%8 == 6){
				out2[i] = '6';
			}
			else if (valor%8 == 7){
				out2[i] = '7';
			}
			else if (valor%8 == 8){
				out2[i] = '8';
			}
			else if (valor%8 == 9){
				out2[i] = '9';
			}
			valor = valor/8;
			i--;
		}
		return out2;
	}
	else if (n == 10 && m == 16){
		i = 7;
		out = (char*)calloc(8,sizeof(char));
		int valor = atoi(entrada);
		while(valor!=0){
			if (valor%16 == 0){
				out[i] = '0';	
			}
			else if (valor%16 == 1){
				out[i] = '1';
			}
			else if (valor%16 == 2){
				out[i] = '2';
			}
			else if (valor%16 == 3){
				out[i] = '3';
			}
			else if (valor%16 == 4){
				out[i] = '4';
			}
			else if (valor%16 == 5){
				out[i] = '5';
			}
			else if (valor%16 == 6){
				out[i] = '6';
			}
			else if (valor%16 == 7){
				out[i] = '7';
			}
			else if (valor%16 == 8){
				out[i] = '8';
			}
			else if (valor%16 == 9){
				out[i] = '9';
			}
			else if (valor%16 == 10){
				out[i] = 'A';
			}
			else if (valor%16 == 11){
				out[i] = 'B';
			}
			else if (valor%16 == 12){
				out[i] = 'C';
			}
			else if (valor%16 == 13){
				out[i] = 'D';
			}
			else if (valor%16 == 14){
				out[i] = 'E';
			}
			else if (valor%16 == 15){
				out[i] = 'F';
			}
			valor = valor/16;
			i--;
		}
			return out;
	}

}
int main(){
	int i = 0, op = 1,op2 = 0, entrada = 0, n = 0, m = 0;
	char *bits = (char*)calloc(8,sizeof(char)),*bits2 = (char*)calloc(8,sizeof(char)), *entrada2 = (char*)calloc(8,sizeof(char));
	char *saida3 = (char*)calloc(16,sizeof(char)), *out = (char*)calloc(16,sizeof(char));
	//float saida2 = 0.0, saida = 0.0;
	printf("Entre com o numero: ");
	scanf("%s",bits);
	printf("Entre com a base do numero: ");
	scanf("%d",&n);
	printf("Entre com a base de conversao: ");
	scanf("%d",&m);
	out = conversorDe(bits,n,m);
	for (i=0;i<16;i++){
		printf("%c",out[i]);
	}
	/*while(op!=0){
		printf("\nEntre com o numero: ");
		scanf("%s",entrada);
		printf("\nEntre com a base do numero e a base de conversao");
		scanf("%d %d",&n,&m);

		if (op == 1){
			printf("1 - Numeros sem virgula\n2 - Numeros com virgula\n0 - Menu Anterior\n");
			scanf("%d",&op2);
			if (op2 == 1){
				printf("Valor para conversao na base 10:\n ");
				scanf("%d",&entrada);
				bits = decimalBinario(entrada);
				for(i=0;i<8;i++){
					printf("%d\t",bits[i]);
				}
			}
				if (op2 == 2){
					printf("Valor para conversao na base 10:\n ");
					scanf("%s",entrada2);
					int tam = strlen(entrada2);
					for (i=0;i<tam;i++){
						if (entrada2[i] == ','){
							bits[i] = &entrada2[i];
							entrada2[i] = NULL;
						}
					}
					out = decimalBinario(entrada2);
					bits2 = decBinVirgula(bits);
					strcpy(saida3,out);
					printf("\n%s",saida3);

				}
		}
		if (op == 2){
			printf("1 - Numeros sem virgula\n2 - Numeros com virgula\n0 - Menu Anterior\n");
			scanf("%d",&op2);
			if (op2 == 1){
				printf("Valor para conversao:\n ");
				scanf("%s",bits);
				saida = binarioDecimal(bits);
				printf("\n%f",saida);
			}
			if (op2 == 2){
				printf("Valor para conversao:\n ");
				scanf("%s",bits);
				for (i=0;i<8;i++){
					if (bits[i] == ','){
						bits2 = &bits[i+1];
						bits[i] = NULL;
					}
				}
				saida = binarioDecimal(bits);
				saida2 = binDeciVirgula(bits2);
				saida2 += saida;
				printf("\n%f\n",saida2);
			}
		}
		/*if (op == 3){
			printf("Valor para conversão:\n ");
			scanf("%s",bits);
			printf("Base do numero:\n ");
			scanf("%d",&n);
			printf("Base desejada: ");
			scanf("%d",&m);
			entrada2 = conversordeBase(bits,n,m);
			printf("\n%s\n",entrada2);
		}
	}*/
}
