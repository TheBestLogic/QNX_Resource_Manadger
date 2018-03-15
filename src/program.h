#pragma once
#include <iostream>
#include <queue>
#include <pthread.h>
#include "connect.h"
using namespace std;


namespace DataSend{

class Data{
		pthread_mutex_t Mutex;
		queue<int> DataQueue;
	friend class DoConnect;
	public:
		Data();
		~Data();
		void GetData(int In);
		int SendData();
};
 	


}
	
