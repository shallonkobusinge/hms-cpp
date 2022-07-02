//
// Created by kobsh on 02/07/2022.
//


#include "../utils/headers.h"
#include "../services/RoomService.h"
#include "../services/UserService.h"

class App{
public:
    UserService userService;
    RoomService roomService;
    void start(){
//        signUp();
//        login();
        vector<User> all = userService.returnAllUsers();
        for(int i=0;i<all.size();i++){
            cout<<all[i].getUserId()<<" "<<all[i].getUsername()<<" "<<all[i].getRole()<<" "<<all[i].getPassword()<<endl;
        }
    }
    void login(){
        string username, password;
        cout << " LOGIN "<<endl;
        cout << "Enter username: ";
        cin>>username;
        cout << "Enter password: ";
        cin>>password;
        User user = User(username,password);
        userService.LoginUser(username, password);
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
        userService.RegisterUser(user);
    }
};
