remove_definitions(-D__DEEPKS)
remove_definitions(-D__CUDA)
remove_definitions(-D__ROCM)
remove_definitions(-D__EXX)

AddTest(
  TARGET cell_neighbor_sltk_adjacent_set
  SOURCES sltk_adjacent_set_test.cpp ../sltk_adjacent_set.cpp
)

AddTest(
  TARGET cell_neighbor_sltk_atom
  SOURCES sltk_atom_test.cpp ../sltk_atom.cpp ../sltk_adjacent_set.cpp
)

AddTest(
  TARGET cell_neighbor_sltk_atom_input
  LIBS ${math_libs} base device cell_info parameter
  SOURCES sltk_atom_input_test.cpp ../sltk_atom_input.cpp ../sltk_atom.cpp ../sltk_adjacent_set.cpp
     ../../../module_io/output.cpp
)

AddTest(
  TARGET cell_neighbor_sltk_grid
  LIBS ${math_libs} base device cell_info parameter
  SOURCES sltk_grid_test.cpp ../sltk_grid.cpp ../sltk_atom_input.cpp ../sltk_atom.cpp ../sltk_adjacent_set.cpp
    ../../../module_io/output.cpp
)

AddTest(
  TARGET cell_neighbor_sltk_atom_arrange
  LIBS ${math_libs} base device cell_info parameter
  SOURCES sltk_atom_arrange_test.cpp  ../sltk_atom_arrange.cpp ../sltk_grid_driver.cpp ../sltk_grid.cpp
  ../sltk_atom_input.cpp ../sltk_atom.cpp ../sltk_adjacent_set.cpp
  ../../../module_io/output.cpp
)