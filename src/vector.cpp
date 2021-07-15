#include <vector.h>


template<typename T> //default consructor 
Vector<T>::Vector(int n)
{
     vLength = n;
     vData = new T[vLength];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& src) //copy constructor
{
    vLength = src.getLength();
    vData = new T[vLength];
    std::memcpy(vData, src.getData(), vLength*sizeof(T));
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst):vLength{lst.size()}, vData{new T[lst.size()]} //initializer list constructor
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
    Vector<T> vec_addition(vLength);
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
    Vector vec_addition(vLength);
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
    Vector vec_subtraction(vLength);
    for (int i = 0; i < vLength; i++)
    {
        vec_subtraction.vData[i] = this->vData[i] - second_vector.vData[i];
    }
    return vec_subtraction;  
}

template<typename T>
Vector<T> Vector<T>::operator* (T scalar_value) //scalar multiplication
{
    Vector vec_multiplied(vLength);
    for (int i = 0; i < vLength; i++)
    {
        vec_multiplied.vData[i] = scalar_value * this->vData[i];
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

template<typename T> //output 
std::ostream& operator<< (std::ostream& out, const Vector<T> &src)
{
    out << "(" << src.getLength() << "-vector):"<<"\n";
    for (int i = 0; i < src.getLength(); i++)
    {
        out << " " << src[i];
    }
    return out;    
}