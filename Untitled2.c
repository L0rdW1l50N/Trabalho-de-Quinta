#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct funcionario{
	char cpf[15];
	char nome[250];
	char telefone[250];
	char endereco[250];
	char ano[4];
	char status;
}; fun;

FILE *fp;

void incluir();
void consultar();
void excluir();
void alterar();
void abrir();
void listar();
void help();

void main(void){
	char opcao[2], op;
	do{
		do{
			clrscr();
			printf("\n\n\n\n\n");
			printf("\t##########\n");
			printf("\t            #\n");
			printf("Cadastro de Funcionarios#\n");
			printf("\t########\n\n\n\n");
			printf("\n Digite uma opcao\n\n");
			printf("\n <I> - Incluir");
			printf("\n <A> - Alterar");
			printf("\n <E> - Excluir");
			printf("\n <C> - Consultar");
			printf("\n <L> - Listar");
			printf("\n <H> - Ajuda");
			printf("\n <S> - Sair");
			printf("\n\n\n Opcao:");
			gets(opcao);
			op=tolowe(*opcao);
		} while(!strchr("iaeclsh", op));
		switch(op){
			case 'i' : incluir(); break;
			case 'a' : alterar(); break;
			case 'e' : excluir(); break;
			case 'c' : consultar(); break;
			case 'l' : listar(); break;
			case 's' : exit(0); break;
			case 'h' : help(); break;
		} while(1);
	}
	
void help(void){
	clrscr();
	printf("\a\n\n\n\n\n\n\n");
	printf("\t#######################################################\n");
	printf("\t# Programa feito por: Wilson, Romero e Renan          #\n");
	printf("\t#######################################################\n");
	printf("\t\t\tTecle <ENTER> para voltar");
	getch();
}
void abrir(char tipo[3]){
	if((fb=fopen("funcionarios.txt",tipo))==NULL){
		printf("\n O arquivo nao pode ser aberto!\n");
		getch();
		exit(1);
		
	}
}
void incluir(void){
	// char *um="0";
	abrir("ab+");
	faseek(fp,0L,SEEK_END);
	
	do{
		printf("\n Digite o cpf ou <FIM> para sair:\n\n");
		gets(fun.cpf);
		
		if((strcmp(fun.cpf,"fim")!=0)&&(strcmp(fun.cpf,"FIM")!=0)){
			printf("\n Nome:"); gets(fun.nome);
			printf("\n Telefone:"); gets(fun.telefone);
			printf("\n Endereço:"); gets(fun.endereco);
			printf("\n Ano de Contratação:"); gets(fun.ano);
			fun.status='1';
			//esta bolinha alt +169
			if(fwrite(®, sizeof(struct funcionario), 1, fp) !=1){
				printf("zn Erro de gravação!!");
				getch();
				
			}
			else{
				printf("\n Registro completo feito com sucesso...\n\n");
			}
			while((strcmp(fun.cpf,"fim")!=0)&&(strcmp(fun.cpf,"FIM")!=0));
			fclose(fp);
				
		}
	}
	
}
int busca(void){
	int achou=-1,posicao=0;
	char cpfbus[15];
	abrir("rb");
	printf("\nDigite o cpf a ser procurado:");
	gets(cpfbus);
	rewind(fp);
	while((!feof(fp)))&&(achou==-1))
	{
		fread(®, sizeof(struct funcionario), 1, fp);
		if (!feof(fp))
	{if(strcmp(cpfbus, fun.cpf)==0)
		{if (fun.status=='0')
			{posicao=-2;}
		achou=1;
		}
	else{posiçao++}
}
		else{posicao=-1;}
	}
	if (achou==-1)
		{posicao=-1;}
	fclore(fp);
	return(posicao);
	}
	
	
	
	
}

	
	
}
