#pragma once
#include <iostream>
#include <queue>
#include <pthread.h>
#include "connect.h"
#include <Pt.h>
#include <string>
using namespace std;


namespace DataSend{

class Data{
		pthread_mutex_t MutexIN;
		pthread_mutex_t MutexOUT;
		queue<string> DataQueueIN;
		queue<string> DataQueueOUT;
	friend class DoConnect;
	public:
		Data();
		~Data();
		void GetData(std::string In);
		std::string SendData();
		void ResourseToQueue(char *R);
		void QueueToResourse(char *R);
};
 	


}
	
