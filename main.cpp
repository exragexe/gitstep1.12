
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
T** init_array(size_t rows, size_t cols)
{
    T** arr = new T*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new T[cols];
        for (size_t j = 0; j < cols; j++)
        {
            arr[i][j] = -10 + T(rand() % 50);
        }
    }
    return arr;
}

template <typename T>
void print_array(T** arr, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

template<typename T>
bool addarr(T** &arr, size_t &rows, size_t &cols, T** items, size_t num_rows, size_t num_cols){
    size_t old_rows = rows;
    rows += num_rows;
    cols = num_cols;
    T** buffer = new T*[rows];
    for (size_t i = 0; i < num_rows; i++) {
        buffer[i] = items[i];
    }
    for (size_t i = 0; i < old_rows; i++) {
        buffer[num_rows + i] = arr[i];
    }

    delete[] arr;
    arr = buffer;
    return true;
}


int main()
{
    srand(time(0));

    cout << "Enter number of rows for the array: ";
    size_t rows;
    cin >> rows;
    cout << "Enter number of columns for the array: ";
    size_t cols;
    cin >> cols;
    int** arr_i = init_array<int>(rows, cols);

    cout << "==================================" << endl;
    cout << "Array: " << endl;
    print_array<int>(arr_i, rows, cols);
    cout << "==================================" << endl;

    cout << "Enter number of rows for the new items to add: ";
    size_t new_rows;
    cin >> new_rows;
    int** item = init_array<int>(new_rows, cols);
    cout << "Elements: " << endl;
    print_array<int>(item, new_rows, cols);

    cout << "==================================" << endl;
    cout << "Result: " << endl;
    addarr(arr_i,rows,cols,item,new_rows,cols);
    print_array(arr_i,rows,cols) ;
    delete[] arr_i;
    return 0;
}