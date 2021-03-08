#include "Observer.h"
#include "Subject.h"


int Observer::static_number_ = 0;

    Observer::~Observer() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Observer::Update(const std::string& message_from_subject) {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void Observer::RemoveMeFromTheList() {
        subject_->Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    void Observer::PrintInfo() {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }




