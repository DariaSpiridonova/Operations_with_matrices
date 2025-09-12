#include <stdio.h>
#include <stdlib.h>

void get_matrix(char* matrix, int y);
void print_matrix(char matrix[][4], int y, size_t n);
void print_max_and_min_item(char matrix[][4], int y, size_t n);
void print_product_of_matrices(char matrix1[][4], char matrix2[][4], int y1, int y2);
void item_value(char matrix1[][4], char matrix2[][4], int y2, int i, int j);

// get_matrix -> int*, x, y (структура)


// int* matrix, size_t size_x, size_y, x, y
// matrix[size_x*y + x] = 5
int * func(int *matrix, size_t size_x, int x, int y)
{
    return &matrix[size_x*y + x];
}

int main()
{ 
    char my_matrix1[4][4] = {};
    get_matrix(my_matrix1, 4);
    char my_matrix2[4][4] = {};
    get_matrix(my_matrix2, 4);

    print_matrix(my_matrix1, 4, 1);
    print_matrix(my_matrix2, 4, 2);

    print_max_and_min_item(my_matrix1, 4, 1);
    print_max_and_min_item(my_matrix2, 4, 2);

    print_product_of_matrices(my_matrix1, my_matrix2, 4, 4);
}

void get_matrix(char matrix[][4], int y)
{
    printf("Введите %d строк матрицы, разделяя элементы пробелом:\n", y);
    char *str = (char *)calloc(10, sizeof(char));

    for (int i = 0; i < y; i++)
    {
        fgets(str, 10, stdin);
        sscanf(str, "%c %c %c %c %c", &matrix[i][0], &matrix[i][1], &matrix[i][2], &matrix[i][3], &matrix[i][4]);
    }
}

void print_matrix(char matrix[][4], int y, size_t n)
{
    printf("Матрица №%d\n", n);
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_max_and_min_item(char matrix[][4], int y, size_t n)
{
    char min_item = matrix[0][0];
    char max_item = matrix[0][0];

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] > max_item) max_item = matrix[i][j];
            if (matrix[i][j] < min_item) min_item = matrix[i][j];
        }
    }

    printf("Максимальный элемент матрицы №%d = %c\n", n, max_item);
    printf("Минимальный элемент матрицы №%d = %c\n", n, min_item);
}

void print_product_of_matrices(char matrix1[][4], char matrix2[][4], int y1, int y2)
{
    printf("Произведение матриц 1 и 2 равно следующей матрице:\n");
    for (int i = 0; i < y1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            item_value(matrix1, matrix2, y2, i, j);
        }
        printf("\n");
    }
}

void item_value(char matrix1[][4], char matrix2[][4], int y2, int i, int j)
{
    int item_value = 0;
    for (int t = 0; t < y2; t++)
    {
        item_value += (((int)matrix1[i][t] - (int)'0') * ((int)matrix2[t][j] - (int)'0')); 
    }
    printf("%3d ", item_value);
}

void solve(double a, double b, double c);

//функцияб возвращающая рез перемножения матриц, возвр новую матрицу, созд вне функции