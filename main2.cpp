//////
////// Created by Kshitij Kulkarni on 12/10/16.
//////
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <string>
//#include <iostream>
//#include <SFML/Network.hpp>
//
//using namespace std;
//
//int main()
//{
////    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
//    sf::TcpSocket socket;
//    char connectionType, mode;
//    char buffer[2000];
//    std::size_t received;
//    std::string text = "Connected to: ";
//
//    std::cout << "Enter (s) for Server, Enter (c) for client: " << std::endl;
//    cin >> connectionType;
//
//    if (connectionType == 's')
//    {
//        sf::TcpListener listener;
//        listener.listen(2000);
//        listener.accept(socket);
//        text += "Server";
//
//    }
//    else if (connectionType == 'c')
//    {
//        sf::IpAddress k("128.61.37.176");
//        socket.connect(k, 2000);
//        text += "Client";
//
//
//    }
//    socket.send(text.c_str(), text.length()+1);
//    socket.receive(buffer, sizeof(buffer),received);
//
//    std::cout << buffer << std::endl;
//    system("pause");
//    return 0;
//}