#=========================================================================
# Newport Proprietary and Confidential    Newport Corporation 2012
#
# No part of this file in any format, with or without modification 
# shall be used, copied or distributed without the express written 
# consent of Newport Corporation.
# 
# Description: This is a Python Script to access CONEX-CC library
#==========================================================================
#Initialization Start
#The script within Initialization Start and Initialization End is needed for properly 
#initializing Command Interface DLL for Conex-CC instrument.
#The user should copy this code as is and specify correct paths here.
import sys

# The CLR module provide functions for interacting with the underlying 
# .NET runtime
import clr
# Add reference to assembly and import names from namespace
clr.AddReferenceToFile("Newport.CONEXCC.CommandInterface.dll")
from CommandInterfaceConexCC import *

import System
#==========================================================================
