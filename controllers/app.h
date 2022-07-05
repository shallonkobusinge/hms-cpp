//
// Created by kobsh on 02/07/2022.
//


#include "../services/RoomService.h"

class App{
public:
    UserService userService;
    RoomService roomService;
    void start(){

        char option;
        do {

        cout<<"                  HOTEL MANAGEMENT SYSTEM                                "<<endl;
        cout<<"                1. REGISTER                                              "<<endl;
        cout<<"                2. LOGIN                                                 "<<endl;
        cin>>option;
        switch (option) {
            case '1':
                signUp();
                break;
            case '2':
                login();
                break;
            default:
                cout<<"Invalid option"<<endl;
                break;
        }
        } while (option != '2');
    }
    void menu(){
        char choice;
        do{
        cout<<"                  HOTEL MANAGEMENT SYSTEM                                "<<endl;
        cout<<"                1. CREATE A ROOM                                         "<<endl;
        cout<<"                2. DELETE A ROOM                                         "<<endl;
        cout<<"                3. LIST ALL ROOM                                         "<<endl;
        cout<<"                4. FIND A ROOM BY ID                                     "<<endl;
        cout<<"                5. UPDATE A ROOM                                         "<<endl;
        cout<<"                6. RESERVE A ROOM                                        "<<endl;
        cout<<"                7. LIST ALL RESERVATIONS                                 "<<endl;
        cout<<"                8. FIND A RESERVATION BY ID                              "<<endl;
            cout<<"                9. LOGOUT                                                "<<endl;
            cout<<"                10. Sort                                                "<<endl;
        cin>>choice;
        switch(choice){
            case '1':
                createRoom();
                break;
            case '2':
                RoomService::deleteRoomById();
                break;
            case '3':
                displayList(RoomService::getAllRoomsList());
                break;
            case '4':
                findRoomById();
                break;
            case '5':
                update();
                break;
            case '6':
                reserve();
                break;
            case '7':
                displayList(RoomService::allReservedRooms());
                break;
            case '8':
                int id;
                cout<<"Enter the reservation room id: ";
                cin>>id;
                displayOneRoomList(RoomService::getReservedRooms(id));
                break;
            case '9':
                system("CLS");
                start();
                break;
            case '10':
                RoomService::sortDataInAfile();
            default:
                cout<<"Invalid option"<<endl;
                break;
        }
        } while (choice!='9');
    }
    void login(){
        string username, password;
        cout << " LOGIN "<<endl;
        cout << "Enter username: ";
        cin>>username;
        cout << "Enter password: ";
        cin>>password;
        User user = User(username,password);
        string message = userService.LoginUser(username, password);
       if(message == "Logged in succesfully"){
           cout<<"Welcome "<<username<<endl;
           menu();
       }else{
           cout<<message<<endl;
       }
    }
    void signUp(){
        string username,role,password;

        cout<<" REGISTRATION FORM  "<<endl;
        cout<<" Username: ";
        cin>>username;
        cout<<" Role: ";
        cin>>role;
        cout<<" Password: ";
        cin>>password;
        for_each(role.begin(), role.end(), [](char &c){
            c = toupper(c);
        });
        User user = User(username,role,password);
        UserService::RegisterUser(user);
    }
    void createRoom(){
        int userId,roomPrice, roomId;
        string status;
        cout<<" CREATE A ROOM "<<endl;
        cout<<" Enter user id: ";
        cin>>userId;
        cout<<" Enter room price: ";
        cin>>roomPrice;
        cout<<" Enter status: ";
        cin>>status;
        for_each(status.begin(), status.end(), [](char &c){
            c = toupper(c);
        });
        RoomDTO room = RoomDTO(userId,roomPrice,status);
        RoomService::createRoom(room);
    }
    void displayList(vector<Room> list){

        cout<<" ROOM LIST "<<endl;
        cout<<"  ------------------------------------------------------------------------------------------------ "<<endl;
        cout<<"  | Room Id           | Room Price           | Status           "<<"| User Id           "<<endl;
        for(int i=0; !list.empty(); i++){
            cout<<list[i].getRoomId()<<"           "<<list[i].getRoomPrice()<<"           "<<list[i].getStatus()<<"           "<<list[i].getUserId()<<endl;
        }
        cout<<"  ------------------------------------------------------------------------------------------------- "<<endl;
    }
    void displayOneRoomList(Room list){

        cout<<" ROOM LIST "<<endl;
        cout<<"  ------------------------------------------------------------------------------------------------ "<<endl;
        cout<<"  | Room Id           | Room Price           | Status           "<<"| User Id           "<<endl;

            cout<<list.getRoomId()<<"           "<<list.getRoomPrice()<<"           "<<list.getStatus()<<"           "<<list.getUserId()<<endl;

        cout<<"  ------------------------------------------------------------------------------------------------- "<<endl;
    }
    void findRoomById(){
        int id;
        cout<<" Enter the id of the room "<<endl;
        cin>>id;
        Room room = RoomService::getRoomById(id);
        cout<<" Room Id: "<<room.getRoomId()<<endl;
        cout<<" Room Price: "<<room.getRoomPrice()<<endl;
        cout<<" Status: "<<room.getStatus()<<endl;
        cout<<" User Id: "<<room.getUserId()<<endl;

    }
    void update(){
        int id,roomPrice;
        cout<<" Enter the id of the room "<<endl;
        cin>>id;
        Room room = RoomService::getRoomById(id);
        cout<<"  Enter the new room price: "<<endl;
        cin>>roomPrice;
        room.setRoomPrice(roomPrice);
        RoomService::updateRoom(id,room);
    }
    void reserve(){
        int id;
        cout<<" Enter the id of the room to reserve "<<endl;
        cin>>id;
        RoomService::makeReservation(id);
    }
};
