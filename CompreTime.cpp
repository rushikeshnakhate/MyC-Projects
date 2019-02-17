#include<iostream>
#include<ctime>
#include<chrono>
#include<thread>
using namespace std;
using namespace chrono;
using namespace literals;


int main() {
	
	auto startTimePoint = std::chrono::system_clock::now() ;

	std::this_thread::sleep_for(5s);

	auto endTimePoint = std::chrono::system_clock::now() ;

	auto timetaken= duration_cast<milliseconds>(endTimePoint-startTimePoint);
	std::cout<<timetaken.count()<<std::endl ;


	return 0;
}

