# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TischkickerFlipScrolling_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TischkickerFlipScrolling_autogen.dir/ParseCache.txt"
  "TischkickerFlipScrolling_autogen"
  )
endif()
