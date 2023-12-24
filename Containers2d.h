#pragma once
#include <vector>
class Containers2d{
    public:
        Containers2d(int theWidth, int theHeight);
        ~Containers2d();

        long long processArray1dByRows();
        long long processArray1dByCols();

        long long processArray2dByRows();
        long long processArray2dByCols();

        long long processVector2dByRows();
        long long processVector2dByCols();

        
    private:
        int m_Width;
        int m_Height;
        double* m_Array1d;
        double** m_Array2d;
        std::vector<std::vector<double>> m_Vector2d;
};