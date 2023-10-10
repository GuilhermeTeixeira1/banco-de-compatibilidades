#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// DEFINES
#define stop 0
#define Tamanho_Gosto_Musical 6
#define Tamanho_Comida_Favorita 7
#define Tamanho_Hobbies 7

/*
    fazer um banco de dados para consultar posteriormente e fazer um percentual de combinação entre um usuario e outro (mostrar o percentual)
    dados a serem cadastrados: nome, cidade, genero, numero, gostos musicais, hobbies, comida favorita
    gostos musicais = (funk, rock, pagode, rap, pop)
    Hobbies: (academia, séries, esportes, viajar, videogame, procrastinar)
    Comidas: (churrasco, pizza, sushi, hambúrger, macobronwie, brisadeiro)

*/

   // STRUCTS E FUNÇÕES
    typedef struct{
        char NomeSobrenome[50], cidade[20];
        int GostoMusical[Tamanho_Gosto_Musical], hobbies[Tamanho_Hobbies], ComidaFavorita[Tamanho_Comida_Favorita], idade, sexo;
    }FichaCadrastro;



    void Conserta_Cagada_Arquivo(FILE *arquivo){
        int Num_Pessoas = 0, offset = 8;

        rewind(arquivo);

        fwrite(&Num_Pessoas, 4, 1, arquivo);
        fwrite(&offset, 4, 1, arquivo);
    }



    int Exibir_Menu(){
        int opcao;

        printf("\no que voce deseja fazer?\n\n");
        printf("1 - cadastrar usuario\n2 - ver compatibilidade de todos os usuarios\n");
        printf("3 - buscar por alguma caracteristica\n4 - sair\n");
        printf("escolha: ");
        fflush(stdin);
        scanf("%i", &opcao);

        return opcao;
    }



    FichaCadrastro cadastrar(){
        FichaCadrastro pessoa;
        int item;
        char *letra;

        // recebendo nome
        printf("\n\ndigite seu nome e o ULTIMO sobrenome: ");
        fflush(stdin);
        scanf("%[^\n]s", pessoa.NomeSobrenome);

        // deixando em um formato padrao
        pessoa.NomeSobrenome[0] = toupper(pessoa.NomeSobrenome[0]);

        for(letra = &pessoa.NomeSobrenome[1]; *letra != '\0'; letra++){
            if (*letra == ' '){
                letra++;
                *letra = toupper(*letra);
            }
            else if (*letra >= 'A' && *letra <= 'Z'){
                *letra = tolower(*letra);
            }
        }
        system("cls");

        // recebendo cidade
        printf("digite sua cidade (sem acentos): ");
        fflush(stdin);
        scanf("%[^\n]s", pessoa.cidade);

        // deixando em um formato padrao
        pessoa.cidade[0] = toupper(pessoa.cidade[0]);
        for(letra = &pessoa.cidade[1]; *letra != '\0'; letra++){
            if (*letra == ' '){
                letra++;
                *letra = toupper(*letra);
            }
            else if (*letra >= 'A' && *letra <= 'Z'){
                *letra = tolower(*letra);
            }
        }
        system("cls");

        //recebendo sexo
        printf("digite os NUMEROS correspondente ao seu sexo:\n");
        printf("1 - masculino\n");
        printf("2 - feminino\n");
        printf("3 - outro\n");
        printf("escolha: ");
        fflush(stdin);
        scanf("%i", &pessoa.sexo);

        system("cls");
        while(pessoa.sexo < 1 || pessoa.sexo > 3){
            printf("numero invalido, digite novamente:\n");
            printf("1 - masculino\n");
            printf("2 - feminino\n");
            printf("3 - outro\n");
            printf("escolha: ");
            fflush(stdin);
            scanf("%i", &pessoa.sexo);
            printf("\n");
        }

        system("cls");

        // recebendo idade
        printf("digite sua idade (apenas os numeros): ");
        fflush(stdin);
        scanf("%i", &pessoa.idade);

        while(pessoa.idade <= 0 || pessoa.idade >= 130){
            system("cls");
            printf("idade invalida, digite denovo, burro !\n\n");
            printf("digite sua idade (apenas os numeros): ");
            fflush(stdin);
            scanf("%i", &pessoa.idade);
            printf("\n");
        }

        system("cls");

        // escolhendo os gostos musicais
        do{
            pessoa.GostoMusical[stop] = 10; // garatindo que so vai ter 0 quando o usuario digitar

            printf("digite os NUMEROS correspondente ao seu gostos musicais no seguinte formato: (numero ENTER numero ENTER):\n");
            printf("0 - parar\n");
            printf("1 - funk\n");
            printf("2 - rock\n");
            printf("3 - pagode\n");
            printf("4 - rap\n");
            printf("5 - pop\n");
            printf("escolha: ");

            fflush(stdin);
            scanf("%i", &item);

            while(item > 5 || item < 0){ // proteção anti burro
                system("cls");

                printf("numero digitado invalido, tente denovo:\n");
                printf("0 - parar\n");
                printf("1 - funk\n");
                printf("2 - rock\n");
                printf("3 - pagode\n");
                printf("4 - rap\n");
                printf("5 - pop\n");
                printf("escolha: ");

                fflush(stdin);
                scanf("%i", &item);

                if (item >= 0 && item <= 5){
                    pessoa.GostoMusical[item] = 1;
                }
                printf("\n"); // formatando pra ficar bonito na tela
            }
            printf("\n"); // formatando pra ficar bonito na tela
            pessoa.GostoMusical[item] = 1;
        } while (pessoa.GostoMusical[stop] != 1);

        // escolhendo os hobbies
        system("cls");

        // escolhendo os gostos musicais
        do{
            pessoa.hobbies[stop] = 10; // garatindo que so vai ter 0 quando o usuario digitar

            printf("digite os NUMEROS correspondente ao seus hobbies no seguinte formato: (numero ENTER numero ENTER):\n");
            printf("0 - parar\n");
            printf("1 - academia\n");
            printf("2 - series\n");
            printf("3 - esportes\n");
            printf("4 - viajar\n");
            printf("5 - videogame\n");
            printf("6 - procrastinar\n");
            printf("escolha: ");

            fflush(stdin);
            scanf("%i", &item);

            while (item > 6 || item < 0){ // proteção anti burro
                system("cls");

                printf("numero digitado invalido, tente denovo:\n");
                printf("0 - parar\n");
                printf("1 - academia\n");
                printf("2 - series\n");
                printf("3 - esportes\n");
                printf("4 - viajar\n");
                printf("5 - videogame\n");
                printf("6 - procrastinar\n");
                printf("escolha: ");

                fflush(stdin);
                scanf("%i", &item);

                if(item >=0 && item <=6){
                    pessoa.hobbies[item] = 1;
                }
                printf("\n");
            }
            printf("\n"); // formatando pra ficar bonito na tela
            pessoa.hobbies[item] = 1;

        } while (pessoa.hobbies[stop] != 1);

        system("cls");

        // escolhendo os gostos musicais
        do{
            pessoa.ComidaFavorita[stop] = 10; // garatindo que so vai ter 0 quando o usuario digitar

            printf("digite os NUMEROS correspondentes a suas comidas favoritas no seguinte formato: (numero ENTER numero ENTER):\n");
            printf("0 - parar\n");
            printf("1 - churrasco\n");
            printf("2 - pizza\n");
            printf("3 - sushi\n");
            printf("4 - hamburguer\n");
            printf("5 - brownie\n");
            printf("6 - brigadeiro\n");
            printf("escolha: ");

            fflush(stdin);
            scanf("%i", &item);

            while (item > 6 || item < 0){ // proteção anti burro
                system("cls");

                printf("numero digitado invalido, tente denovo:\n");
                printf("0 - parar\n");
                printf("1 - churrasco\n");
                printf("2 - pizza\n");
                printf("3 - sushi\n");
                printf("4 - hamburguer\n");
                printf("5 - brownie\n");
                printf("6 - brigadeiro\n");
                printf("escolha: ");

                fflush(stdin);
                scanf("%i", &item);

                if(item >=0 && item <=6){
                    pessoa.ComidaFavorita[item] = 1;
                    }
                printf("\n");
            }
            printf("\n"); // formatando pra ficar bonito na tela
            pessoa.ComidaFavorita[item] = 1;

        } while (pessoa.ComidaFavorita[stop] != 1);

        system("cls");

        return pessoa;
    }



    void Escrever_Arquivo(FILE *arquivo, FichaCadrastro pessoa){
        int Num_pessoas, offset = 8, Tamanho_Struct = sizeof(pessoa);

        // posionando no começo do arquivo
        rewind(arquivo);

        // vendo o num de pessoas registradas
        fread(&Num_pessoas, 4, 1, arquivo);

        // escrevendo as infos da pessoa
        fseek(arquivo, offset+(Num_pessoas*Tamanho_Struct), SEEK_SET);
        fwrite(&pessoa, Tamanho_Struct, 1, arquivo);

        // encrementando o numero de pessoas registradas
        rewind(arquivo);
        Num_pessoas++;
        fwrite(&Num_pessoas, 4, 1, arquivo);
    }


    int Contar_Itens_Pessoa(FichaCadrastro pessoa, int opcao){
        int i, Num_Itens = 0;

        if (opcao == 0){
            for(i=1; i<Tamanho_Gosto_Musical; i++){
                if (pessoa.GostoMusical[i] == 1){
                    Num_Itens++;
                }
            }
            return Num_Itens;
        } // if oppcao == 0

        if (opcao == 1){
            for(i=1; i<7; i++){
                if (pessoa.hobbies[i] == 1){
                    Num_Itens++;
                }
            }
            return Num_Itens;
        } // if oppcao == 1

        if (opcao == 2){
            for(i=1; i<Tamanho_Comida_Favorita; i++){
                if (pessoa.ComidaFavorita[i] == 1){
                    Num_Itens++;
                }
            }
            return Num_Itens;
        } // if oppcao == 2
    }



    float Comparar_Pessoas(FichaCadrastro pessoa1, FichaCadrastro pessoa2){
        int i;
        float score=0;

        for(i=1; i<Tamanho_Comida_Favorita; i++){
            if(i <= 5){
                if(pessoa1.GostoMusical[i] == 1 && pessoa2.GostoMusical[i] == 1){
                    score += 1;
                }
            } // if exterior

            if(pessoa1.hobbies[i] == 1 && pessoa2.hobbies[i] == 1){
                    score += 1;
                }

            if(pessoa1.ComidaFavorita[i] == 1 && pessoa2.ComidaFavorita[i] == 1){
                    score += 1;
                }
        } // for
        return score;
    } // funcao



    void Analisar_Compatibilidade(FILE *arquivo){

        //variaveis
        FichaCadrastro pessoa1, pessoa2;
        int Num_pessoas, offset = 8, Tamanho_Struct = sizeof(pessoa1), i, x;
        int N_itens_pessoa1[3]; // [0] = gosto musical, [1] = hobbies e [2] = comida favorita
        float pontuacao=0, Pontuacao_Max=0;

        rewind(arquivo);

        // vendo o num de pessoas registradas
        fread(&Num_pessoas, 4, 1, arquivo);

        // analisando 1 por 1 e comparando com todos
        for(i=0; i<Num_pessoas; i++){
            fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
            fread(&pessoa1, Tamanho_Struct, 1, arquivo);

            // pegando o numero de itens qe a pessoa escolheu por categoria
            N_itens_pessoa1[0] = Contar_Itens_Pessoa(pessoa1, 0);
            N_itens_pessoa1[1] = Contar_Itens_Pessoa(pessoa1, 1);
            N_itens_pessoa1[2] = Contar_Itens_Pessoa(pessoa1, 2);
            Pontuacao_Max = N_itens_pessoa1[0] + N_itens_pessoa1[1] + N_itens_pessoa1[2];

            for(x= 0; x<Num_pessoas; x++){
                if(x == 0){
                    fseek(arquivo, offset, SEEK_SET); // colocando no inicio do arquivo toda vez que rodar o for
                    }
                fread(&pessoa2, Tamanho_Struct, 1, arquivo);

                pontuacao = Comparar_Pessoas(pessoa1, pessoa2);

                // escrevendo na tela as compatibilidades
                printf("%s com %s: %0.2f%% \n", pessoa1.NomeSobrenome, pessoa2.NomeSobrenome, ((pontuacao/Pontuacao_Max) * 100));
                printf("%0.0f de %0.0f acertos\n", pontuacao, Pontuacao_Max);
                printf("\n");
            }
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
        } // for exterior
    } // funcao



    int Filtrar_Busca(){
        int Decisao_Usuario;

        printf("digite APENAS um NUMERO que corresponda o que voce deseja filtrar no seguinte formato: (1 ENTER): \n");
        printf("1 - Nome e Sobrenome \n2 - cidade \n");
        printf("3 - genero\n4 - idade \n");
        printf("5 - gostos musicais \n6 - hobbies \n7 - comidas favoritas \n");
        printf("escolha: ");
        fflush(stdin);
        scanf("%i", &Decisao_Usuario);

        while(Decisao_Usuario < 1 || Decisao_Usuario > 7){ // anti burro
            printf("numero digitado invalido\n");
            printf("1 - Nome e Sobrenome \n2 - cidade \n");
            printf("3 - genero\n4 - idade \n");
            printf("5 - gostos musicais \n6 - hobbies \n7 - comidas favoritas \n");
            printf("escolha: ");
            fflush(stdin);
            scanf("%i", &Decisao_Usuario);
        }
        return Decisao_Usuario;
    }



    void Exibir_Dados_Pessoa_Filtrada(FichaCadrastro Pessoa_Filtrada){
        int i;

        // mostrando nome e sobrenome
        printf("nome e sobrenome: %s\n", Pessoa_Filtrada.NomeSobrenome);

        // mostrando cidade
        printf("cidade: %s\n", Pessoa_Filtrada.cidade);

        // mostrando sexo
        if(Pessoa_Filtrada.sexo == 1){
            printf("genero: masculino\n");
        }
        else if(Pessoa_Filtrada.sexo == 2){
            printf("genero: feminino\n");
        }
        else {printf("genero: outro\n");}

        // mostrando idade
        printf("idade: %i\n", Pessoa_Filtrada.idade);

        // mostrando gostos musicais
        printf("gostos musicais: ");
        for(i=1; i < Tamanho_Gosto_Musical; i++){
            if(Pessoa_Filtrada.GostoMusical[i] == 1){
                    switch (i){
                    case 1:
                        printf("funk, ");
                        break;
                    case 2:
                        printf("rock, ");
                        break;
                    case 3:
                        printf("pagode, ");
                        break;
                    case 4:
                        printf("rap, ");
                        break;
                    case 5:
                        printf("pop, ");
                        break;
                   }
            } // if
        } // for

        // mostrando os hobbies
        printf("\nhobbies: ");
        for(i=1; i < Tamanho_Hobbies; i++){
            if(Pessoa_Filtrada.hobbies[i] == 1){
                    switch (i){
                    case 1:
                        printf("academia, ");
                        break;
                    case 2:
                        printf("series, ");
                        break;
                    case 3:
                        printf("esportes, ");
                        break;
                    case 4:
                        printf("viajar, ");
                        break;
                    case 5:
                        printf("videogame, ");
                        break;
                    case 6:
                        printf("procrastinar, ");
                        break;
                   }
            } // if
        } // for

        // mostrando as comdidas favoritas
        printf("\ncomidas favoritas: ");
        for(i=1; i < Tamanho_Comida_Favorita; i++){
            if(Pessoa_Filtrada.ComidaFavorita[i] == 1){
                    switch (i){
                    case 1:
                        printf("churrasco, ");
                        break;
                    case 2:
                        printf("pizza, ");
                        break;
                    case 3:
                        printf("sushi, ");
                        break;
                    case 4:
                        printf("hamburguer, ");
                        break;
                    case 5:
                        printf("brownie, ");
                        break;
                    case 6:
                        printf("brigadeiro, ");
                        break;
                   }
            } // if
        } // for
        printf("\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    }



    int Filtro_Filtrar_Busca(FILE *arquivo, int Num_pessoas, int Decisao_Usuario){
        FichaCadrastro pessoa;
        int offset = 8, Tamanho_Struct = sizeof(pessoa), i, x, Num_Acertos=0;
        int saida = 2; // saida = 1 = (saida aberta) e saida = 0 = (saida fechada)
        int Mensagem_Erro = 0; // = 0 = a pessoa digitou um nome que existe no banco de dados. >= 1 = nome nao consta no banco de dados
        char *letra;

        do{
            switch(Decisao_Usuario){

            // escolheu nome
            case 1:
                printf("ok, agora digite o nome e o ULTIMO sobrenome da pessoa: ");

                char Nome_Sobrenome_Escolhido[50];

                fflush(stdin);
                scanf("%[^\n]s", Nome_Sobrenome_Escolhido);

                // formatando para um formato padrao
                Nome_Sobrenome_Escolhido[0] = toupper(Nome_Sobrenome_Escolhido[0]); // anti burro
                for(letra = &Nome_Sobrenome_Escolhido[1]; *letra != '\0'; letra++){
                    if (*letra == ' '){
                        letra++;
                        *letra = toupper(*letra);
                        }
                    else if (*letra >= 'A' && *letra <= 'Z'){
                        *letra = tolower(*letra);
                    }
                }
                system("cls");
                printf("aqui estao os dados de todas as pessoas que tem esse nome e sobrenome: %s\n\n", Nome_Sobrenome_Escolhido);

                for(i=0; i<Num_pessoas; i++){
                    fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
                    fread(&pessoa, Tamanho_Struct, 1, arquivo); // testando pessoa por pessoa

                    if(strcmp(pessoa.NomeSobrenome, Nome_Sobrenome_Escolhido) == 0){ // testando se os nomes sao iguais
                        Exibir_Dados_Pessoa_Filtrada(pessoa);
                        Mensagem_Erro++;
                    }
                }
                if (Mensagem_Erro == 0){ // testando se o usuario digitou algo errado ou se realmete nao consta no banco de dados
                    printf("o nome nao consta no banco de dados, tente novamente com outro nome");
                }
                Mensagem_Erro = 0;
                break;

            // escolheu cidade
            case 2:
                printf("ok, agora digite a cidade da pessoa (sem acentos): ");

                char Cidade_Escolhida[50];

                fflush(stdin);
                scanf("%[^\n]s", Cidade_Escolhida);
                letra = Cidade_Escolhida;

                // formatando para um formato padrao
                Cidade_Escolhida[0] = toupper(Cidade_Escolhida[0]);
                for(letra = &Cidade_Escolhida[1]; *letra != '\0'; letra++){
                    if (*letra == ' '){
                        letra++;
                        *letra = toupper(*letra);
                        }
                    else if (*letra >= 'A' && *letra <= 'Z'){
                        *letra = tolower(*letra);
                    }
                }
                system("cls");
                printf("aqui estao os dados de todas as pessoas que moram nessa cidade: %s\n\n", Cidade_Escolhida);

                for(i=0; i<Num_pessoas; i++){
                    fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
                    fread(&pessoa, Tamanho_Struct, 1, arquivo); // testando pessoa por pessoa

                    if(strcmp(pessoa.cidade, Cidade_Escolhida) == 0){ // testando se aa cidades sao iguais
                        Exibir_Dados_Pessoa_Filtrada(pessoa);
                        Mensagem_Erro++;
                    }
                }
                if (Mensagem_Erro == 0){ // testando se o usuario digitou algo errado ou se realmete nao consta no banco de dados
                    printf("a cidade nao consta no banco de dados, tente com outra cidade");
                }
                Mensagem_Erro = 0;
                break;

            // escolheu idade
            case 4:
                printf("ok, agora digite a idade da pessoa (apenas os numeros): ");

                int Idade_Escolhida;

                fflush(stdin);
                scanf("%i", &Idade_Escolhida);

                system("cls");
                printf("aqui estao os dados de todas as pessoas que tem essa idade: %i\n\n", Idade_Escolhida);

                for(i=0; i<Num_pessoas; i++){
                    fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
                    fread(&pessoa, Tamanho_Struct, 1, arquivo); // testando pessoa por pessoa

                    if(pessoa.idade == Idade_Escolhida){ // testando se as idades sao iguais
                        Exibir_Dados_Pessoa_Filtrada(pessoa);
                        Mensagem_Erro++;
                    }
                }
                if (Mensagem_Erro == 0){ // testando se o usuario digitou algo errado ou se realmete nao consta no banco de dados
                    printf("a idade nao consta no banco de dados, tente com outra idade");
                }
                Mensagem_Erro = 0;
                break;

            // escolheu genero
            case 3:
                printf("ok, agora digite o numero correspondente ao genero da pessoa:\n");
                printf("1 - masculino\n2 - feminino\n3 - outro\n");
                printf("escolha: ");

                int Genero_Escolhido;

                fflush(stdin);
                scanf("%i", &Genero_Escolhido);

                system("cls");

                while(Genero_Escolhido < 1 || Genero_Escolhido > 3){ // protecao anti burro
                    printf("genero invalido, digite novamente:\n");
                    printf("1 - masculino\n2 - feminino\n3 - outro\n");
                    printf("escolha: ");
                    fflush(stdin);
                    scanf("%i", &Genero_Escolhido);
                    printf("\n");
                }

                system("cls");
                printf("aqui estao os dados de todas as pessoas que tem esse sexo: %i\n\n", Genero_Escolhido);

                for(i=0; i<Num_pessoas; i++){
                    fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
                    fread(&pessoa, Tamanho_Struct, 1, arquivo); // testando pessoa por pessoa

                    if(pessoa.sexo == Genero_Escolhido){ // testando se os generos sao iguais
                        Exibir_Dados_Pessoa_Filtrada(pessoa);
                        Mensagem_Erro++;
                    }
                }
                if (Mensagem_Erro == 0){ // testando se o usuario digitou algo errado ou se realmete nao consta no banco de dados
                    printf("o genero nao consta no banco de dados, tente com outro genero");
                }
                Mensagem_Erro = 0;
                break;

            // escolheu gostos musicais
            case 5:
                printf("\n");
                int Itens_Gostos_Musicais[Tamanho_Gosto_Musical], item=0, Num_Itens=0;
                // escolhendo repetidamente ate o usuario querer parar
                do{
                    printf("ok, agora digite os NUMEROS correspondente ao gosto musical da pessoa no seguinte formato: (numero ENTER numero ENTER):\n");
                    printf("0 - parar\n1 - funk\n2 - rock\n3 - pagode\n");
                    printf("4 - rap\n5 - pop\n");
                    printf("escolha: ");
                    fflush(stdin);
                    scanf("%i", &item);

                    while (item > 5 || item < 0){ // proteção anti burro
                        system("cls");

                        printf("numero invalido, tente denovo\n");
                        printf("0 - parar\n1 - funk\n2 - rock\n3 - pagode\n");
                        printf("4 - rap\n5 - pop\n");
                        printf("escolha: ");
                        fflush(stdin);
                        scanf("%i", &item);
                        printf("\n");
                    }

                    if(Itens_Gostos_Musicais[item] != 1){ // garatindo que so vai ter 1 item de cada
                        Itens_Gostos_Musicais[item] = 1;
                        Num_Itens++;
                    }

                printf("\n");
                } while (Itens_Gostos_Musicais[stop] != 1);

                system("cls");

                for(i=0; i<Num_pessoas; i++){
                    fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
                    fread(&pessoa, Tamanho_Struct, 1, arquivo); // testando pessoa por pessoa

                    for(x = 1; x < Tamanho_Gosto_Musical; x++){ // passando por todos os gostos musicais
                        if(pessoa.GostoMusical[x] == 1 && Itens_Gostos_Musicais[x] == 1){ // testando se os gostos musicais sao iguais

                            Num_Acertos++;
                            if(Num_Acertos == (Num_Itens-1)){ // garantindo que todos os requisitos foram satisfeitos
                                Exibir_Dados_Pessoa_Filtrada(pessoa);
                                Num_Acertos = 0;
                                Mensagem_Erro++;
                            }
                        } // if maior
                    } // for interno
                    Num_Acertos = 0;
                } // for externo

                if (Mensagem_Erro == 0){ // exibiindo mensagem de erro caso o usuario tenha digitado algo errado ou realmente nao consta no banco de dados
                    printf("o gosto musical nao consta no banco de dados, tente com outro gosto musical");
                }
                Mensagem_Erro = 0; // garatindo que na proxima busca a mensagem de erro nao apareca sem motivo
                break;

            // escolheu hobbies
            case 6:
                item = 0;
                Num_Itens = 0;
                int Itens_Hobbies[Tamanho_Hobbies];
                // escolhendo repetidamente ate o usuario querer parar
                do{
                    printf("ok, agora digite os NUMEROS correspondente ao hobbie da pessoa no seguinte formato: (numero ENTER numero ENTER):\n");
                    printf("0 - parar\n1 - academia\n2 - series\n3 - esportes\n");
                    printf("4 - viajar\n5 - videogame\n6 - procrastinar\n");
                    printf("escolha: ");
                    fflush(stdin);
                    scanf("%i", &item);

                    while (item > 6 || item < 0){ // proteção anti burro
                        system("cls");

                        printf("numero invalido, tente denovo\n");
                        printf("0 - parar\n1 - academia\n2 - series\n3 - esportes\n");
                        printf("4 - viajar\n5 - videogame\n6 - procrastinar\n");
                        printf("escolha: ");
                        fflush(stdin);
                        scanf("%i", &item);
                        printf("\n");
                    }

                   if(Itens_Hobbies[item] != 1){ // garatindo que so vai ter 1 item de cada
                        Itens_Hobbies[item] = 1;
                        Num_Itens++;
                    }
                printf("\n");

                } while (Itens_Hobbies[stop] != 1);

                system("cls");

                for(i=0; i<Num_pessoas; i++){
                    fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
                    fread(&pessoa, Tamanho_Struct, 1, arquivo); // testando pessoa por pessoa

                    for(x = 1; x < Tamanho_Hobbies; x++){ // passando por todos os hobbies
                        if(pessoa.hobbies[x] == 1 && Itens_Hobbies[x] == 1){ // testando se os hobbies sao iguais

                            Num_Acertos++;
                            if(Num_Acertos == (Num_Itens-1)){ // garantindo que todos os requisitos foram satisfeitos
                                Exibir_Dados_Pessoa_Filtrada(pessoa);
                                Num_Acertos = 0;
                                Mensagem_Erro++;
                            }
                        } // if maior
                    } // for interno
                    Num_Acertos = 0;
                } // for externo
                if (Mensagem_Erro == 0){
                    printf("o hobbie nao consta no banco de dados, tente com outro hobbie");
                }
                Mensagem_Erro = 0; // garatindo que na proxima busca a mensagem de erro nao apareca sem motivo
                break;

            // escolheu comidas favoritas
            case 7:
                item = 0;
                Num_Itens = 0;
                int Itens_Comidas_Favoritas[Tamanho_Comida_Favorita];
                // escolhendo repetidamente ate o usuario querer parar
                do{
                    printf("ok, agora digite os NUMEROS correspondente a comida favorita da pessoa no seguinte formato: (numero ENTER numero ENTER):\n");
                    printf("0 - parar\n1 - churrasco\n2 - pizza\n3 - sushi\n");
                    printf("4 - hamburguer\n5 - brownie\n6 - brigadeiro\n");
                    printf("escolha: ");
                    fflush(stdin);
                    scanf("%i", &item);

                    while (item > 6 || item < 0){ // proteção anti burro
                        system("cls");

                        printf("numero invalido, tente denovo\n");
                        printf("0 - parar\n1 - churrasco\n2 - pizza\n3 - sushi\n");
                        printf("4 - hamburguer\n5 - brownie\n6 - brigadeiro\n");
                        printf("escolha: ");
                        fflush(stdin);
                        scanf("%i", &item);
                        printf("\n");
                }

                if(Itens_Comidas_Favoritas[item] != 1){ // garatindo que so vai ter 1 item de cada
                        Itens_Comidas_Favoritas[item] = 1;
                        Num_Itens++;
                    }
                printf("\n");

                } while (Itens_Comidas_Favoritas[stop] != 1);

                system("cls");

                for(i=0; i<Num_pessoas; i++){
                    fseek(arquivo, offset+(i*Tamanho_Struct), SEEK_SET);
                    fread(&pessoa, Tamanho_Struct, 1, arquivo); // testando pessoa por pessoa

                    for(x = 1; x < Tamanho_Comida_Favorita; x++){ // passando por todos os hobbies
                        if(pessoa.ComidaFavorita[x] == 1 && Itens_Comidas_Favoritas[x] == 1){ // testando se as comidas sao iguais

                            Num_Acertos++;
                            if(Num_Acertos == (Num_Itens-1)){ // garantindo que todos os requisitos foram satisfeitos
                                Exibir_Dados_Pessoa_Filtrada(pessoa);
                                Num_Acertos = 0;
                                Mensagem_Erro++;
                            }
                        } // if maior
                    } // for interno
                    Num_Acertos = 0;
                } // for externo

                if (Mensagem_Erro == 0){
                    printf("a comida nao consta no banco de dados, tente com outra comida");
                }
                Mensagem_Erro = 0;
                break;
            } // switch case

            printf("\n\ndeseja continuar pesquisando?\n0 - sim\n1 - nao\n");
            printf("escolha: ");
            fflush(stdin);
            scanf("%i", &saida);

            system("cls");

            return saida;
        } while (1);
    }



    void Buscar_Caracteristica(FILE *arquivo){
        int Num_pessoas, Decisao_Usuario, saida=0;

        rewind(arquivo);

        // vendo o num de pessoas registradas
        fread(&Num_pessoas, 4, 1, arquivo);

        do{
            // filtrando a escolha do que o usuario vai querer buscar
            Decisao_Usuario = Filtrar_Busca();
            system("cls");

            saida = Filtro_Filtrar_Busca(arquivo, Num_pessoas, Decisao_Usuario);
        } while (saida != 1);
    }


    // MAIN
int main()
{
    // declarando variaveis, funções
    int opcao;
    FILE *arquivo;
    FichaCadrastro pessoa;

    //abrindo arquivo para escrito em texto
    arquivo = fopen("tinder.txt", "r+b");

    // abrindo tela inicial
    printf("\t\t\t BEM VINDO AO TINDER FAMILY FRIENDLY !!!\n");

    do{
        // loop usuario escolhendo o que quer fazer
        opcao = Exibir_Menu();
        system("cls");

        // executando a escolha
        switch (opcao){

        // cadastrar
        case 1:
            pessoa = cadastrar(); //recebendo escolhas
            Escrever_Arquivo(arquivo, pessoa); // escrevendo a strutc no arquivo
            printf("\ncadastro feito com sucesso !!\n");
            break;

        // ver percentual de compatibilidade de todos os usuarios
        case 2:
            Analisar_Compatibilidade(arquivo);
            system("pause");
            system("cls");
            break;

        // consultar algo em especifico no banco de dados
        case 3:
            Buscar_Caracteristica(arquivo);
            break;

        // sair
        case 4: // apenas para nao aparecer a mensagem do default caso a pessoa aperte 4
            system("cls");
            printf("\n\n\t\tadeus, volte sempre !!!");
            break;

        default:
            printf("opcao invalida, digite novamente !!!");
            break;
        } // switch
    } while(opcao != 4);

    fclose(arquivo);
    return 0;
}

// essa é a função caso tenha que resetar o arquivo do 0
/*
            Conserta_Cagada_Arquivo(arquivo);
            fclose(arquivo);
            arquivo = fopen("tinder.txt", "r+b");
*/
