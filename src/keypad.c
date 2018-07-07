/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "keypad.h"
/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
int keypad_scan_tasks=0;
long int keypad_delay=0;
int current_line=1;

/*
 * char Keypad_scan(void)
{
    char dat_return='Q';
    
    switch(keypad_scan_tasks)
    {
        case 0:
        {
            key_L1_outOn();key_L2_outOff();key_L3_outOff();key_L4_outOff();
            keypad_scan_tasks=4;
            break;
        }
        case 1:
        {
            key_L1_outOff();key_L2_outOn();key_L3_outOff();key_L4_outOff();
            keypad_scan_tasks=4;
            break;
        }
        case 2:
        {
            key_L1_outOff();key_L2_outOff();key_L3_outOn();key_L4_outOff();
            keypad_scan_tasks=4;
            break;
        }
        case 3:
        {
            key_L1_outOff();key_L2_outOff();key_L3_outOff();key_L4_outOn();
            keypad_scan_tasks=4;
            break;
        }
        
        case 4:
        {
            keypad_delay++;
            if(keypad_delay>0x0500)
            {
                keypad_delay=0;
                MLed2Toggle();
                
                if(key_C1_inStateGet()==1)
                {
                    delay_ms1(200);
                    if(current_line==0)dat_return= 'A';
                    if(current_line==1)dat_return= 'B';
                    if(current_line==2)dat_return= 'C';
                    if(current_line==3)dat_return= 'D';                
                }
                else if(key_C2_inStateGet()==1)
                {
                    delay_ms1(200);
                    if(current_line==0)dat_return= '3';
                    if(current_line==1)dat_return= '6';
                    if(current_line==2)dat_return= '9';
                    if(current_line==3)dat_return= '#';                
                }
                else if(key_C3_inStateGet()==1)
                {
                    delay_ms1(200);
                    if(current_line==0)dat_return= '2';
                    if(current_line==1)dat_return= '5';
                    if(current_line==2)dat_return= '8';
                    if(current_line==3)dat_return= '0';                
                }
                else if(key_C4_inStateGet()==1)
                {
                    delay_ms1(200);
                    if(current_line==0)dat_return= '1';
                    if(current_line==1)dat_return= '4';
                    if(current_line==2)dat_return= '7';
                    if(current_line==3)dat_return= '*';                
                }
                
                if(current_line==3)current_line=0; else current_line++;
                
                keypad_scan_tasks=current_line;
                
            }
            break;
        }
       
        default:
        {
            // TODO: Handle error in application's state machine. 
            keypad_scan_tasks=0;
            dat_return= 'Q';
            break;
        }
    }
    return dat_return;
}
*/
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
int global_data;


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 *//*
static int ExampleLocalFunction(int param1, int param2) {
    return 0;
}
*/

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
int ExampleInterfaceFunction(int param1, int param2) {
    return 0;
}


/* *****************************************************************************
 End of File
 */
