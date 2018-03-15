#pragma once
#include <pthread.h>
#include <string>
#include <process.h>
#include <dirent.h>

namespace pid{

class pid_info{
		char* MyName;
		pid_t MyPID;
		pid_t HisPID;
		bool ReadyFlag;

	public:
		pid_info();
		pid_info(char* Name);
		virtual ~pid_info();

		inline pid_t GetMyPid();
		inline pid_t GetHisPid();
		inline char* GetMyName();
		inline void SetMyName(char *Name);
		inline bool GetFlag();
		inline void FlagOn();
		inline void FlagOff();
		inline void FlagInverte();
		void FindIfNotFinf(char *str);
		void FindIfFind();
		void FindCheckThread();
};



}
