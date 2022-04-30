file(GLOB_RECURSE SourceFile_Src "*.cc" "*.hh")
add_executable(${PROJECT_NAME} ${SourceFile_Src} ${CMAKE_BINARY_DIR}/resource.c)
target_link_libraries(${PROJECT_NAME} GTKMM HANDY)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})
compile_resources(
    ${CMAKE_BINARY_DIR}/resource.c
    ui.glade
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)