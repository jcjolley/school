#!/bin/bash

######################################################################
# verify.em
#
# Written by: Morgen Peschke, April 2012
#
# Purpose:
#    This script verifies the output of shell scripts written for the
#    Operating Systems lab which requires gathering basic system
#    information using the bash shell.
#
# Usage:
#    For invocation information use 'labLinuxInfoVerify.em -h'.  Inside
#    the script itself the following default options can be customized:
#        Line    Option
#        27      Executable used for comparison
#        31      Tolerance for Free Memory variance
#        32      Tolerance for Load Average variance
#        35-44   States modified by command line flags
#        65-72   Colors used when printing
#        77      Usage message
#
######################################################################

# Executable used for comparision
CONTROL="/home/jonesro/cs345/labHandouts/labLinuxInfoSample"

# Percent difference allowed for fluxuating values. Memory is so large
# that the tolerance is rather small.
MEMFREE_TOLERANCE=".1"
LOADAVG_TOLERANCE="100"

# Enables progress reports to stderr
VERBOSE=0

# Creates a version that is kinder by stripping out the blank lines
KIND=0

# Gives feedback as a percent
PERCENT=0

# Colorizes output
COLOR=0

# Constants for colorizing
COLOR_OFF="\e[0m"
COLOR_RED="\e[0;31m"
COLOR_GREEN='\e[0;32m'
COLOR_YELLOW='\e[0;33m'
COLOR_BLUE='\e[0;34m'
COLOR_PURPLE='\e[0;35m'
COLOR_CYAN='\e[0;36m'
COLOR_WHITE='\e[0;37m'

COLOR_IRED='\e[0;91m'
COLOR_IGREEN='\e[0;92m'
COLOR_IYELLOW='\e[0;93m'
COLOR_IBLUE='\e[0;94m'
COLOR_IPURPLE='\e[0;95m'
COLOR_ICYAN='\e[0;96m'
COLOR_IWHITE='\e[0;97m'

# Colors chosen
COLOR_PERCENT_100=$COLOR_WHITE
COLOR_PERCENT_80=$COLOR_IWHITE
COLOR_PERCENT_60=$COLOR_IRED
COLOR_PERCENT_0=$COLOR_RED

COLOR_OK=$COLOR_WHITE
COLOR_ERROR_TITLE=$COLOR_RED
COLOR_ERROR=$COLOR_IRED

function usage
{
    cat <<EOF 
Usage: $0 options

This script verifys the output for the Linux Lab Info project.
Note: this will check the output of all files ending in .sh

OPTIONS:
    -e <program> Set the executable used as a verification source
                 (defaults to labLinuxInfoSample).

    -l <percent> Sets the percent variance allowed for the Load
                 Average data. This is a percent as a float value
                 greater than 0. Ex: "-l 10" means 10% variance.

    -m <percent> Sets the percent variance allowed for the Free Memory
                 data. This value is on the same scale as the percent
                 variance for the Load Average data.

    -v Print progress to standard error (useful when redirecting
       standard out to a file).

    -k Attempts to be kinder by ignoring blank lines. It will try and
       keep them in the output for readability's sake.

    -c Colorizes output to make it easier to read (use 'less -R').

    -p Attempts to rate how close the output corresponds to what it is
       supposed to. The algorithm is very naive, so take it with a
       grain of salt.
EOF
    exit 1;
}

while getopts "vkpche:m:l:" OPTION
do
    case $OPTION in
        v) VERBOSE=1 ;;
        k) KIND=1 ;;
        p) PERCENT=1 ;;
        c) COLOR=1 ;;
        e) CONTROL="$OPTARG" ;;
        m) MEMFREE_TOLERANCE="$OPTARG" ;;
        l) LOADAVG_TOLERANCE="$OPTARG" ;;
        h) usage ;;
    esac
done

# Clear the color codes if we aren't going to use them
if [[ $COLOR -eq 0 ]]; then
    COLOR_PERCENT_100=""
    COLOR_PERCENT_80=""
    COLOR_PERCENT_60=""
    COLOR_PERCENT_0=""
    
    COLOR_OK=""
    COLOR_ERROR=""
    COLOR_ERROR_TITLE=""
fi

# Returns the first word of a line
function key
{
    echo "$*" | sed "s/^\s+//" | cut -d' ' -f1
}

# Returns the part after the ':'
function value
{
    echo "$*" | sed "s/^\s+//" | cut -d':' -f2 | sed "s/^\s+//"
}

# Does a very naive qualitative string comparison
function rateString
{
    # Calculate the difference in number of characters
    local str1=($(echo "$1" | grep -o . ))
    local str2=($(echo "$2" | grep -o . ))
    
    if [[ ${#str1[@]} -gt ${#str2[@]} ]]; then
        local max=${#str1[@]}
    else
        local max=${#str2[@]}
    fi

    local charDiff=$(diff <(echo ${str1[@]}|tr ' ' '\n') <(echo ${str2[@]}|tr ' ' '\n')| grep '^[><]' | wc -l)

    # Calculate the difference in the number of whitespace characters
    str1=${1//[^[:space:]]/}
    str2=${2//[^[:space:]]/}

    if [[ ${#str1} -gt ${#str2} ]]; then
        max=$(( $max + ${#str1} ))
        local spaceDiff=$(( ${#str1} - ${#str2} ))
    else
        max=$(( $max + ${#str2} ))
        local spaceDiff=$(( ${#str2} - ${#str1} ))
    fi

    if [[ $max -eq 0 ]]; then
        local score="--"
    else
        local score=$(echo "scale=2;a=($max - $charDiff - $spaceDiff)/$max * 100;sqrt(a^2)" | bc -q)
    fi
    
    echo "${score%.*}"
}

# It makes typing easier. If more than one value is given as an argument, 
# they all have to be there.
function errorMsg
{
    if [[ $PERCENT -eq 1 ]]; then
        local score=$(rateString "$2" "$3")
        local printColor=""
        if [[ ${score} == "--" ]]; then
            printColor=$COLOR_ERROR_TITLE

        elif [[ ${score} -eq 100 ]]; then
            printColor=$COLOR_PERCENT_100

        elif [[ ${score} -ge 80 ]]; then
            printColor=$COLOR_PERCENT_80
            
        elif [[ ${score} -ge 60 ]]; then
            printColor=$COLOR_PERCENT_60

        else
            printColor=$COLOR_PERCENT_0
        fi

        printf "%b%3s%%:%b $1\n" "${printColor}" "$score" "${COLOR_OFF}"
    else
        echo -e "${COLOR_ERROR_TITLE}ERROR: $1${COLOR_OFF}"
    fi
    if [[ $# -eq 3 ]]; then
        echo -e "\tControl = $2"
        echo -e "\tStudent = $3"
    elif [[ $# -eq 4 ]]; then
        echo -e "\tPrerun  = $2"
        if [[ $3 != "-" ]]; then
            echo -e "\tStudent = $3"
        fi
        echo -e "\tPostrun = $4"
    fi
}

function goodMsg
{
    if [[ $PERCENT -eq 1 ]]; then
        echo -e "${COLOR_PERCENT_100}100%:${COLOR_OFF} $1"
    else
        echo -e "${COLOR_OK}OK:${COLOR_OFF} $1"
    fi
}

if [[ ! -f "$CONTROL" ]]; then
    errorMsg "Control program doesn't exist"
    exit 1
fi

if [[ ! -x "$CONTROL" ]]; then
    errorMsg "Cannot run control program"
    exit 1
fi

# Feedback to user
if [[ $VERBOSE -eq 1 ]]; then
    printf "Generating output files" 1>&2
fi

# This acts as a control for the lowest value
if [[ $KIND -eq 0 ]]; then
    $CONTROL > startVals;
else
    $CONTROL | grep -v "^\s*$" > startVals;
fi

# Generate output files for all of the .sh files in this directory
for FILE in $(ls *.sh)
do
    if [[ $KIND -eq 0 ]]; then
        bash ./"$FILE" > ${FILE%.sh}.out 2>/dev/null
    else
        bash ./"$FILE" | grep -v "^\s*$" > ${FILE%.sh}.out 2>/dev/null
    fi

    if [[ $VERBOSE -eq 1 ]]; then
    # Check for error status
        if [[ $? -eq 127 ]]; then
            printf 'x' 1>&2
        else
            printf '.' 1>&2
        fi
    fi
done

# This acts as a control for the highest value
if [[ $KIND -eq 0 ]]; then
    $CONTROL > endVals;
else
    $CONTROL | grep -v "^\s*$" > endVals;
fi

if [[ $VERBOSE -eq 1 ]]; then
    printf "\n" 1>&2
    printf "Processing output files" 1>&2
fi

for FILE in $(ls *.sh)
do

    if [[ $VERBOSE -eq 1 ]]; then
        printf '.' 1>&2
    fi

    echo '======================================================================'
    echo " Program: $FILE"
    echo '======================================================================'

    if [[ ! -f "${FILE%.sh}.out" ]]; then
        echo -e "${COLOR_ERROR_TITLE}ERROR: $FILE did not execute correctly.${COLOR_OFF}"
        continue
    fi

    #Set the file descriptors to the startVals, this student file, and the endVals
    exec 3<startVals 4<"${FILE%.sh}.out" 5<endVals
   
    oldStudent=""

    READNEXT=1
    while (true)
    do        
        # Read a line from each file, or break if any of the reads fail
        if [[ ${READNEXT} -eq 1 ]]; then
            read -ru3 begin && read -ru4 student && read -ru5 end || break
        else
            oldStudent=""
            READNEXT=1
        fi

        # Skip duplicate lines
        while [[ "$student" == "$oldStudent" ]]
        do
            errorMsg "Duplicate line"
            read -ru4 student
        done

        # If KIND mode is off, check for missing content
        if [[ $KIND -eq 0 ]];then
            if [[ $begin != "" && $student == "" ]]; then
                errorMsg "Probably missing an answer, attempting to find next question."

                while [[ $(key $student) != "What" && $(key $student) != "How" ]]
                do
                    echo -e "${COLOR_ERROR}\tDiscarding from student:${COLOR_OFF} $student"
                    read -ru4 student || break 2
                done

                while [[ $(key $begin) != "What" && $(key $begin) != "How" ]]
                do
                    echo -e "${COLOR_ERROR}\tDiscarding from control:${COLOR_OFF} $begin"
                    read -ru3 begin && read -ru5 end || break 2
                done

                echo ""
            elif [[ $begin == "" && $student != "" ]]; then
                errorMsg "Missing blank line"
                read -ru3 begin && read -ru5 end || break
            fi
        fi

        # Put in a blank line at the appropriate places if we are in kind mode (and it is not the first line)
        if [[ $KIND -eq 1  && $oldStudent != "" && ($(key $begin) == "What" || $(key $begin) == "How") ]]; then
            echo ""
        fi

        oldStudent="$student"        

        # Echo the line if everything is ok
        if [[ $begin == $student && $student == $end ]]; then
            if [[ $begin == "" ]]; then
                echo ""            
            else
                goodMsg "$student"
            fi

        # If the first words don't match, we might have an order or formatting problem (or a missed question).
        elif [[ $(key $begin) != $(key $student) || $(key $student) != $(key $end) ]]; then

            # If we don't match on a question, it's probably a skipped one
            if [[ $(key $begin) == "What" || $(key $begin) == "How" ]]; then                
                errorMsg "Probably missing a question, attempting to find next question." \
                    "$begin" "$student"
                
                # Skip to the next question
                echo -e "${COLOR_ERROR}\tDiscarding from control:${COLOR_OFF} $begin"
                read -ru3 begin && read -ru5 end || break 2

                while [[ $(key $begin) != "What" && $(key $begin) != "How" ]]
                do                
                    echo -e "${COLOR_ERROR}\tDiscarding from control:${COLOR_OFF} $begin"
                    read -ru3 begin && read -ru5 end || break 2
                done
                
                echo ''

                # Don't read in a new line next time
                READNEXT=0
            else
                errorMsg "Mismatch" \
                    "$begin" "$student"
            fi
            
        # Other cases vary by line beginning
        else
            KEY="$(key $student)"
            case "$KEY" in
                # First we convert to seconds by doing string replaces to build our equation, which is send to bc.
                up)
                    beginTime="${begin//up /(}";
                    beginTime="${beginTime// days, / * 24 * 60) + (}"
                    beginTime="${beginTime//:/ * 60) + }"
                    
                    studentTime="${student//up /(}";
                    studentTime="${studentTime// days, / * 24 * 60) + (}"
                    studentTime="${studentTime//:/ * 60) + }"
                    
                    endTime="${end//up /(}";
                    endTime="${endTime// days, / * 24 * 60) + (}"
                    endTime="${endTime//:/ * 60) + }"
                    
                    beginTime=$(echo "$beginTime" | bc -q 2>/dev/null)
                    studentTime=$(echo "$studentTime" | bc -q 2>/dev/null)
                    endTime=$(echo "$endTime" | bc -q 2>/dev/null)

                    # Finally we check if the student value falls between the values given by the opening and closing runs.
                    if [[ $beginTime -le $studentTime && $studentTime -le $endTime ]]; then
                        goodMsg "$student"
                    else
                        errorMsg "Value should fall between Prerun and Postrun numbers" \
                            "$begin" "$student" "$end"
                    fi
                    ;;

                # This fluctuates so we check the % difference
                MemFree:)
                    beginMem=$(echo $(value "$begin")|cut -d' ' -f1)
                    studentMem=$(echo $(value "$student")|cut -d' ' -f1)
                    endMem=$(echo $(value "$end")|cut -d' ' -f1)
                    if [[ $(echo "scale=20;a=$beginMem;b=$endMem;a=(a-b)/b; a=sqrt(a^2);a > ($MEMFREE_TOLERANCE/100)"| bc -q 2>/dev/null) -eq 1 ]]; then
                        errorMsg "Prerun and Postrun differences exceed tolerance for 'MemFree' ($MEMFREE_TOLERANCE%)" \
                            "$begin" "-" "$end"
                    else
                        if [[ $(echo "scale=20;a=$beginMem;b=$studentMem;a=(a-b)/b; a=sqrt(a^2);a > ($MEMFREE_TOLERANCE/100)"| bc -q 2>/dev/null) -eq 1 && \
                            $(echo "scale=20;a=$endMem;b=$studentMem;a=(a-b)/b; a=sqrt(a^2);a > ($MEMFREE_TOLERANCE/100)"| bc -q 2>/dev/null) -eq 1 ]]; then
                            errorMsg "MemFree differs by more than allowable amount ($MEMFREE_TOLERANCE%)" \
                                "$begin" "$student"
                        else
                            if [ "$(echo $(value "$student")|cut -d' ' -f2)" != 'kB' ]; then
                                errorMsg "Incorrect units: should be kB" \
                                    "$begin" "$student"
                            else
                                goodMsg "$student"
                            fi                            
                        fi
                    fi
                    ;;
                
                # This fluctuates so we check the % difference
                Load)
                    beginAvg=($(echo $(value "$begin")|sed 's/,//g'))
                    studentAvg=($(echo $(value "$student")|sed 's/,//g'))
                    endAvg=($(echo $(value "$end")|sed 's/,//g'))
                    
                    if [[ ${#studentAvg[@]} -ne 3 ]]; then
                        errorMsg "Missing Load Average Values" \
                            "$begin" "$student"
                        break
                    fi
                    
                    FLAG=0
                    for i in {0..2}
                    do
                        if [[ $(echo "scale=20;a=${beginAvg[$i]};b=${endAvg[$i]};a=(a-b)/b; a=sqrt(a^2);a > ($LOADAVG_TOLERANCE/100)"| bc -q 2>/dev/null) -eq 1 ]]; then
                            FLAG=1
                            break
                        fi
                    done

                    if [[ $FLAG -eq 1 ]]; then
                        errorMsg "Prerun and Postrun differences exceed tolerance for 'Load Average' ($LOADAVG_TOLERANCE%)" \
                            "$begin" "-" "$end"
                    else
                        FLAG=0
                        for i in {0..2}
                        do
                            if [[ $(echo "scale=20;a=${beginAvg[$i]};b=${studentAvg[$i]};a=(a-b)/b; a=sqrt(a^2);a > ($LOADAVG_TOLERANCE/100)"| bc -q 2>/dev/null) -eq 1 && \
                                $(echo "scale=20;a=${endAvg[$i]};b=${studentAvg[$i]};a=(a-b)/b; a=sqrt(a^2);a > ($LOADAVG_TOLERANCE/100)"| bc -q 2>/dev/null) -eq 1 ]]; then
                                FLAG=1
                                break
                            fi
                        done

                        if [[ $FLAG -eq 1 ]]; then
                            errorMsg "Load Average differs by more than allowable amount ($LOADAVG_TOLERANCE%)" \
                                "$begin" "$student"
                        else
                            goodMsg "$student"
                        fi
                    fi                    
                    ;;
                
                # Check to verify the other values are between the first and last run values
                'USER:'|'SYSTEM:'|'IDLE:'|'Processes'|'Context'|'Read:'|'Written:' )
                    beginVal=$(echo $(value $begin)|cut -d' ' -f1)
                    studentVal=$(echo $(value $student)|cut -d' ' -f1)
                    endVal=$(echo $(value $end)|cut -d' ' -f1)

                    if [[ $(echo "scale=20; ($beginVal <= $studentVal) && ($studentVal <= $endVal)" | bc -q 2>/dev/null) -eq 1 ]]; then

                        if [[ "$KEY" == "Read:" || "$KEY" == "Written:" ]]; then

                            if [ "$(echo $(value "$student")|cut -d' ' -f2)" != 'kB' ]; then
                                errorMsg "Incorrect units: should be kB" \
                                    "$begin" "$student"
                            else
                                goodMsg "$student"
                            fi
                            
                        else
                            goodMsg "$student"
                        fi
                        
                    else
                        errorMsg "Value should fall between Prerun and Postrun numbers" \
                            "$begin" "$student" "$end"
                    fi                                                        
                    ;;
                
                # Catch all for the rest
                *)                    
                    errorMsg "Mismatch" \
                        "$begin" "$student"
                    ;;
            esac
        fi
    done

    # Finally a check for missing content (or extra stuff)
    if [ $(wc -l startVals | cut -d' ' -f1 ) -ne $(wc -l "${FILE%.sh}.out" | cut -d' ' -f1) ]; then
        echo -e "${COLOR_ERROR_TITLE}ERROR: File lengths do not match${COLOR_OFF}"
    fi

    # Close the file descriptors
    exec 3>&- 4>&- 5>&-

done

if [[ $VERBOSE -eq 1 ]]; then
    printf "\n" 1>&2
    echo "Done" 1>&2
fi

# Clean up intermediate files
rm *.out startVals endVals

