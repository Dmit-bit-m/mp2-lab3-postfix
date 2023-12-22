file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${stack_test} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${stacktest}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${stack_test} ${stack} gtest) #Подключаем к проекту с именем ${stack} библиотеки с именами ${stacklib} и gtest