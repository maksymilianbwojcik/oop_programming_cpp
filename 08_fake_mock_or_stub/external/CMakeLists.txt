
set(BUILD_GMOCK ON CACHE BOOL "Suppressing gmock's" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Suppressing gtest's install" FORCE)

add_subdirectory(googletest)
