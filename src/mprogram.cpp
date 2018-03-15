#include "program.h"
using namespace std;
extern pthread_t Threads[3];

using namespace DataSend;

	Data::Data()
	{
		pthread_mutex_init( &Mutex , NULL);
	}

	Data::~Data()
	{
		while( !DataQueue.empty() )
		{
			DataQueue.pop();
		}
		pthread_mutex_destroy( &Mutex );
	}

	void Data::GetData( int In )
	{
		pthread_mutex_lock( &Mutex );
		DataQueue.push( In );
		pthread_mutex_unlock( &Mutex );
	}


	int Data::SendData()
	{
		pthread_mutex_lock( &Mutex );
		int buf = DataQueue.front();
		DataQueue.pop();
		pthread_mutex_unlock( &Mutex );
		return buf;
	}


		
	





	

