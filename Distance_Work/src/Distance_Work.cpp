#include <iostream>
#include <time.h>
using namespace std;
template<typename T>
class Matrix
{
public:
    T** arr;
    int n, m;
    Matrix()
    {

    };
    Matrix(int n, int m)
    {
        this->n = n;
        this->m = m;
        this->arr = (T**) new T * [this->n];
        for (int i = 0; i < this->n; i++)
        {
            this->arr[i] = (T*) new T[this->m];
            for (int j = 0; j < this->m; j++)
                this->arr[i][j] = rand() % 21 - 10;
        }
        cout << "Матрица номер " << this << " Создана " << endl;
    }
    friend void print(const Matrix<T>& other);
    friend void mult(const Matrix<T>& other1, const Matrix<T>& other2);
    friend void add(const Matrix& other1, const Matrix& other2);
    ~Matrix()
    {
        for (int i = 0; i < n; i++)
            delete[]arr[i];
        delete[]arr;
        cout << "Матрица номер " << this << " Удалена " << endl;
    }
};
template<typename T>
void print(Matrix<T>& other)
{
    for (int i = 0; i < other.n; i++)
    {
        for (int j = 0; j < other.m; j++)
            cout << other.arr[i][j] << "\t";
        cout << "\n";
    }
    cout << "\n";
};
template<typename T>
void mult(Matrix<T>& other1, Matrix<T>& other2)
{
    try
    {
        cout << "Попытка перемножить матрицы " << endl;
        if (other1.m == other2.n && other1.n == other2.m)
        {
            Matrix<T> c(other1.n, other2.m);
            for (int i = 0; i < other1.n; i++)
                for (int j = 0; j < other2.m; j++)
                    c.arr[i][j] = 0;
            for (int i = 0; i < other2.m; i++)
            {
                for (int j = 0; j < other1.n; j++)
                {
                    for (int k = 0; k < other2.n; k++)
                        c.arr[i][j] += other1.arr[i][k] * other2.arr[k][j];
                }
            }
            print(c);
            cout << "Перемножение матиц выполнено успешно " << endl;
        }
        else
            throw 1;
    }
    catch (int i)
    {
        cout << "Ошибка перемножения матриц !" << std::endl;
    }
};
template<typename T>
void add(Matrix<T>& other1, Matrix<T>& other2)
{
    try {
        cout << "Попытка сложить матрицы " << endl;
        if (other1.m == other2.m && other1.n == other2.n)
        {
            Matrix<T> d(other1.n, other2.m);
            for (int i = 0; i < other1.n; i++)
                for (int j = 0; j < other1.m; j++)
                    d.arr[i][j] = 0;
            for (int i = 0; i < other2.n; i++)
            {
                for (int j = 0; j < other2.m; j++)
                {
                    d.arr[i][j] = other1.arr[i][j] + other2.arr[i][j];
                }
            }
            print(d);
            cout << "Сложение матиц выполнено успешно " << endl;
        }
        else
            throw 2;
    }
    catch (int j)
    {
        cout << "Ошибка сложения матриц !" << std::endl;
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    Matrix<int> arr1(3, 3), arr2(3, 3);
    print(arr1);
    print(arr2);
    add(arr1, arr2);
    mult(arr1, arr2);

}