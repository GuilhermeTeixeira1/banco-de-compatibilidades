projeto onde o usuário pode se cadastrar em um banco de dados, analisar as compatibilidades das pessoas cadastradas e filtrar ele por alguma característica. Foi programado em C na plataforma CodeBlocks. O intuito do projeto é manipular arquivos e banco de dados. O banco está salvo em binário no arquivo "tinder.txt".
 
 COMO FUNCIONA CADA OPÇÃO?
 
 - Cadastrar-se: o usuário receberá várias perguntas tendo algumas possibilidades de escolhas. depois de ter escolhido tudo, volta para a tela de início automatcamente.

 - Analisar compatibilidades: ao clicar, aparece uma lista completa com a ánalise de todos usuários com os outros, sendo que o nome da esquerda é a pessoa que está sendo analisada, já a da direita, o objeto usado para calcular o percentual de acertos entre os 2.

 - Filtrar: aparece um menu onde há todos os itens que podem ser usados como critério para filtro, depois de escolher, mostra a ficha inteira dos usuários que coincidem com o que foi escolhido.

EXPLICAÇÃO DA LINHA DE RACICÍONO E MOSTRANDO COMO FOI FEITO O CODIGO:
- Tela inicial:
  A tela inicial consiste basicamente em 3 opções (são as mesmas citadas a cima), para o usuário escolher (foi usado "printf" e estão todos contidos na função "Exibir_Menu"). Nesse menu inicial, é mostrado ao usuário as possibilidades de escolha.
  Todo essa tela esta em um loop usando "do while", que só é quebrado quando o usuário escolher a opção de sair do programa.

- Cadastrar-se: // parei aqui
quando o usuario escolhe 1 no menu, esse valor é armazenado na variavel "opcao" que vai para um switch case, assim, executando o case 1. São 2 funções, a "cadastrar" e a "Escrever_Arquivo". Primeiro executa o "cadastrar" que cria uma struct que irá receber vários dados do usuario conforme ele respondende o questionario na tela. Quando terminar o cadastro, a função devolve essa struct que esta definida do tipo "FichaCadastro" na variavel "pessoa".

Depois, executa o "Escrever_Arquivo" onde ele recebe a strutc "pessoa" e o ponteiro do arquivo, depois abre o arquivo txt que irá ser o meu banco de dados, nele já foi colocado 2 variaveis previamente que só atualizam de valor conforme o codigo, elas servem para saber o número de pessoas cadastras e o offset em bytes para começar as infos de cada usuario. Logo após, é armazenado a struct em binario, encrementa a variavel de controle do nuemro de pessoas cadastras e se fecha o arquivo.

- analisar compatibilidades:
consiste na função "Analisar_Compatibilidades" que recebe como argumento o ponteiro do arquivo. Lá, é executado um "for" que passa por todo o banco, são declaradas as struts "pessoa1" e "pessoa2", que vao servir como pessoa analisada e opção de analise, respectivamente. Durante o loop, é executado a função "Contar_Itens_Pessoa" e devolve um inteiro que o vetor N_Itens_Pessoa1 armazena em cada indice para ser calculado a pontuação maxima.

Depois começa a analise entre as 2 structs comparando cada item na função "Comparar_Pessoas", se os 2 forem iguais, encrementa o numero de acertos. Essa função devolve o numero de acertos e assim é calculado o percentual ((pontuação / pontuação maxima) * 100), depois é exibido os nomes e a compatibilidade (percentual).

- filtrar:
Começa com a função "Busca_Caracteristica" que recebe o ponteiro do arquivo. Se trata de um loop que acontece até o usuario digitar que quer parar de pesquisar dentro do banco de dados. Dentro dessa função existe mais 2 funções, "Filtrar_Busca" e seu complemento "Filtro_Filtrar_Busca", onde um (Filtro_Busca) serve pra descobrir por qual segmento o usuario deseja filtrar e a outra função (Filtro_Filtrar_Busca) delimita e mostra quais as opções dentro daquele segmento escolhido, assim começando a filtrar o banco de dados.

Esse filtro ocorre da seguinte forma: primeiro recebe a decisão de qual filtro sera, depois, compara com o mesmo segmento do item dos usuarios, se forem iguais, vai para uma função (Exibir_Dados_Pessoa_Filtrada) que recebe a struct do usuario. Lá, é exbidido toda ficha de cadastro. No final, depois de mostrar todas as fichas, é perguntado se o usuario quer continuar pesquisando, se sim, é repetido todo o processo, se nao, a variavel de controle da "Busca_Caracteristica" quebra o loop, voltando para o menu inicial.
