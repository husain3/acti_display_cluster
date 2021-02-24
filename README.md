# acti_display_cluster
Assetto Corsa display cluster made for Automotive Grade Linux in C++ and QML

Loosely based on these articles to using a C++ backend for QML:
https://retifrav.github.io/blog/2016/07/18/cpp-backend-qml/
https://retifrav.github.io/blog/2018/03/08/qt-client-server-qml/

Used this as a guide to properly read from a UDP socket:
https://stackoverflow.com/questions/42714700/how-to-receive-proper-udp-packet-in-qt

Used this to learn how to cast a QByteArray to a struct:
https://stackoverflow.com/questions/26603697/qt-how-to-convert-a-qbytearray-to-struct

Used this to learn how to declare C structs in C++ (PLEASE NOTE THE RESPONSE FROM sierdzio):
https://forum.qt.io/topic/43165/solved-use-the-struct-inside-a-class/2

Used these to figure out how to pass struct to signal to the QML frontend:
https://stackoverflow.com/questions/19397567/passing-structure-to-signal-in-qt
https://stackoverflow.com/questions/45650277/best-way-to-access-a-cpp-structure-in-qml
