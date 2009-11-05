link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

add_executable(resolute
    ${SOURCES}
    main.cpp
    about.cpp
    resolute.cpp
    resolutionModel.cpp
    sponsorModel.cpp
    gtkResolution.cpp )

target_link_libraries(resolute
    ${GTKMM_LIBRARIES}  )
