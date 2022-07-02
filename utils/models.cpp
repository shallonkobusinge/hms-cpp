//
// Created by kobsh on 02/07/2022.
//

#include "headers.h"

enum ERole {
    ADMIN,
    USER
};


class User{
private:
    int userId;
    string username;
    string role;
    string password;
public:
    User(){
        userId = 0;
        username = "";
        role = USER;
        password = "";
    }
    User( string username, string role, string password){
        this->username = username;
        this->role = role;
        this->password = password;
    }
    User(int userId, string username, string role, string password){
        this->userId = userId;
        this->username = username;
        this->role = role;
        this->password = password;
    }
    User(string username, string password){
        this->username = username;
        this->password = password;
    }
    int getUserId() {
        return userId;
    }
    void setUserId(int userId) {
        this->userId = userId;
    }
    string getRole() {
        return role;
    }
    void setRole(string role) {
        this->role = role;
    }
    string getPassword() {
        return password;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getUsername() {
        return username;
    }
    void setUsername(string username) {
        this->username = username;
    }
};

class Room{
private:
    int roomPrice;
    int roomId;
    User user;
public:
    Room(){
        roomPrice = 0;
        roomId = 0;
        user = User();
    }
    Room(int roomPrice, int roomId, User user){
        this->roomPrice = roomPrice;
        this->roomId = roomId;
        this->user = user;
    }

    int getRoomPrice() {
        return roomPrice;
    }
    void setRoomPrice(int roomPrice) {
        this->roomPrice = roomPrice;
    }
    int getRoomId() {
        return roomId;
    }
    void setRoomId(int roomId) {
        this->roomId = roomId;
    }
    User getUser() {
        return user;
    }
    void setUser(User user) {
        this->user = user;
    }

};

