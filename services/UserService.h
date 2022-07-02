//
// Created by kobsh on 02/07/2022.
//

#include "../utils/models.cpp"

class UserService {
public:
    static User RegisterUser(User user){
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
        return {user.getUserId(),user.getUsername(),user.getRole(),user.getPassword()};
    };
    static string LoginUser(const string& username, const string& password){
        string message;
        bool userExists = userExistsByUsername(username);
        if(!userExists){
            return "User does not exist";
        }
        User user = getUserByUsername(username);
        if(user.getPassword() != password){
            return "Password is incorrect";
        }
        return "Logged in succesfully";
    };
    static bool userExistsByUsername(string user){
        vector<User> users = returnAllUsers();
        bool exists = false;
        for(auto & i : users){
            if(i.getUsername() == user){
                exists = true;
                return exists;
            }
        }
        return exists;
    }
    void UpdateUser(int userId,User user){

    };
    void DeleteUser(int userId){

    };
    static bool userExistsById(int id){
        vector<User> users = returnAllUsers();
        bool exists = false;
        for(auto & i : users){
            if(i.getUserId() == id){
                exists = true;
                return exists;
            }
        }
        return exists;
    }
    static User findUserById(int id){
        vector<User> all = returnAllUsers();
         User user;
        for(auto & i : all){
            if(i.getUserId() == id){
                user = i;
            }else{
                cout<<" User not found"<<endl;
            }
        }
        return user;
    };
    static User getUserByUsername(const string& username){
        vector<User> users = returnAllUsers();
        for(auto & user : users){
            if(user.getUsername() == username){
                return user;
            }
        }
        return {};
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
    static int returnLastId(){
        vector<User> all = returnAllUsers();
        int lastId = 0;
       for(auto & i : all){
           if(i.getUserId() > lastId){
               lastId = i.getUserId();
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
