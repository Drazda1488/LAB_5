#include <iostream>
#include <ctime>

using namespace std;

// ������� ��� ���������� ���������� ������� ���������� �������
void fillMatrix(int** arr, int ROWS, int COLS, int maxValue) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = rand() % (maxValue + 1); // ��������� ���������� ������� �� 0 �� maxValue
        }
    }
}

// ������� ��� ������ ���������� �������
void printMatrix(int** arr, int ROWS, int COLS) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " "; // ������ ������� ����� � ������
        }
        cout << endl;
    }
}

// ������� ��� ������ �������� �����
void findSaddlePoints(int** arr, int ROWS, int COLS) {
    cout << "�������� ����� �������:" << endl;
    bool found_saddle_points = false;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // ���������, �������� �� arr[i][j] ���������� � ����� ������ � ���������� � ����� �������
            bool is_min_in_row = true;
            for (int k = 0; k < COLS && is_min_in_row; ++k) { // ��������� ������, ���� is_min_in_row �������
                if (arr[i][j] > arr[i][k]) {
                    is_min_in_row = false;
                }
            }

            bool is_max_in_col = true;
            for (int k = 0; k < ROWS && is_max_in_col; ++k) { // ��������� �������, ���� is_max_in_col �������
                if (arr[i][j] < arr[k][j]) {
                    is_max_in_col = false;
                }
            }

            // ���������, �������� �� arr[i][j] ���������� � ����� ������ � ���������� � ����� �������
            bool is_max_in_row = true;
            for (int k = 0; k < COLS && is_max_in_row; ++k) {  // ��������� ������, ���� is_max_in_row �������
                if (arr[i][j] < arr[i][k]) {
                    is_max_in_row = false;
                }
            }

            bool is_min_in_col = true;
            for (int k = 0; k < ROWS && is_min_in_col; ++k) { // ��������� �������, ���� is_min_in_col �������
                if (arr[i][j] > arr[k][j]) {
                    is_min_in_col = false;
                }
            }

            if ((is_min_in_row && is_max_in_col) || (is_max_in_row && is_min_in_col)) {
                cout << "�������: " << arr[i][j] << " (������: " << i + 1 << ", �������: " << j + 1 << ")" << endl;
                found_saddle_points = true;
            }
        }
    }

    if (!found_saddle_points) {
        cout << "�������� ����� �� �������." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL)); // �������������� ��������� ��������� �����

    int ROWS, COLS;

    cout << "������� ���������� �����: ";
    cin >> ROWS;

    cout << "������� ���������� ��������: ";
    cin >> COLS;

    // �������� ������ ��� ���������� �������
    int** arr = new int* [ROWS];
    for (int i = 0; i < ROWS; ++i) {
        arr[i] = new int[COLS];
    }

    // ��������� ������ ���������� �������
    fillMatrix(arr, ROWS, COLS, 9); // ��������� ������� �� 0 �� 9

    // ������� ������
    cout << "�������������� ������:" << endl;
    printMatrix(arr, ROWS, COLS);

    // ���� �������� �����
    findSaddlePoints(arr, ROWS, COLS);

    // ����������� ������
    for (int i = 0; i < ROWS; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
