#include "RPSS.h"
#include "Comm_Driver.h"


RPSS_State_Machine_Controller::RPSS_State_Machine_Controller(RPSS_States starting_state){
  currentState = starting_state;
}

RPSS_State_Machine_Controller::~RPSS_State_Machine_Controller(){
  
}

void RPSS_State_Machine_Controller::RPSS_Begin(){
   comm_driver.CommBegin(9600); 
   scanner.FingerScannerBegin();
}

// remember to initialize the first state to GOT_NEW_PATRON instead of default like on the gui handler, it is only t
void RPSS_State_Machine_Controller::handler(){
        switch(currentState){
		case GOT_NEW_PATRON:
                        comm_driver.wait_for_command();
                        comm_driver.setMessage(scanner.Scan());
                        currentState = comm_driver.update_GUI();
			break;
		case IN_DATABASE:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_GUI();
			break;
		case NOT_IN_DATABASE:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_GUI();
			break;
		case BREATHALYZER_PASS:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_GUI();
			break;
		case BREATHALYZER_FAIL:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_GUI();
			break;
		case RPSS_DEFAULT:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_GUI();
			break;
		case MAINTENANCE:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_GUI();
			break;
		default:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_GUI();
                        break;
        }

}
