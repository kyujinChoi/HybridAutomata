# HybridAutomata
This is a framework for building any kind of FSM. 
# 

Advisor : Kim Kang-hee 

1st Contributor : Choi Kyu-Jin 

Soongsil Univ., Department of Smart Systems Software, Rubicom Laboratory
## What is Hybrid Automata?
  **Finite state machine** with a finite set of continuous variables whose values are described by a set of ordinary differential euqtions

##   Usage
### 
```c++
#include "HybridAutomata.h"
HA_example = new HybridAutomata(int Start_State_id, int Finish_State_id)
```
####   Set State
```c++
HA_example->setState(int State_id, void* function)
```
####   Set Condition
```c++
Condition_Start_2_Finish *cond_example = new Condition_Start_2_Finish();
HA_example->setState(int pre_State_id, Condition cond_example, int post_State_id);
```
## Example Folder
### Build
```c
make clean 
make
```

"Main.cpp" is a exmple code for how to use "HybridAutomata" class
