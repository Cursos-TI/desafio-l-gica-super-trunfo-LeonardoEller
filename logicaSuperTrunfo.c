#include <stdio.h>

// Define a estrutura que armazena os dados de uma carta de cidade.
// O 'typedef' nos permite usar "CartaCidade" como um novo tipo de variável.
typedef struct {
    char estado[50];
    int codigo_carta;
    char nome_cidade[50];
    long populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade_populacional; // Campo calculado
} CartaCidade;

// Função para exibir as informações de uma carta de forma organizada.
void exibir_carta(CartaCidade carta) {
    printf("\n--------------------------\n");
    printf("Cidade: %s, %s\n", carta.nome_cidade, carta.estado);
    printf("Codigo da Carta: %d\n", carta.codigo_carta);
    printf("Populacao: %ld habitantes\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: R$ %.2f bilhoes\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("--------------------------\n");
}

int main() {
    // Declara duas variáveis do tipo CartaCidade para armazenar os dados.
    CartaCidade carta1, carta2;

    printf("=============================================\n");
    printf(" JOGO DE COMPARACAO DE CARTAS DE CIDADES \n");
    printf("=============================================\n");
    printf("Observacao: Ao digitar nomes de cidades ou estados, nao use espacos.\nExemplo: 'Sao_Paulo' ou 'Belo_Horizonte'.\n");

    // --- ETAPA 1: CADASTRO DE CARTAS (ENTRADA DE DADOS) ---

    // Cadastro da primeira carta
    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Digite o estado: ");
    scanf("%s", carta1.estado);
    printf("Digite o codigo da carta: ");
    scanf("%d", &carta1.codigo_carta);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta1.nome_cidade);
    printf("Digite a populacao: ");
    scanf("%ld", &carta1.populacao);
    printf("Digite a area em km2: ");
    scanf("%lf", &carta1.area);
    printf("Digite o PIB em bilhoes: ");
    scanf("%lf", &carta1.pib);
    printf("Digite o n. de pontos turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cadastro da segunda carta
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o estado: ");
    scanf("%s", carta2.estado);
    printf("Digite o codigo da carta: ");
    scanf("%d", &carta2.codigo_carta);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta2.nome_cidade);
    printf("Digite a populacao: ");
    scanf("%ld", &carta2.populacao);
    printf("Digite a area em km2: ");
    scanf("%lf", &carta2.area);
    printf("Digite o PIB em bilhoes: ");
    scanf("%lf", &carta2.pib);
    printf("Digite o n. de pontos turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Calcula a densidade populacional para ambas as cartas
    // (evita divisão por zero caso a área seja 0)
    if (carta1.area > 0) {
        carta1.densidade_populacional = carta1.populacao / carta1.area;
    } else {
        carta1.densidade_populacional = 0;
    }

    if (carta2.area > 0) {
        carta2.densidade_populacional = carta2.populacao / carta2.area;
    } else {
        carta2.densidade_populacional = 0;
    }

    // --- ETAPA 2: EXIBIÇÃO DOS RESULTADOS ---
    printf("\n\n=== Cartas Cadastradas ===\n");
    exibir_carta(carta1);
    exibir_carta(carta2);

    // --- ETAPA 3: COMPARAÇÃO DAS CARTAS ---
    printf("\n\n=== Resultado da Batalha ===\n");

    // Comparação por População (maior vence)
    printf("\nComparando por POPULACAO (maior vence):\n");
    if (carta1.populacao > carta2.populacao) {
        printf("VENCEDOR: %s\n", carta1.nome_cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("VENCEDOR: %s\n", carta2.nome_cidade);
    } else {
        printf("EMPATE!\n");
    }

    // Comparação por PIB (maior vence)
    printf("\nComparando por PIB (maior vence):\n");
    if (carta1.pib > carta2.pib) {
        printf("VENCEDOR: %s\n", carta1.nome_cidade);
    } else if (carta2.pib > carta1.pib) {
        printf("VENCEDOR: %s\n", carta2.nome_cidade);
    } else {
        printf("EMPATE!\n");
    }
    
    // Comparação por Densidade Populacional (menor vence)
    printf("\nComparando por DENSIDADE POPULACIONAL (menor vence):\n");
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("VENCEDOR: %s\n", carta1.nome_cidade);
    } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
        printf("VENCEDOR: %s\n", carta2.nome_cidade);
    } else {
        printf("EMPATE!\n");
    }

    // --- ALTERAÇÃO AQUI ---
    // Pausa o programa e espera o usuário pressionar Enter para fechar.
    printf("\n\nPressione Enter para sair...");
    
    // Limpa o buffer de entrada para garantir que o getchar() espere por uma nova entrada.
    while (getchar() != '\n'); 
    getchar(); // Espera o usuário pressionar Enter

    return 0; // Indica que o programa terminou com sucesso
}
