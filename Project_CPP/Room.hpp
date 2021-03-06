#ifndef Room_hpp
#define Room_hpp

#include <string>
#include <vector>
#include <iostream>
#include <list>
#include "Object.hpp"
#include "Item.hpp"
#include "Container.hpp"
#include "Creature.hpp"
#include "Trigger.hpp"

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::vector;

class Room:public Object {
private:
    string type;
    string description;
    vector<Room*> borders; //0,north;1,south;2,west;3,east
    list<Item*> items;
    list<Container*> containers;
    list<Creature*> creatures;
    //list<Trigger*> triggers;
    
public:
    Room(string name, string description, string type, list<Trigger> triggers, string status):Object(name, triggers, status) {
        this->description = this->description.assign(description);
        borders.push_back(NULL);borders.push_back(NULL);
        borders.push_back(NULL);borders.push_back(NULL);
        this->type = type;
    }
    ~Room();

    void add_border(list<Room*> room_list, string direction, string roomname);
    void add_item(vector<Item*> item_vec, string item);
    void add_container(vector<Container*> container_vec, string container);
    void add_creature(vector<Creature*> creature_vec, string creature);
    
    int delete_item(string name);
    int delete_con(string name);
    int delete_item_incons(string name);
    int delete_creature(string name);
    void delete_border(Room* room);
    
    Item* find_itemp(string name);
    Container* find_conp(string name);
    Item* find_itemp_incons(string name);
    Creature* find_creaturep(string name);
    
    Room* get_border(int direction) {
        return borders[direction];
    }
    string get_description(){
        return this->description;
    }
    string get_type(){
        return this->type;
    }
    list<Item*>* get_items_inroom() {
        return &items;
    }
    list<Container*>* get_containers_inroom() {
        return &containers;
    }
    list<Creature*>* get_creatures_inroom() {
        return &creatures;
    }

};



#endif /* Room_hpp */
