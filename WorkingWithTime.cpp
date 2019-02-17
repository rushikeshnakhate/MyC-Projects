#include<ctime>
#include<chrono>
#include<iostream>

using namespace std;


int main () {
	auto currentTimePoint = chrono::system_clock::now() ;
	auto currentTime= chrono::system_clock::to_time_t(currentTimePoint);
	auto time=ctime(&currentTime);
	std::cout<<time<<std::endl ;
	return 0; 


}
