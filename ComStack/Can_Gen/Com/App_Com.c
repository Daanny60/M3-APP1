/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       App_Com.c
********************************************************************************
*   Project/Product: COM programme
*   Title:           App_Com.c
*   Author:          bo.liu        2010-2011
*                    donger.yang   2012-
********************************************************************************
*   Description:     Defination of Interface for Application Layer
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
#include "demm.h"
#include "App_Can.h"
#include "App_Keyboard.h"
#include "App_WheelHeat.h"
uint8_t dtc_index;
void Com_TxIpduCallout(PduIdType PduId) {
    if (COM_TXIPDU_Message1 == PduId) {
        Ipdu_TxMessage1._c[7] = (0x09 & _dem_get_state(dtc_index++));
        if (dtc_index == NUM_OF_DTC) {
            dtc_index = 0;
        }
    }
}

void Com_RxIpduCallout(PduIdType PduId) {
}



//////////////////////////////////////////////////////////////////

void AppIpduSWS_4A8_TxTOIndication(void) {
    AppIpduSWS_4A8_TOProcess();
}

void AppIpduSWS_3B0_TxTOIndication(void) {
    AppIpduSWS_3B0_TOProcess();
}

void AppIpduSWS_429_TxTOIndication(void) {
    AppIpduSWS_429_TOProcess();
}
///////////////////////////////////////////////

void AppIpdu_Message1_TxTOIndication(void) {
    AppIpduSWS_36A_TOProcess();
}
void AppTxIpdu_Message1_Conf(void) {
    AppIpduSWS_36A_ConfProcess();
}



void AppIpduSWS_4A8_Conf(void) {
    //AppIpduSWS_4A8_ConfProcess();
}

void AppIpduSWS_3B0_Conf(void) {
    //AppIpduSWS_3B0_ConfProcess();
}

void AppIpduSWS_429_Conf(void) {
    //AppIpduSWS_429_ConfProcess();
}
//////////////////////////////////////

/* ---------------------------------------------------------------------M3
1.
2.
----------------------------------------------------------------------- */

//接收加热按键是否按下
void AppIpdu_Message1_Ind(void) {
    AppIpduADS_2CD_Ind_Process();
}
//接收发动机状态
void AppIpdu_Message2_Ind(void) {
    AppIpdu_117_Ind_Process();
}

void AppIpdu_193_Ind(void) {
    //AppIpdu_193_Ind_Process();
}
void AppIpdu_1F4_Ind(void) {
    // AppIpdu_1F4_Ind_Process();
}

void AppIpdu_23C_Ind(void) {
    // AppIpdu_23C_Ind_Process();
}




void AppIpduADS_29C_Ind(void) {
    (void)AppIpduADS_29C_Ind_Process();
}

void AppIpduBCM_12D_Ind(void) {
    (void)AppIpduBCM_12D_Ind_Process();
}

void AppIpduLBC_4BF_Ind(void) {
    (void)AppIpduLBC_4BF_Ind_Process();
}

void AppIpduMPC_316_Ind(void) {
    (void)AppIpduMPC_316_Ind_Process();
}

void AppIpduMED_385_Ind(void) {
    (void)AppIpduMED_385_Ind_Process();
}

void AppIpduFGM_49A_Ind(void) {
    (void)AppIpduFGM_49A_Ind_Process();
}


void AppIpduCSM_0A2_Ind(void) {
    (void)AppIpduCSM_0A2_Ind_Process();
}

void AppIpduRBC_4E6_Ind(void) {
    (void)AppIpduRBC_4E6_Ind_Process();
}

//////////////////////////////////////////////////////

/* 接收节点超时，DTC报节点故障
----------------------------------------------------------------------M3
----------------------------------------------------------------------- */
void AppRxIpdu_Message1_TimeOutInd(void) {
    AppRxIpdu_Message1_TimeOutProcess();
}
void AppRxIpdu_Message2_TimeOutInd(void) {
    AppRxIpdu_Message2_TimeOutProcess();
}

void AppRxIpdu_193_TimeOutInd(void) {
    AppRxIpdu_193_TimeOutProcess();
}

/////////////////////////////////////////////////////////////////////