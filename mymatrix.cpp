#include <iostream>
using namespace std;

class mymatrix {
    int row, col;
    int **mat;

    // Helper method: Dynamic 2D Array Memory Allocate aur 0 Initialize karne ke liye
    void allocateAndInitialize() {
        mat = new int*[row]; // Rows ke liye array of pointers
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col]; // Har row ke liye columns
            for (int j = 0; j < col; j++) {
                mat[i][j] = 0; // Sabhi values ko 0 set kiya
            }
        }
    }

    // Helper method: Allocated Memory Delete karne ke liye
    void freeMemory() {
        if (mat != nullptr) {
            for (int i = 0; i < row; i++) {
                delete[] mat[i]; // Har row ki memory free karo
            }
            delete[] mat; // Main array of pointers free karo
            mat = nullptr;
        }
    }

public:
    // 1. Default Constructor (3x3 Matrix)
    mymatrix() {
        row = 3;
        col = 3;
        allocateAndInitialize();
    }

    // 2. Parameterized Constructor (r x c Matrix)
    mymatrix(int r, int c) {
        row = r;
        col = c;
        allocateAndInitialize();
    }

    // 3. Copy Constructor (Deep Copy)
    mymatrix(const mymatrix &s) {
        row = s.row;
        col = s.col;
        allocateAndInitialize();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] = s.mat[i][j];
            }
        }
    }

    // 4. Assignment Operator Overloading
    mymatrix& operator=(const mymatrix &s) {
        if (this == &s) return *this; // Self-assignment check

        freeMemory(); // Existing memory clean karo

        row = s.row;
        col = s.col;
        allocateAndInitialize();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] = s.mat[i][j];
            }
        }
        return *this;
    }

    // 5. Destructor
    ~mymatrix() {
        freeMemory();
    }

    // User input lene ke liye helper function
    void inputData() {
        cout << "Enter elements for " << row << "x" << col << " matrix:\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Matrix display karne ke liye helper function
    void display() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    // 6. Operator + Overloading (Matrix Addition)
    mymatrix operator+(const mymatrix &m) const {
        if (row != m.row || col != m.col) {
            cout << "\nError: Addition not possible! Dimensions must match.\n";
            return mymatrix(0, 0);
        }
        mymatrix result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    // 7. Operator * Overloading (Matrix Multiplication)
    mymatrix operator*(const mymatrix &m) const {
        if (col != m.row) {
            cout << "\nError: Multiplication not possible! Columns of 1st must equal Rows of 2nd.\n";
            return mymatrix(0, 0);
        }
        mymatrix result(row, m.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < m.col; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < col; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }

    // 8. Sum of Diagonal Elements (Primary + Secondary)
    void sumOfDiagonalElements() const {
        if (row != col) {
            cout << "\nDiagonal sum is only possible for square matrices!\n";
            return;
        }
        int primarySum = 0, secondarySum = 0;
        for (int i = 0; i < row; i++) {
            primarySum += mat[i][i];
            secondarySum += mat[i][row - 1 - i];
        }
        cout << "Primary Diagonal Sum: " << primarySum << "\n";
        cout << "Secondary Diagonal Sum: " << secondarySum << "\n";
    }

    // 9. Sum of Outer (Boundary) Elements
    int sumOfOuterElements() const {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // First row, last row, first col, or last col boundary conditions
                if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }

    // 10. Print Matrix in Spiral Order
    void printSpiral() const {
        cout << "Spiral Traversal: ";
        int top = 0, bottom = row - 1;
        int left = 0, right = col - 1;

        while (top <= bottom && left <= right) {
            // Left to Right
            for (int i = left; i <= right; i++) cout << mat[top][i] << " ";
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; i++) cout << mat[i][right] << " ";
            right--;

            // Right to Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) cout << mat[bottom][i] << " ";
                bottom--;
            }

            // Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) cout << mat[i][left] << " ";
                left++;
            }
        }
        cout << "\n";
    }

    // 11. Leaders of Matrix
    // Element is a leader if it is strictly greater than all elements to its right and bottom
    void printLeaders() const {
        cout << "Leaders in Matrix: ";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                bool isLeader = true;
                
                // Check all elements to the right and bottom
                for (int r = i; r < row; r++) {
                    for (int c = (r == i ? j + 1 : 0); c < col; c++) {
                        if (mat[r][c] >= mat[i][j]) {
                            isLeader = false;
                            break;
                        }
                    }
                    if (!isLeader) break;
                }

                if (isLeader) {
                    cout << mat[i][j] << " ";
                }
            }
        }
        cout << "\n";
    }
};

int main() {
    mymatrix m1(3, 3);
    cout << "--- Input for Matrix 1 ---\n";
    m1.inputData();

    cout << "\n--- Matrix 1 ---\n";
    m1.display();

    cout << "\n--- Diagonal Sums ---\n";
    m1.sumOfDiagonalElements();

    cout << "\n--- Outer Elements Sum ---\n";
    cout << "Outer Sum: " << m1.sumOfOuterElements() << "\n";

    cout << "\n--- Spiral Traversal ---\n";
    m1.printSpiral();

    cout << "\n--- Leaders in Matrix ---\n";
    m1.printLeaders();

    return 0;
}