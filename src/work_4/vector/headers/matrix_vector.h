#include <vector>
#include <random>
#include <ctime>


struct Set {
private:
    std::vector<std::pair<int, int>> points;

    bool onAxis(std::pair<int, int>& point1, std::pair<int, int>& point2);
    bool singleAxisIntersection(std::pair<int, int>& point1, std::pair<int, int>& point2);
    int generate(std::uniform_int_distribution<>& dis, std::mt19937& generator);

public:
    Set(int size);

    void fillRandomly(std::uniform_int_distribution<>& dis, std::mt19937& generator);

    void fillManually();

    void print();

    int validSegments();
};