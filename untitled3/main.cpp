#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>

int main()
{

    std::ifstream in("huffman.in");
    std::string line;
    int dimension = 0;
    int *array;
    int index = 0;

    while (getline(in, line))
    {
        if (index == 0)
        {
            dimension = std::stoi(line);
            array = new int[dimension];
        } else
        {
            std::istringstream lineStream(line);
            std::string item;
            int jndex = 0;
            while (getline(lineStream, item, ' '))
            {
                array[jndex] = std::stoi(item);
                jndex++;
            }
        }
        index++;
    }
    in.close();

    long long int result = 0;
    std::vector<long long int> container;
    container.reserve(dimension);
    std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> queue(std::greater<long long int>(), std::move(container));
    index = 0;
    while (index < dimension)
    {
        queue.push(array[index]);
        index++;
    }


    index = 0;
    while (index < dimension - 1)
    {
        long long int a = queue.top();
        queue.pop();
        long long int b = queue.top();

        queue.pop();
        long long int c(a + b);
        result += c;
        queue.push(c);
        index++;
    }
    std::ofstream out("huffman.out");
    out << result;
    out.close();

    return 0;
}