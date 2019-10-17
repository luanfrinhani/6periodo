#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define bits2 8 
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
