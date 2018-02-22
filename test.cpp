#include <stdio.h>
// TBB
#include <tbb/tbb.h>
// #include <tbb/parallel_for.h>
// #include <tbb/task_scheduler_init.h>
// #include <tbb/blocked_range.h>

using namespace tbb;

class hello {
  public:
    void operator()(int x) const {
      printf("Hello TBB! TBB version is %d.%d\n", TBB_VERSION_MAJOR, TBB_VERSION_MINOR);
    }
};
void Parallel_Test(double *a, size_t n ) {
  parallel_for( blocked_range<size_t>(0, n),
    [=](const blocked_range<size_t>& r) {
      for(size_t i=r.begin(); i!= r.end(); ++i) {
      	printf("a[%d] = %f\n", i, a[i]);
      }
    }
  );
}
int main (int argc, char* argv[]) {
  // Get the default number of threads
  int num_threads = task_scheduler_init::default_num_threads();
  task_scheduler_init init(num_threads);  // Automatic number of threads

  parallel_for( 0, 5, 1, hello() );

  int N = 100000;
  double *vec;
  vec = (double*) malloc(N*sizeof(double));
  for(int i = 0; i < N; i++) {
    vec[i] = rand();
  }
  Parallel_Test(vec, N);
  free(vec);
  
  return 0;
}
