int main(){
	int i = 0, n = 0, m = 0;
	char *bits = (char*)calloc(bits2,sizeof(char)), *out = (char*)calloc(bits2,sizeof(char));
	printf("Entre com o numero: ");
	scanf("%s",bits);
	printf("Entre com a base do seu numero: ");
	scanf("%d",&n);
	printf("Entre com a base para conversao: ");
	scanf("%d",&m);
	out = conversorDe(bits,n,m);
	for (i=0;i<bits2;i++){
		printf("%c",out[i]);
	}
}
