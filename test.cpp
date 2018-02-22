#include <stdio.h>
// TBB
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/task_scheduler_init.h>
#include <tbb/blocked_range.h>

using namespace tbb;

class hello {
  public:
    void operator()(int x) const {
      printf("Hello TBB! TBB version is %d.%d\n", TBB_VERSION_MAJOR, TBB_VERSION_MINOR);
    }
};

int main (int argc, char* argv[]) {
  // Get the default number of threads
  int num_threads = task_scheduler_init::default_num_threads();
  task_scheduler_init init(num_threads);  // Automatic number of threads

  parallel_for( 0, 5, 1, hello() );


  return 0;
}
