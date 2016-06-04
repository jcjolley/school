#!/usr/bin/perl -w
# parseTest.pl --- 
# Author: Morgen Peschke <pes11001@byui.edu>
# Created: 10 Feb 2012
# Version: 1.0

######################################################################
#
# Test function for the producer/consumer lab
# 
# Purpose:
#    This program verifies the output of producer/consumer programs as
#    an aid to debugging your program.
#
# Usage:
#    ./validate.pl your_program_name run_time #producers #consumers
#
# Arguments:
#    your_program_name is your actual compiled program, not your
#    source file.
#
#    The rest of the arguments will be passed directly to your
#    program.
#
# Errors:
#    ERROR (FIFO violated) - this means the consumer did not consume
#    the correct value from the buffer. Occasionally this will cause a
#    cascade of errors.
#
#    Error (Empty Buffer) - this generally happens at the beginning of
#    your program, when consumers are taking from a buffer that hasn't
#    been loaded yet.
#
#    Error (Overfull Buffer) - this happens when you put more than 5
#    items in a buffer. Helpfully a list of the current buffer items
#    is printed so you can convince yourself this is the case and fix
#    the problem.
#
#    Other - this program also looks for unused producers and
#    consumers, as well as incorrect max sleep times.
#
######################################################################
use warnings;
use strict;

if (scalar @ARGV != 4)
{
    print "$0 program run_time #producers #consumers".$/;
    exit;
}

my $EXECUTABLE = $ARGV[0];
my $SLEEP_TIME = $ARGV[1];
my $PRODUCERS  = $ARGV[2];
my $CONSUMERS  = $ARGV[3];

my $BUFFER_MAX = 5;

my @buffer;
my @consumerList;
my @producerList;

if (scalar @ARGV) {
    open SOURCE, "\"./$EXECUTABLE\" \"$SLEEP_TIME\" \"$PRODUCERS\" \"$CONSUMERS\" |" or die $!;    
}

my $foundError = 0;
print
    '+---------------------------+----------+-----------+-----------+'.$/;
printf
    '|Output for %16s|sleeping%2d|producers%2d|consumers%2d|'.$/, $EXECUTABLE, $SLEEP_TIME, $PRODUCERS, $CONSUMERS;
print
    '+---------------------------+----------+-----------+-----------+'.$/;
while (<SOURCE>) {
    chomp;
    if (/(\d+)\s+P(\d+)/) {
        my $number = $1;
        my $producer = $2;
        unshift(@buffer, [$number, $producer]);

        ++$producerList[$producer];
    }
    elsif (/(\d+)\s+C(\d+)/) {
        my $number = $1;
        my $consumer = $2;

        if (scalar @buffer) {
            my $oldest = pop @buffer;
            if ($number != $oldest->[0]) {
                
                ++$foundError;
                print "ERROR (FIFO violated): C$consumer ate $number, should have eaten $oldest->[0]$/";
                
            }
            else{
                printf "%3d: P%02d => C%02d$/", $number, $oldest->[1], $consumer.$/;
            }
        }
        else{
            ++$foundError;
            print "ERROR (Empty Buffer): C$consumer consumed a value from an empty buffer$/";
        }

        ++$consumerList[$consumer];
    }
    if (scalar @buffer > $BUFFER_MAX) {
        print "ERROR (Overfull Buffer): Max buffer size of $BUFFER_MAX exceeded, current size = " . (scalar @buffer);
        print ' {'.join (', ', map {$_->[0]} @buffer).'}'.$/;
    }
}

close SOURCE;

print 
    '+--------------------------------------------------------------+'.$/.
    '|                         Summary                              |'.$/.
    '+--------------------------------------------------------------+'.$/;

print 'Max producer: ' . (scalar @producerList - 1);
if (scalar @producerList - 1 != $PRODUCERS) {
    print " (should be $PRODUCERS)";
    ++$foundError;
}

print $/.'Max consumer: ' . (scalar @consumerList - 1);
if (scalar @consumerList - 1 != $CONSUMERS) {
    print " (should be $CONSUMERS)";
    ++$foundError;
}
print $/;

for my $i (1..scalar @producerList - 1) {
    unless (defined $producerList[$i] && $producerList[$i]) {
        print " P$i was never used$/";
        ++$foundError;
    }            
}

for my $i (1..scalar @consumerList - 1) {
    unless (defined $consumerList[$i] && $consumerList[$i]) {
        print " C$i was never used$/";
        ++$foundError;
    }
}

my @grepTest = `grep 150000 $EXECUTABLE.c*`;
unless (scalar @grepTest) {
    print $/.'Timing Error likely'.$/;
    ++$foundError;
}


print $/."Total Errors: $foundError".$/;

exit $foundError;
