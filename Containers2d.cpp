#include "Containers2d.h"


Containers2d::~Containers2d() {
    
}

long long Containers2d::processContainer(const bool& theByRows)
{
    auto start = std::chrono::high_resolution_clock::now();

    if(theByRows)
    {
        processContainerByRows();
    }
    else
    {
        processContainerByCols();
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();

    return microseconds;
};

Array1d::~Array1d()
{
    delete[] m_Array1d;
}
void Array1d::initializeContainerWithRandomNumbers()
{
    m_Array1d = new double[m_Width*m_Height];
    
    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            m_Array1d[i*m_Width + j] = m_Distribution(m_RandomEngine);
        }
    }
};
void Array1d::processContainerByRows()
{
    processArray1dByRows(m_Array1d);
};

void Array1d::processContainerByCols()
{
    processArray1dByCols(m_Array1d);
};

void Array1d::processArray1dByRows(double*& theArray)
{
    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            auto element = theArray[i*m_Width + j];
            theArray[i*m_Width + j] = element*element;
        }
    }
}
void Array1d::processArray1dByCols(double*& theArray)
{
    for (int i = 0; i < m_Width; ++i)
    {
        for(int j = 0; j < m_Height; ++j)
        {
            auto element = theArray[j*m_Width + i];
            theArray[j*m_Width + i] = element*element;
        }
    }
}

Array2d::~Array2d()
{
    for(int i=0; i<m_Height; ++i)
    {
        delete[] m_Array2d[i];
    }

    delete[] m_Array2d;
}

void Array2d::initializeContainerWithRandomNumbers()
{
    m_Array2d = new double*[m_Height];
    for(int i=0; i<m_Height; ++i)
    {
        m_Array2d[i] = new double[m_Width];
    }

    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            m_Array2d[i][j] = m_Distribution(m_RandomEngine);
        }
    }
};

void Array2d::processContainerByRows()
{
    processArray2dByRows(m_Array2d);
};

void Array2d::processContainerByCols()
{
    processArray2dByCols(m_Array2d);
};

void Array2d::processArray2dByRows(double**& theArray)
{
    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            auto element =  theArray[i][j];
            theArray[i][j] =element*element;
        }
    }
};

void Array2d::processArray2dByCols(double**& theArray)
{
    for (int i = 0; i < m_Width; ++i)
    {
        for(int j = 0; j < m_Height; ++j)
        {
            auto element =  theArray[j][i];
            theArray[j][i] =element*element;
        }
    }
};

void Vector2d::initializeContainerWithRandomNumbers()
{
    m_Vector2d.resize(m_Height);
    for (int i = 0; i < m_Height; ++i) 
    {
        m_Vector2d[i].resize(m_Width, 0.0);
    }
    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            m_Vector2d[i][j] = m_Distribution(m_RandomEngine);
        }
    }
};
void Vector2d::processContainerByRows()
{
    processVector2dByRows(m_Vector2d);
};

void Vector2d::processContainerByCols()
{
    processVector2dByCols(m_Vector2d);
};

void Vector2d::processVector2dByRows(std::vector<std::vector<double>>& theVector)
{
    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            auto element = theVector[i][j];
            theVector[i][j] = element*element;
        }
    }
};

void Vector2d::processVector2dByCols(std::vector<std::vector<double>>& theVector)
{
    for (int i = 0; i < m_Width; ++i)
    {
        for(int j = 0; j < m_Height; ++j)
        {
            auto element = theVector[j][i];
            theVector[j][i] = element*element;
        }
    }
};