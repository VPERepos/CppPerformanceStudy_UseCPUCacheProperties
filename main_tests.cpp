#include <gtest/gtest.h>
#include "Containers2d.h"

class TestArray1d: public Array1d{
  public:
    TestArray1d(int theWidth, int theHeight):Array1d(theWidth, theHeight){};
    void testProcessArray1dByRows(double*& theArray)
    {
      processArray1dByRows(theArray);
    }
    void testProcessArray1dByCols(double*& theArray)
    {
      processArray1dByCols(theArray);
    }
};
class TestVariablesandObjects: public testing::Test{
  public:
    int width{10};
    int height{10};
    TestArray1d testArray1d{width, height};
};

TEST_F(TestVariablesandObjects, IndexingCorrectnessByCols) 
{
  double* array1d = new double[width*height];
    
  for (int i = 0; i < width*height; ++i)
  {
      array1d[i]=i;
  }

  double* squaredArray1d = new double[width*height];
  for (int i = 0; i < width*height; ++i)
  {
      squaredArray1d[i] = array1d[i]*array1d[i];
  }

  testArray1d.testProcessArray1dByCols(array1d);

  for (int i = 0; i < width*height; ++i)
  {
    auto squaredArrayElement = squaredArray1d[i];
    auto arrayElement = array1d[i];
    auto absDifference = abs(squaredArrayElement-arrayElement);
    ASSERT_LE(absDifference,1e-6);
  }

  delete[] squaredArray1d;
  delete[] array1d;
}
