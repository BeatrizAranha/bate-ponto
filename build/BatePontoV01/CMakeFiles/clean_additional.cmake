# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\bate-ponto_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\bate-ponto_autogen.dir\\ParseCache.txt"
  "bate-ponto_autogen"
  )
endif()
