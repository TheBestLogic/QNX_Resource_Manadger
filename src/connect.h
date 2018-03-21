#pragma once
#include "program.h"
#include <errno.h>
#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>

namespace DataSend{
class Data;
class DoConnect{


		//IN
		resmgr_attr_t resmgr_attr_IN, resmgr_attr_OUT;
		dispatch_t *dpp_IN, *dpp_OUT;
		dispatch_context_t *ctp_IN, *ctp_ret_IN, *ctp_OUT, *ctp_ret_OUT;
		int id_IN, id_OUT;
		static resmgr_connect_funcs_t connect_funcs_IN, connect_funcs_OUT;
		static resmgr_io_funcs_t io_funcs_IN, io_funcs_OUT;
		static iofunc_attr_t attr_IN, attr_OUT;
		//OUT
		//muter read write
		void CreateIN();
		void CreateOUT();
		int threadIn();
		int threadOut();
		static int prior_read(resmgr_context_t *ctp, io_read_t *msg, RESMGR_OCB_T *ocb);
		static int prior_write(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb);
	public:
		Data *D;

		DoConnect();
		~DoConnect();
	friend class DataSend;
/*
 * metods
 * connect to file read(mutex)
 * connector
 * connect to file write(mutex)
 */

};

}
