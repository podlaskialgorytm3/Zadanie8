#include <stdio.h>
#include <stdlib.h>
#include "fun_stack.h"

int main()
{
    printf("Test funkcji stosu:\n");

    // Test 1: Próba zdjęcia elementu ze stosu, gdy jest pusty
    printf("\nTest 1: Próba zdjęcia elementu z pustego stosu.\n");
    char *funame = get_from_fun_stack();
    if (funame == NULL)
    {
        printf("Stos jest pusty - poprawne zachowanie.\n");
    }

    // Test 2: Dodanie elementów na stos
    printf("\nTest 2: Dodanie elementów na stos.\n");
    put_on_fun_stack(17, "Ala");
    put_on_fun_stack(21, "Ola");
    put_on_fun_stack(32, "Ela");
    printf("Dodano 3 funkcje na stos.\n");

    // Test 3: Sprawdzenie szczytowego poziomu nawiasowego
    printf("\nTest 3: Sprawdzenie poziomu nawiasowego na szczycie stosu.\n");
    int par_level = top_of_funstack();
    if (par_level != -1)
    {
        printf("Poziom nawiasowy na szczycie stosu: %d\n", par_level);
    }

    // Test 4: Zdjęcie elementów ze stosu
    printf("\nTest 4: Zdjęcie elementów ze stosu.\n");
    while ((funame = get_from_fun_stack()) != NULL)
    {
        printf("Zdjęto funkcję: %s\n", funame);
        free(funame); // Pamiętaj o zwolnieniu zaalokowanej pamięci!
    }

    // Test 5: Przekroczenie pojemności stosu
    printf("\nTest 5: Test przekroczenia pojemności stosu.\n");
    for (int i = 0; i < MAX_STACK_SIZE + 1; i++)
    {
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "Function%d", i);
        put_on_fun_stack(i, buffer);
    }
    printf("Test przekroczenia pojemności stosu zakończony.\n");

    // Test zakończony
    printf("\nTesty zakończone.\n");
    return 0;
}
