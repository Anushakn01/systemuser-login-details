#include "UserLogin.h"
#include <iostream>
using namespace std;

ofstream logFileStream;
//Function to create log file
void CreateLogFile(struct utmp* user)
{
    struct sysinfo info;
    sysinfo(&info);
    int32_t boottimestamp=((unsigned long)time(NULL)-info.uptime);
    if(user->ut_type==USER_PROCESS&&(user->ut_time>boottimestamp))
    {
        if(logFileStream.is_open() == true)
        {
        logFileStream << user->ut_name <<endl;
        }
     }
     return;
}

//Function to find the user
void FindUserLoginInfo()
{
    struct utmp* user;
    utmpname(_PATH_WTMP);
    setutent();
    logFileStream.open("UserLog.log");
    while((user=getutent( ))!=NULL)
    CreateLogFile(user);
    endutent();
    logFileStream.close();
    return;
}
