#pragma once
#include "program.h"
#include <sys/iofunc.h>
#include <sys/dispatch.h>

namespace DataSend{
class Data;
class DoConnect{

		pthread_t ThreadsIn[3];
		pthread_t ThreadsOut[3];
		pthread_mutex_t Mutex;
		//IN
		resmgr_attr_t resmgr_attr_IN;
		dispatch_t *dpp_IN;
		dispatch_context_t *ctp_IN;
		int id_IN;
		static resmgr_connect_funcs_t		 connect_funcs_IN;
		static resmgr_io_funcs_t 		io_funcs_IN;
		static iofunc_attr_t attr_IN;
		//OUT
		resmgr_attr_t resmgr_attr_OUT;
		dispatch_t *dpp_OUT;
		dispatch_context_t *ctp_OUT;
		int id_OUT;
		static resmgr_connect_funcs_t		 connect_funcs_OUT;
		static resmgr_io_funcs_t 		io_funcs_OUT;
		static iofunc_attr_t attr_OUT;
		//muter read write
		void CreateIN();
		void CreateOUT();

	public:
		DoConnect();
		~DoConnect();
/*
 * metods
 * connect to file read(mutex)
 * connector
 * connect to file write(mutex)
 */

};

}
