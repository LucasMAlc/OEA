#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco{
    char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int main(int argc, char const *argv[]){

    long tam, inicio, meio, fim;
    int c = 0;
    Endereco e;
    FILE *f = fopen("cep_ordenado.dat", "r");

    if (argc != 2){
        fprintf(stderr, "USO: %s [CEP]", argv[0]);
        return 1;
    }
    if (f == NULL){
        printf("Erro ao abrir o arquivo \n");
        return 0;
    }
    

    printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco));
    fseek(f,0,SEEK_END);
    tam = ftell(f);
    inicio = 0;
    fim = (tam/sizeof(Endereco))-1;
    rewind(f); //fseek(f, 0, SEEK_SET);

    while (strncmp(argv[1],e.cep, 8) != 0){

        c++;
        meio = ((inicio + fim)/2);

        fseek(f, sizeof(Endereco) * meio, SEEK_SET);
        fread(&e, sizeof(Endereco), 1, f);

        if (strncmp(argv[1], e.cep, 8) < 0){
           fim = meio - 1; 
        } else if (strncmp(argv[1], e.cep, 8) > 0){
            inicio = meio + 1;
        } 
        if (strncmp(argv[1], e.cep, 8) == 0){
            printf("\n%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
            break;
        }
        if (c > 20){
            printf("\nCEP Nao encontrado \n");
            break;
        }
        
    }
    
    printf("Lidos: %d\n", c);
    fclose(f);
}