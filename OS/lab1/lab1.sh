#!/bin/bash

# Lab LinuxInfoT2
# Brother Jones, CS 345, Operating Systems
# Joshua Jolley
############################################################################
#
# Changes made to my code for the re-submission:
#   - My uptime can handle systems with 0 days.
#	 - I added the nice time to the user time.
#   - Updated all but two lines to be field based rather than character based
#   - Fixed a problem with load averages on a recently restarted system
############################################################################
#
############################################################################
# Summary:
#   A simple bash script that displays various system information.
############################################################################

#***********************************************************************
# FUNCTION: getCpuInfo()
# gets the CPUInfo and prints it to the screen
#***********************************************************************
getCpuInfo()
{
   #gather CPU type and model information from /proc/cpuinfo
	local CPUINFO=$(grep 'model\ name' /proc/cpuinfo | uniq | cut -d' ' -f3-)
 
	#print out the CPU info we gathered
	printf "What is the CPU type and model?\n"
   printf "\t%s\n\n" "$CPUINFO"	
}


#***********************************************************************
# FUNCTION: getProcessorInfo()
# Displays information about the number of processors, cores, and ht
#***********************************************************************
getProcessorInfo()
{
   #Store processor info from lscpu in variables   
	local PROCESSORS=$(lscpu | grep Socket | awk '{print $2}')
   local CORES=$(     lscpu | grep Core   | awk '{print $4}')
	local THREADS=$(   lscpu | grep Thread | awk '{print $4}')

	#It's hyperthreaded if there is more than one thread per core
	if [ $THREADS -le 1 ]
	   then
			local HT="not hyperthreaded"
      else
		   local HT="hyperthreaded"
   fi

	#print out the info we gathered
	printf "%s\n" "How many processors on this system?"
	printf "\t%d processor with %d cores each (%s)\n\n" $PROCESSORS $CORES "$HT"
}


#***********************************************************************
# FUNCTION: getKernelInfo
# Displays information about the kernel
#***********************************************************************
getKernelInfo()
{
   local KVERSION=$(uname -r)
	local KDATE=$(rev /proc/sys/kernel/version | cut -c 5- | rev)

	printf "What version of the Linux kernel is being used?\n"
	printf "\tLinux version %s %s\n\n" "$KVERSION" "$KDATE"
}


#***********************************************************************
# FUNCTION: getUptime
# Displays the uptime
#***********************************************************************
getUptime()
{
   local UPTIME_SECONDS=$(awk '{print $1}' /proc/uptime)
	local DAYS=$(   echo " $UPTIME_SECONDS / 86400"      | bc)
	local HOURS=$(  echo "($UPTIME_SECONDS / 3600) % 24" | bc)
	local MINUTES=$(echo "($UPTIME_SECONDS / 60) % 60"   | bc)
	printf "How long has it been since the system was last booted?\n"
	printf "\tup %d days,  %d:%02.0f\n\n" $DAYS $HOURS $MINUTES
}

#***********************************************************************
# FUNCTION: getExecutionTime
# Displays the system, user, and idle time
#***********************************************************************
getExecutionTime()
{
   local USER_HUNDREDTHS=$(grep 'cpu\ ' /proc/stat | awk '{print $2}')
	local NICE_HUNDREDTHS=$(grep 'cpu\ ' /proc/stat | awk '{print $3}')
	local TUSER=$(echo "scale=2; ($USER_HUNDREDTHS + $NICE_HUNDREDTHS) / 100.0" | bc)
   
   local SYS_HUNDREDTHS=$(grep 'cpu\ ' /proc/stat | awk '{print $4}')
	local TSYS=$(echo "scale=2; $SYS_HUNDREDTHS / 100.0" | bc)
	
   local IDLE_HUNDREDTHS=$(grep 'cpu\ ' /proc/stat | awk '{print $5}')
	local TIDLE=$(echo "scale=2; $IDLE_HUNDREDTHS / 100.0" | bc)

	printf "How much CPU execution time has been spent in user, system and idle modes?\n"
	printf "\tUSER: %.2f seconds\n"   $TUSER
	printf "\tSYSTEM: %.2f seconds\n" $TSYS
	printf "\tIDLE: %.2f seconds\n\n" $TIDLE
}


#***********************************************************************
# FUNCTION: getMemoryInfo
# Displays total and currently available memory on the machine
#***********************************************************************
getMemoryInfo()
{
   local MEMTOTAL=$(grep MemTotal /proc/meminfo)
	local MEMFREE=$(grep MemFree /proc/meminfo)

	printf "How much memory is on the machine?\n"
	printf "\t%s\n\n" "$MEMTOTAL"
	
	printf "How much memory is currently available?\n"
	printf "\t%s\n\n" "$MEMFREE"
}

#***********************************************************************
# FUNCTION: getDiscInfo
# Displays how many kB have been written and read since the last reboot 
#***********************************************************************
getDiskInfo()
{
   local IOREAD=$(iostat -k | grep sda | awk '{print $5}')
	local IOWRITTEN=$(iostat -k | grep sda | awk '{print $6}')

	printf "How many kBytes have been read and written to the disk since the last reboot?\n"
	printf "\tRead: %d kB\n" $IOREAD
	printf "\tWritten: %d kB\n\n" $IOWRITTEN
}

#***********************************************************************
# FUNCTION: getProcessesCreated
# Displays the number of processes created since the last reboot
#***********************************************************************
getProcessesCreated()
{
   local NUM_PROCESSES=$(grep processes /proc/stat | cut -d' ' -f2-)

	printf "How many processes have been created since the last reboot?\n"
	printf "\tProcesses created: %d\n\n" $NUM_PROCESSES
}

#***********************************************************************
# FUNCTION: getContextSwitches
# Displays the number of context switches since the last reboot
#***********************************************************************
getContextSwitches()
{
   local NUM_SWITCHES=$(grep ctxt /proc/stat | cut -d' ' -f2-)

	printf "How many context switches have been performed since the last reboot?\n"
	printf "\tContext switches: %d\n\n" $NUM_SWITCHES
}

#***********************************************************************
# FUNCTION: getContextSwitches
# Displays the number of context switches since the last reboot
#***********************************************************************
getLoadAverages()
{
   local LOAD_AVERAGES=$(awk '{print $1 " " $2 " " $3}' /proc/loadavg)

   printf "What is the current load average for the last 1, 5 and 15 minutes?\n"
	printf "\tLoad average: %s\n" "$LOAD_AVERAGES"
}

#***********************************************************************
# FUNCTION: Main
# Our driver 
#***********************************************************************
main()
{
   getCpuInfo
	getProcessorInfo
	getKernelInfo
	getUptime
	getExecutionTime
	getMemoryInfo
	getDiskInfo
	getProcessesCreated
	getContextSwitches
	getLoadAverages
}

#call main
main
