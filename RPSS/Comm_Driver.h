/*
Author: Stephen Copeland

This define's the communications driver, it also defines the message command and there associated char
*/

#pragma once

#include "RPSS.h"
#include "RPSS_States.h"

// RPSS Messages
#define CHECK_DATABASE 'a'
#define REGISTER_PATRON 'b'
#define USER_NOT_IN_DATABASE 'c'
#define USER_IN_DATABASE 'h'
#define CHECK_BREATHALYZER 'd'
#define BREATHALYZER_TEST_PASS 'e'
#define BREATHALYZER_TEST_FAIL 'f'
#define MAINTENANCE_MODE 'g'
#define PATRON_REGISTERED_SUCCESSFULLY 'i'
#define RELEASE_PATRON 'j'
#define RPSS_RELEASED 'k'
#define TAXI_DEPLOYED 'l'
#define DEFAULT_STATUS 'm'
#define DEFAULT_ACK 'n'
#define RPSS_ERROR_STATE 'o'




class Comm_Driver{
 
  char message;
  public:
  Comm_Driver();
  ~Comm_Driver(void);

  void CommBegin(int);
  // communication driver is implemented on the same way on the tiva
  
  void setMessage(char);
  RPSS_States update_GUI(void);
  void wait_for_command(void);
  void send_result(char);
  
};
