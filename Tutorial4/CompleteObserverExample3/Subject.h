#pragma once
#include "ISubject.h"
#include "IObserver.h"

class Subject : public ISubject {
public:
    virtual ~Subject();
    Subject(std::string);

    /**
     * The subscription management methods.
     */
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void Notify() override;

    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();

    /**
     * Usually, the subscription logic is only a fraction of what a Subject can
     * really do. Subjects commonly hold some important business logic, that
     * triggers a notification method whenever something important is about to
     * happen (or after it).
     */
    void SomeBusinessLogic();

private:
    std::list<IObserver*> list_observer_;
    std::string message_;
};
