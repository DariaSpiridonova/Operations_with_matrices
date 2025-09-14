#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int num_of_elements(int y);
struct matrix_parameters get_matrix(void);
void print_matrix(struct matrix_parameters matrix_par);
struct min_and_max_items get_max_and_min_item(struct matrix_parameters matrix_par);
void print_max_and_min_item(struct min_and_max_items extreme_elements);

struct matrix_parameters
{
    int *matrix;
    int y;
};

struct min_and_max_items
{
    int min_item;
    int max_item;
};

int main()
{
    struct matrix_parameters matrix_par = get_matrix();

    print_matrix(matrix_par);

    print_max_and_min_item(get_max_and_min_item(matrix_par));

    free(matrix_par.matrix);

    return 0;
}

int num_of_elements(int y)
{
    return (1 + y) * y / 2;
}

struct matrix_parameters get_matrix(void)
{
    struct matrix_parameters matrix_n;
    int y = 0;
    printf("Укажите количество строк в треугольной матрице: ");
    scanf("%d", &y);

    printf("Введите %d строк матрицы, разделяя элементы пробелом:\n", y);
    int *matrix = (int *)calloc(num_of_elements(y), sizeof(int));

    for (int i = 0; i < num_of_elements(y); i++)
    {
        scanf("%d", &matrix[i]);
    }
    matrix_n.matrix = matrix;
    matrix_n.y = y;

    return matrix_n;
}

void print_matrix(struct matrix_parameters matrix_par)
{
    assert(matrix_par.matrix != NULL);

    printf("Треугольная матрица\n");
    for (int i = 0; i < matrix_par.y; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", matrix_par.matrix[num_of_elements(i) + j]);
        }
        printf("\n");
    }
}

struct min_and_max_items get_max_and_min_item(struct matrix_parameters matrix_par)
{
    assert(matrix_par.matrix != NULL);

    struct min_and_max_items extreme_elements;
    int min_item = *matrix_par.matrix;
    int max_item = *matrix_par.matrix;

    for (int i = 0; i < num_of_elements(matrix_par.y); i++)
    {
        if (matrix_par.matrix[i] > max_item)
            max_item = matrix_par.matrix[i];
        if (matrix_par.matrix[i] < min_item)
            min_item = matrix_par.matrix[i];
    }

    extreme_elements.min_item = min_item;
    extreme_elements.max_item = max_item;

    return extreme_elements;
}

void print_max_and_min_item(struct min_and_max_items extreme_elements)
{
    assert(&extreme_elements != NULL);

    printf("Максимальный элемент треугольной матрицы = %d\n",extreme_elements.max_item);
    printf("Минимальный элемент треугольной матрицы = %d\n",extreme_elements.min_item);
}