#include <stdio.h>
#include <stdlib.h>

struct User {
    char * Name;
    char * LastName;
    char * Email;
    int Age;
};

struct userList {
    struct User * usersList;
    int numberOfUsersInArray;
    int capacityOfArray;
};

int writeUserInfoFromArray(struct userList *users) {
    for (int i = 0; i < users->numberOfUsersInArray; i++) {
        printf("Name: %s\n", users->usersList[i].Name);
        printf("LastName: %s\n", users->usersList[i].LastName);
        printf("Email: %s\n", users->usersList[i].Email);
        printf("Age: %d\n", users->usersList[i].Age);
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
        int koeficient = 0;
        for (int i = 0; i < users->numberOfUsersInArray - 1; ++i) {
            if (users->usersList[i].Name == user.Name && users->usersList[i].LastName == user.LastName && users->usersList[i].Email == user.Email && users->usersList[i].Age == user.Age) {
                free(users->usersList[i].Name);
                free(users->usersList[i].LastName);
                free(users->usersList[i].Email);
                koeficient ++;
            }
            else {
                users->usersList[i] = users->usersList[i + koeficient];
            }
        }
        users->numberOfUsersInArray --;
        users->usersList = realloc(users->usersList, sizeof(struct User) * users->numberOfUsersInArray);
        users->capacityOfArray--;
    }
    else {
        printf("Error: User list is empty\n");
    }
}

struct User questionnareToGenerateUser() {
    struct User user;
    char name[50];
    char lastName[50];
    char email[100];

    printf("Enter Name : ");
    scanf("%s", name);
    user.Name = name;

    printf("Enter Last Name : ");
    scanf("%s", lastName);
    user.LastName = lastName;

    printf("Enter Email : ");
    scanf("%s", email);
    user.Email = email;

    printf("Enter Age : ");
    scanf("%d", &user.Age);

    return user;
}

int main(void) {
    struct userList users = createUserList(30);
    while (true) {
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Write all users in array\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        struct User user;
        switch (choice) {
            case 1:
                user = questionnareToGenerateUser();

                addUserToList(&users, user);
            break;
            case 2:
                user = questionnareToGenerateUser();
                deleteUserFromList(&users, user);
            break;
            case 3:
                writeUserInfoFromArray(&users);
            break;
            case 4:
                printf("Exit\n");
            free(users.usersList);
            return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}