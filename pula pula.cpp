#include<iostream>
#include<list>
#include<string>

using namespace std;

class Children 
{
private:
    int age;
    string name;

public:
    Children(int age,string name) 
    {
        this->age=age;
        this->name=name;
    }
    friend ostream& operator<<(ostream& os, Children& children)
    {
        os<<"("<<children.name<<", "<<children.age<<")"<<endl;
        return os;
    }
};

class Trampoline
{ 
private:
    list<Children> waiting;
    list<Children> playing;

public:
    void add_children(Children children)
    {
        waiting.push_back(children);
    }
    void waiting_to_playing()
    {
        if(!waiting.empty())
        {
            playing.push_back(waiting.front());
            waiting.pop_front();
        }
    }
    void playing_to_waiting()
    {
        if(!playing.empty())
        {
            waiting.push_back(playing.front());
            playing.pop_front();
        }
    }
    void print_waiting()
    {
        for(auto it=waiting.begin();it!=waiting.end();it++)
        {
            cout<<"Esperando:"<<*it<<endl;
        }
    }
    void print_playing()
    {
        for(auto it=playing.begin();it!=playing.end();it++)
        {
            cout<<"Pulando:"<<*it<<endl;
        }
    }
};

int main()
{
    Trampoline trampoline;
    trampoline.add_children(Children(18,"Emilly"));
    trampoline.add_children(Children(19,"Rafael"));
    trampoline.add_children(Children(18,"Guilherme"));
    trampoline.waiting_to_playing();
    trampoline.print_waiting();
    trampoline.print_playing();
    trampoline.playing_to_waiting();
    trampoline.waiting_to_playing();
    trampoline.print_waiting();
    trampoline.print_playing();
    return 0;
}
