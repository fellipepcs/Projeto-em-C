#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int op,quantidadeAssociados,id,atividade,atividade2,atividade3,opc,continua,x,indice,contador1,contador2,contador3,contadorDep; //declaração de  variaveis
float quantidadeAulas; //declaração de  variaveis
char pesquisa[20];
void cadastroAssociado();
char cadastrar_dependente();
char listarAssociados();
char Listar_associados_por_modalidade(); // prototipo das funções
char pesquisarAssociados();
char relatorioAssociados();
void limpaTela();
void despedida();

struct dependente   //struct dos dependentes
{
    char nome[20];
    int idade;
};
struct dependente dep[3];// nome que irei utilizar nas funções

struct associado   // struct dos associados
{
    int id;
    char nome[20];
    int idade;
    int qtdDep;
    struct dependente dep[3];
    bool natacao;
    bool futsal;
    bool tenis;
};
struct associado filiado[200]; // nome que irei utilizar nas funções


int main()
{
contadorDep=0;
quantidadeAssociados=0; // inicializando variavel global
    while(op!=7|| op>7|| op<1)  // while para rodar somente se o usuario digitar os numeros propostos no parametro
    {
        printf(" \n =============== Sistema de Gerencia de Clube Esportivo=================\n");
        printf("Escolha uma das opcoes do menu abaixo:\n");
        printf("1-Cadastrar associado\n");
        printf("2-Cadastrar dependente\n");
        printf("3-Listar associados\n");
        printf("4-Listar associados por modalidade\n");
        printf("5-Pesquisar associados\n");
        printf("6-Gerar relatorio de associados\n");
        printf("7-Finalizar Programa\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        limpaTela();
        switch (op)  //switch case para definir os casos das opções do menu
        {
        case 1:
            cadastroAssociado(); // chamando a função da opcao 1 sobre cadastrod de associados
            break;
        case 2:
            limpaTela(); // função limpaTela para limpar a tela e deixar mais organizado
            cadastrar_dependente(); // chamando a função da opcao 2 sobre cadastrar dependentes
            break;
        case 3:
            limpaTela();// função limpaTela para limpar a tela e deixar mais organizado
            listarAssociados();// chamando a função da opcao 3 sobre listar associados
            break;
        case 4:
            limpaTela();// função limpaTela para limpar a tela e deixar mais organizado
            Listar_associados_por_modalidade(); // chamando a função da opcao 4 para listar associados por modalidade;
            break;
        case 5:
            limpaTela();// função limpaTela para limpar a tela e deixar mais organizado
            pesquisarAssociados(); //chamando a função da opcao 5 que pesquisa associados
            break;
        case 6:
            limpaTela();// função limpaTela para limpar a tela e deixar mais organizado
            relatorioAssociados();//chamando a função da opcao 6 que gera um relatorio sobre todos os associados
            break;
        case 7:
			despedida(); //chamando função despedida
            break;
        }
    }
    return 0;
}

void cadastroAssociado()
{
    int indice,x,i; //declaração de  variaveis
    x=1;
    indice=quantidadeAssociados;// declarando que indice recebe quantidade de associados

    printf("Quantos associados voce quer cadastrar? ");// pergunta quantos usuarios quer cadastrar
    scanf("%d", &x);// leitura da quant de usuarios
    for(i=0; i<x; i++)  // for para dar o loop e iniciar a variavel i
    {
        printf("Digite o nome do associado: ");
        scanf(" %[^\n]s",filiado[indice].nome);
        printf("Digite a idade do associados: ");
        scanf("%d", &filiado[indice].idade);
        while(filiado[indice].idade<0)  // while para dar loop ate garantir que a idade que ele digitar seja positiva
        {
            printf("Erro! Digite novamente a idade, desde que ela seja positiva!");
            scanf("%d", &filiado[indice].idade);
        }
        printf("Voce faz natacao? Digite 1 para Sim e 2 para nao.  "); // pergunta se ele faz natação e opcao de escolha
        scanf("%d", &atividade); // leitura que define se ele ira faz natação ou nao
        if(atividade==1)  // se esse if for igual a 1 ele é verdadeiro
        {
            filiado[indice].natacao=1; // recebendo um, pois o if é verdadeiro
            contador1=contador1+1; // variavel contadora para o caso 6

        }
        printf("Voce faz futsal? Digite 1 para Sim e 2 para nao. ");// pergunta se ele faz futsal e opcao de escolha
        scanf("%d", &atividade2);// leitura que define se ele ira faz futsal ou nao
        if(atividade2==1)  // se esse if for igual a  1 ele é verdadeiro
        {
            filiado[indice].futsal=1;// recebendo um, pois o if é verdadeiro
            contador2=contador2+1;// variavel contadora para o caso 6
        }
        printf("Voce faz tenis? Digite 1 para Sim e 2 para nao.  ");// pergunta se ele faz tenis e opcao de escolha
        scanf("%d", &atividade3);// leitura que define se ele ira faz tenis ou nao
        if(atividade3==1) // se esse if for igual a 1 ele é verdadeiro
        {
            filiado[indice].tenis=1;// recebendo um, pois o if é verdadeiro
            contador3=contador3+1;// variavel contadora para o caso 6
        }
        filiado[indice].id=indice+1; // adicionando indice +1 para que quando der o loop ele não rescrever os ids dos associados
        filiado[indice].qtdDep=0;// inicializando a variavel
        quantidadeAssociados++;//adicionando um contador
        printf("O id do associado e: %d \n", filiado[indice].id);// printando o id do associado
        indice=indice+1;// adicionando um a variavel para ela salvar nos vetores e não sobrescrever os antigos
    }

}
char cadastrar_dependente()
{
    int i,identificador,c,continuaDep,indice; //declaração de  variaveis
    printf("Digite o Id do associado que voce deseja se vincular:\n "); //pedido que ele digite o id que deseja cadastrar os dependentes nesse id
    scanf("%d", &identificador);// leitura do id
    if(identificador<=quantidadeAssociados) // if que demonstra se o id digitado está no banco de dados
    {
        i=identificador-1;// i recebendo identificador -1 para que fique
        printf("ID encontrado!\n");
        printf(" %s \n",filiado[indice].nome);// printando nome do associado do id
        while(filiado[i].qtdDep<3)  // while definindo que ele rode so se a variavel for menor que 3
        {
            printf("Digite o nome do dependente: "); // pedindo para ele digitar o nome
            scanf(" %[^\n]s", filiado[i].dep[filiado[i].qtdDep].nome);// leitura
            printf("Digite a idade do dependente: ");// pedindo para ele digitar a idade
            scanf("%d", &filiado[i].dep[filiado[i].qtdDep].idade);// leitura
            while(filiado[i].dep[filiado[i].qtdDep].idade<0)  // while para loopar e garantir que ele digite a idade positiva
            {
                printf("Erro! Digite novamente a idade, desde que ela seja positiva!");// erro se ele não digitar a idade positiva
                scanf("%d", &filiado[i].dep[filiado[i].qtdDep].idade); // leitura da idade novamente
            }
            filiado[i].qtdDep++; // somando 1 para quantidade de dep como contador

            for(c=0; c<filiado[i].qtdDep; c++)  // for com contador para a loopar ate a quantidade de dependentes cadastradas
            {
                printf("O nome do dependente e :%s\n",filiado[i].dep[c].nome);  // printando nome
                printf("A idade do dependente e:%d\n", filiado[i].dep[c].idade); // printando idade
            }
            contadorDep=contadorDep+1;
            printf("Voce deseja cadastrar outro dependente ? 1 para sim e 2 para nao. "); // pergunta se ele quer continuar cadastrando
            scanf("%d",&continuaDep);// leitura caso 1 para sim para continuar e 2 ele da break
            if(continuaDep==2) // if para dar break caso ele digite 2
            {
                break;
            }
        }
        if(filiado[i].qtdDep>=3) // if para definir se o maximo de dependentes foi alcançado
        {
            printf("O numero maximo de dependentes foi alcançado\n");
        }

    }
    else  // else caso ele digite um id que não tem no banco de dados, ele ira voltar para o menu
    {
        printf("ID não encontrado!Volte ao menu!\n");// mensagem informando acima
    }
    return 0;
}


char listarAssociados()
{
    int i;//declaração de  variaveis
    printf("\n");
    printf("==================Listar associados=================\n");
    printf("\n");
    printf("Identificador-Nome-Idade-Qtd dependentes-Modalidades\n");
    printf("\n");
    for(i=0; i<quantidadeAssociados; i++) // for para loopar os cadastrados e mostrar-los
    {
        printf("%d",filiado[i].id); // printando id
        printf(" - %s",filiado[i].nome);// printando nome
        printf(" - %d",filiado[i].idade);// printando idade
        printf(" - %d",filiado[i].qtdDep);// printando quantidade de dependentes
        if(filiado[i].natacao==1) // if para descobrir se o associado faz natação se no banco de dados estiver 1 em seu vetor
        {
            printf(" - Faz natacao!");
        }
        else  // Se no banco de dados não estiver 1 em seu vetor, ele entra no else, sendo assim não realizando natação
        {
            printf(" - Nao faz natacao!");
        }
        if(filiado[i].futsal==1) // if para descobrir se o associado faz futsal se no banco de dados estiver 1 em seu vetor
        {
            printf(" - Faz futsal!");
        }
        else  // Se no banco de dados não estiver 1 em seu vetor, ele entra no else, sendo assim não realizando futsal
        {
            printf(" - Nao faz futsal!");
        }
        if(filiado[i].tenis==1) // if para descobrir se o associado faz tenis se no banco de dados estiver 1 em seu vetor
        {
            printf(" - Faz tenis!\n");
        }
        else   // Se no banco de dados não estiver 1 em seu vetor, ele entra no else, sendo assim não realizando tenis
        {
            printf(" - Nao faz tenis!\n");
        }
    }
    return 0;
}

char Listar_associados_por_modalidade()
{
    int i;//declaração de  variaveis
    printf("\n");
    printf("-----------Lista de Associados por Modalidade--------------\n");
    printf("\n");
    printf("1- Natacao\n");
    printf("2- Futsal\n");
    printf("3- Tenis\n");
    printf("Digite uma das opcoes acima: ");
    scanf("%d",&opc);
    if(opc<3 || opc>0)  //if definindo que não aceiteo opções invalidas
    {
        switch (opc)  // switch para facilitar o caso de selecionar as opções
        {
        case 1:
            for(i=0; i<quantidadeAssociados; i++) // for para inicializar e rodar o loop dos nomes que estão cadastrados na modalidade
            {
                if(filiado[i].natacao==true)  // if limitando que seja printado so os associados que praticam natação
                {
                    printf("%d",filiado[i].id);
                    printf("- %s ",filiado[i].nome);
                }
            }
            break;
        case 2:
            for(i=0; i<quantidadeAssociados; i++) // for para inicializar e rodar o loop dos nomes que estão cadastrados na modalidade
            {
                if(filiado[i].futsal==true) // if limitando que seja printado so os associados que praticam futsal
                {
                    printf("%d",filiado[i].id);
                    printf("- %s ",filiado[i].nome);
                }
            }
            break;
        case 3:
            for(i=0; i<quantidadeAssociados; i++) // for para inicializar e rodar o loop dos nomes que estão cadastrados na modalidade
            {
                if(filiado[i].tenis==true)  // if limitando que seja printado so os associados que praticam tenis
                {
                    printf("%d",filiado[i].id);
                    printf("- %s ",filiado[i].nome);
                }
            }
            break;
        }
    }
    else  // else definindo que se digitar uma opcao errada ele voltará para o menu
    {
        printf("\n Volte ao menu e retorne digitando uma opcao valida!");
    }
    return 0;
}

char pesquisarAssociados()
{
    int i;//declaração de  variaveis
    float media,valor;//declaração de  variaveis
    bool verifica=true;//declaração de  variaveis
    quantidadeAulas=0;//inialização da variavel
    valor=0;//inialização da variavel
    media=0;//inialização da variavel
    printf("===========================================================\n");
    printf("Digite o nome do associado:");
    scanf(" %[^\n]s",pesquisa);// pesquisa do nome do associado
    for(i=0; i<quantidadeAssociados; i++) // for para loopar até a quantidade de associados
    {
        if(strcmp(pesquisa,filiado[i].nome)==0) // if para descobrir se o nome pesquisado existe no banco de dados, se existir ele é ==0
        {
            printf("O Seu resultado da pesquisa e:\n");
            printf("Identificador: %d \n", filiado[i].id);
            printf("Nome: %s \n",filiado[i].nome);
            printf("Idade: %d \n", filiado[i].idade);
            printf("Quantidade de Dependentes: %d \n", filiado[i].qtdDep);
            valor=100+(50*filiado[i].qtdDep)+(30*filiado[i].natacao)+(30*filiado[i].futsal)+(30*filiado[i].tenis);// somatoria das mensalidades
            printf("Valor da mensalidades:%.2f \n", valor);// print do valor das mensalidades
            quantidadeAulas=(filiado[i].futsal+filiado[i].natacao+filiado[i].tenis);// a cada variavel do boll recebe 1, dessa forma somando e sendo a quantidade de aulas
            printf("Quantidade de aulas: %.2f \n", quantidadeAulas);// print da quantidade de aulas
            verifica++;// contador
        }
    }
    if(verifica==false) // if verificando pelo bool false que o associado não foi encontrado, nesse caso avisando e voltando para o menu
    {
        printf("Associado não encontrado! \n");
    }
    return 0;
}
char relatorioAssociados()  //função que mostra o relatorio dos associados
{
    int i,aulasPraticadas,Total,maior;//declaração de  variaveis
    float media,valor;//declaração de  variaveis
    media=0; //inialização da variavel
    valor=0;//inialização da variavel
    Total=0;//inialização da variavel
    maior=0;//inialização da variavel
    aulasPraticadas=0;//inialização da variavel
    for(i=0; i<quantidadeAssociados; i++) // for para loopar e me dar quantas vezes deverá ser executada
    {
        Total=100+(50*filiado[i].qtdDep)+(30*filiado[i].natacao)+(30*filiado[i].futsal)+(30*filiado[i].tenis);// somatoria das mensalidades
        if(Total>maior) // if que irá verificar qual o maior valor passando a todo momento pelo if, até o ultimo maior valor ser salvo
        {
            maior=Total;// maior recebe total
        }
        quantidadeAulas=filiado[i].futsal+filiado[i].natacao+filiado[i].tenis; // quantidade recebe os bools que vale 1 a cada modalidade escolhida pelo associado
        if(quantidadeAulas>=aulasPraticadas)// if que define que as aulaspraticadas recebem quantidade de aula descrita acima;
        {
            aulasPraticadas=quantidadeAulas; //aulas praticadas recebe quantidade de aulas
        }
    }
    printf("===========================================================\n");
    printf("Numero total de associados cadastrados: %d\n ", quantidadeAssociados); //print da quantidade de associados
    printf("Numero total de dependentes cadastrados: %d\n ", contadorDep); //print da quantidade de associados
    printf("Numero de associados que fazem aula de Natacao: %d \n ",contador1);//print da quant dos numeros de associados que fazem natação
    printf("Numero de associados que fazem aula de futsal: %d \n ",contador2);//print da quant dos numeros de associados que fazem futsal
    printf("Numero de associados que fazem aula de Tenis: %d \n ",contador3);//print da quant dos numeros de associados que fazem tenis
    valor= 100*quantidadeAssociados+(50*contadorDep+30*contador1+30*contador2+30*contador3); // variavel que recebe a somatoria das modalidades
    media=(valor/quantidadeAssociados);//variavel media que constitui a media dos valores
    printf("Valor total de todas as mensalidades dos associados: %2.f \n ", valor);// print valor total de mensalidades 
    printf("Valor medio das mensalidades dos associados: %2.f \n ", media);//print valor medio das mensalidades
    printf("Valor de mensalidade mais alto pago por um associado: %d \n ", maior);// print valor da maior mensalidade paga
    for(i=0 ; i<quantidadeAssociados; i++)// for para loopar e me dar quantas vezes deverá ser executada
    {
        if(aulasPraticadas==filiado[i].futsal+filiado[i].natacao+filiado[i].tenis)// if para definir o nome do associado que faz mais aula, através dos bools sendo igual
        {
            printf("O nome do associado que faz mais aula e: %s \n ", filiado[i].nome);// print do nome do associado que faz mais aula
        }
    }
	return 0;
}

void limpaTela(void)												  //função para limpar tela.
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(_unix) || defined(unix) || (defined(APPLE) && defined(MACH_))
    system("clear");
#else
#error "Função não suportada no sistema atual."
#endif
}
void despedida(void)
{
	printf("Tchau! Fique com Deus!\n Que Deus abencoe! \n Sistema Encerrado!");
}

