#pragma once
#include "program.h"

namespace DataSend{
class Data;
class DoConnect{

	pthread_t ThreadsIn[3];
	pthread_t ThreadsOut[3];
	pthread_mutex_t Mutex;
	//resmgr_connect_funcs_t	connect_funcs;
	//resmgr_io_funcs_t io_funcs;
//muter read write
	public:
		DoConnect();
		~DoConnect();
/*
 * metods
 * connect to file read(mutex)
 * connector
 * connect to file write(mutex)
 */

 void StartTimer( Data &Data );
};

}
