set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../floah-layout")
include(floahVersionString)

set(NAME floah-data)
set(TYPE module)
set(INCLUDE_DIR "include/floah-data")
set(SRC_DIR "src")

set(HEADERS
    ${INCLUDE_DIR}/bool_data_source.h
    ${INCLUDE_DIR}/data_source.h
    ${INCLUDE_DIR}/i_bool_data_source.h
    ${INCLUDE_DIR}/i_list_data_source.h
    ${INCLUDE_DIR}/i_value_data_source.h
    ${INCLUDE_DIR}/value_data_source.h
)

set(SOURCES
    ${SRC_DIR}/bool_data_source.cpp
    ${SRC_DIR}/data_source.cpp
)

set(DEPS_PUBLIC
    floah-layout
)

set(DEPS_PRIVATE

)

make_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION ${FLOAH_VERSION}
    WARNINGS WERROR
    HEADERS "${HEADERS}"
    SOURCES "${SOURCES}"
    DEPS_PUBLIC "${DEPS_PUBLIC}"
    DEPS_PRIVATE "${DEPS_PRIVATE}"
)

install_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION ${FLOAH_VERSION}
    HEADERS "${HEADERS}"
)

target_compile_definitions(
    ${NAME}
    PRIVATE
        FLOAH_VERSION_MAJOR=${FLOAH_VERSION_MAJOR}
        FLOAH_VERSION_MINOR=${FLOAH_VERSION_MINOR}
        FLOAH_VERSION_PATCH=${FLOAH_VERSION_PATCH}
)
