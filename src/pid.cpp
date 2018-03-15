#include "pid.h"

using namespace pid;

pid_info::pid_info():ReadyFlag(false)
{

}

pid_info::pid_info(char* Name):MyName(Name)
{

}

pid_info::~pid_info()
{

}

inline pid_t pid_info::GetMyPid()
{
	return MyPID;
}

inline pid_t pid_info::GetHisPid()
{
	return HisPID;
}

inline char* pid_info::GetMyName()
{
	return MyName;
}


inline void pid_info::SetMyName(char *Name)
{
	this->MyName = Name;
}

inline bool pid_info::GetFlag()
{
	return ReadyFlag;
}

inline void pid_info::FlagOn()
{
	this->ReadyFlag = false;
}

inline void pid_info::FlagOff()
{
	this->ReadyFlag = true;
}

inline void pid_info::FlagInverte()
{
	this->ReadyFlag = ~this->ReadyFlag;
}

/*void pid_info::FindIfNotFinf()
{
	struct dirent   *dirent;
	DIR             *dir;
	int             pid;
	string    name;
	QNXProcInfo *info;

	if (!(dir = opendir ("/proc")))
	    throw QNXProcException("couldn't open /proc");

	while ((dirent = readdir(dir)))
	{
	    if (isdigit(*dirent->d_name))
	    {
	        pid = atoi(dirent->d_name);
	        info = new QNXProcInfo(pid);
	        name = info->GetName();
	        if (name == pname)
	        	return info;
	        else
	        	delete info;
	    }
	    }
	  closedir (dir);
	  throw QNXProcException("Process not found");
}*/

void pid_info::FindIfNotFinf(char *p)
{
	char *argv2[] = {0};
	spawnl( P_WAIT,"/bin/pidin", "/bin/pidin", "-P", p, NULL, argv2);
}

void pid_info::FindIfFind()
{

}

void pid_info::FindCheckThread()
{

}

