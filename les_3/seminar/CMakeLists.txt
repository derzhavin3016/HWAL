cmake_minimum_required(VERSION 3.13)
project(sem_2)

# option for debug (debug info)
set(PR_DEBUG_OPTIONS -g)

# option for release (optimization)
set(PR_RELEASE_OPTIONS -O2)

# some useful warnings
set(WARN_OPTIONS
  -Wall 
  -Wextra
  -Wunused -Wpedantic # classic
  -Wno-old-style-cast -Waggressive-loop-optimizations
  -Wunreachable-code)

add_executable(money money.cc)
add_executable(cover cover.cc)

set(TARGETS money cover)

foreach(TARGET ${TARGETS})
  target_compile_features(${TARGET} PRIVATE cxx_std_14)
  target_compile_options(${TARGET} PRIVATE ${WARN_OPTIONS})

  target_compile_options(${TARGET} PRIVATE "$<$<CONFIG:DEBUG>:${PR_DEBUG_OPTIONS}>")
  target_compile_options(${TARGET} PRIVATE "$<$<CONFIG:RELEASE>:${PR_RELEASE_OPTIONS}>")
endforeach()


