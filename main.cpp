#include<iostream>
using namespace std;

void fill(int **mat, int n); //заполнение матрицы различными числами
void print(int **mat, int n); //вывод исходной матрицы
void make_new_matrix(int **mat, int pos, int n, int **&tmp_mat); // создание матрицы на 1 размерность меньше
int sign(int n); // Знак перед минором
int Determinant(int **arr, int size, int **&tmp_mat); //основная функция подсчета. Ищем по разложению первой строки

int main(int argc, char* argv[])
{
    int n; //размерность матрицы
    int **mat; //матрица
    int **tmp_mat; // матрица на 1 размерность меньше предыдущей

    cout<< "Enter matrix size: ";
    cin >> n;
    cout << endl;

    mat = new int *[n];
    for(int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }

    cout<< "Fill matrix \n" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
        
    }
   
    cout << "\nDeterminant = " <<Determinant(mat, n, tmp_mat) << endl;
    system("pause");
}

int Determinant(int **arr, int size, int **&tmp_mat)
{
    int s = 0;
    if(size == 1) return arr[0][0]; // доделать
    else
    {
        for (int j = 0; j < size; j++)
        {
            make_new_matrix(arr, size, j, tmp_mat);
            s += arr[0][j] * sign(j) * Determinant(tmp_mat, size - 1, tmp_mat);
        }  
    }

    return s;
}

void make_new_matrix(int **mat, int size, int pos, int **&tmp_mat)
{
    tmp_mat = new int *[size-1];
    for (int i = 0; i < size-1; i++)
    {
        tmp_mat[i] = new int[size-1];
    }
    
    int row = 0, col = 0;

    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(j == pos) continue;
            tmp_mat[row][col] = mat[i][j];
            col++;
        }
        row++;
        col = 0;
    } 
}

int sign(int n)
{
    if(n % 2 != 0) return -1;
    else return 1;
}