#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 100
typedef struct pilha pilha;
struct pilha {
	char dados[MAX_CAPACITY];
	int topo;
};
pilha *cria_pilha() {
	pilha *p = malloc(sizeof(pilha));
	p->topo = 0;
	return p;
}
int push(pilha *p, char valor) {
	if (p->topo < MAX_CAPACITY) {
		p->dados[p->topo++] = valor;
		return 1;
	} else
		return 0;
}
int pop(pilha *p, char *r) {
	if (p->topo > 0) {
		*r = p->dados[--p->topo];
		return 1;
	} else
		return 0;
}
void inverte_string(char *s, char *dest) {
	int l = strlen(s);
	pilha *p = cria_pilha();
	int i;
	for (i = 0; i < l-1; i++)
		push(p, s[i]);
	
	for (i = 0; i < l-1; i++) {
		char atual;
		pop(p, &atual);
		dest[i] = atual;
	}
	dest[l-1] = 0;
}
int main() {
	char texto[100];
	fgets(texto, 100, stdin);
	char *dest = malloc(sizeof(char)*strlen(texto));
	inverte_string(texto, dest);
	printf("%s", dest);
	return 0;
}