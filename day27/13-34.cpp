#include "13-34.h"

void Message::add_to_folders(const Message& message)
{
    for (const auto pf: message.folders)
    {
        pf->add_msg(this);
    }
}

void Message::remove_from_folders()
{
    for (const auto pf: this->folders)
    {
        pf->rem_msg(this);
    }
}

Message::Message(const Message& m)
    : contents(m.contents), folders(m.folders)
{
    this->add_to_folders(m);
}

const Message& Message::operator=(const Message& rhs)
{
    this->remove_from_folders();
    this->contents = rhs.contents;
    this->folders = rhs.folders;
    this->add_to_folders(*this);
    return *this;
}

Message::~Message()
{
    this->remove_from_folders();
}

void Message::save(Folder& f)
{
    f.add_msg(this);
    this->folders.insert(&f);
}

void Message::remove(Folder& f)
{
    f.rem_msg(this);
    this->folders.erase(&f);
}

void Folder::add_message(const Folder& f)
{
    for (const auto m: f.messages)
    {
        m->add_dir(this);
    }
}

void Folder::remove_message()
{
    for (const auto m: this->messages)
    {
        m->rem_dir(this);
    }
}

Folder::Folder(const Folder& folder)
    : messages(folder.messages)
{
    this->add_message(*this);
}

Folder::~Folder()
{
    this->remove_message();
}

const Folder& Folder::operator=(const Folder& f)
{
    this->remove_message();
    this->messages = f.messages;
    this->add_message(*this);
    return *this;
}
