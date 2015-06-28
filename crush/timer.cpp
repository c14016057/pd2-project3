#include "timer.h"

timer::timer()
{

}
void timer::waitclocktime(clock_t n){
    clock_t start=clock();
    while((clock()-start)<n);
}
