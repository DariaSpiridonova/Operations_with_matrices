#include <stdio.h>
#include <stdlib.h>

int *func(int *matrix, size_t size_x, int x, int y);
struct matrix_parameters get_matrix(void);
void print_matrix(int *matrix, int y, int x, size_t n);
struct min_and_max_items get_max_and_min_item(int *matrix, int y, int x);
void print_max_and_min_item(struct min_and_max_items extreme_elements, size_t n);
int *create_product_of_matrices(int y1, int x2);
int *get_product_of_matrices(int *matrix_product, int *matrix1, int *matrix2, int y2, int y1, int x2);
int get_single_element_of_product_matrix(int *matrix1, int *matrix2, int y2, int x2, int i, int j);

struct matrix_parameters
{
    int *matrix;
    int x;
    int y;
};

struct min_and_max_items
{
    int min_item;
    int max_item;
};

int main()
{
    struct matrix_parameters matrix1_par = get_matrix();
    struct matrix_parameters matrix2_par = get_matrix();

    print_matrix(matrix1_par.matrix, matrix1_par.y, matrix1_par.x, 1);
    print_matrix(matrix2_par.matrix, matrix2_par.y, matrix2_par.x, 2);

    print_max_and_min_item(get_max_and_min_item(matrix1_par.matrix, matrix1_par.y, matrix1_par.x), 1);
    print_max_and_min_item(get_max_and_min_item(matrix2_par.matrix, matrix2_par.y, matrix2_par.x), 2);

    int *product_of_matrices = get_product_of_matrices(create_product_of_matrices(matrix1_par.y, matrix2_par.x), matrix1_par.matrix, matrix2_par.matrix, matrix2_par.y, matrix1_par.y, matrix2_par.x);

    print_matrix(product_of_matrices, matrix1_par.y, matrix2_par.x, 3);
}

int *func(int *matrix, size_t size_x, int x, int y)
{
    return &matrix[size_x * y + x];
}

struct matrix_parameters get_matrix(void)
{
    struct matrix_parameters matrix_n;
    int y = 0, x = 0;
    printf("Укажите количество строк и стобцов в матрице через пробел: ");
    scanf("%d ", &y);
    scanf("%d", &x);

    printf("Введите %d строк матрицы, разделяя элементы пробелом:\n", y);
    int *matrix = (int *)calloc(x * y, sizeof(int));

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            scanf("%d", func(matrix, x, j, i));
        }
    }
    matrix_n.matrix = matrix;
    matrix_n.y = y;
    matrix_n.x = x;

    return matrix_n;
}

void print_matrix(int *matrix, int y, int x, size_t n)
{
    printf("Матрица №%d\n", n);
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ", *func(matrix, x, j, i));
        }
        printf("\n");
    }
}

struct min_and_max_items get_max_and_min_item(int *matrix, int y, int x)
{
    struct min_and_max_items extreme_elements;
    int min_item = *matrix;
    int max_item = *matrix;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (*func(matrix, x, j, i) > max_item)
                max_item = *func(matrix, x, j, i);
            if (*func(matrix, x, j, i) < min_item)
                min_item = *func(matrix, x, j, i);
        }
    }

    extreme_elements.min_item = min_item;
    extreme_elements.max_item = max_item;

    return extreme_elements;
}

void print_max_and_min_item(struct min_and_max_items extreme_elements, size_t n)
{
    printf("Максимальный элемент матрицы №%d = %d\n", n, extreme_elements.max_item);
    printf("Минимальный элемент матрицы №%d = %d\n", n, extreme_elements.min_item);
}

int *create_product_of_matrices(int y1, int x2)
{
    int *matrix = (int *)calloc(y1 * x2, sizeof(int));
    return matrix;
}

int *get_product_of_matrices(int *matrix_product, int *matrix1, int *matrix2, int y2, int y1, int x2)
{
    for (int i = 0; i < y1; i++)
    {
        for (int j = 0; j < x2; j++)
        {
            *func(matrix_product, x2, j, i) = get_single_element_of_product_matrix(matrix1, matrix2, y2, x2, i, j);
        }
    }

    return matrix_product;
}

int get_single_element_of_product_matrix(int *matrix1, int *matrix2, int y2, int x2, int i, int j)
{
    int value_of_single_element = 0;
    for (int t = 0; t < y2; t++)
    {
        value_of_single_element += (*func(matrix1, y2, t, i)) * (*func(matrix2, x2, j, t));
    }
    return value_of_single_element;
}