#include "HybridAutomata.h"
#include <stdio.h>
enum    // for State ID
{
    START,
    OFF,
    ON,
    QUIT,
    FINISH
};

HybridAutomata *HA_example;
char key_input=0;

///////////////////// Conditions //////////////////////

class COND_OFF2ON : public Condition
{
public:
  bool check(HybridAutomata *HA)
  {
    if (key_input != 'q')
    {
      //cout << "COND_OFF2ON Satisfied!" << endl;
      return true;
    }
    else
      return false;
  }
};

class COND_ON2OFF : public Condition
{
public:
  bool check(HybridAutomata *HA)
  {
    if (key_input != 'q')
    {
      //cout << "COND_ON2OFF Satisfied!"  << endl;
      return true;
    }
    else
      return false;
  }
};

class COND_ALL2FIN : public Condition
{
public:
  bool check(HybridAutomata *HA)
  {
    if (key_input == 'q')
    {
      //cout << "COND_ALL2FIN Satisfied!"  << endl;
      return true;
    }
    else
      return false;
  }
};
/////////////////////////////////////////////////////


///////////////////// States //////////////////////

int behavior_off()
{
    cout<<"##############\n";
    cout<<"# Switch Off #\n";
    cout<<"##############\n\n";
    return 2;
}
int behavior_on()
{
    cout<<"#############\n";
    cout<<"# Switch On #\n";
    cout<<"#############\n\n";
    return 3;
}
int behavior_finish()
{
    cout<<"#############\n";
    cout<<"# Bye Bye~~ #\n";
    cout<<"#############\n\n";
    return 1;
}

///////////////////////////////////////////////////
void myFlush() // to flush keyboard buffer
{
  while(getchar() != '\n');
}
void init_state_machine_for_EXAMPLE()
{
  HA_example = new HybridAutomata(START, FINISH);
  HA_example->setState(OFF, behavior_off);
  HA_example->setState(ON, behavior_on);
  HA_example->setState(FINISH, behavior_finish);

  COND_OFF2ON *cond_off2on = new COND_OFF2ON();
  COND_ON2OFF *cond_on2off = new COND_ON2OFF();
  COND_ALL2FIN *cond_all2fin = new COND_ALL2FIN();

  HA_example->setCondition(START, NULL, OFF);
  HA_example->setCondition(OFF, cond_off2on, ON);
  HA_example->setCondition(ON, cond_on2off, OFF);
  HA_example->setCondition(ON, cond_all2fin, FINISH);
  HA_example->setCondition(OFF, cond_all2fin, FINISH);
}

int main()
{
  int result = -1;
    init_state_machine_for_EXAMPLE();
    
    while(1)
    {
      cout << "--------------------------------------\n";
      cout << "press any key + enter, to toggle switch('q' to quit)\n";
      key_input = getchar();
      //myFlush();

      result = HA_example->operate();
      printf("result = %d\n",result);
      if(HA_example -> curState == FINISH) break;
    }
}

