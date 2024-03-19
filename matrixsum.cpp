#include <iostream>
using namespace std;

class Matrix
{
    int row,column;
    int** matrix;
    public:
        Matrix(int r,int c)
        {
            row = r;
            column = c;
            matrix = new int*[row];
            for(int i = 0; i < row; i++)
            {
                matrix[i] = new int[column];
            }
        }
        void getValues();
        void display();
        friend class Sum;
};

class Sum
{
    public: 
        void add(Matrix, Matrix, Matrix );
};

void Matrix::getValues()
{
    cout<<"Enter the values: "<<endl;
    for(int i = 0; i< row; i++)
    {
        for(int j = 0; j<column; j++)
        {
            cin>>matrix[i][j];
        }
    }
}

void Matrix::display()
{
    cout<<"The values are: "<<endl;
    for(int i = 0; i< row; i++)
    {
        for(int j = 0; j<column; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Sum::add(Matrix m1, Matrix m2, Matrix m3)
{
    for(int i = 0; i< m1.row; i++)
    {
        for(int j = 0; j< m1.column; j++)
        {
            m3.matrix[i][j] = m1.matrix[i][j]+m2.matrix[i][j];
        }
    }
}

int main()
{
    int r1,c1;
    cout<<"Enter the number of rows and columns: "<<endl;
    cin>>r1>>c1;
    Matrix mat1(r1,c1);
    mat1.getValues();
    mat1.display();

    Matrix mat2(r1,c1);
    mat2.getValues();
    mat2.display();

    Matrix mat3(r1,c1);
    
    Sum s;
    s.add(mat1,mat2,mat3);
    mat3.display();
    
}
