/*
 * Fatec Ipiranga - Estrutura de Dados
 * Prof. Veríssimo
 * Atividade N2-1: Explorando Árvore Binária
 *
 * Programa que instancia uma BST com profundidade de 7 níveis
 * e exibe propriedades estruturais via funções recursivas.
 */

#include <stdio.h>
#include <stdlib.h>

/* ─────────────────────────────────────────
   ESTRUTURA DO NÓ
───────────────────────────────────────── */
typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

/* ─────────────────────────────────────────
   CRIAÇÃO E INSERÇÃO
───────────────────────────────────────── */
No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

/* ─────────────────────────────────────────
   1. RAIZ
───────────────────────────────────────── */
void exibirRaiz(No *raiz) {
    printf("==================================================\n");
    printf("RAIZ:\n");
    if (raiz != NULL)
        printf("  %d\n", raiz->valor);
    else
        printf("  (árvore vazia)\n");
}

/* ─────────────────────────────────────────
   2. NÓS INTERNOS (possuem ao menos 1 filho)
───────────────────────────────────────── */
void exibirNosInternos(No *no) {
    if (no == NULL) return;
    if (no->esq != NULL || no->dir != NULL)
        printf("  %d\n", no->valor);
    exibirNosInternos(no->esq);
    exibirNosInternos(no->dir);
}

/* ─────────────────────────────────────────
   3. NÓS EXTERNOS / FOLHAS (grau zero)
───────────────────────────────────────── */
void exibirFolhas(No *no) {
    if (no == NULL) return;
    if (no->esq == NULL && no->dir == NULL)
        printf("  %d\n", no->valor);
    exibirFolhas(no->esq);
    exibirFolhas(no->dir);
}

/* ─────────────────────────────────────────
   4. NÍVEIS (nós por nível, 1-indexado)
───────────────────────────────────────── */
/* Conta quantos nós existem em um nível específico */
int contarNivel(No *no, int nivelAtual, int nivelAlvo) {
    if (no == NULL) return 0;
    if (nivelAtual == nivelAlvo) return 1;
    return contarNivel(no->esq, nivelAtual + 1, nivelAlvo) +
           contarNivel(no->dir, nivelAtual + 1, nivelAlvo);
}

/* Imprime os valores de todos os nós em um nível específico */
void imprimirNosDoNivel(No *no, int nivelAtual, int nivelAlvo) {
    if (no == NULL) return;
    if (nivelAtual == nivelAlvo) {
        printf("  %d\n", no->valor);
        return;
    }
    imprimirNosDoNivel(no->esq, nivelAtual + 1, nivelAlvo);
    imprimirNosDoNivel(no->dir, nivelAtual + 1, nivelAlvo);
}

/* Calcula a altura da árvore (número de níveis) */
int altura(No *no) {
    if (no == NULL) return 0;
    int altEsq = altura(no->esq);
    int altDir = altura(no->dir);
    return 1 + (altEsq > altDir ? altEsq : altDir);
}

void exibirNiveis(No *raiz) {
    printf("==================================================\n");
    printf("NÍVEIS:\n");
    int totalNiveis = altura(raiz);
    for (int nivel = 1; nivel <= 7; nivel++) {
        printf("  Nível %d:", nivel);
        if (nivel > totalNiveis || contarNivel(raiz, 1, nivel) == 0) {
            printf(" (vazio)\n");
        } else {
            printf("\n");
            imprimirNosDoNivel(raiz, 1, nivel);
        }
    }
}

/* ─────────────────────────────────────────
   5. GRAU DE CADA NÓ
───────────────────────────────────────── */
int calcularGrau(No *no) {
    if (no == NULL) return -1;
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

void exibirGraus(No *no) {
    if (no == NULL) return;
    printf("  %d → grau %d\n", no->valor, calcularGrau(no));
    exibirGraus(no->esq);
    exibirGraus(no->dir);
}

/* ─────────────────────────────────────────
   6. ANCESTRAIS DE UM NÓ
───────────────────────────────────────── */
/* Retorna 1 se encontrou o valor; imprime o caminho de volta (ancestrais) */
int exibirAncestral(No *no, int valorAlvo) {
    if (no == NULL) return 0;
    if (no->valor == valorAlvo) return 1;
    if (exibirAncestral(no->esq, valorAlvo) ||
        exibirAncestral(no->dir, valorAlvo)) {
        printf("  %d\n", no->valor);
        return 1;
    }
    return 0;
}

/* ─────────────────────────────────────────
   7. DESCENDENTES DE UM NÓ
───────────────────────────────────────── */
/* Primeiro localiza o nó; depois imprime toda a subárvore (exceto a raiz) */
No *buscarNo(No *no, int valor) {
    if (no == NULL) return NULL;
    if (no->valor == valor) return no;
    No *resultado = buscarNo(no->esq, valor);
    if (resultado != NULL) return resultado;
    return buscarNo(no->dir, valor);
}

void exibirDescendentes(No *no, int imprimirRaiz) {
    if (no == NULL) return;
    if (!imprimirRaiz) {          /* pula a própria raiz da busca */
        exibirDescendentes(no->esq, 1);
        exibirDescendentes(no->dir, 1);
        return;
    }
    printf("  %d\n", no->valor);
    exibirDescendentes(no->esq, 1);
    exibirDescendentes(no->dir, 1);
}

/* ─────────────────────────────────────────
   8. ALTURA DE UM NÓ ESPECÍFICO
      (distância até a folha mais profunda abaixo)
───────────────────────────────────────── */
int alturaDono(No *raiz, int valor) {
    No *alvo = buscarNo(raiz, valor);
    if (alvo == NULL) return -1;
    return altura(alvo) - 1;   /* altura da subárvore - 1 */
}

/* ─────────────────────────────────────────
   9. PROFUNDIDADE DE UM NÓ ESPECÍFICO
      (distância até a raiz)
───────────────────────────────────────── */
int profundidade(No *no, int valor, int nivel) {
    if (no == NULL) return -1;
    if (no->valor == valor) return nivel;
    int esq = profundidade(no->esq, valor, nivel + 1);
    if (esq != -1) return esq;
    return profundidade(no->dir, valor, nivel + 1);
}

/* ─────────────────────────────────────────
   10. SUB-ÁRVORE (exibição visual em texto)
───────────────────────────────────────── */
void exibirSubArvore(No *no, char *prefixo, int ehFilhoDir) {
    if (no == NULL) return;

    /* Imprime o prefixo acumulado + conector */
    printf("%s", prefixo);
    if (ehFilhoDir == -1) {           /* raiz da sub-árvore */
        printf("%d\n", no->valor);
    } else if (ehFilhoDir) {
        printf("└── %d\n", no->valor);
    } else {
        printf("├── %d\n", no->valor);
    }

    /* Monta novo prefixo para os filhos */
    char novoPrefixo[256];
    if (ehFilhoDir == -1) {
        snprintf(novoPrefixo, sizeof(novoPrefixo), "%s", prefixo);
    } else if (ehFilhoDir) {
        snprintf(novoPrefixo, sizeof(novoPrefixo), "%s    ", prefixo);
    } else {
        snprintf(novoPrefixo, sizeof(novoPrefixo), "%s│   ", prefixo);
    }

    if (no->esq != NULL || no->dir != NULL) {
        if (no->esq != NULL)
            exibirSubArvore(no->esq, novoPrefixo, 0);
        if (no->dir != NULL)
            exibirSubArvore(no->dir, novoPrefixo, 1);
    }
}

/* ─────────────────────────────────────────
   MAIN
───────────────────────────────────────── */
int main(void) {

    /* ── Construção da BST (7 níveis conforme exemplo do PDF) ── */
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 65, 5, 2};
    int total = sizeof(valores) / sizeof(valores[0]);
    for (int i = 0; i < total; i++)
        raiz = inserir(raiz, valores[i]);

    /* Nó de consulta para demonstração (nó do nível 3: 60) */
    int noConsulta = 60;

    /* ════════════════════════════════════════
       SAÍDA
    ════════════════════════════════════════ */

    /* 1. RAIZ */
    exibirRaiz(raiz);

    /* 2. NÓS INTERNOS */
    printf("==================================================\n");
    printf("NÓS INTERNOS (possuem ao menos 1 filho):\n");
    exibirNosInternos(raiz);

    /* 3. FOLHAS */
    printf("==================================================\n");
    printf("NÓS EXTERNOS (FOLHAS - grau 0):\n");
    exibirFolhas(raiz);

    /* 4. NÍVEIS */
    exibirNiveis(raiz);

    /* 5. GRAU */
    printf("==================================================\n");
    printf("GRAU DOS NÓS:\n");
    exibirGraus(raiz);

    /* 6. ANCESTRAIS do noConsulta */
    printf("==================================================\n");
    printf("ANCESTRAIS DO NÓ %d:\n", noConsulta);
    if (!exibirAncestral(raiz, noConsulta))
        printf("  Nó não encontrado.\n");

    /* 7. DESCENDENTES do noConsulta */
    printf("==================================================\n");
    printf("DESCENDENTES DO NÓ %d:\n", noConsulta);
    No *noAlvo = buscarNo(raiz, noConsulta);
    if (noAlvo != NULL)
        exibirDescendentes(noAlvo, 0);
    else
        printf("  Nó não encontrado.\n");

    /* 8. ALTURA do noConsulta */
    printf("==================================================\n");
    printf("ALTURA DO NÓ %d:\n", noConsulta);
    int alt = alturaDono(raiz, noConsulta);
    if (alt >= 0)
        printf("  Altura de %d = %d "
               "(distância até a folha mais profunda abaixo)\n",
               noConsulta, alt);
    else
        printf("  Nó não encontrado.\n");

    /* 9. PROFUNDIDADE do noConsulta */
    printf("==================================================\n");
    printf("PROFUNDIDADE DO NÓ %d:\n", noConsulta);
    int prof = profundidade(raiz, noConsulta, 0);
    if (prof >= 0)
        printf("  Profundidade de %d = %d "
               "(distância até a raiz)\n",
               noConsulta, prof);
    else
        printf("  Nó não encontrado.\n");

    /* 10. SUB-ÁRVORE a partir do nó 30 */
    int noSubArvore = 30;
    printf("==================================================\n");
    printf("SUB-ÁRVORE COM RAIZ NO NÓ %d:\n", noSubArvore);
    No *subRaiz = buscarNo(raiz, noSubArvore);
    if (subRaiz != NULL)
        exibirSubArvore(subRaiz, "", -1);
    else
        printf("  Nó não encontrado.\n");

    printf("==================================================\n");

    return 0;
}
