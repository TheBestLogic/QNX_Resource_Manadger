#include "program.h"
using namespace std;
extern pthread_t Threads[3];

using namespace std;
using namespace DataSend;

	Data::Data()
	{
		pthread_mutex_init( &MutexIN , NULL);
		pthread_mutex_init( &MutexOUT , NULL);
	}

	Data::~Data()
	{
		while( !DataQueueIN.empty() )
		{
			DataQueueIN.pop();
		}
		while( !DataQueueOUT.empty() )
		{
			DataQueueOUT.pop();
		}
		pthread_mutex_destroy( &MutexIN );
		pthread_mutex_destroy( &MutexOUT );
	}

	void Data::GetData( std::string In )
	{
		pthread_mutex_lock( &MutexIN );
		DataQueueIN.push( In );
		pthread_mutex_unlock( &MutexIN );
	}

	void Data::QueueToResourse()
	{
		string Buffer = {0};
		Buffer += DataQueue.front() + '\n';
		DataQueueOUT.pop();
		pthread_mutex_lock( &MutexIN );
		pthread_mutex_lock( &MutexOUT );
		PtText
		pthread_mutex_unlock( &MutexOUT );
		pthread_mutex_unlock( &MutexIN );
		memset(Buffer, 0, Buffer.size());
	}

	void Data::ResourseToQueue()
	{
		char *ch;
		PtGetResources(PtText,1 ,ch);
		pthread_mutex_lock( &MutexIN );
		pthread_mutex_lock( &MutexOUT );

		pthread_mutex_unlock( &MutexOUT );
		pthread_mutex_unlock( &MutexIN );
	}

	std::string Data::SendData()
	{
		pthread_mutex_lock( &MutexOUT );
		std::string buf = DataQueue.front();
		DataQueueOUT.pop();
		pthread_mutex_unlock( &MutexOUT );
		return buf;
	}


		
	





	

