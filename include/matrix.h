#ifndef MATRIX_H
#define MATRIX_H

#include <cstring>
#include <cassert>
#include <iostream>
#include <initializer_list>



template<typename T>
class Matrix
{
  private:
    int m_rowSize;
    int m_colSize;
    T* mData;
 
  public:
    Matrix<T>(int dim); //default square matrix constructor
    Matrix<T>(int rows, int cols); //default rectangular matrix constructor
    Matrix<T>(int rows, int cols, std::initializer_list<T>); //initializer list constructors
    ~Matrix(); //destructor
    Matrix<T>(const Matrix&); //copy constructor 
    int getRows() const {return m_rowSize;} // the row numbers
    int getCols() const {return m_colSize;} // the column numbers

    Matrix<T>& operator= (const Matrix&); //copy assignment operator=
    T* operator[](const int) const;
    T& operator() (const int, const int) const; // element access operator 
    Matrix<T> operator+  (const Matrix&); //matrix addition 
    Matrix<T> operator+ (T);
    Matrix<T> operator- (const Matrix&); //matrix decrement 
    Matrix<T> operator* (const Matrix&); //matrix multiplication
    Matrix<T> operator* (const T&); //scalar multiplication   
    friend std::ostream& operator<< (std::ostream& out, const Matrix<T>& given_matrix) //output   
    {
      
      for (int i = 1; i <= given_matrix.getRows(); i++)
      {
          out << std::endl; //new line
          for (int j = 1; j <= given_matrix.getCols(); j++)
          {
              out<<given_matrix(i,j)<< " ";
          }
      }
      out<<std::endl;
      return out;
    }
};

template<typename T>
Matrix<T>::Matrix(int dim): m_rowSize(dim), m_colSize(dim) //default square matrix constructor
{
    mData = new T[dim*dim];
}

template<typename T>
Matrix<T>::Matrix(int rows, int cols): m_rowSize(rows), m_colSize(cols) //default rectangular matrix constructor
{
    mData = new T[rows*cols];
}

template<typename T>
Matrix<T>::Matrix(int rows, int cols, std::initializer_list<T> lst): m_rowSize{rows}, m_colSize{cols}, mData{new T[lst.size()]} //initializer list constructor
{   
    std::copy(lst.begin(), lst.end(), mData);
}

template<typename T>
Matrix<T>::Matrix(const Matrix& src):m_colSize{src.m_colSize}, m_rowSize{src.m_rowSize} //copy constructor 
{
    std::memcpy(mData, src.mData, m_rowSize*m_colSize*sizeof(T));   
}

template<typename T>
Matrix<T>::~Matrix() //destructor
{
    delete[] mData;
}

template<typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix& src) //asignment operator=
{
    if(this != &src) //protect against invalid self-assignment 
    {
        if(m_rowSize * m_colSize != src.m_rowSize * src.m_colSize)
        {
            delete[] mData; //destroying old stack 
            mData = new T[src.m_rowSize * src.m_colSize];
        }
        m_rowSize = src.m_rowSize;
        m_colSize = src.m_colSize;  
        //deep copy 
        std::memcpy(mData, src.mData, m_rowSize * m_colSize * sizeof(T));
    }
    return *this;
}

template<typename T>
T& Matrix<T>::operator()(const int row_index, const int col_index) const // element access operator 
{
    assert((row_index>0 && row_index<=m_rowSize) && "Matrix: row out of the range");
    assert((col_index>0 && col_index<=m_colSize) && "Matrix: col out of the range");

    return (*this).mData[(row_index-1)*m_colSize + col_index - 1];
}

template<typename T>
T* Matrix<T>::operator[](const int row_index) const  //element access operator
{
    assert((row_index < (*this).getRows()) && "Matrix: Row out of range.");
    
    
    return &mData[(*this).getCols()* row_index];
}

template<typename T>
Matrix<T> Matrix<T>::operator+  (const Matrix& second_matrix) //matrix addition 
{
    assert((second_matrix.getRows() == m_rowSize && second_matrix.getCols() == m_colSize) && "Matrices can't be added");
    Matrix<T> m_summed(m_rowSize, m_colSize); 
    for(int i=0; i < m_colSize * m_rowSize; i++)
    {
        m_summed.mData[i] = (*this).mData[i] + second_matrix.mData[i];
    }
    return m_summed;
}

template<typename T>
Matrix<T> Matrix<T>::operator+ (T value) //adding constant at each element
{
    Matrix<T> m_summed(m_rowSize, m_colSize);
    for (int  i = 0; i < m_rowSize * m_colSize; i++)
    {
         m_summed.mData[i]= (*this).mData[i] + value;
    }
    return m_summed;
}

template<typename T>
Matrix<T> Matrix<T>::operator- (const Matrix& second_matrix) //matrix decrement 
{
    assert((second_matrix.getRows() == m_rowSize && second_matrix.getCols() == m_colSize) && "Matrices can't be subtracted");
    Matrix<T> m_subtracted(m_rowSize, m_colSize); 
    for(int i=0; i < m_colSize * m_rowSize; i++)
    {
        m_subtracted.mData[i] = (*this).mData[i] - second_matrix.mData[i];
    }
    return m_subtracted;
}

template<typename T>
Matrix<T> Matrix<T>::operator* (const Matrix& second_matrix) //matrix multiplication
{
    assert((m_colSize == second_matrix.getRows()) && "Two matrices dimensions are mismatched.");
    Matrix<T> m_multiplied(m_rowSize , second_matrix.getCols());
    for (int  i = 0; i < m_rowSize; i++)
    {
        for (int j = 0; j < second_matrix.getCols(); j++)
        {
            T *s = &m_multiplied[i][j]; 
            *s=0;
            for (int k = 0; k < m_colSize; k++)
            {

                *s +=(*this).mData[i*m_colSize+k] * second_matrix.mData[k*second_matrix.m_colSize + j];
            }
            
        }
        
    }
    return m_multiplied;
}

template<typename T>
Matrix<T> Matrix<T>::operator* (const T& scalar) //scalar multiplication
{
    Matrix<T> m_multiplied(m_rowSize, m_colSize);
    for (int i = 0; i < m_rowSize; i++)
    {
        for (int j = 0; j < m_colSize; j++)
        {
            m_multiplied.mData[i*m_colSize + j] = scalar * (*this).mData[i*m_colSize + j];
        }
    }
    return m_multiplied;
}   


#endif