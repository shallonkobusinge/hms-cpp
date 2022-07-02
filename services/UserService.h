//
// Created by kobsh on 02/07/2022.
//

#include "../utils/models.cpp"
#include "../utils/headers.h"

class UserService {
public:
    User RegisterUser(User user){
        ofstream file;
        file.open("users.txt", ios::app);
        bool userExists = userExistsByUsername(user.getUsername());
        if(userExists){
            cout<<"User already exists"<<endl;
            return user;
        }
        int lastId = returnLastId();
        user.setUserId(lastId+1);
        file << user.getUserId() << "  " << user.getUsername() << "  " << user.getRole() << "  " << user.getPassword() << "  "<< endl;
        file.close();
        return User(user.getUserId(),user.getUsername(),user.getRole(),user.getPassword());
    };
    User LoginUser(string username, string password){

        bool userExists = userExistsByUsername(username);
        if(!userExists){

            cout<<"User does not exist"<<endl;
            return User();
        }
        User user = getUserByUsername(username);
        if(user.getPassword() != password){
            cout<<"Password is incorrect"<<endl;
            return User();
        }
        cout<<" Logged in succesfully"<<endl;
        return user;
    };
    bool userExistsByUsername(string user){
        vector<User> users = returnAllUsers();
        bool exists = false;
        for(int i= 0; i<users.size(); i++){
            if(users[i].getUsername() == user){
                exists = true;
                return exists;
            }
        }
        return exists;
    }
    User GetUser(int userId){
        User user;
        vector<User> all = returnAllUsers();
        for(int i=0;i<all.size();i++){
            if(all[i].getUserId() == userId){
                return all[i];
            }
        }
    };
    void UpdateUser(int userId,User user){

    };
    void DeleteUser(int userId){

    };
    User getUserByUsername(string username){
        vector<User> users = returnAllUsers();
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername() == username){
                return users[i];
            }
        }
        return User();
    };

    static User returnSingleUser(const string &line){
        stringstream ss(line);
        User user;
        string item;
        int i=0;
        for(string rowElement; ss >> rowElement;) {

            if (reinterpret_cast<const char *>(rowElement[rowElement.length() - 1] ) == "")
                rowElement.pop_back();

            if (i == 0) user.setUserId(stoi(rowElement));
            else if (i == 1) user.setUsername(rowElement);
            else if (i == 2) user.setRole(rowElement);
            else if (i == 3) user.setPassword(rowElement);
            i++;
        }
        return user;
    }
    int returnLastId(){
        vector<User> all = returnAllUsers();
        int lastId = 0;
       for(int i=0; i<all.size(); i++){
           if(all[i].getUserId() > lastId){
               lastId = all[i].getUserId();
           }
       }
       return lastId;
    }
    static vector<User> returnAllUsers(){
        vector<User> users;
        ifstream file;
        file.open("users.txt", ios::app);
        string line;
        string storedLine;
        while(getline(file, line)){
            stringstream ss(line);
            string token;
        User user =  returnSingleUser(line);
        users.push_back(user);
        }
        file.close();
        return users;
    }
};
