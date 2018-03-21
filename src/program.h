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
		pthread_mutex_t Mutex;
		queue<string> DataQueue;
	//friend class DoConnect;
	public:
		Data();
		~Data();
		void GetData(std::string In);
		std::string SendData(  );
};
 	


}
	
