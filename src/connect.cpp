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
		 */
		// инициализация интерфейса диспетчеризации
	 	if ((dpp_IN = dispatch_create()) == NULL)
	 	{
	 		perror("allocate dispatch"), exit(EXIT_FAILURE);
	 	}

	 	// инициализация атрибутов менеджера
	 	memset(&resmgr_attr, 0, sizeof resmgr_attr);
	 	resmgr_attr.nparts_max = 1;
	 	resmgr_attr.msg_max_size = 2048;
	 	// инициализация таблиц функций обработчиков
	 	static resmgr_connect_funcs_t		 connect_funcs;
	 	static resmgr_io_funcs_t 		io_funcs;
	 	iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs,
	  	_RESMGR_IO_NFUNCS, &io_funcs);
	 	// здесь нами дописан всего один обработчик - операции read,
	 	// все остальное делается менеджером по умолчанию!
	 	io_funcs.read = prior_read;
	 	// инициализация атрибутной структуры, используемой
	 	// устройством.
	 	static iofunc_attr_t attr;
	 	iofunc_attr_init(&attr, S_IFNAM | 0666, 0, 0);
	 	// здесь создается путевое имя для менеджера
	 	id = resmgr_attach(dpp, &resmgr_attr, "/dev/prior", _FTYPE_ANY, 0, &connect_funcs, &io_funcs, &attr);
		if (id == -1)
	 		perror("attach name"), exit(EXIT_FAILURE);
	 	ctp = dispatch_context_alloc(dpp);
}

void DoConnect::CreateOUT()
{

}

void DoConnect::DoConnect()
{

}

void DoConnect::~DoConnect()
{

}
