# this embedded boost is generated using the boost/tools/bcp tool.
# https://www.boost.org/doc/libs/1_40_0/tools/bcp/bcp.html
#
# it contains the following libraries:
# ./dist/bin/bcp --namespace=boost_kahypar program_options range dynamic_bitset lexical_cast any type_index function bind core tokenizer concept_check utility iterator type_traits dynamic_bitset integer random container_hash ./boost_kahypar
# of which only program_options and range are not header-only so we compile them.
#
# bash rename_kahypar.sh   # rename fully boost to boost_kahypar in include directory.
#
# this cmake is a simple polyfill by zizheng.

add_library(
  BoostKaHyPar
  STATIC
  libs/program_options/src/cmdline.cpp
  libs/program_options/src/config_file.cpp
  libs/program_options/src/convert.cpp
  libs/program_options/src/options_description.cpp
  libs/program_options/src/parsers.cpp
  libs/program_options/src/positional_options.cpp
  libs/program_options/src/split.cpp
  libs/program_options/src/utf8_codecvt_facet.cpp
  libs/program_options/src/value_semantic.cpp
  libs/program_options/src/variables_map.cpp
  libs/program_options/src/winmain.cpp
  )

set_target_properties(BoostKaHyPar PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(
  BoostKaHyPar PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  )
