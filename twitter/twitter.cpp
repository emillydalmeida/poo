#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Tweet
{
    private:
    string username;
    string msg;
    set <string> likes;
    Tweet *rt;
    int id;

    public:

    Tweet (int id, string username, string msg){
        this->id = id;
        this->username = username;
        this->msg = msg;
    }

    int get_id()
    {
        return this->id;
    }

    string get_sender()
    {
        return this->username;
    }

    string get_msg()
    {
        return this->msg;
    }

    friend ostream& operator<<(ostream& os, const Tweet& tweet)
    {
        os << tweet.username << ": " << tweet.msg;
        return os;
    }

    void like(string username)
    {
        if (likes.find(username) == likes.end()) {
            likes.insert(username);
        } else {
            cout<< "Ja curtiu " << username << endl;
        }
    }

    void get_likes()
    {
        for (auto it = likes.begin(); it != likes.end(); it++) {
            cout << *it << endl;
        }
    }

    void set_rt(Tweet tw)
    {
        this->rt = &tw;
    }

    bool deleted()
    {
        if (this->rt->get_id() == 0)
        {
            return true;
        }
        
    }

    void set_deleted()
    {
        if(this->rt->get_id() != 0){
            this->rt->id = 0;
            cout << "Tweet deletado" << endl;
            likes.clear();
        }
    }

    bool is_deleted()
    {
        if (this->rt->get_id() == 0)
        {
            return true;
        }
    }
};

class Inbox
{
    private:
    map <int, Tweet> timeline;  
    map <int, Tweet> myTweets;

    public:
    Inbox(){}

    void store_timeLine(Tweet tw)
    {
        this->timeline[tw.get_id()] = tw;
    }

    void get_timeline()
    {
        for (auto it = timeline.begin(); it != timeline.end(); it++) {
            cout << it->second << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Inbox& inbox)
    {
        os << "Timeline: " << endl;
        for (auto it = inbox.timeline.begin(); it != inbox.timeline.end(); it++) {
            os << it->second << endl;
        }
        return os;
    }

    Tweet get_tweet(int id)
    {
        if (myTweets.find(id) != myTweets.end()) {
            return myTweets[id];
        } 
    }

    void store_tweet(Tweet tweet)
    {
        myTweets[tweet.get_id()] = tweet;
    }

    void get_myTweets()
    {
        for (auto it = myTweets.begin(); it != myTweets.end(); it++) {
            cout << it->second << endl;
        }
    }
    
};

class User
{
    private:
    string username;
    Inbox inbox;
    map <string, User> followers;
    map <string, User> following;

    public:

    User(string username){
        this->username = username;
    }
    
    friend ostream& operator<<(ostream& os, const User& user)
    {
        os << user.username;
        return os;
    }

    void follow(User other)
    {
        if (following.find(other.username) == following.end()) {
            following[other.username] = other;
        } else {
            cout<< "Seguindo " << other.username << endl;
        }
    }

    Inbox get_inbox()
    {
        return this->inbox;
    }

    void send_tweet(Tweet tw)
    {
        this->inbox.store_tweet(tw);
        this->inbox.store_timeLine(tw);
    }

    void unfollow(User other)
    {
        if (following.find(other.username) != following.end()) {
            following.erase(other.username);
        } else {
            cout<< "Não seguindo " << other.username << endl;
        }
    }

    void like(int idTw)
    {
        this->inbox.get_tweet(idTw).like(this->username);
    }

    void unfollow_all()
    {
        following.clear();
    }

    void reject_all()
    {
        followers.clear();
    }
    
};

class Controller
{
    private:
    int nextTweetId;
    map <string, User> users;
    map <int, Tweet> tweets;

    public:
    Controller(){}

    void add_user(string username)
    {
        if (users.find(username) == users.end()) {
            users[username] = User(username);
        } 
    }

    friend ostream& operator<<(ostream& os, const Controller& controller)
    {
        os << "Users: " << endl;
        for (auto it = controller.users.begin(); it != controller.users.end(); it++) {
            os << it->second << endl;
        }
        return os;
    }

    void create_tweet(string sender, string msg)
    {
        this->tweets[nextTweetId] = Tweet(nextTweetId, sender, msg);
        this->users[sender].send_tweet(this->tweets[nextTweetId]);
        nextTweetId++;
    }

    void get_user(string username)
    {
        if (users.find(username) != users.end()) {
            cout << users[username] << endl;
        } else {
            cout << "Usuário não encontrado" << endl;
        }
    }

    void send_tweet(string username, string msg)
    {
        this->get_user(username);
        this->create_tweet(username, msg);
        this->users[username].send_tweet(this->tweets[this->nextTweetId]);
    }

    void send_rt(string username, int itwId, string rtMsg)
    {
        this->get_user(username);
        this->tweets[itwId].set_rt(this->tweets[itwId]);
    }

    void rm_user(string username)
    {
        this->get_user(username);
        this->users[username].unfollow_all();
        this->users[username].reject_all();
        this->users.erase(username);
    }
};

int main(){
    return 0;
}
