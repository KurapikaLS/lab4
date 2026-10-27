
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int stack_var = 10;
    int *heap_array = calloc(3, sizeof(int));

    if (heap_array == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("=== 1. Дослідження адрес (Stack vs Heap) ===\n");
    printf("[STACK] Адреса змінної stack_var: %p\n", (void *)&stack_var);
    printf("[STACK] Адреса вказівника heap_array: %p\n", (void *)&heap_array);
    printf("[HEAP] Адреса динамічного масиву: %p\n", (void *)heap_array);

    for (int i = 0; i < 3; i++) {
        heap_array[i] = (i + 1) * 10;
    }

    int *temp = realloc(heap_array, 5 * sizeof(int));

    if (temp == NULL) {
        free(heap_array);
        printf("Помилка перевиділення пам'яті!\n");
        return 1;
    }

    heap_array = temp;

    for (int i = 3; i < 5; i++) {
        heap_array[i] = (i + 1) * 10;
    }

    printf("\n=== 2. Стан масиву після realloc ===\n");
    printf("[HEAP] Адреса масиву після realloc: %p\n", (void *)heap_array);
    printf("Вміст масиву в купі:\n");

    for (int i = 0; i < 5; i++) {
        printf("heap_array[%d] = %d (адреса елемента: %p)\n",
               i, heap_array[i], (void *)&heap_array[i]);
    }

    free(heap_array);
    heap_array = NULL;

    printf("\nПам'ять успішно звільнено.\n");

    return 0;
}
