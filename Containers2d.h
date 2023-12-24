#pragma once
#include <vector>
#include <random>
#include <chrono>

class Containers2d{
    public:
        Containers2d(int theWidth, int theHeight):m_Width{theWidth}, m_Height{theHeight}{};
        virtual ~Containers2d(){};
        virtual void initializeContainerWithRandomNumbers();
        long long processContainer(const bool& theByRows);
    protected:
        virtual void processContainerByRows();
        virtual void processContainerByCols();
        
        int m_Width;
        int m_Height;
           
        std::random_device m_RandomDevice;
        std::mt19937 m_RandomEngine{m_RandomDevice()};
        std::uniform_real_distribution<double> m_Distribution{0, 1};
        
};

class Array1d: public Containers2d{
    public:
        Array1d(int theWidth, int theHeight):Containers2d(theWidth, theHeight){};
        ~Array1d();
        void initializeContainerWithRandomNumbers()override;
    protected:
        void processContainerByRows() override;
        void processContainerByCols() override;
        void processArray1dByRows(double*& theArray);
        void processArray1dByCols(double*& theArray);
    private:
        double* m_Array1d;
};

class Array2d: public Containers2d{
    public:
        Array2d(int theWidth, int theHeight):Containers2d(theWidth, theHeight){};
        ~Array2d();
        void initializeContainerWithRandomNumbers()override;
    protected:
        void processContainerByRows() override;
        void processContainerByCols() override;
        void processArray2dByRows(double**& theArray);
        void processArray2dByCols(double**& theArray);
    private:
        double** m_Array2d;
};

class Vector2d: public Containers2d{
    public:
        Vector2d(int theWidth, int theHeight):Containers2d(theWidth, theHeight){};
        ~Vector2d(){};
        void initializeContainerWithRandomNumbers()override;
    protected:
        void processContainerByRows() override;
        void processContainerByCols() override;
        void processVector2dByRows(std::vector<std::vector<double>>& theVector);
        void processVector2dByCols(std::vector<std::vector<double>>& theVector);
    private:
        std::vector<std::vector<double>> m_Vector2d;
};