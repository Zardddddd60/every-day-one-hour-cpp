#pragma once

#include <set>
#include <string>

class Folder;

class Message
{
    public:
        friend Folder;
        friend void swap(Message& lhs, Message& rhs);
    public:
        Message(const std::string& str = ""):
            contents(str) {}
        Message(const Message&);
        const Message& operator=(const Message&);
        ~Message();

        void save(Folder&);
        void remove(Folder&);

    private:
        // 遍历message中的folder，都添加这个message
        void add_to_folders(const Message&);
        void remove_from_folders();
        void add_dir(Folder* f) { folders.insert(f); };
        void rem_dir(Folder* f) { folders.erase(f); };

    private:
        std::string contents;
        std::set<Folder*> folders;
};

class Folder
{
    public:
        friend Message;
        friend void swap(Folder&, Folder&);
    public:
        Folder() = default;
        Folder(const Folder&);
        const Folder& operator=(const Folder&);
        ~Folder();
    private:
        void add_message(const Folder&);
        void remove_message();
        void add_msg(Message* m) { messages.insert(m); }
        void rem_msg(Message* m) { messages.erase(m); };
    private:
        std::set<Message*> messages;
};

inline void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    lhs.remove_from_folders();
    rhs.remove_from_folders();
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    lhs.add_to_folders(lhs);
    rhs.add_to_folders(rhs);
}

inline void swap(Folder& lhs, Folder& rhs)
{
    using std::swap;
    lhs.remove_message();
    rhs.remove_message();

    swap(lhs.messages, rhs.messages);

    lhs.add_message(lhs);
    rhs.add_message(rhs);
}
