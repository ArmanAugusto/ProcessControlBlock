/*
 * Project Name:    Process Control Block
 * Description:     This is the header file for the Process Control Block
 *                  containing all processes for the system
 */

/* 
 * File:            PCB.h
 * Author:          Arman Augusto
 * ID:              004588816
 * Class:           CS 433 - Operating Systems
 * Assignment:      Assignment 1/*
 * Project Name:    Process Control Block
 * Description:     This is the header file for the Process Control Block
 *                  containing all processes for the system
 */

/* 
 * File:            PCB.h
 * Author:          Arman Augusto
 * ID:              004588816
 * Class:           CS 433 - Operating Systems
 * Assignment:      Assignment 1
 *
 * Created on January 30, 2019, 11:16 AM
 */

#ifndef PCB_H
#define PCB_H

#include <iostream>

class PCB {
public:
    int PID;              // Process identification number
    std::string state;    // representing NEW, READY, RUNNING, WAITING, TERMINATED
    int priority;         // priority of processes range with lowest number is highest priority
    PCB();            // Constructor
    ~PCB();           // Deconstructor
    PCB& operator= (PCB& source); //Overloads the = operator
};

#endif /* TESTPCB_H */
