# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TischkickerIdee_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TischkickerIdee_autogen.dir\\ParseCache.txt"
  "TischkickerIdee_autogen"
  )
endif()
