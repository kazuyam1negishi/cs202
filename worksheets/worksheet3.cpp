#include <iostream>
using namespace std;

class Matrix{
    private:
        int rows;
        int columns;
        int *** matrix;
    public:
        Matrix(){
            rows = 3;
            columns = 3;
        };
        Matrix(int rows, int columns){
            this->rows = rows;
            this->columns = columns;
        };
        void fillMatrix(){
            matrix = new int ** [rows];
            for(int i = 0; i < rows; i++){
                matrix[i] = new int * [columns];
                for(int j = 0; j < columns; j++){
                    matrix[i][j] = new int;
                    * matrix[i][j] = rand() % 20;
                }
            }
        };
        void printMatrix(){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    cout << * matrix[i][j] << " ";
                }
                cout << endl;
            }
        };
        int getRows() const{
            return(rows);
        }
        int getColumns() const{
            return(columns);
        }
        ~Matrix(){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    delete matrix[i][j];
                }
                delete [] matrix[i];
            }
            delete [] matrix;
            matrix = nullptr;
        }
};

int main(){
    Matrix arr1;
    arr1.fillMatrix();
    arr1.printMatrix();
    return(0);
}