//
// Created by heimy4prez on 3/29/18.
//
#include osm.h


/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations){
    int i = 0;
    int temp, codeStart, codeEnd;
    struct timeval begin, end;

    codeStart = gettimeofday(&begin, NULL);

    while (i < iterations){
        temp + 1;
        temp + 1;
        temp + 1;
        temp + 1;
        temp + 1;
        temp + 1;
        temp + 1;
        temp + 1;
        temp + 1;
        temp + 1;

        i += 10;
    }

    codeEnd = gettimeofday(&end, NULL);


    if (codeStart != -1 && codeEnd != -1){
        return (double) (end.tv_sec - begin.tv_sec) + ((end.tv_usec - beign.tv_usec)/1000000.0);
    }
    return -1;


}


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations);


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations){
    int i = 0;
    int temp, codeStart, codeEnd;
    struct timeval begin, end;

    codeStart = gettimeofday(&begin, NULL);

    while (i < iterations){
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        i += 10;
    }

    codeEnd = gettimeofday(&end, NULL);


    if (codeStart != -1 && codeEnd != -1){
        return (double) (end.tv_sec - begin.tv_sec) + ((end.tv_usec - beign.tv_usec)/1000000.0);
    }
    return -1;
}
