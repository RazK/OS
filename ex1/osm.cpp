//
// Created by heimy4prez on 3/29/18.
//


/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations){
    int i = 0;
    int temp;
    double start = gettimeofday();

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

    double end = gettimeofday();

    if (start != -1 && end != -1){
        return end - start; // div by 1000 for miliseconds?
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
double osm_syscall_time(unsigned int iterations);
