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
    User(){}
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
    string status;
    int userId;
public:
     Room(){}
     Room(int roomPrice, string status, int userId){
        this->roomPrice = roomPrice;
        this->status = status;
        this->userId = userId;
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
    int getUserId() const {
        return userId;
    }
    void setUserId(int user) {
        this->userId = user;
    }
    string getStatus(){
        return status;
    }
    void setStatus(string status){
        this->status = status;
    }

};


class RoomDTO{
private:
    int userId;
    int roomPrice;
    int roomId;
    string status;
public:
    RoomDTO(int userId, int roomPrice, string status){
        this->userId = userId;
        this->roomPrice = roomPrice;
        this->status = status;
    }
    int getUserId(){
        return userId;
    }
    void setUserId(int userId){
        this->userId = userId;
    }
    string getStatus(){
        return status;
    }
    void setStatus(string status){
        this->status = status;
    }
    int getRoomPrice(){
        return roomPrice;
    }
    void setRoomPrice(int roomPrice){
        this->roomPrice = roomPrice;
    }
    int getRoomId(){
        return roomId;
    }
    void setRoomId(int roomId){
        this->roomId = roomId;
    }


};
