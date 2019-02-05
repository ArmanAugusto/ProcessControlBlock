/*
 * Project Name:    Process Control Block
 * Description:     This file contains the function definitions and behaviors
 *                  of the PCB header file.
 */

/* 
 * File:            TestPCB.cpp
 * Author:          Arman Augusto
 * ID:              004588816
 * Class:           CS 433 - Operating Systems
 * Assignment:      Assignment 1
 *
 * Created on January 30, 2019, 11:10 AM
 */

#include <iostream>
#include "PCB.h"

PCB::PCB() {
    PID = 99;
    state = "READY";
    priority = 99;
}

PCB::~PCB() {}

//This overloads the = operator, so that we can set one PCB object equal to another, which is important for the insertion and removal process.
PCB& PCB::operator=(PCB& source) {
    this->PID = source.PID;
    this->state = source.state;
    this->priority = source.priority;
}

