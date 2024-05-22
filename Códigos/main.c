#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>                   // Adiciona a biblioteca time.h para hora e dia

#define Qtd15 15                    //Define constante de tamanho 15 para variaveis
#define Qtd20 20                    //Define constante de tamanho 20 para variaveis
#define Qtd100 100                  //Define constante de tamanho 100 para variaveis

//Dados para login
char login[Qtd15]="login";         //O login do programa �: 'login'
char login1[Qtd15];
char senha[Qtd15]="senha";         //A senha do programa �: 'senha'
char senha1[Qtd15];

//Variaveis Geral
char opcao_escolha_opcao_desejada;
int opcao_retornar_ao_menu;
int opcao_comprar_ingresso_ou_nao;
int quantidade_tentativa_login=3;     //Caso seja tentado fazer login mais de 3 vezes, o programa impede o login para previnir logins fraudulentos
int quantidade_tentativa_login1;
int teste;
int mostrador_qtd_login=4;
int tipo_de_ingresso_comprar;
int contador1=0;
int contador2=0;
int contador3=0;
int valor_ingressos;
int resposta_comprar_mais_ingresso;
FILE* ponteiro_arquivo_txt;
FILE* ponteiro_arquivo_csv;
int voltar_p_menu;
char data_hora[30];
int questionario_sim_nao;
int exposicao_apreciada;

//Variaveis para Verificador de Ingresso
int codigo_ingressos_verificador[Qtd100];
int ingresso_validador;
int i;
int cont;

//Dados Question�rio Marie
char nome_pesquisa_marie[Qtd20];
char gostou_obras_marie_pesquisa[Qtd20];
char conhecia_marie_pesquisa[Qtd20];
int recomendar_aos_amigos_pesquisa_marie;
int feito_marie_pesquisa;
char contribuicoes_pesquisa_marie[Qtd20];
char inspiradora_pesquisa_marie[Qtd20];

//Dados Question�rio Centen�rio
char nome_pesquisa_centenario[Qtd20];
char gostou_obras_centenario_pesquisa[Qtd20];
char conhecia_centenario_pesquisa[Qtd20];
int recomendar_aos_amigos_pesquisa_centenario;
int feito_centenario_pesquisa;
char contribuicoes_pesquisa_centenario[Qtd20];
char inspiradora_pesquisa_centenario[Qtd20];

//Dados Question�rio Olimpiadas
char nome_pesquisa_olimpiadas[Qtd20];
char gostou_obras_olimpiadas_pesquisa[Qtd20];
char conhecia_olimpiadas_pesquisa[Qtd20];
int recomendar_aos_amigos_pesquisa_olimpiadas;
int feito_olimpiadas_pesquisa;
char contribuicoes_pesquisa_olimpiadas[Qtd20];
char inspiradora_pesquisa_olimpiadas[Qtd20];

//Struct para os tipos de ingressos vendidos
struct tipos_de_ingresso {
    int qtd_ingresso_inteiro;
    int qtd_ingresso_meia;
    int qtd_ingresso_isensao;
    int codigo_ingressos;
}tipos_ingresso;

struct tipos_de_ingresso tipos_ingresso;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    tela_inicial();
    menu_opcoes();
    tela_de_login();
    opcoes_selecionadas();
    sistema_bloqueado();
    questionario_marie();
    questionario_centenario();
    questionario_olimpiadas();
    formas_pagamento();

}

void tela_inicial(){
    system("cls");
      // Tela de in�cio
    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("* Bem-vindo ao Museu das Artes Inspiradoras! *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    printf("\n");

      // Mensagem atrativa
    printf("Explore o mundo fascinante da criatividade e da express�o art�stica!\n");
    printf("\n");
    printf("Nosso museu � um lugar �nico, repleto de obras que inspiram e emocionam.\n");
    printf("\n");
    printf("Descubra a beleza, a inova��o e a paix�o por tr�s de cada pe�a exposta.\n");
    printf("\n");
    printf("Venha vivenciar a magia das artes conosco!\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    system("pause");

    return 0;

}

void menu_opcoes() {
    system("cls");
    printf("Escolha a Op��o Desejada\n");
    printf("\n");
    printf("1 - Mulheres que inspiraram o mundo: Cientista Marie Curie\n");
    printf("2 - Centen�rio da Semana da Arte Moderna\n");
    printf("3 - Relembrando os Jogos Ol�mpicos 2006\n");
    printf("4 - Validar Ingresso\n");
    printf("5 - Sair do Programa\n");
    printf("\n");
    printf("Digite a op��o desejada\n");

    scanf("%s",& opcao_escolha_opcao_desejada);
    opcoes_selecionadas();
}

void opcoes_selecionadas() {
    system("cls");
    switch(opcao_escolha_opcao_desejada) {

    case '1':                                                       //FUNCIONANDO - OK
        system("cls");                                              //Entra na op��o de venda da Marie, fala sobre ela, e pergunta dos ingressos
        printf("Op��o Selecionada: Marie Curie\n");
        printf("\n");
        printf("Algumas informa��es sobre a Marie Curie e sobre as obras que ser�o expostas\n");
        printf("\n");
        printf("Seu nome completo era: Marie Sktodowska Curie\n");
        printf("Seu nascimento aconteceu no dia 7 de novembro de 1867, em Vars�via, Pol�nia (ent�o parte do Imp�rio Russo)\n");
        printf("Um de seus principais feitos foram as descobertas dos elementos radioativos Pol�nio e do R�dio\n");
        printf("\n");
        printf("Nesta exposi��o exibiremos obras que retratam a vida de Marie Curie, e tab�m obras que demonstram sobre suas descobertas\n");
        printf("Gostaria de comprar um ingresso para est� exibi��o?\n");
        printf("\n");
        digite_novamente:
        printf("1 - Comprar Ingresso\n");
        printf("2 - Retornar ao Menu\n");
        scanf("%d",& opcao_comprar_ingresso_ou_nao);
        if (opcao_comprar_ingresso_ou_nao == 1) {
            tela_de_login();
        }
        else if (opcao_comprar_ingresso_ou_nao == 2) {
            menu_opcoes();

        }
        else {
            system("cls");
            printf("Op��o Inexistente Digite Novamente!\n");
            sleep(2);
            goto digite_novamente;
        }

    break;

    case '2':                                                       //FUNCIONANDO - OK
        system("cls");
        printf("Op��o Selecionada: Centen�rio da Semana da Arte Moderna\n");
        printf("\n");
        printf("Algumas informa��es sobre o Centen�rio da Semana da Arte Moderna e sobre as obras que ser�o expostas\n");
        printf("\n");
        printf("De 13 a 18 de fevereiro de 1922 acontecia, em S�o Paulo, a Semana de Arte Moderna ou 'Semana de 22', como ficou conhecida na Hist�ria.\n");
        printf("O evento foi organizado para celebrar o centen�rio da independ�ncia do Brasil (em 1822), e aconteceu no Teatro Municipal de S�o Paulo, marcando o in�cio do Modernismo no Brasil.)\n");
        printf("\n");

        printf("Nesta exposi��o exibiremos obras que retratam o Centen�rio da Semana da Arte Moderna e suas obras mais conhecidas como A Boba, O Homem Amarelo e A Estudante Russa. \n");
        printf("Gostaria de comprar um ingresso para est� exibi��o?\n");
        printf("\n");
        digite_novamente2:
        printf("1 - Comprar Ingresso\n");
        printf("2 - Retornar ao Menu\n");
        scanf("%d",& opcao_comprar_ingresso_ou_nao);
        if (opcao_comprar_ingresso_ou_nao == 1) {
            tela_de_login();
}        else if (opcao_comprar_ingresso_ou_nao == 2) {
            menu_opcoes();
        }
        else {
            system("cls");
            printf("Op��o Inexistente Digite Novamente!\n");
            sleep(2);
            goto digite_novamente2;
        }

    break;

    case '3':                                                       //FUNCIONANDO - OK
        system("cls");
        printf("Op��o Selecionada: Jogos Ol�mpicos 2006\n");
        printf("\n");
        printf("Algumas informa��es sobre os Jogos Ol�mpicos de 2006 e sobre as obras que ser�o expostas\n");
        printf("\n");
        printf("Foi um evento multiesportivo realizado na cidade de Turim, na It�lia, entre 10 e 26 de fevereiro de 2006. Essa foi a terceira vez que a It�lia recebeu uma edi��o dos Jogos Ol�mpicos..\n");
        printf("\n");
        printf("Nesta exposi��o exibiremos obras que retratam os Jogos Ol�mpicos de Inverno de 2006 e como foi o evento para os competidores que representaram o Brasil, sendo 6 homens e 3 mulheres em 4 modalidades. \n");
        printf("Gostaria de comprar um ingresso para est� exibi��o?\n");
        printf("\n");

        digite_novamente3:
        printf("1 - Comprar Ingresso\n");
        printf("2 - Retornar ao Menu\n");
        scanf("%d",& opcao_comprar_ingresso_ou_nao);
        if (opcao_comprar_ingresso_ou_nao == 1) {
            tela_de_login();
        }
        else if (opcao_comprar_ingresso_ou_nao == 2) {
            menu_opcoes();
        }
        else {
            system("cls");
            printf("Op��o Inexistente Digite Novamente!\n");
            sleep(2);
            goto digite_novamente3;
        }

    break;

    case '4':                                                       //FAZENDO
        system("cls");
        printf("Op��o Selecionada: Validar Ingresso\n");
        printf("\n");
        printf("Digite o c�digo que deseja validar\n");
        scanf("%d",&ingresso_validador);

        for (i = 0; i <= 100; i++) {
            if (ingresso_validador == codigo_ingressos_verificador[i]) {
                codigo_ingressos_verificador[i] = 0;
                printf("O c�digo pesquisado � valido!\n");
                sleep(2);

                //NESSE MOMENTO O CLIENTE APRECIA A EXPOSI��O, AP�S ISSO, ELE RETORNA E ENCONTRA ESSAS OP��ES NO COMPUTADOR AO LADO DA SAIDA

                errada:
                system("cls");
                printf("Ap�s apreciar a exposi��o, voc� gostaria de participar de um breve question�rio? 1 - Sim || 2 - N�o\n");
                scanf("%d",& questionario_sim_nao);
                if (questionario_sim_nao == 1) {
                    quest:
                    printf("Qual exposi��o voc� acabou de apreciar? 1 - Marie || 2 - Centen�rio || 3 - Olimp�adas\n");
                    scanf("%d",& exposicao_apreciada);

                    if (exposicao_apreciada == 1) {
                        printf("Redirecionando para o question�rio em 3 segundos...\n");
                        sleep(1);
                        printf("Redirecionando para o question�rio em 2 segundos...\n");
                        sleep(1);
                        printf("Redirecionando para o question�rio em 1 segundos...\n");
                        sleep(1);
                        questionario_marie();
                    }
                    else if (exposicao_apreciada == 2) {
                        printf("Redirecionando para o question�rio em 3 segundos...\n");
                        sleep(1);
                        printf("Redirecionando para o question�rio em 2 segundos...\n");
                        sleep(1);
                        printf("Redirecionando para o question�rio em 1 segundos...\n");
                        sleep(1);
                        questionario_centenario();
                    }
                    else if (exposicao_apreciada == 3) {
                        printf("Redirecionando para o question�rio em 3 segundos...\n");
                        sleep(1);
                        printf("Redirecionando para o question�rio em 2 segundos...\n");
                        sleep(1);
                        printf("Redirecionando para o question�rio em 1 segundos...\n");
                        sleep(1);
                        questionario_olimpiadas();
                    }
                    else {
                        printf("Op��o errada!\n");
                        goto quest;
                    }
                }
                else if (questionario_sim_nao == 2) {
                    printf("Retornando ao menu em 3 segundos...\n");
                    sleep(1);
                    printf("Retornando ao menu em 2 segundos...\n");
                    sleep(1);
                    printf("Retornando ao menu em 1 segundos...\n");
                    sleep(1);
                    menu_opcoes();
                }
                else {
                    printf("Op��o errada!\n");
                    sleep(2);
                    goto errada;
                }
            }
        }

        printf("O c�digo pesquisado � Inv�lido!\n");
        printf("Retornando ao menu em 3 segundos...\n");
        sleep(1);
        printf("Retornando ao menu em 2 segundos...\n");
        sleep(1);
        printf("Retornando ao menu em 1 segundos...\n");
        sleep(1);
        menu_opcoes();

    break;

    case '5':                                                       //FUNCIONANDO - OK
        system("cls");                                              //Encerra o programa
        printf("Saindo do programa em 3 segundos...\n");
        sleep(1);
        printf("Saindo do programa em 2 segundos...\n");
        sleep(1);
        printf("Saindo do programa em 1 segundos...\n");
        sleep(1);
        exit(0);
    break;

    default:
        menu_opcoes();
    break;
    }
}

void tela_de_login() {
    system("cls");

    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("|  Fa�a Login Para Habilitar a Venda  |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n");

    printf("\n");
    printf("Tentativa(s) de login restante(s): %d\n", quantidade_tentativa_login);

    printf("\nDigite seu login: ");
    scanf("%s", login1);
    printf("Digite sua senha: ");
    scanf("%s", senha1);

    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0) { // Compara o login e a senha
        sleep(1);
        system("cls");
        printf("Bem-vindo(a) ao sistema!\n");
        sleep(1);
        venda_de_ingresso();
    } else {
        quantidade_tentativa_login--;

        if (quantidade_tentativa_login > 0) {
            system("cls");
            printf("Login inv�lido. Tentativas restantes: %d\n\n", quantidade_tentativa_login);
            sleep(2);
            tela_de_login(); // Chama a fun��o novamente para uma nova tentativa
        } else {
            system("cls");
            printf("Quantidade de logins excedida!\n");
            printf("\n");
            printf("Login bloqueado!\n");
            printf("\n");
            printf("Solicite o suporte t�cnico!\n");
            sleep(2);
            sistema_bloqueado();
        }
    }

}

void obter_data_hora_atual() {
    time_t t;
    struct tm* info_tempo;

    time(&t);
    info_tempo = localtime(&t);

    strftime(data_hora, 30, "%d/%m/%Y %H:%M:%S", info_tempo);
}

void venda_de_ingresso() {                                          //FUNCIONANDO - OK
    system("cls");
    printf("Tipos de ingresso:\n");
    printf("\n");
    printf("1 - Entrada Inteira\n");
    printf("2 - Meia Entrada\n");
    printf("3 - Isen��o de Pagamento\n");
    printf("\n");
    printf("Informe o tipo de ingresso que deseja comprar:\n");
    scanf("%d",& tipo_de_ingresso_comprar);

    switch (tipo_de_ingresso_comprar) {

    case 1:
        do {
        system("cls");
        printf("Op��o Selecionada: Entrada Inteira\n");
        printf("\n");
        printf("Cada ingresso possui o valor de R$10,00, informe a quantidade que deseja comprar:\n");
        scanf("%d",& tipos_ingresso.qtd_ingresso_inteiro);

        valor_ingressos = valor_ingressos + tipos_ingresso.qtd_ingresso_inteiro * 10;
        opcao_errada:
        printf("Deseja comprar mais ingressos?\n");
        printf("1 - Sim\n");
        printf("2 - N�o\n");
        scanf("%d",& resposta_comprar_mais_ingresso);

        if (resposta_comprar_mais_ingresso == 1) {
            venda_de_ingresso();
        }
        else if (resposta_comprar_mais_ingresso == 2) {
            contador1 = 1;
            goto saiu;
        }
        else {
            goto opcao_errada;
        }

        } while (contador1 == 0);
        saiu:
        printf("Insira o c�digo do ingresso gerado:\n");
        scanf("%d",& tipos_ingresso.codigo_ingressos);

        codigo_ingressos_verificador[cont] = tipos_ingresso.codigo_ingressos;
        cont++;

        formas_pagamento();

        printf("Aguardando pagamento dos ingressos...\n");
        sleep(2);
        printf("O valor foi devidamente pago!\n");
        sleep(2);
        printf("O comprovante de pagamento foi emitido!\n");

        obter_data_hora_atual();
        ponteiro_arquivo_txt = fopen("comprovante_de_pagamento.txt", "a");
        fprintf(ponteiro_arquivo_txt, "Este comprovante certifica o pagamento de R$%d pagos pelo cliente no ato da compra do(s) ingresso(s)\n",valor_ingressos);
        fprintf(ponteiro_arquivo_txt, "Data e hora da compra: %s\n", data_hora);
        fclose(ponteiro_arquivo_txt);

        digitenovamente:
        printf("Pressione a tecla '9' para retornar ao menu!\n");
        scanf("%d",& voltar_p_menu);
        if (voltar_p_menu == 9) {
            menu_opcoes();
        }
        else {
            goto digitenovamente;
        }
    break;

    case 2:
        system("cls");
        printf("Op��o Selecionada: Meia Entrada\n");
        printf("\n");
        printf("Estudantes, mediante apresenta��o de carteira de estudante v�lida.\n");
        printf("Cada ingresso possui o valor de R$5,00, informe a quantidade que deseja comprar:\n");
        scanf("%d",& tipos_ingresso.qtd_ingresso_meia);

        valor_ingressos = valor_ingressos + tipos_ingresso.qtd_ingresso_meia * 5;
        opcao_errada2:
        printf("Deseja comprar mais ingressos?\n");
        printf("1 - Sim\n");
        printf("2 - N�o\n");
        scanf("%d",& resposta_comprar_mais_ingresso);

        if (resposta_comprar_mais_ingresso == 1) {
            venda_de_ingresso();
        }
        else if (resposta_comprar_mais_ingresso == 2) {
            contador2 = 1;
            goto saiu2;
        }

        else {
            goto opcao_errada2;
        }
        while (contador2 == 0);
        saiu2:
        printf("Insira o c�digo do ingresso gerado:\n");
        scanf("%d",& tipos_ingresso.codigo_ingressos);

        codigo_ingressos_verificador[cont] = tipos_ingresso.codigo_ingressos;
        cont++;

        formas_pagamento();

        printf("Aguardando pagamento dos ingressos...\n");
        sleep(2);
        printf("O valor foi devidamente pago!\n");
        sleep(2);
        printf("O comprovante de pagamento foi emitido!\n");

        obter_data_hora_atual();
        ponteiro_arquivo_txt = fopen("comprovante_de_pagamento.txt", "a");
        fprintf(ponteiro_arquivo_txt, "Este comprovante certifica o pagamento de R$%d pagos pelo cliente no ato da compra do(s) ingresso(s)\n",valor_ingressos);
        fprintf(ponteiro_arquivo_txt, "Data e hora da compra: %s\n", data_hora);
        fclose(ponteiro_arquivo_txt);

        digitenovamente2:
        printf("Pressione a tecla '9' para retornar ao menu!\n");
        scanf("%d",& voltar_p_menu);
        if (voltar_p_menu == 9) {
            menu_opcoes();
        }
        else {
            goto digitenovamente2;
        }
    break;

    case 3:
        system("cls");
        printf("Op��o Selecionada: Isen��o de Pagamento\n");
        printf("\n");
        printf("Crian�as de at� 2 anos n�o pagam o ingresso!\n");
        printf("Informe a quantidade de ingressos que deseja solicitar:\n");
        scanf("%d",& tipos_ingresso.qtd_ingresso_isensao);

        valor_ingressos = valor_ingressos;
        opcao_errada3:
        printf("Deseja comprar mais ingressos?\n");
        printf("1 - Sim\n");
        printf("2 - N�o\n");
        scanf("%d",& resposta_comprar_mais_ingresso);

        if (resposta_comprar_mais_ingresso == 1) {
            venda_de_ingresso();
        }
        else if (resposta_comprar_mais_ingresso == 2) {
            contador3 = 1;
            goto saiu3;
        }

        else {
            goto opcao_errada3;
        }
        while (contador3 == 0);
        saiu3:
        printf("Insera o c�digo do ingresso gerado\n");
        scanf("%d",& tipos_ingresso.codigo_ingressos);

        codigo_ingressos_verificador[cont] = tipos_ingresso.codigo_ingressos;
        cont++;

        formas_pagamento();

        printf("Aguardando pagamento dos ingressos...\n");
        sleep(2);
        printf("O valor foi devidamente pago!\n");
        sleep(2);
        printf("O comprovante de pagamento foi emitido!\n");

        obter_data_hora_atual();
        ponteiro_arquivo_txt = fopen("comprovante_de_pagamento.txt", "a");
        fprintf(ponteiro_arquivo_txt, "Este comprovante certifica o pagamento de R$%d pagos pelo cliente no ato da compra do(s) ingresso(s)\n",valor_ingressos);
        fprintf(ponteiro_arquivo_txt, "Data e hora da compra: %s\n", data_hora);
        fclose(ponteiro_arquivo_txt);

        digitenovamente3:
        printf("Pressione a tecla '9' para retornar ao menu!\n");
        scanf("%d",& voltar_p_menu);
        if (voltar_p_menu == 9) {
            menu_opcoes();
        }
        else {
            goto digitenovamente3;
        }
    break;

    default:
        venda_de_ingresso();
    break;
    }
}

void sistema_bloqueado() {                                          //FUNCIONANDO - OK
    system("cls");
    printf("-----------------------\n");
    printf("|                     |\n");
    printf("|  SISTEMA BLOQUEADO  |\n");
    printf("|                     |\n");
    printf("-----------------------\n");
    sleep(2);
    printf("Saindo do programa em 3 segundos...\n");
    sleep(1);
    printf("Saindo do programa em 2 segundos...\n");
    sleep(1);
    printf("Saindo do programa em 1 segundos...\n");
    sleep(1);
    exit(0);
}

void questionario_marie() {                                               //FUNCIONANDO - OK
    system("cls");
    printf("Por favor, responde a este breve question�rio sobre a exposi��o que acabou de prestigiar da Marie Curie!\n");
    printf("\n");
    printf("Informe seu primeiro nome\n");
    scanf("%s",& nome_pesquisa_marie);
    printf("Voc� gostou das obras apresentadas? Responda apenas Sim ou Nao!\n");
    scanf("%s",& gostou_obras_marie_pesquisa);
    printf("Voc� j� conhecia a Marie Curie? Responda apenas Sim ou Nao!\n");
    scanf("%s", conhecia_marie_pesquisa);
    printf("De 0 at� 10, o qu�o bem voc� acha que o museu apresentou as informa��es sobre os feitos de Marie Curie?\n");
    scanf("%d",& feito_marie_pesquisa);
    printf("O museu destaca as contribui��es cient�ficas de Marie Curie de maneira clara? Responda apenas Sim ou Nao!\n");
    scanf("%s",& contribuicoes_pesquisa_marie);
    printf("A experi�ncia oferecida pelo museu foi educativa para voc�? Responda apenas Sim ou Nao!\n");
    scanf("%s",& inspiradora_pesquisa_marie);
    printf("De 0 a 10, qual a probabilidade de voc� recomendar nosso museu a amigos ou familiares?\n");
    scanf("%d",& recomendar_aos_amigos_pesquisa_marie);

    obter_data_hora_atual();
    ponteiro_arquivo_csv = fopen("respostas_do_questionario_marie_curie.csv", "a");
    fprintf(ponteiro_arquivo_csv,"%s;%s;%s;%d;%s;%s;%d;Data e hora da avalia��o: %s\n", nome_pesquisa_marie,gostou_obras_marie_pesquisa,conhecia_marie_pesquisa,feito_marie_pesquisa,contribuicoes_pesquisa_marie,inspiradora_pesquisa_marie,recomendar_aos_amigos_pesquisa_marie,data_hora);
    fclose(ponteiro_arquivo_csv);

    system("cls");
    printf("Obrigado por participar de nossa pesquisa!\n");
    sleep(2);
    printf("\n");
    printf("Redirecionando para a tela inicial do programa em 3 segundos...\n");
    sleep(1);
    printf("Redirecionando para a tela inicial do programa em 2 segundos...\n");
    sleep(1);
    printf("Redirecionando para a tela inicial do programa em 1 segundos...\n");
    sleep(1);
    menu_opcoes();
}

void questionario_centenario() {                                            //FUNCIONANDO - OK
    system("cls");
    printf("Por favor, responde a este breve question�rio sobre a exposi��o que acabou de prestigiar do Centen�rio da Semana da Arte Moderna!\n");
    printf("\n");
    printf("Informe seu primeiro nome\n");
    scanf("%s",& nome_pesquisa_centenario);
    printf("Voc� gostou das obras apresentadas? Responda apenas Sim ou Nao!\n");
    scanf("%s",& gostou_obras_centenario_pesquisa);
    printf("Voc� j� sabia da existencia do Centen�rio da Semana da Arte Moderna? Responda apenas Sim ou Nao!\n");
    scanf("%s", conhecia_centenario_pesquisa);
    printf("De 0 at� 10, o qu�o bem voc� acha que o museu apresentou as informa��es sobre o Centen�rio da Semana da Arte Moderna?\n");
    scanf("%d",& feito_centenario_pesquisa);
    printf("O museu destaca as contribui��es do Centen�rio da Semana da Arte Moderna de maneira clara? Responda apenas Sim ou Nao!\n");
    scanf("%s",& contribuicoes_pesquisa_centenario);
    printf("A experi�ncia oferecida pelo museu foi educativa para voc�? Responda apenas Sim ou Nao!\n");
    scanf("%s",& inspiradora_pesquisa_centenario);
    printf("De 0 a 10, qual a probabilidade de voc� recomendar nosso museu a amigos ou familiares?\n");
    scanf("%d",& recomendar_aos_amigos_pesquisa_centenario);

    obter_data_hora_atual();
    ponteiro_arquivo_csv = fopen("respostas_do_questionario_centenario.csv", "a");
    fprintf(ponteiro_arquivo_csv,"%s;%s;%s;%d;%s;%s;%d;Data e hora da compra: %s\n", nome_pesquisa_centenario,gostou_obras_centenario_pesquisa,conhecia_centenario_pesquisa,feito_centenario_pesquisa,contribuicoes_pesquisa_centenario,inspiradora_pesquisa_centenario,recomendar_aos_amigos_pesquisa_centenario,data_hora);
    fclose(ponteiro_arquivo_csv);

    system("cls");
    printf("Obrigado por participar de nossa pesquisa!\n");
    sleep(2);
    printf("\n");
    printf("Redirecionando para a tela inicial do programa em 3 segundos...\n");
    sleep(1);
    printf("Redirecionando para a tela inicial do programa em 2 segundos...\n");
    sleep(1);
    printf("Redirecionando para a tela inicial do programa em 1 segundos...\n");
    sleep(1);
    menu_opcoes();
}

void questionario_olimpiadas() {                                                //FUNCIONANDO - OK
    system("cls");
    printf("Por favor, responde a este breve question�rio sobre a exposi��o que acabou de prestigiar das Olimp�adas de 2006!\n");
    printf("\n");
    printf("Informe seu primeiro nome\n");
    scanf("%s",& nome_pesquisa_olimpiadas);
    printf("Voc� gostou das obras apresentadas? Responda apenas Sim ou Nao!\n");
    scanf("%s",& gostou_obras_olimpiadas_pesquisa);
    printf("Voc� j� sabia dos esportes presentes nas Olimp�adas de 2006? Responda apenas Sim ou Nao!\n");
    scanf("%s", conhecia_olimpiadas_pesquisa);
    printf("De 0 at� 10, o qu�o bem voc� acha que o museu apresentou as informa��es sobre as Olimp�adas de Inverno de 2006?\n");
    scanf("%d",& feito_olimpiadas_pesquisa);
    printf("O museu destaca a import�ncia da Olimp�adas de Inverno de 2006 de maneira clara? Responda apenas Sim ou Nao!\n");
    scanf("%s",& contribuicoes_pesquisa_olimpiadas);
    printf("A experi�ncia oferecida pelo museu foi educativa para voc�? Responda apenas Sim ou Nao!\n");
    scanf("%s",& inspiradora_pesquisa_olimpiadas);
    printf("De 0 a 10, qual a probabilidade de voc� recomendar nosso museu a amigos ou familiares?\n");
    scanf("%d",& recomendar_aos_amigos_pesquisa_olimpiadas);

    obter_data_hora_atual();
    ponteiro_arquivo_csv = fopen("respostas_do_questionario_olimpiadas.csv", "a");
    fprintf(ponteiro_arquivo_csv,"%s;%s;%s;%d;%s;%s;%d;Data e hora da compra: %s\n",nome_pesquisa_olimpiadas,gostou_obras_olimpiadas_pesquisa,conhecia_olimpiadas_pesquisa,feito_olimpiadas_pesquisa,contribuicoes_pesquisa_olimpiadas,inspiradora_pesquisa_olimpiadas,recomendar_aos_amigos_pesquisa_olimpiadas,data_hora);
    fclose(ponteiro_arquivo_csv);

    system("cls");
    printf("Obrigado por participar de nossa pesquisa!\n");
    sleep(2);
    printf("\n");
    printf("Redirecionando para a tela inicial do programa em 3 segundos...\n");
    sleep(1);
    printf("Redirecionando para a tela inicial do programa em 2 segundos...\n");
    sleep(1);
    printf("Redirecionando para a tela inicial do programa em 1 segundos...\n");
    sleep(1);
    menu_opcoes();
}

void formas_pagamento() {
    int opcao;
    novamente:
    system("cls");
    printf("Escolha a forma de pagamento:\n");
    printf("1 - Dinheiro\n");
    printf("2 - Cart�o de Cr�dito\n");
    printf("3 - Cart�o de D�bito\n");
    printf("4 - PIX\n");
    printf("Digite o n�mero correspondente � sua escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Forma de pagamento escolhida: dinheiro.\n");
            printf("\n");
            break;

        case 2:
            printf("Forma de pagamento escolhida: cart�o de cr�dito.\n");
            printf("\n");
            break;

        case 3:
            printf("Forma de pagamento escolhida: cart�o de d�bito.\n");
            printf("\n");
            break;

        case 4:
            printf("Forma de pagamento escolhida: PIX.\n");
            printf("\n");
            break;

        default:
            printf("Op��o inv�lida.\n");
            sleep(2);
            goto novamente;
            break;
    }

    return 0;
}
