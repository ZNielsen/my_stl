# My STL

My stl is a practice library for me to implement data structures and algorithms.
This is just light practice for me in my spare time, so I'm not concerned with having these algorithms be the most efficient they can possibly be.


## TODO
- Decide on a build framework
  - ~~Hand done makefiles~~ - Done it before, want to try something new
  - ~~tup~~ - saw some talk that it was not as solid as initially advertised
  - ninja - fast.  Need a generation system.  Leaning towards CMake just because of how ubiquitous it is.  I've never done a CMake project, so this would be a good way to learn.
  - CMake + makefiles - Probably the most standard route.
- Integrate google test framework to unit test implementations
  - Correctness
  - Memory Safety
  - Speed vs actual standard library
