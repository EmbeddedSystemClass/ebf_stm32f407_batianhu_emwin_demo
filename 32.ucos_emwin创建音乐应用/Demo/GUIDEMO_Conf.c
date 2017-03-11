/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.32 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to STMicroelectronics International
N.V. a Dutch company with a Swiss branch and its headquarters in Plan-
les-Ouates, Geneva, 39 Chemin du Champ des Filles, Switzerland for the
purposes of creating libraries for ARM Cortex-M-based 32-bit microcon_
troller products commercialized by Licensee only, sublicensed and dis_
tributed under the terms and conditions of the End User License Agree_
ment supplied by STMicroelectronics International N.V.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information

Licensor:                 SEGGER Software GmbH
Licensed to:              STMicroelectronics International NV
Licensed SEGGER software: emWin
License number:           GUI-00429
License model:            Buyout SRC [Buyout Source Code License, signed November 29th 2012]
Licensed product:         -
Licensed platform:        STMs ARM Cortex-M based 32 BIT CPUs
Licensed number of seats: -
----------------------------------------------------------------------
File        : GUIDEMO_Conf.c
Purpose     : Runtime configurability of the GUIDEMO
----------------------------------------------------------------------
*/
/*********************************************************************
*
*       Includes
*
**********************************************************************
*/
#include "GUI.h"
#include "GUIDEMO.h"
#if GUIDEMO_USE_VNC
  #include "GUI_VNC.h"
#endif

/*********************************************************************
*
*       Routine table
*/
static void (* _apfTest[])(void) = {
#if (SHOW_GUIDEMO_SPEEDOMETER                         && GUI_SUPPORT_MEMDEV)
  GUIDEMO_Speedometer,                                                              //  1
#endif
#if (SHOW_GUIDEMO_ZOOMANDROTATE     && GUI_WINSUPPORT && GUI_SUPPORT_MEMDEV)
  GUIDEMO_ZoomAndRotate,                                                            //  2
#endif
#if (SHOW_GUIDEMO_RADIALMENU        && GUI_WINSUPPORT)
  GUIDEMO_RadialMenu,                                                               //  3
#endif
#if (SHOW_GUIDEMO_SKINNING          && GUI_WINSUPPORT && GUI_SUPPORT_MEMDEV)
  GUIDEMO_Skinning,                                                                 //  4
#endif
#if (SHOW_GUIDEMO_BARGRAPH                            && GUI_SUPPORT_MEMDEV)
  GUIDEMO_BarGraph,                                                                 //  5
#endif
#if (SHOW_GUIDEMO_FADING                              && GUI_SUPPORT_MEMDEV)
  GUIDEMO_Fading,                                                                   //  6
#endif
#if SHOW_GUIDEMO_BITMAP
  GUIDEMO_Bitmap,                                                                   //  7
#endif
#if SHOW_GUIDEMO_AATEXT
  GUIDEMO_AntialiasedText,                                                          //  8
#endif
#if (SHOW_GUIDEMO_TRANSPARENTDIALOG && GUI_WINSUPPORT && GUI_SUPPORT_MEMDEV)
  GUIDEMO_TransparentDialog,                                                        //  9
#endif
#if (SHOW_GUIDEMO_WASHINGMACHINE    && GUI_WINSUPPORT && GUI_SUPPORT_MEMDEV)
  GUIDEMO_WashingMachine,                                                           //  10
#endif
#if (SHOW_GUIDEMO_ICONVIEW          && GUI_WINSUPPORT && GUI_SUPPORT_MEMDEV)
  GUIDEMO_IconView,                                                                 //  11
#endif
#if (SHOW_GUIDEMO_IMAGEFLOW         && GUI_WINSUPPORT && GUI_SUPPORT_MEMDEV)
  GUIDEMO_ImageFlow,                                                                //  12
#endif
#if (SHOW_GUIDEMO_TREEVIEW          && GUI_WINSUPPORT)
  GUIDEMO_Treeview,                                                                 //  13
#endif
#if (SHOW_GUIDEMO_LISTVIEW          && GUI_WINSUPPORT)
  GUIDEMO_Listview,                                                                 //  14
#endif
#if SHOW_GUIDEMO_VSCREEN
  GUIDEMO_VScreen,                                                                  //  15
#endif
#if (SHOW_GUIDEMO_GRAPH             && GUI_WINSUPPORT && GUI_SUPPORT_MEMDEV)
  GUIDEMO_Graph,                                                                    //  16
#endif
#if SHOW_GUIDEMO_SPEED
  GUIDEMO_Speed,                                                                    //  17
#endif
#if (SHOW_GUIDEMO_CURSOR            && GUI_SUPPORT_CURSOR)
  GUIDEMO_Cursor,                                                                   //  18
#endif
#if SHOW_GUIDEMO_COLORBAR
  GUIDEMO_ColorBar,                                                                 //  19
#endif
#if (SHOW_GUIDEMO_AUTOMOTIVE                          && GUI_SUPPORT_MEMDEV)
  GUIDEMO_Automotive,                                                               //  20
#endif
  0
};

/*********************************************************************
*
*       GUIDEMO_Config
*/
void GUIDEMO_Config(GUIDEMO_CONFIG * pConfig) {
  pConfig->apFunc   = _apfTest;
  pConfig->NumDemos = GUI_COUNTOF(_apfTest);
  pConfig->Flags    = GUIDEMO_CF_SHOW_SPRITES | GUIDEMO_CF_USE_VNC | GUIDEMO_CF_USE_AUTO_BK | GUIDEMO_CF_SUPPORT_TOUCH;   
  #if GUIDEMO_USE_VNC
    pConfig->pGUI_VNC_X_StartServer = GUI_VNC_X_StartServer;
  #endif
}

/*************************** End of file ****************************/
