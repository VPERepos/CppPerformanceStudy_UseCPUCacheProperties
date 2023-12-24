#include "Containers2d.h"
#include <iostream>

int main()
{
    Containers2d containers(1000,1000);
    std::cout << "Process 1D Array by rows took (microseconds) = "<<containers.processArray1dByRows() << std::endl;
    std::cout << "Process 2D Array by rows took (microseconds) = "<<containers.processArray2dByRows() << std::endl;
    std::cout << "Process 2D Vector by rows took (microseconds) = "<<containers.processVector2dByRows() << std::endl;
    std::cout << std::endl;
    std::cout << "Process 1D Array by cols took (microseconds) = "<<containers.processArray1dByCols() << std::endl;
    std::cout << "Process 2D Array by cols took (microseconds) = "<<containers.processArray2dByCols() << std::endl;
    std::cout << "Process 2D Vector by cols took (microseconds) = "<<containers.processVector2dByCols() << std::endl;

    return 0;
}