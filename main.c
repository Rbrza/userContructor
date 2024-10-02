#include <stdio.h>
#include <stdlib.h>

struct User {
    char * Name;
    char * LastName;
    char * Email;
    int Age;
};

struct User createUser(char * Name, char * LastName, char * Email, int Age) {
    struct User user;
    user.Name = Name;
    user.LastName = LastName;
    user.Email = Email;
    user.Age = Age;
    return user;
}

int printUserInfo(struct User user) {
    printf("Name: %s\n", user.Name);
    printf("LastName: %s\n", user.LastName);
    printf("Email: %s\n", user.Email);
    printf("Age: %d\n", user.Age);
    return 0;
}

struct userList {
    struct User * usersList;
    int numberOfUsersInArray;
    int capacityOfArray;
};

int writeUserInfoFromArray(struct userList *users) {
    for (int i = 0; i < users->numberOfUsersInArray; i++) {
        printUserInfo(users->usersList[i]);
    }
    return 0;
}

struct userList createUserList(int size) {
    struct userList users;
    users.capacityOfArray = size;
    users.usersList = malloc(sizeof(struct User) * size);
    users.numberOfUsersInArray = 0;
    return users;
};

void addUserToList(struct userList * users, struct User user) {
    if (users->capacityOfArray < users->numberOfUsersInArray + 1) {
        users -> capacityOfArray++;
        users->usersList = realloc(users->usersList, sizeof(struct User) * users->capacityOfArray);
        users->numberOfUsersInArray ++;
        users->usersList[users->numberOfUsersInArray - 1] = user;
    }
    else {
        users->numberOfUsersInArray ++;
        users->usersList[users->numberOfUsersInArray - 1] = user;
    }
}

void deleteUserFromList(struct userList * users, struct User user) {
    if (users->numberOfUsersInArray > 0) {

}

int main(void) {
    struct userList users = createUserList(10);
    struct User user = createUser("John", "Doe", "Smith", 180);
    struct User user2 = createUser("Marry", "Long", "Hamburbur", 45);
    printUserInfo(user);
    users.usersList[0] = user;
    users.usersList[1] = user2;
    /*
    printf("Size of array: %llu\n",sizeof*(users)); //Furt stejný size i když smažu user2 z pole
    printf("First name: %s\n",(users + 1)->Name); // Nepotřebuju * a jestli jí tam dám tak musí tam být i &. Když ne * tak nic??
    */
    writeUserInfoFromArray(&users);
    free(users.usersList);
    return 0;
}