#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <fstream>
#include <stdlib.h>
#include <utmp.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <iostream>
using namespace std;

     
void CreateLogFile(struct utmp* user);
void FindUserLoginInfo();

#endif //USERLOGIN_H
