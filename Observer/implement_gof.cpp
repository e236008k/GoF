#include "Observer.h"
#include <iostream>

/* Subject = Publisher -> 変化を伝える */
class Mailer : public Subject
{

private :

    bool status;
    bool new_Mail_Arrived(){ status = !status; title = "Greetings";message = "Hello,everyone.";return status; }

public :

    std::string title;

    std::string message;

    Mailer(){status = false;}

    void run()
    {
        if( new_Mail_Arrived() )
        {
            Notify();
        }
    }

    /* Default Special Function */
    virtual ~Mailer()                 = default;
    Mailer(const Mailer &)            = default;
    Mailer &operator=(const Mailer &) = default;
    Mailer(Mailer &&)                 = default;
    Mailer &operator=(Mailer &&)      = default;
};

/* Implement Concrete Class */
class Mail_Manager : public Observer
{
public :

    Mail_Manager(){}

    /* Virtual means possible override. */
    virtual void Update(Subject *s)
    {
        Mailer *m = (Mailer *)s;

        std::string str = m->title;
        std::string msg = m->message;

        std::cout << "e-mail title is " + str;
        std::cout << "e-mail message is " + m->message;
    }

    /* Default Special Function */
    virtual ~Mail_Manager()                       = default;
    Mail_Manager(const Mail_Manager &)            = default;
    Mail_Manager &operator=(const Mail_Manager &) = default;
    Mail_Manager(Mail_Manager &&)                 = default;
    Mail_Manager &operator=(Mail_Manager &&)      = default;

};

void run_observer()
{
    Mailer *mail = new Mailer();

    Mail_Manager *manager = new Mail_Manager();

    mail->Attach(manager);

    mail->run();

}

