#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>

void displayClock(){
    while(true){
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::tm *localTime = std::localtime(&currentTime);

        #ifdef _WIN32
            system("cls");
        #endif

        std::cout << std::setfill('0') << std::setw(2) << localTime->tm_hour << ":"
                  << std::setfill('0') << std::setw(2) << localTime->tm_min << ":"
                  << std::setfill('0') << std::setw(2) << localTime->tm_sec << ":" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));


    }
}


int main(){
    std::cout << "Digital Clock\n" << std::endl;
    displayClock();
    return 0;
}