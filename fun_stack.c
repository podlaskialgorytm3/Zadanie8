#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun_stack.h"

typedef struct
{
    int par_level;
    char *funame;
} FunStackElement;

static FunStackElement fun_stack[MAX_STACK_SIZE];
static int stack_top = -1;

// zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
int top_of_funstack(void)
{
    if (stack_top < 0)
    {
        fprintf(stderr, "Error: Stack is empty.\n");
        return -1; // Wartość oznaczająca błąd
    }
    return fun_stack[stack_top].par_level;
}

// odkłada na stos parę (funame,par_level)
void put_on_fun_stack(int par_level, char *funame)
{
    if (stack_top >= MAX_STACK_SIZE - 1)
    {
        fprintf(stderr, "Error: Stack overflow.\n");
        return;
    }

    stack_top++;
    fun_stack[stack_top].par_level = par_level;
    fun_stack[stack_top].funame = strdup(funame);
    if (!fun_stack[stack_top].funame)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        stack_top--;
    }
}

char *get_from_fun_stack(void)
{
    if (stack_top < 0)
    {
        fprintf(stderr, "Error: Stack is empty.\n");
        return NULL;
    }

    char *funame = fun_stack[stack_top].funame;
    stack_top--;
    return funame;
}
