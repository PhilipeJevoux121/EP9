#include <stdio.h>

#define MAX 100

char percorre(int a, int b, char vetor[a][b]){
	int i = 0, j = 0;
	int aux[a][b];

	for (int i = 0; i < a; i++){
			for (int j = 0; j < b; j++){
				aux[i][j] = 0;
			}
		}

	while(i < MAX && j < MAX){
		if (vetor[i][j] == '>'){
			aux[i][j]++;
			if (aux[i][j] == 2){
				return '!';
			}
			j++;
			while(vetor[i][j] == '.'){
				aux[i][j]++;
				if (aux[i][j] == 2){
					return '!';
				}
				j++;
			}
		}

		else if (vetor[i][j] == 'v'){
			aux[i][j]++;
			if (aux[i][j] == 2){
				return '!';
			}
			i++;
			while (vetor[i][j] == '.'){
				aux[i][j]++;
				if (aux[i][j] == 2){
					return '!';
				}
				i++;
			}
		}
		else if (vetor[i][j] == '<'){
			aux[i][j]++;
			if (aux[i][j] == 2){
				return '!';
			}
			j--;
			while (vetor[i][j] == '.'){
				aux[i][j]++;
				if (aux[i][j] == 2){
					return '!';
				}
				j--;
			}
		}
		else if (vetor[i][j] == '^'){
			aux[i][j]++;
			if (aux[i][j] == 2){
				return '!';
			}
			i--;
			while (vetor[i][j] == '.'){
				aux[i][j]++;
				if (aux[i][j] == 2){
					return '!';
				}
				i--;
			}
		}
		else if (vetor[i][j] == '*'){
			return '*';
		}

		else{
			return '!';
		}

	}
	return '!';
}

int main(){
	int x, y;
	char result;

	scanf("%d", &x);
	scanf("%d", &y);

	char vet[y][x];

	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			scanf(" %c", &vet[i][j]);
		}
	}

	result = percorre(y, x, vet);

	printf("%c\n", result);

	return 0;
}