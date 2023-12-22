file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h
add_executable(${postfix_main} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${postfix}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${postfix_main} ${postfix}) #Подключаем к проекту с именем ${postfix} библиотеку с именем ${postfix_main}

#add_library(${MyLib1} STATIC ${srcs} ${hdrs}) #Создаем статическую библиотеку с именем из переменной ${MyLib1}, объявленной в родительском CMake файле (локальные переменные переносятся в наследников), в неё добавляются файлы из переменных ${srcs} и ${hdrs}