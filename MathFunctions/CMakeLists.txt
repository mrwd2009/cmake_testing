add_library(MathFunctions1 mysqrt.cpp)

install(TARGETS MathFunctions1 DESTINATION bin)
install(FILES MathFunctions.h DESTINATION include)