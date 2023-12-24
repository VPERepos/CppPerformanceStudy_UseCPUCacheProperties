#include "Containers2d.h"
#include <memory>

int main()
{
    const int width = 1000;
    const int height = 1000;
    const int numberOfSamplesForAveraging = 1000;
    const int numberOfContainerTypes = 3;

    std::vector<std::vector<double>> processingTimesTable;

    std::vector<double> averageProcessingTimes;
    averageProcessingTimes.resize(numberOfContainerTypes*2, 0.0);

    for(int i=0; i < numberOfSamplesForAveraging; ++i)
    {
        std::vector<std::shared_ptr<Containers2d>> containers;

        containers.emplace_back(std::make_shared<Array1d>(width, height));
        containers.emplace_back(std::make_shared<Array2d>(width, height));
        containers.emplace_back(std::make_shared<Vector2d>(width, height));
        
        std::vector<double> processingTimesForContainers;
        bool byRows = true;
        for(auto& containerElement : containers)
        {
            containerElement->initializeContainerWithRandomNumbers();

            byRows = true;
            processingTimesForContainers.emplace_back(containerElement->processContainer(byRows));
            byRows = false;
            processingTimesForContainers.emplace_back(containerElement->processContainer(byRows));
        }
        
        processingTimesTable.emplace_back(processingTimesForContainers);
    
    }
    for(int i = 0; i < numberOfContainerTypes*2; ++i)
    {
        for(int j=0; j < numberOfSamplesForAveraging; ++j)
        {
            averageProcessingTimes[i] += processingTimesTable[j][i];
        }
        averageProcessingTimes[i]=averageProcessingTimes[i]/numberOfSamplesForAveraging;
    }

    std::cout << "Process 1D Array by rows took (microseconds) = "<<averageProcessingTimes[0] << std::endl;
    std::cout << "Process 2D Array by rows took (microseconds) = "<<averageProcessingTimes[2] << std::endl;
    std::cout << "Process 2D Vector by rows took (microseconds) = "<<averageProcessingTimes[4] << std::endl;
    std::cout << std::endl;
    std::cout << "Process 1D Array by cols took (microseconds) = "<<averageProcessingTimes[1] << std::endl;
    std::cout << "Process 2D Array by cols took (microseconds) = "<<averageProcessingTimes[3] << std::endl;
    std::cout << "Process 2D Vector by cols took (microseconds) = "<<averageProcessingTimes[5] << std::endl;

    return 0;
}