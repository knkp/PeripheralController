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

// remember to initialize the first state to START
void RPSS_State_Machine_Controller::handler(){
        switch(currentState){
                case START:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
                        break;
		case GOT_NEW_PATRON:
                        result = scanner.Scan();
                        comm_driver.setMessage(result);
                        comm_driver.send_result();
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
			break;
		case IN_DATABASE:
                        windSensor.waitForBreath();
                        result = breathSensor.check_patron_BAC();
                        comm_driver.setMessage(result);
                        comm_driver.send_result();
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
			break;
		case NOT_IN_DATABASE:
                        cabinetID = cabinet.get_new_cabinet();
                        result = scanner.add_patron_to_DB(cabinetID);
                        comm_driver.setMessage(result);
                        comm_driver.send_result();
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
			break;
		case BREATHALYZER_PASS:
                        result = cabinet.openPatronCabinet();
                        comm_driver.setMessage(result);
                        comm_driver.send_result();
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
                        break;
		case BREATHALYZER_FAIL:
                        // I think I will let the pi manager handle this side since management intervention is required
                        // I may still do that, but during testing it still needs a response
                        comm_driver.setMessage(TAXI_DEPLOYED);
                        comm_driver.send_result();
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
			break;
		case RPSS_DEFAULT:
                        comm_driver.setMessage(DEFAULT_ACK);
                        comm_driver.send_result();
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
			break;
		case MAINTENANCE:
                        // we haven't defined what maintenance mode really does - it is likely that will be handled by the RPSS manager as well.
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
			break;
		default:
                        comm_driver.wait_for_command();
                        currentState = comm_driver.update_State();
                        break;
        }

}
