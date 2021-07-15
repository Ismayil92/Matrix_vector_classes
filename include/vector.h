#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstring> //enable memcpy
#include <cassert> //enable assert
#include <initializer_list>
#include <matrix.h>
//think about static_assert
enum class VECTOR_TYPE{
    ROW,
    COLUMN
};

template<typename T = double>
class Vector
{
    private:
        T* vData;
        int vLength;
        VECTOR_TYPE vType;
    public:
        Vector<T>(int, const VECTOR_TYPE &);
        Vector<T>(const Vector<T>&); //copy constructor
        Vector<T>(std::initializer_list<T>, const VECTOR_TYPE &vector_type); //initializer list constructor
        ~Vector<T>();
        
        T& operator[] (int) const; //element access operator 
        
        Vector<T>& operator= (const Vector<T>&); //direct assignment operator
        Vector<T> operator+ (T); //add scalar 
        Vector<T> operator+ (const Vector<T>&); //Vector addition 
        Vector<T> operator- (const Vector<T>&); //Vector subtraction 
        Vector<T> operator* (T); //scalar multiplication
        Vector<T> operator* (const Matrix<T>&); // matrix vector multiplication
        int getLength() const; //get a vector length
        T* getData() const; //get data
        VECTOR_TYPE getVectorType() const; //get a vector type
        friend std::ostream& operator<< (std::ostream& out, const Vector<T>& src) //output
        {
           
            for (int i = 0; i < src.getLength(); i++)
            {
                if (src.getVectorType() == VECTOR_TYPE::ROW)
                {
                    out << src[i]<<" ";
                }
                else 
                {
                    out << src[i] <<std::endl;
                }
                
            }
            return out;    
        }
        friend Vector<T> operator* (const Matrix<T>& mat , const Vector<T>& vec){

            assert((vec.getLength() == mat.getCols()) && "Vector and Matrix dimensions don't match.");
            assert((vec.getVectorType() == VECTOR_TYPE::COLUMN) && "Row vector can not be used here");
    
            Vector<T> vec_multiplied(vec.getLength(), vec.getVectorType());    
            for (int i = 0; i < vec.getLength(); i++)
            {
                    for (int j = 0; j <  mat.getCols(); j++)
                    {
                        vec_multiplied.vData[i] = mat[i][j] * vec.vData[j];
                    }                    
            }
        
            return vec_multiplied;            
        }
         
};

template<typename T> //default consructor 
Vector<T>::Vector(int n, const VECTOR_TYPE & _vector_type)
{
     vType = _vector_type;
     vLength = n;
     vData = new T[vLength];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& src):Vector<T>(src.getLength(), src.getVectorType()) //copy constructor
{
    std::memcpy(vData, src.getData(), vLength*sizeof(T));
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst, const VECTOR_TYPE &_vector_type):Vector<T>(lst.size(),_vector_type) // initializer list constructor
{
   std::copy(lst.begin(), lst.end(), vData);
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] vData;
}

template<typename T>
T& Vector<T>::operator[](const int _index) const //indexing element
{
    return vData[_index];
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& src) //direct assignment
{
    if(this != &src)
    {
        if(vLength != src.getLength()) //I could use directly src.vLength too
        {
            delete[] vData;
            vType = src.getVectorType();
            vLength = src.getLength();
            vData = new T[src.getLength()];
        }
        std::memcpy(vData, src.getData(), vLength * sizeof(T));
    }
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+ (T scalar_value) //add scalar
{
    Vector<T> vec_addition(vLength, this->getVectorType());
    for (int i = 0; i < vLength; i++)
    {
        vec_addition.vData[i]=this->vData[i] + scalar_value;
    }
    return vec_addition;    
} 

template<typename T>
Vector<T> Vector<T>::operator+ (const Vector<T>& second_vector) //add vector
{
    assert((vLength == second_vector.getLength()) && "Vector length mismatch.");
    assert((vType == second_vector.getVectorType()) && "Vector types are different.");
    Vector<T> vec_addition(vLength, second_vector.getVectorType());
    for (int i = 0; i < vLength; i++)
    {
        vec_addition.vData[i] = this->vData[i] + second_vector.vData[i];
    }
    return vec_addition;    
}

template<typename T>
Vector<T> Vector<T>::operator- (const Vector<T>& second_vector) //Vector subtraction 
{
    assert((vLength == second_vector.getLength()) && "Vector length mismatch.");
    assert((vType == second_vector.getVectorType()) && "Vector types are different.");
    Vector<T> vec_subtraction(vLength, second_vector.getVectorType());
    for (int i = 0; i < vLength; i++)
    {
        vec_subtraction.vData[i] = this->vData[i] - second_vector.vData[i];
    }
    return vec_subtraction;  
}

template<typename T>
Vector<T> Vector<T>::operator* (T scalar_value) //scalar multiplication
{
    Vector<T> vec_multiplied(vLength, this->getVectorType());
    for (int i = 0; i < vLength; i++)
    {
        vec_multiplied.vData[i] = scalar_value * this->vData[i];
    }
    return vec_multiplied;
    
}

template<typename T> 
Vector<T> Vector<T>::operator* (const Matrix<T> &src) //row_vector * matrix
{   
    assert((vLength == src.getRows()) && "Vector and Matrix dimensions don't match.");
    assert((vType == VECTOR_TYPE::ROW) && "Column vector can not be used here");
    
    Vector<T> vec_multiplied(vLength, this->getVectorType());    
    for (int i = 0; i < vLength; i++)
    {
            for (int j = 0; j <  src.getRows(); j++)
            {
                vec_multiplied.vData[i] = src[j][i] * this->vData[j];
            }
            
    }
        
    return vec_multiplied;
}

template<typename T>
int Vector<T>::getLength() const  //get vector length
{
    return vLength;
}

template<typename T>
T* Vector<T>::getData() const
{
    return vData;
}

template<typename T>
VECTOR_TYPE Vector<T>::getVectorType() const
{
    return vType;
}
#endif