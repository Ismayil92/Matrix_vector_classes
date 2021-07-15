#include <iostream>
#include <matrix.h>
#include <vector.h>

int main()
{
    Vector<int> vector_a({1,2,3}, VECTOR_TYPE::COLUMN);
    Matrix<int> matrix_a(3,3,{1,2,3,4,5,6,7,8,9});   

    int s{5};

    Vector<int> vector_b = vector_a+s; //scalar vector addition    
    Vector<int> vector_c = vector_a*s; //scalar vector multiplcation
    Vector<int> vector_d = vector_a + vector_b; //vector addition 
    int second_element = vector_a[1];

    std::cout<<"-----Vector equations -----"<<std::endl;
    std::cout<<"s = "<<s<<std::endl;
    std::cout<<"vector_a \n "<<vector_a<<std::endl;
    std::cout<<"vector_b = vector_a + s \n"<<vector_b<<std::endl;
    std::cout<<"vector_c = vector_a * s \n"<<vector_c<<std::endl;
    std::cout<<"vector_d = vector_a + vector_b \n"<<vector_d<<std::endl;
    std::cout<<"vector_a[1] \n" <<second_element<<std::endl;


    Matrix<int> matrix_b = matrix_a * s; //scalar matrix multiplication
    Matrix<int> matrix_c = matrix_a + s; //scalar matrix addition
    Matrix<int> matrix_d = matrix_a + matrix_b; //matrix addition 
    Matrix<int> matrix_e = matrix_a * matrix_b; //matrix multiplication
    int matrix_element = matrix_a[2][0];
  

    Vector<int> vector_e = matrix_a * vector_a; 
    std::cout<<"vector_e = vector_a * matrix_a \n" <<vector_e<<std::endl;

    std::cout<<"-----Matrix equation -----"<<std::endl;
    std::cout<<"matrix_a \n "<<matrix_a<<std::endl;
    std::cout<<"matrix_b = matrix_a * s \n"<<matrix_b<<std::endl;
    std::cout<<"matrix_c = matrix_a +  s \n"<<matrix_c<<std::endl;
    std::cout<<"matrix_d = matrix_a + matrix_b \n"<<matrix_d<<std::endl;
    std::cout<<"matrix_a[2][0] = " <<matrix_element<<std::endl;
    std::cout<<"matrix_e \n"<<matrix_e<<std::endl;
    return 0;
}
