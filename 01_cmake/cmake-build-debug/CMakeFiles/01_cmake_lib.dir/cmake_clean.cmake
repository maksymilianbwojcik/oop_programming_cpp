file(REMOVE_RECURSE
  "lib01_cmake_lib.a"
  "lib01_cmake_lib.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/01_cmake_lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
