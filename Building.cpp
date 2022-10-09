#include <iostream>
#include <cassert>

using namespace std;

class Light
{
private:
    bool open;
public:
    Light();
    bool isOpen();
    void toggle();
};

Light::Light()
{
    open = false;
}

bool Light::isOpen()
{
    return open;
}

void Light::toggle()
{
    open = !open;
}


class Door
{
private:
    bool open;
public:
    Door();
    bool isOpen();
    void toggle();
};

Door::Door()
{
    open = false;
}

bool Door::isOpen()
{
    return open;
}

void Door::toggle()
{
    open = !open;
}

class Window
{
private:
    bool open;
public:
    Window();
    bool isOpen();
    void toggle();
};

Window::Window()
{
    open = false;
}

bool Window::isOpen()
{
    return open;
}

void Window::toggle()
{
    open = !open;
}

class Room
{
private:
    Light light;
    Window* window;
    size_t numberOfWindows;
public:
    Room(size_t numberOfWindows);
    ~Room();
    Light* getLight();
    Window* getwindow(size_t index);
    size_t getNumberOfWindows();
};

Room::Room(size_t numberOfWindows)
{
    this->numberOfWindows = numberOfWindows;
    window = new Window[numberOfWindows];
}

Room::~Room()
{
    delete [] window;
}

Light* Room::getLight()
{
    return &light;
}

Window* Room::getwindow(size_t index)
{
    return &(window[index]);
}

size_t Room::getNumberOfWindows()
{
    return numberOfWindows;
}

class Flat
{
private:
    Room bedroom = Room(1), livingRoom = Room(2);
    Door outerDoor, innerDoor;
public:
    Room* getBedroom();
    Room* getLivingRoom();
    Door* getInnerDoor();
    Door* getOuterDoor();
};

Room* Flat::getBedroom()
{
    return &bedroom;
}

Room* Flat::getLivingRoom()
{
    return &livingRoom;
}

Door* Flat::getInnerDoor()
{
    return &innerDoor;
}

Door* Flat::getOuterDoor()
{
    return &outerDoor;
}

class Floor
{
private:
    Flat flats[2];
    Window* window = NULL;
public:
    Floor();
    Floor(bool withWindow);
    ~Floor();
    Flat* getFlat(size_t index);
    Window* getWindow();
};

Floor::Floor()
{
    window = new Window;
}

Floor::Floor(bool withWindow)
{
    if(withWindow)
    {
        window = new Window;
    }
}

Floor::~Floor()
{
    delete [] window;
}

Flat* Floor::getFlat(size_t index)
{
    return &(flats[index]);
}

class Building
{
private:
    size_t numberOfFloors;
    Floor* floors;
public:
    Building(size_t numberOfFloors);
    ~Building();
    Floor* getFloor(size_t index);
    Flat* getFlat(size_t doorNumber);
};

Building::Building(size_t numberOfFloors)
{
    this->numberOfFloors = numberOfFloors;
    floors = new Floor[numberOfFloors];
}

Building::~Building()
{
    delete [] floors;
}

Floor* Building::getFloor(size_t index)
{
    return &(floors[index]);
}

Flat* Building::getFlat(size_t doorNumber)
{
    return floors[(doorNumber - 1) / 2].getFlat((doorNumber - 1) % 2);
}

int main()
{

    return 0;
}