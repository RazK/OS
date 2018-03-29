#include "osm.h"
#include <sys/time.h>

/*
 * Time conversion constants
 */
const double SEC_TO_MILIS = 1000;
const double SEC_TO_MICRS = 1000000;
const double SEC_TO_NANOS = 1000000000;
const double SEC_IN_MILIS = 1/SEC_TO_MILIS;
const double SEC_IN_MICRS = 1/SEC_TO_MICRS;
const double SEC_IN_NANOS = 1/SEC_TO_NANOS;

/*
 * Recursive template for loop unrolling using the preprocessor.
 */
const int UNROLLING_FACTOR = 10;

// Recursion body
template <unsigned N> struct faux_unroll {
    template <typename F> static void call(F const& f) {
        f();
        faux_unroll<N-1>::call(f);
    }
};

// Recursion terminating condition
template <> struct faux_unroll<0u> {
    template <typename F> static void call(F const&) {}
};

/* Initialization function that the user must call
 * before running any other library function.
 * The function may, for example, allocate memory or
 * create/open files.
 * Pay attention: this function may be empty for some designs. It's fine.
 * Returns 0 upon success and -1 on failure
 */
int osm_init()
{
    return 0;
}


/* finalizer function that the user must call
 * after running any other library function.
 * The function may, for example, free memory or
 * close/delete files.
 * Returns 0 uppon success and -1 on failure
 */
int osm_finalizer()
{
    return 0;
}


/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations);


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
void empty(){};
double osm_function_time(unsigned int iterations)
{
    // Prepare structs for timing calculations
    struct timeval begin, end;

    // Start the clock!
    gettimeofday(&begin, nullptr);

    // Iterate and unroll
    for (unsigned int i = 0; i < iterations; i += UNROLLING_FACTOR)
    {
        // Unroll 10 times (or whatever UNROLLING_FACTOR equals to)
        // 10 x call empty()
        faux_unroll<UNROLLING_FACTOR>::call([&] {empty();});
    }

    // Stop the clock!
    gettimeofday(&end, nullptr);

    // Calc the total number of ms that the code took:
    double elapsed_sec = (end.tv_sec - begin.tv_sec) +
                        ((end.tv_usec - begin.tv_usec) * SEC_IN_MICRS);

    // Return elapsed in nano-seconds
    return elapsed_sec * SEC_TO_NANOS;
}

/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations);