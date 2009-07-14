link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

add_executable(resolute
    main.cpp )

target_link_libraries(resolute
    ${GTKMM_LIBRARIES}  )
