#include <iostream>
#include <random>
#include <ctime>
#include <unordered_map>

std::unordered_map <int, std::string> reasons {
    {1,  "I overslept"},
    {2,  "I underslept"},
    {3,  "I slept with {insert name}"},
    {4,  "I was stalking RANEPA girls/boys"},
    {5,  "I was cooking some dope ass new-jazz beat"},
    {6,  "I don't give a fuck"},
    {7,  "I had been watching TikTok all night"},
    {8,  "I was tired"},
    {9,  "I forgot"},
    {10, "I had some more important things to do"},
    {11, "I was so damn horny"},
    {12, "I have depression and I am demotivated"},
    {13, "I work at 3 jobs. What are you even talking about?"},
    {14, "I just... don't know"},
    {15, "I did. Why do you even think I didn't? (lie)"},
    {16, "I was high af"},
    {17, "I was eagerly waiting for Playboi Carti to drop his album"},
    {18, "I was listening to Playboi Carti's new album (lie)"},
    {19, "I was writing some dumbass C++ code"},
    {20, "..."},
};

int main() {
    srand(time(NULL));

    int reasonGenerator = 1 + rand() % 20;

    std::cout << "Do not do homework, boys and girls!\n";
    std::cout << "If they ask why not, just say something like \"" << reasons[reasonGenerator] << "\"";

    return 0;
}