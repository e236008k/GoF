#include "state.h"

/* Define Each Status Class */
class LSM_Init_State : public State
{
public:

    void Handle1() override;

    void Handle2() override{ std::cout << "LSM_Init\n"; };

};

class LSM_Config_State : public State
{
    void Handle1() override{  };

    void Handle2() override{ std::cout << "LSM_Config Status\n"; };
};

class LSM_Measure_State : public State
{
    void Handle1() override;

    void Handle2() override{ std::cout << "LSM_Measure Status\n"; };
};

