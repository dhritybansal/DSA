#include <iostream>
#include <vector>
using namespace std;

struct Triplet {
    int row;
    int col;
    int val;
};

void displayTriplets(vector<Triplet>& triplets) {
    cout << "Row\tCol\tValue\n";
    for (auto t : triplets) {
        cout << t.row << "\t" << t.col << "\t" << t.val << endl;
    }
}

vector<Triplet> transpose(vector<Triplet>& mat) {
    vector<Triplet> result;
    for (int c = 0; ; c++) {
        bool found = false;
        for (auto t : mat) {
            if (t.col == c) {
                result.push_back({t.col, t.row, t.val});
                found = true;
            }
        }
        if (!found && c > mat.back().col) break; 
    }
    return result;
}


vector<Triplet> add(vector<Triplet>& A, vector<Triplet>& B) {
    vector<Triplet> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result.push_back(A[i]);
            i++;
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result.push_back(B[j]);
            j++;
        } else { 
            int sum = A[i].val + B[j].val;
            if (sum != 0)
                result.push_back({A[i].row, A[i].col, sum});
            i++; j++;
        }
    }
    while (i < A.size()) result.push_back(A[i++]);
    while (j < B.size()) result.push_back(B[j++]);
    return result;
}


vector<Triplet> multiply(vector<Triplet>& A, vector<Triplet>& B, int rowsA, int colsB) {
    vector<Triplet> result;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (auto a : A) {
                if (a.row == i) {
                    for (auto b : B) {
                        if (b.row == a.col && b.col == j)
                            sum += a.val * b.val;
                    }
                }
            }
            if (sum != 0) result.push_back({i, j, sum});
        }
    }
    return result;
}

int main() {
    int rows, cols, nonZero;

    cout << "Enter rows, cols, and number of non-zero elements of matrix A: ";
    cin >> rows >> cols >> nonZero;

    vector<Triplet> A(nonZero);
    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 0; i < nonZero; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    cout << "\nMatrix A in triplet form:\n";
    displayTriplets(A);

  
    vector<Triplet> At = transpose(A);
    cout << "\nTranspose of Matrix A:\n";
    displayTriplets(At);


    vector<Triplet> sum = add(A, A);
    cout << "\nAddition of Matrix A + A:\n";
    displayTriplets(sum);

  
    vector<Triplet> prod = multiply(A, At, rows, rows);
    cout << "\nMultiplication of Matrix A * Transpose(A):\n";
    displayTriplets(prod);

    return 0;
}
