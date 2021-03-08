#pragma once
#include "IObserver.h"
#include "Subject.h"



class Observer : public IObserver {
public:


    Observer(Subject* subject) {
        subject_ = subject;
        subject_->Attach(this);
        std::cout << "Hi, I'm the Observer \"" << ++static_number_ << "\".\n";
        this->number_ = static_number_;
    }

    virtual ~Observer();

    void Update(const std::string& message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();
private:
    std::string message_from_subject_;
    Subject* subject_;
    static int static_number_;
    int number_;
};



