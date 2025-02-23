#include <iostream>
#include <ctime>

using namespace std;

// Функция для заполнения двумерного массива случайными числами
void fillMatrix(int** arr, int ROWS, int COLS, int maxValue) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = rand() % (maxValue + 1); // Заполняем случайными числами от 0 до maxValue
        }
    }
}

// Функция для вывода двумерного массива
void printMatrix(int** arr, int ROWS, int COLS) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " "; // Просто выводим число и пробел
        }
        cout << endl;
    }
}

// Функция для поиска седловых точек
void findSaddlePoints(int** arr, int ROWS, int COLS) {
    cout << "Седловые точки матрицы:" << endl;
    bool found_saddle_points = false;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Проверяем, является ли arr[i][j] наименьшим в своей строке и наибольшим в своем столбце
            bool is_min_in_row = true;
            for (int k = 0; k < COLS && is_min_in_row; ++k) { // Проверяем строку, пока is_min_in_row истинно
                if (arr[i][j] > arr[i][k]) {
                    is_min_in_row = false;
                }
            }

            bool is_max_in_col = true;
            for (int k = 0; k < ROWS && is_max_in_col; ++k) { // Проверяем столбец, пока is_max_in_col истинно
                if (arr[i][j] < arr[k][j]) {
                    is_max_in_col = false;
                }
            }

            // Проверяем, является ли arr[i][j] наибольшим в своей строке и наименьшим в своем столбце
            bool is_max_in_row = true;
            for (int k = 0; k < COLS && is_max_in_row; ++k) {  // Проверяем строку, пока is_max_in_row истинно
                if (arr[i][j] < arr[i][k]) {
                    is_max_in_row = false;
                }
            }

            bool is_min_in_col = true;
            for (int k = 0; k < ROWS && is_min_in_col; ++k) { // Проверяем столбец, пока is_min_in_col истинно
                if (arr[i][j] > arr[k][j]) {
                    is_min_in_col = false;
                }
            }

            if ((is_min_in_row && is_max_in_col) || (is_max_in_row && is_min_in_col)) {
                cout << "Элемент: " << arr[i][j] << " (строка: " << i + 1 << ", столбец: " << j + 1 << ")" << endl;
                found_saddle_points = true;
            }
        }
    }

    if (!found_saddle_points) {
        cout << "Седловые точки не найдены." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL)); // Инициализируем генератор случайных чисел

    int ROWS, COLS;

    cout << "Введите количество строк: ";
    cin >> ROWS;

    cout << "Введите количество столбцов: ";
    cin >> COLS;

    // Выделяем память для двумерного массива
    int** arr = new int* [ROWS];
    for (int i = 0; i < ROWS; ++i) {
        arr[i] = new int[COLS];
    }

    // Заполняем массив случайными числами
    fillMatrix(arr, ROWS, COLS, 9); // Заполняем числами от 0 до 9

    // Выводим массив
    cout << "Сформированный массив:" << endl;
    printMatrix(arr, ROWS, COLS);

    // Ищем седловые точки
    findSaddlePoints(arr, ROWS, COLS);

    // Освобождаем память
    for (int i = 0; i < ROWS; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
