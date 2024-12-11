/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       Com_Lcfg.c
********************************************************************************
*   Project/Product: COM programme
*   Title:           Com_Lcfg.c
*   Author:          bo.liu        2010-2011
*                    donger.yang   2012-
********************************************************************************
*   Description:     Define configure data for Com
* 
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
* 
*   Version       Date    Initials      CR#     Descriptions
*   -------   ----------  ----------    ------  -------------------
*   03.00.xx
********************************************************************************
*END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com.h"

/*******************************************************************************
*   for Com_SendSignal M3项目配置
*******************************************************************************/
/*HEAT_STATUS*/
void  COM_SendSig1(COM_CONST void* SigValue)
{
  Ipdu_TxMessage1.Ipdu_TxMessage1.Tx_signal1 = (*(uint8 *)SigValue);
  //Com_SetSendRequest(COM_TXSIGSWS_HEATSTATUS);
}
/*Heat_result*/
void  COM_SendSig2(COM_CONST void* SigValue)
{
  Ipdu_TxMessage1.Ipdu_TxMessage1.Tx_signal2 = (*(uint8 *)SigValue);
  //Com_SetSendRequest(COM_TXSIGSWS_HEATSTATUS);
}
/*软件版本*/
void  COM_SendSig3(COM_CONST void* SigValue)
{
  Ipdu_TxMessage1.Ipdu_TxMessage1.Tx_signal3 = (*(uint8 *)SigValue);
  //Com_SetSendRequest(COM_TXSIGSWS_HEATSTATUS);
}
/*硬件本版*/
void  COM_SendSig4(COM_CONST void* SigValue)
{
  Ipdu_TxMessage1.Ipdu_TxMessage1.Tx_signal4 = (*(uint8 *)SigValue);
  //Com_SetSendRequest(COM_TXSIGSWS_HEATSTATUS);
}
void  COM_SendSig5(COM_CONST void* SigValue)
{
  Ipdu_TxMessage1.Ipdu_TxMessage1.Tx_signal5 = (*(uint8 *)SigValue);
  //Com_SetSendRequest(COM_TXSIGSWS_HEATSTATUS);
}


#if (COM_TXIPDUNUM>=1)
COM_CONST COM_SendSignalFun COM_SendSignalFunPrt[COM_TXSIGNUM]={
  COM_SendSig1,
  COM_SendSig2,
  COM_SendSig3,
  COM_SendSig4,
  COM_SendSig5,
  //M3
};
#endif
/*******************************************************************************
*  M3
 for Com_ReceiveSignal
*******************************************************************************/

void COM_ReceiveSigADS_HeatCommand(void* SigValue)
{
// (*(uint8 *)SigValue) = RxIpduADS_560.IpduADS_560.HEAT_Command;
}

void COM_ReceiveSig_EngineState(void* SigValue)
{
// (*(uint8 *)SigValue) = RxIpdu_117.Ipdu_117.EngineState;
}

//Receive signal HvtSts
void  COM_ReceiveSigHvtSts(void* SigValue)
{
// (*(uint8 *)SigValue) = RxIpdu_193.Ipdu_193.HvtSts;
}

void  COM_ReceiveSigKeyState(void* SigValue)
{
// (*(uint8 *)SigValue) = RxIpdu_2AB.Ipdu_2AB.KeyState;
}

void COM_ReceiveSigVehSpd(void* SigValue)
{
  // uint16_t u16VehSpd = 0;
  // u16VehSpd = RxIpdu_23C.Ipdu_23C.VehSpdMsb<<8;
  // u16VehSpd |= RxIpdu_23C.Ipdu_23C.VehSpdLsb;
  // (*(uint16 *)SigValue) = u16VehSpd;
}
void  COM_ReceiveSig1(void *SigValue) {
    (*(uint8 *)SigValue) = RxIpdu_Message1.Rx_Message1.Rx_signal1;
}

void  COM_ReceiveSig2(void *SigValue) {
    (*(uint8 *)SigValue) = RxIpdu_Message2.Rx_Message2.Rx_signal2;
}


///////////////////////////////////////////////////////////////////
#if (COM_RXIPDUNUM>=1)
COM_CONST COM_ReceivedSignalFun COM_ReceivedSignalFunPrt[COM_RXSIGNUM]={
COM_ReceiveSig1,
COM_ReceiveSig2,

};
#endif
