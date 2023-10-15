cmake_minimum_required (VERSION 3.8)

project ("Calc")

set(CMAKE_CXX_STANDARD 17)

add_executable (Calculator "Calculator/Source.cpp" 
                           "Calculator/ExpressionElements.h" "Calculator/ExpressionElements.cpp" 
                           "Calculator/API.h" "Calculator/API.cpp"
                           "Calculator/BaseOperation.h" "Calculator/BaseOperation.cpp"
                           "Calculator/Calculator.h" "Calculator/Calculator.cpp"
                           "Calculator/ModuleManager.h" "Calculator/ModuleManager.cpp"
                           "Calculator/Separator.h" "Calculator/Separator.cpp"  )
install (TARGETS Calculator)
install (TARGETS Pow DESTINATION modules)
install (TARGETS Trigonometry DESTINATION modules)
install (TARGETS Logarifms DESTINATION modules)