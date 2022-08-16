@rem !/bin/msdos
@
@rem  Make all examples.
@rem  No Scons, no CMake, no Make or any other make tool
@rem  One line one example
@rem  Designed for easy copy/paste
@
@rem DO NOT CALL directly
@cls
@
@echo %cd%
@
@cl /EHsc /I../src step_1.cpp
@cl /EHsc /I../src step_2.cpp
@cl /EHsc /I../src step_3.cpp
@cl /EHsc /I../src step_4.cpp
@cl /EHsc /I../src TopLog.cpp

pause