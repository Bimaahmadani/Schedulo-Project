# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ScheduloProject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ScheduloProject_autogen.dir\\ParseCache.txt"
  "ScheduloProject_autogen"
  )
endif()
