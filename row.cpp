#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define size 5

struct scope
{
    int data[size];
    int start;
    int end;
};

struct scope row;
int op;

void row_enter();
void row_exit();
void row_view();
void menu_view();

int main()
{
    op = 1;
    row.start = 0;
    row.end = 0;
    while (op != 0)
    {
        system("cls");
        menu_view();
        row_view();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            row_enter();
            break;
        case 2:
            row_exit();
            break;
        }
    }
    return (0);
}

void row_enter()
{
    if (row.end == size)
    {
        printf("\n A fila está cheia, remova algum valor!\n\n");
        system("Pause");
    }
    else
    {
        printf("\n Digite o valor a ser inserido: ");
        scanf("%d", &row.data[row.end]);
        row.end++;
    }
}

void row_exit()
{
    if (row.start == row.end)
    {
        printf("\n A fila esta vazia, adicione algum valor primeiro!\n");
        system("pause");
    }
    else
    {
        int i;
        for (i = 0; i < size; i++)
        {
            row.data[i] = row.data[i + 1];
        }
        row.data[row.end] = 0;
        row.end--;
    }
}

void row_view()
{
    int i;
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf(" %d", row.data[i]);
    }
    printf(" ]\n\n");
}

void menu_view()
{

    printf("\n Escolha uma alternativa:\n");
    printf("1- Incluir na fila\n");
    printf("2- Excluir da fila\n");
    printf("0- Sair\n\n");
}
