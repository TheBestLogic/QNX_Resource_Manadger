#include "program.h"
using namespace std;
extern pthread_t Threads[3];

using namespace std;
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

	void Data::GetData( std::string In )
	{
		pthread_mutex_lock( &Mutex );
		DataQueue.push( In );
		//sovat v resurci
		pthread_mutex_unlock( &Mutex );
	}




	std::string Data::SendData(  )
	{
		pthread_mutex_lock( &Mutex );
		std::string buf = DataQueue.front();
		DataQueue.pop();
		//sovat v resurci
		pthread_mutex_unlock( &Mutex );
		return buf;
	}
	





	

