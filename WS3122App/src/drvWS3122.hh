#ifndef INC_DRVWS3122_HH
#define INC_DRVWS3122_HH

/*
 * drvWS3122.hh
 *
 * Author: Jeong Han Lee
 *
 * Created Wednesday, February 28 21:20:54 CET 2018
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>



#include <asynPortDriver.h>
#include <asynOctetSyncIO.h>


//#include "WS3122Def.hh"
#include "snipDrvAsynUSBTMC.hh"

#define MAX_BUF_SIZE            65536
#define TIMEOUT                 2

#define MAX_ASYN_ADDRESS        0
#define MAX_BUFFER_SIZE	        512

#define DevIDNString                 "DEV_IDN"                   // asynOctet      w  
#define DevManufacturerString        "DEV_MANUFACTURER"          // asynOctet,    r/o manufacturer name 
#define DevModelString               "DEV_MODEL"                 // asynOctet,    r/o model name 
#define DevSerialNumberString        "DEV_SERIAL_NUMBER"         // asynOctet,    r/o serial number 


#define CmdHeaderPathString          "CMD_HEADER_PATH"
#define CmdPhaseInvertString         "CMD_PHASE_INVERT"              // asynParamInt32
#define CmdScreenSaveString          "CMD_SCREEN_SAVE"
#define CmdClockSourceString         "CMD_CLOCK_SOURCE"              // asynParamInt32


class drvWS3122 : public asynPortDriver {
public:
  drvWS3122(const char *portName, const char *asynUSBTMCPortName);
  virtual ~drvWS3122();


  //virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
  //virtual asynStatus readOctet (asynUser *pasynUser, char *value, size_t maxChars, size_t *nActual, int *eomReason);
  virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
  virtual asynStatus writeOctet(asynUser *pasynUser, const char *value, size_t 	nChars, size_t *nActual);
  
  friend std::ostream& operator<<(std::ostream& os, const drvWS3122 &ws);

protected:

  /** Values used for pasynUser->reason, and indexes into the parameter library. */
  int  devIdentification_;
#define FIRST_PARAM devIdentification_
  int  devManufacturer_;
  int  devModel_;
  int  devSerialNumber_;
  int  cmdHeaderPath_;
  int  cmdPhaseInvert_;
  int  cmdScreenSave_;
  int  cmdClockSource_;
#define LAST_PARAM cmdClockSource_

  
private:


  asynStatus Init();
  
  asynUser	*usbTmcAsynUser;
  std::string    asynUsbTmcPortName;
  
  const char* getUsbTmcPortName() const { return asynUsbTmcPortName.c_str();};
  asynStatus  usbTmcWriteRead(char *sendBuffer, char *recvBuffer, int &recvBufSize, double timeout=TIMEOUT);
  asynStatus  usbTmcWrite(std::string sendBuffer, double timeout=TIMEOUT);
  //asynStatus usbTmcRead(double timeout=TIMEOUT);
  //asynStatus usbTmcWrite(double timeout=TIMEOUT);

  asynStatus write_read    (std::string cmd);
  asynStatus SetClockSource(epicsInt32 value);
  asynStatus SetPhaseInvert(epicsInt32 value);
  asynStatus SetScreenSave (epicsInt32 value);
  
  
  asynInterface *pasynInterface;
  drvPvt        *pasynDrvPvt;

  asynStatus report_device_information(FILE *fp);
  asynStatus set_device_information();
  
};

#define NUM_PARAMS ((int)(&LAST_PARAM - &FIRST_PARAM + 1))

#endif 
