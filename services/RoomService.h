//
// Created by kobsh on 02/07/2022.
//

#include "../services/UserService.h"

class RoomService{
public:
    UserService userService;
    static Room createRoom(RoomDTO dto){
        ofstream file;
        file.open("rooms.txt", ios::app);

        User user = UserService::findUserById(dto.getUserId());

        bool userExists = UserService::userExistsById(dto.getUserId());
        if(!userExists){
            cout<<"User does not exist"<<endl;
            return {};
        }
        int id = getLastRoomId();
        Room room = Room(dto.getRoomPrice(),dto.getStatus(),dto.getUserId());
        room.setRoomId(id+1);
       file  << room.getRoomId() << "  " <<  room.getRoomPrice() << "  "  << room.getStatus() << "  " << room.getUserId() << "  " << endl;
        file.close();
        return room;
    }
    static Room getSingleRoom(const string &line){
         stringstream ss(line);
        Room room;
        int i=0;
        for(string rowElement; ss >> rowElement;){
           if(reinterpret_cast<const char *>(rowElement[rowElement.length() - 1 ]) == "")
               rowElement.pop_back();
           if(i == 0) room.setRoomId(stoi(rowElement));
           else if(i == 1)  room.setRoomPrice(stoi(rowElement));
           else if(i == 2) room.setStatus(rowElement);
           else if(i == 3) room.setUserId(stoi(rowElement));
              i++;
        }
        return room;
    }
    static vector<Room> getAllRoomsList(){
        vector<Room> rooms;
        ifstream file("rooms.txt");
        string line;
        while(getline(file,line)){
            stringstream ss(line);
            Room room = getSingleRoom(line);
            rooms.push_back(room);
        }
        return rooms;
        }
    static Room getRoomById(int roomId){
        vector<Room> rooms = getAllRoomsList();
        for(auto & room : rooms){
            if(room.getRoomId() == roomId){
                return room;
            }
        }
        return {};
    }
    static void deleteRoomById() {
        vector<Room> rooms = getAllRoomsList();
        int id;

        cout << "     ENTER ROOM ID TO DELETE" << endl;
        cin >> id;
        ifstream file("rooms.txt");
        ofstream tempFile("temp.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            if (line.find(to_string(id)) != string::npos) {
                cout<<" the one to delete is "<<line<<endl;
            }else{
                tempFile << line << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("rooms.txt");
        rename("temp.txt", "rooms.txt");
    }
    static int getLastRoomId(){
        vector<Room> rooms = getAllRoomsList();
        int lastId = 0;
        for(int i=0; i<rooms.size(); i++){
            if(rooms[i].getRoomId() > lastId){
                lastId = rooms[i].getRoomId();
            }
        }
        return lastId;
    }
    static Room updateRoom(int roomId, Room room){
        vector<Room> rooms = getAllRoomsList();
        string line;
        ifstream file("rooms.txt");
        ofstream tempFile("temp.txt");
        while(getline(file, line)){
            stringstream ss(line);
            if(line.find(to_string(roomId)) != string::npos){
                cout<<" The one to update is "<<line<<endl;
            }else{
                tempFile<< line << endl;
            }
        }
        tempFile<< room.getRoomId() << "  " <<  room.getRoomPrice() << "  "  << room.getStatus() << "  " << room.getUserId() << "  " << endl;
        file.close();
        tempFile.close();
        remove("rooms.txt");
        rename("temp.txt", "rooms.txt");
        return room;

    }
    static void makeReservation(int roomId){
        Room room = getRoomById(roomId);
        ifstream file("rooms.txt");
        ofstream tempFile("temp.txt");
        string line;
        while (getline(file, line)){
            stringstream ss(line);
            if(line.find(to_string(roomId))!= string::npos){
                cout<<" The one to update is "<<line<<endl;
            }else{
                tempFile<< line << endl;
            }
        }
        room.setStatus("RESERVED");
        tempFile<< room.getRoomId() << "  " <<  room.getRoomPrice() << "  "  << room.getStatus() << "  " << room.getUserId() << "  " << endl;
        file.close();
        tempFile.close();
        remove("rooms.txt");
        rename("temp.txt", "rooms.txt");

    }
    static Room getReservedRooms(int roomId){
        vector<Room> all = getAllRoomsList();
        Room reservedRoom;
        for(int i=0; i<all.size(); i++){
            if(all[i].getRoomId() == roomId && all[i].getStatus() == "RESERVED"){
                    reservedRoom = all[i];
            }

        }
        return reservedRoom;

    }
    static vector<Room> allReservedRooms(){
        vector<Room> all = getAllRoomsList();
        vector<Room> reservedRooms;
        for(int i=0; i<all.size(); i++){
            if(all[i].getStatus() == "RESERVED"){
                reservedRooms.push_back(all[i]);
            }
        }
        return reservedRooms;
    }
};