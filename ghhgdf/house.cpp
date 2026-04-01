#include <iostream>
#include <vector>

using namespace std;

class Room {
public:
    int number;

    Room(int n) {
        number = n;
    }

    void show() {
        cout << "Комната номер: " << number << endl;
    }
};

class House {
private:
    vector<Room> rooms; 

public:
    void addRoom(int number) {
        rooms.push_back(Room(number));
    }

    void showRooms() {
        cout << "Комнаты в доме:" << endl;
        for (int i = 0; i < rooms.size(); i++) {
            rooms[i].show();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    House house;

    house.addRoom(1);
    house.addRoom(2);
    house.addRoom(3);

    house.showRooms();

    return 0;
}