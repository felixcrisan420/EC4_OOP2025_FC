# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EC4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EC4_autogen.dir\\ParseCache.txt"
  "EC4_autogen"
  )
endif()
