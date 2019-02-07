/* 
 * File:            PCB.h
 * Author:          Arman Augusto
 * Project Name:    Process Control Block
 * Description:     This is the header file for the Process Control Block
 *                  containing all processes for the system
 */

#ifndef PCB_H
#define PCB_H

#include <iostream>

class PCB {
public:
    int PID;            // Process identification number
    std::string state;  // representing NEW, READY, RUNNING, WAITING, TERMINATED
    int priority;       // priority of processes range with lowest number is highest priority
    PCB();              // Constructor
    ~PCB();             // Deconstructor
    PCB& operator= (PCB& source); //Overloads the = operator
};

#endif /* TESTPCB_H */
