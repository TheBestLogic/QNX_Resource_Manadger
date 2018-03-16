#include "connect.h"
using namespace std;
using namespace DataSend;

void DoConnect::CreateIN()
{
		/*
		 * resmgr_attr_t resmgr_attr_IN;
		dispatch_t *dpp_IN;
		dispatch_context_t *ctp_IN;
		int id_IN;
		static resmgr_connect_funcs_t		 connect_funcs_IN;
		static resmgr_io_funcs_t 		io_funcs_IN;
		static iofunc_attr_t attr_IN;
		throw "\"\" - failed";
		 */
		// инициализация интерфейса диспетчеризации
	 	if ((dpp_IN = dispatch_create()) == NULL)
	 	{
	 		throw "\"dpp_IN = dispatch_create()\" - failed";
	 	}
	 	// инициализация атрибутов менеджера
	 	memset(&resmgr_attr_IN, 0, sizeof resmgr_attr_IN);
	 	resmgr_attr_IN.nparts_max = 1;
	 	resmgr_attr_IN.msg_max_size = 2048;
	 	// инициализация таблиц функций обработчиков
	 	iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs_IN,_RESMGR_IO_NFUNCS, &io_funcs_IN);
	 	// здесь нами дописан всего один обработчик - операции read,
	 	// все остальное делается менеджером по умолчанию!

	 	io_funcs_IN.read = prior_read;//must be my read function

	 	// инициализация атрибутной структуры, используемой
	 	// устройством.
	 	iofunc_attr_init(&attr_IN, S_IFNAM | 0666, 0, 0);
	 	// здесь создается путевое имя для менеджера
	 	id = resmgr_attach(dpp_IN, &resmgr_attr_IN, "/dev/prior_IN", _FTYPE_ANY, 0, &connect_funcs_IN, &io_funcs_IN, &attr_IN);
		if (id == -1)
	 		throw "\"id = resmgr_attach(dpp_IN, &resmgr_attr_IN, \"/dev/prior_IN\", _FTYPE_ANY, 0, &connect_funcs_IN, &io_funcs_IN, &attr_IN)\" - failed";
	 	ctp_IN = dispatch_context_alloc(dpp_IN);
}

void DoConnect::CreateOUT()
{
			// инициализация интерфейса диспетчеризации
		 	if ((dpp_OUT = dispatch_create()) == NULL)
		 	{
		 		throw "\"dpp_OUT = dispatch_create()\" - failed";
		 	}
		 	// инициализация атрибутов менеджера
		 	memset(&resmgr_attr_OUT, 0, sizeof resmgr_attr_OUT);
		 	resmgr_attr_OUT.nparts_max = 1;
		 	resmgr_attr_OUT.msg_max_size = 2048;
		 	// инициализация таблиц функций обработчиков
		 	iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs_OUT,_RESMGR_IO_NFUNCS, &io_funcs_OUT);
		 	// здесь нами дописан всего один обработчик - операции read,
		 	// все остальное делается менеджером по умолчанию!

		 	io_funcs_OUT.write =  prior_write;//must be my write function

		 	// инициализация атрибутной структуры, используемой
		 	// устройством.
		 	iofunc_attr_init(&attr_OUT, S_IFNAM | 0666, 0, 0);
		 	// здесь создается путевое имя для менеджера
		 	id = resmgr_attach(dpp_OUT, &resmgr_attr_OUT, "/dev/prior_OUT", _FTYPE_ANY, 0, &connect_funcs_OUT, &io_funcs_OUT, &attr_OUT);
			if (id == -1)
		 		throw "\"id = resmgr_attach(dpp_OUT, &resmgr_attr_OUT, \"/dev/prior_OUT\", _FTYPE_ANY, 0, &connect_funcs_OUT, &io_funcs_OUT, &attr_OUT)\" - failed";
		 	ctp_OUT = dispatch_context_alloc(dpp_OUT);
}

void DoConnect::DoConnect()
{
	DoConnect::CreateIN();
	DoConnect::CreateOUT();
}

void DoConnect::~DoConnect()
{

}

static int DoConnect::prior_write(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb)
{
	 static bool odd = true;
 	int status = iofunc_read_verify(ctp, msg, ocb, NULL);
 	if (status != EOK)
 		return status;
 	if (msg->i.xtype & _IO_XTYPE_MASK != _ID_XTYPE_NONE)
  		return ENOSYS;
 	if (odd)
 	{
  		struct sched_param 		param;
  		sched_getparam(0, &param);
  		static char rbuf[4];
  		sprintf(rbuf, "%d ", param.sched_curpriority);
  		MsgReply(ctp->rcvid, strlen(rbuf) + 1, rbuf, strlen(rbuf) + 1);
 	}
 	else
 		MsgReply(ctp->rcvid, EOK, NULL, 0);
 	odd = !odd;
 	return _RESMGR_NOREPLY;
}

static int DoConnect::prior_read(resmgr_context_t *ctp, io_read_t *msg, RESMGR_OCB_T *ocb)
{
	 static bool odd = true;
 	int status = iofunc_write_verify(ctp, msg, ocb, NULL);
 	if (status != EOK)
 		return status;
 	if (msg->i.xtype & _IO_XTYPE_MASK != _ID_XTYPE_NONE)
  		return ENOSYS;
 	if (odd)
 	{
  		//
  		sprintf(/*ukazatel na govno*/, "/*tip govna*/", /*soderjimoe govna*/);//suda kidaem govno
  		MsgSend(ctp->rcvid, /*status no budet dlina govna +1*/, /*ukazatel na govno*/, /*dlina govna +1*/);
 	}
 	else
 		MsgReply(ctp->rcvid, EOK, NULL, 0);
 	//
 	odd = !odd;
 	return _RESMGR_NOREPLY;
}
