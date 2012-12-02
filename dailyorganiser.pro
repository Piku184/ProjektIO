HEADERS =   mainwindow.h \
    day.h \
    task.h
 SOURCES =   main.cpp \
             mainwindow.cpp \
    day.cpp \
    task.cpp

 # install
 target.path = $$[QT_INSTALL_EXAMPLES]/widgets/calendarwidget
 sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS calendarwidget.pro resources
 sources.path = $$[QT_INSTALL_EXAMPLES]/widgets/calendarwidget
 INSTALLS += target sources

CONFIG -= x86_64
