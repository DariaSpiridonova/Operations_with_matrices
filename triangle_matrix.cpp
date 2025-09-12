#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Введите количество строк в треугольной матрице: ");
    int num_strings = 0;
    scanf("%d", &num_strings);

    int num_items = (1 + num_strings) * num_strings / 2;
    char *triangle_matrix = (char *)calloc(num_items + 1, sizeof(char));

    for (int item = 0; item < num_items; item++)
    {
        int value = 0;
        scanf("%d", &value);
        printf("%d\n", value);
        triangle_matrix[item] = value;
    }
}