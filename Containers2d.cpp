#include "Containers2d.h"
#include <random>
#include <iostream>
#include <chrono>

Containers2d::Containers2d(int theWidth, int theHeight):m_Width{theWidth}, m_Height{theHeight}
{
    std::random_device rd;

    std::mt19937 e2(rd());

    std::uniform_real_distribution<double> dist(0, 1);

    m_Array1d = new double[m_Width*m_Height];
    
    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            m_Array1d[i*m_Width + j] = dist(e2);
        }
    }

    m_Array2d = new double*[m_Height];
    for(int i=0; i<m_Height; ++i)
    {
        m_Array2d[i] = new double[m_Width];
    }

    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            m_Array2d[i][j] = dist(e2);
        }
    }

    m_Vector2d.resize(m_Height);
    for (int i = 0; i < m_Height; ++i) 
    {
        m_Vector2d[i].resize(m_Width, 0.0);
    }
    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            m_Vector2d[i][j] = dist(e2);
        }
    }
}

Containers2d::~Containers2d()
{
    delete[] m_Array1d;
    
    for(int i=0; i<m_Height; ++i)
    {
        delete[] m_Array2d[i];
    }

    delete[] m_Array2d;
}

long long Containers2d::processArray1dByRows()
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            auto element = m_Array1d[i*m_Width + j];
            m_Array1d[i*m_Width + j] = element*element;
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();

    return microseconds;
}
long long Containers2d::processArray1dByCols()
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < m_Width; ++i)
    {
        for(int j = 0; j < m_Height; ++j)
        {
            auto element = m_Array1d[j*m_Width + i];
            m_Array1d[i*m_Width + m_Height] = element*element;
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();

    return microseconds;
}

long long Containers2d::processArray2dByRows()
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            auto element =  m_Array2d[i][j];
            m_Array2d[i][j] =element*element;
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();

    return microseconds;
}
long long Containers2d::processArray2dByCols()
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < m_Width; ++i)
    {
        for(int j = 0; j < m_Height; ++j)
        {
            auto element =  m_Array2d[j][i];
            m_Array2d[j][i] =element*element;
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();

    return microseconds;
}

long long Containers2d::processVector2dByRows()
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < m_Height; ++i)
    {
        for(int j = 0; j < m_Width; ++j)
        {
            auto element = m_Vector2d[i][j];
            m_Vector2d[i][j] = element*element;
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();

    return microseconds;
}
long long Containers2d::processVector2dByCols()
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < m_Width; ++i)
    {
        for(int j = 0; j < m_Height; ++j)
        {
            auto element = m_Vector2d[j][i];
            m_Vector2d[j][i] = element*element;
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();

    return microseconds;
}