#ifndef INC_WS3122Def_HH
#define INC_WS3122Def_HH


#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>

#include "WSTypes.hh"


class BasicWave
{

public:
  BasicWave();
  // BasicWave(const BasicWave& bwv);
  virtual ~BasicWave();

  friend std::ostream& operator<<(std::ostream& os, const BasicWave &bwv);
  
  // BasicWave & operator=(const BasicWave &bwv);
  
  void Init();
  void Print(std::string in);

  void buildCommand();
  void clearCommand();
  
  const std::string     getFullCommand()             { return fullCommandStream.str();};
   
  const std::string       getHeaderPath()            { return headerPathMap[headerPathID]; };
  
  const EBasicWaveType_t  getWaveTypeID()            { return waveTypeID; };
  const std::string       getWaveTypeString()        { return waveTypeString;};
  
  const double          getFrequencyVal()            { return frequencyVal; };
  const double          getAmplifierVal()            { return amplifierVal; };
  const double          getOffsetVal()               { return offsetVal; };
  
  const double          getSymmetryVal()             { return symmetryVal; };
  
  const double          getDutyCycleVal()            { return dutyCycleVal; };
  
  const double          getPhaseVal()                { return phaseVal; };
  const double          getStdDevVal()               { return stdDevVal; };
  const double          getMeanVal()                 { return meanVal; };
  
  const double          getWidthVal()                { return widthVal; };
  const double          getRiseVal()                 { return riseVal; };
  const double          getFallVall()                { return fallVal; };
  const double          getDelayVal()                { return delayVal; };
  

  void    setHeaderPath(EHeaderPath_t id)        {  headerPathID = id; };
  
  void    setWaveTypeID(EBasicWaveType_t id) ;   
  
  void    setFrequencyVal(double val)          { frequencyVal = val; };
  void    setAmplifierVal(double val)          { amplifierVal = val; };
  void    setOffsetVal(double val)             { offsetVal    = val; };
 
  void    setPhaseVal(double val)              { phaseVal     = val; };
  void    setStdDevVal(double val)             { stdDevVal    = val; };
  void    setMeanVal(double val)               { meanVal      = val; };

  void    setWidthVal(double val)              { widthVal     = val; };
  void    setRiseVal(double val)               { riseVal      = val; };
  void    setFallVal(double val)               { fallVal      = val; };
  void    setDelayVal(double val)              { delayVal     = val; };
 
  void    setSymmetryVal(double val)           { symmetryVal  = val; };
  
  void    setDutyCycleVal(double val)          { dutyCycleVal = val; };

  void    setCarrierFlag(bool in)              { carrier_flag = in; };
  
  bool    IsFrequency()          const {return frequency_flag;};
  bool    IsAmplifier()          const {return amplifier_flag;};
  bool    IsOffset()             const {return offset_flag;};
  
  bool    IsSymmetry()           const {return symmetry_flag;};
  bool    IsDutyCycle()          const {return duty_cycle_flag;};

  bool    IsWidth()              const {return width_flag;};
  bool    IsRise()               const {return rise_flag;};
  bool    IsFall()               const {return fall_flag;};
  bool    IsDelay()              const {return delay_flag;};
  
  bool    IsPhase()              const {return phase_flag;};
  bool    IsStdDev()             const {return std_dev_flag;};
  bool    IsMean()               const {return mean_flag;};

  bool    IsCarrier()            const {return carrier_flag;};
  
private:

  std::string            headerPath;
  
  EBasicWaveType_t       waveTypeID;
  BasicWaveMap           waveTypeMap;
  
  EWaveParameter_t       waveParmeterID;
  WaveParameterMap       waveParamterMap;
  
  EHeaderPath_t          headerPathID;
  HeaderPathMap          headerPathMap;

  // ECmdSymbol_t           cmdSymbolID;
  // CmdSymbolMap           cmdSymbolMap;

  double              frequencyVal;   
  double              amplifierVal;   
  double              offsetVal;
  double              phaseVal;

  double              widthVal; 
  double              riseVal;  
  double              fallVal;  
  double              delayVal;
    
  double              symmetryVal;    
  double              stdDevVal;
  double              meanVal;  
  
  double              dutyCycleVal;

  
  bool                frequency_flag;
  bool                amplifier_flag;
  bool                offset_flag;
  bool                phase_flag;
  
  bool                width_flag;
  bool                rise_flag;
  bool                fall_flag;
  bool                delay_flag;
  
  bool                symmetry_flag;
  bool                std_dev_flag;
  bool                mean_flag;
  
  bool                duty_cycle_flag;

  bool                carrier_flag;


  std::string         waveTypeString;
  std::string         frequencyUnit;  // Hz, [1e-6, depends on the model]
  std::string         amplifierUnit;  // V   [2mVpp, 20Vpp] for WS3000
  std::string         offsetUnit;     // V   [, depends on the model]
  std::string         dutyCycleUnit;  // percent if WVTP SQUARE, [20,80], if WVTP PULSE [0.1,99.9]
  std::string         delayUnit;
  //  char standardDeviationUnit [maxUnitStringLength]; // V [0.5m, 1.599] valid only when WVTP NOISE
  
  std::ostringstream fullCommandStream;

  const std::string getBasicWaveCmdSnip();
  const std::string getWaveCmdSnip(bool cmd_flag, EWaveParameter_t id, double value, bool front_prefix);
  void set_flags(EBasicWaveType_t id);
   
};



class BurstWave
{

public:
  BurstWave();
  virtual ~BurstWave();
  
  void Init();
  void Print(std::string in);

  void buildCommand();
  void clearCommand();
  
  const std::string getFullCommand()   { return fullCmdStream.str(); };
  const std::string getHeaderPath()    { return headerPathMap[headerPathID]; };
  
  const EBasicWaveType_t  getCarrierWaveTypeID() { return carrierWaveTypeID; };
  const std::string   getCarrierWaveTypeString() { return carrierWaveTypeString;};
 

  const double  getPeriodVal()       { return periodVal; };
  const double  getStartPhaseVal()   { return startPhaseVal; };
  const double  getDelayVal()        { return delayVal; };
  const double  getCycleTimeVal()    { return cycleTimeVal; };
  const std::string getCarrierCmd()  { return carrierCmdString; };

  
  void setCarrierCmd        (std::string in);
  void setHeaderPath        (EHeaderPath_t id)  { headerPathID = id; };
  
  void setCarrierWaveTypeID (EBasicWaveType_t id);
  void setWaveState         (EWaveState_t     id);
  void setBurstMode         (EBurstMode_t     id);
  void setTriggerSrc        (ETriggerSrc_t    id);
  void setTriggerMode       (ETriggerMode_t   id);
  void setPolarity          (EPolarityMap_t   id);
  void setEdge              (EEdgeModeMap_t   id);

  
  void setPeriodVal     (double val)   { periodVal     = val; };
  void setStartPhaseVal (double val)   { startPhaseVal = val; };
  void setDelayVal      (double val)   { delayVal      = val; };
  void setCycleTimeVal  (double val)   { cycleTimeVal  = val; };

  void setEnable(bool in) ;
 
  bool IsEnable()       const {return enable_flag;};
  bool IsCarrierCmds()  const {return carrierCmd_flag;};

  bool IsBurstMode()    const {return gateNcyc_flag;}
  bool IsPeriod()       const {return period_flag;};
  bool IsStartPhase()   const {return startPhase_flag;};
  bool IsDelay()        const {return delay_flag;};
  bool IsCycleTime()    const {return cycleTime_flag;};
  
  int set_flags(EBasicWaveType_t wave_type_id, EBurstMode_t gate_ncyc_id, ETriggerSrc_t trigger_src_id);
  
private:


  EHeaderPath_t       headerPathID;
  HeaderPathMap       headerPathMap;
  
  EBasicWaveType_t    carrierWaveTypeID;
  BasicWaveMap        carrierWaveTypeMap;
  std::string         carrierWaveTypeString;
  
  EBurstMode_t        burstModeID;
  std::string         burstModeString;
  
  ETriggerSrc_t       triggerSrcID;
  std::string         triggerSrcString;
   

  ETriggerMode_t      triggerModeID;
  std::string         triggerModeString;

  EEdgeModeMap_t      edgeModeID;
  std::string         edgeModeString;

  EPolarityMap_t      polarityID;
  std::string         polarityString;
  

  EWaveState_t        waveStateID;
  std::string         waveStateString;


  
  
  
  ECmdSymbol_t        cmdSymbolID;
  CmdSymbolMap        cmdSymbolMap;

  BurstParameterMap   burstParameterMap;
  
  bool                enable_flag;
  bool                carrierCmd_flag;
  bool                fullCmdStream_flag;

  
  bool                period_flag;      // PRD
  bool                startPhase_flag;  // STPS
  bool                delay_flag;       // DLAY
  bool                cycleTime_flag;   // TIME
  
  bool                gateNcyc_flag;    // GATE_NSCYC
  bool                triggerSrc_flag;  // TRSR
  bool                triggerMode_flag; // TRMD
  bool                edge_flag;        // EDGE
  bool                polarity_flag;    // PLRT

  
  bool                mtrig_flag;       // MAN
  
  
  
  double              periodVal;   
  double              startPhaseVal;   
  double              delayVal;
  double              cycleTimeVal;


  std::string         periodUnit;
  std::string         delayUnit;
   
  std::ostringstream fullCmdStream;

  std::string        carrierCmdString;
  
  const std::string getBurstCmdSnip();
  const std::string getCmdSnip(bool cmd_flag, EBurstParameter_t id,  bool front_prefix, double value);
  const std::string getCmdSnip(bool cmd_flag, EBurstParameter_t id,  bool front_prefix);
  
};


#endif

