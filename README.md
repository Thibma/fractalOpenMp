# Compilation on Mac OS :
## Command line :
```g++ -o julia.o main.cpp complex.cpp fractal.cpp fractalmodel.cpp julia.cpp EasyBMP/EasyBMP.cpp -lomp -Xpreprocessor -fopenmp```

# Compilation on Windows:
## Command line : 
```g++ -Wall -o julia.exe main.cpp complex.cpp fractal.cpp fractalmodel.cpp julia.cpp EasyBMP/EasyBMP.cpp -fopenmp```

# Or

## Makefile:
Prerequisite:
- mingw : https://sourceforge.net/projects/mingw/postdownload
	- In installator, select in MinGW Base system : 
	  * mingw32-pthreads-w32-dev mingw32-pthreads-w32-doc mingw32-pthreads-w32-lib
	- add to path mingw32 bin

- cmake : https://cmake.org/download/
	- add to path cmake bin
  
 Run app (in fractalOpenMp-master/):
1. run 'cmake -G "MinGW Makefiles" .'
2. run 'mingw32-make'
3. run './julia.exe'
4. open out.bmp

