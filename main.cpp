#include<iostream>
using namespace std;

void fill(int **mat, int n); //заполнение матрицы различными числами
void print(int **mat, int n); //вывод исходной матрицы
void make_new_matrix(int **mat, int pos, int n, int **&current_mat); // создание матрицы на 1 размерность меньше
int sign(int n); // Знак перед минором
int Determinant(int **arr, int size, int **&current_mat); //основная функция подсчета. Ищем по разложению первой строки

int main(int argc, char* argv[])
{
    srand(15);
    int n;
    cin >> n;

    int **current_mat;          //матрица размерностью меньше
    int **mat = new int *[n];
    for(int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }
    fill(mat, n);
    cout << "\n";
    print(mat, n);
    cout << "\n\n" << endl;

    cout << Determinant(mat, n, current_mat) << endl;



    system("pause");
}

int Determinant(int **arr, int size, int **&current_mat)
{
    int s = 0;
    if(size == 1) return arr[0][0]; // доделать
    else
    {
        for (int j = 0; j < size; j++)
        {
            make_new_matrix(arr, size, j, current_mat);
            s += arr[0][j] * sign(j) * Determinant(current_mat, size - 1, current_mat);
        }  
    }

    return s;
}

void make_new_matrix(int **mat, int size, int pos, int **&current_mat)
{
    current_mat = new int *[size-1];
    for (int i = 0; i < size-1; i++)
    {
        current_mat[i] = new int[size-1];
    }
    
    int row = 0, col = 0;

    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(j == pos) continue;
            current_mat[row][col] = mat[i][j];
            col++;
        }
        row++;
        col = 0;
    } 
}

void fill(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = rand() % 10;
        }
    }
}

void print(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int sign(int n)
{
    if(n % 2 != 0) return -1;
    else return 1;
}