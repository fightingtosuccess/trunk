//计时器
#include<iostream>
#include<sys/time.h>

using namespace std;

class TimeHandle
{
public:
    void start();
    double stop();
private:
    struct timeval starttime;
};

void TimeHandle::start()
{
    gettimeofday(&starttime,NULL);
}

double TimeHandle::stop()
{
    double elapsed_time = 0;
    struct timeval curtime;
    gettimeofday(&curtime,NULL);
    elapsed_time = (curtime.tv_sec - starttime.tv_sec)*1e9 + (curtime.tv_usec - starttime.tv_usec)*1e3;
    return elapsed_time;
}


int main()
{
    TimeHandle timehandle;
    timehandle.start();
    for(int i = 0;i<1000000;++i)
    {

    }
    double tim = timehandle.stop();
    cout<<tim<<endl;
    return 0;
}
