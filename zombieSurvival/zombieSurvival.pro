TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        boom.cpp \
        bullet.cpp \
        game.cpp \
        item.cpp \
        main.cpp \
        monster.cpp \
        myFunctions.cpp \
        player.cpp

HEADERS += \
    boom.hpp \
    bullet.hpp \
    constants.hpp \
    game.hpp \
    item.hpp \
    monster.hpp \
    myFunctions.hpp \
    player.hpp
