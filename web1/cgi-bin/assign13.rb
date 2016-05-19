#!/usr/bin/ruby -w
#######################################################################
# Program:
#    Assignment 11, Ruby forms processing
#    Brother Ercanbrack, CS 213
# Author:
#    Joshua Jolley 
# Summary:
#    Demonstrates the use of Ruby to process a form
#######################################################################
require "cgi"

##############################################################
# FUNCTION addLine
# Adds a line to the array of lines from the file
##############################################################
def addLine(cgi, lines)

  line = cgi['fname'];
  line += " ";
  line += cgi['lname'];
  line += " ";
  line += cgi['id']
  line += " ";
  line += cgi['skill'];
  line += " ";
  line += cgi['instrument']
  line += " ";
  line += cgi['location'];
  line += " ";
  line += cgi['room'];
  line += " ";
  line += cgi['time'];

  if (cgi['performance'] == "duet")
    line += " " + cgi['performance'] + " ";
    line += cgi['fname2'] + " ";
    line += cgi['lname2'] + " ";
    line += cgi['id2'];
  end

  lines.push(line);
  return lines;
end


##############################################################
# FUNCTION parseLines
# Prints an HTML table to stdout
##############################################################
def parseLines(lines)
  #Start the table
  puts "<table>"
  puts "  <tr>"
  puts "    <th>"
  puts "      Name"
  puts "    </th>"
  puts "    <th>"
  puts "      I-Number"
  puts "    </th>"
  puts "    <th>"
  puts "      Skill Level"
  puts "    </th>"
  puts "    <th>"
  puts "      Intrument"
  puts "    </th>"
  puts "    <th>"
  puts "      Location"
  puts "    </th>"
  puts "    <th>"
  puts "      Time"
  puts "    </th>"
  puts "  </tr>"

  #add a line in the table for each line in the file
  for line in lines
    items = line.split;
    puts "  <tr>"
    puts "    <td>"
    puts "      #{items[0]} #{items[1]}"
    puts "    </td>"
    puts "    <td>"
    puts "      #{items[2]}"
    puts "    </td>"
    puts "    <td>"
    puts "      #{items[3]}"
    puts "    </td>"
    puts "    <td>"
    puts "      #{items[4]}"
    puts "    </td>"
    puts "    <td>"
    puts "      #{items[5]} \##{items[6]}"
    puts "    </td>"
    puts "    <td>"
    puts "      #{items[7]}"
    puts "    </td>"
    puts "  </tr>"

    if (items[8] == 'duet')
      puts "  <tr>"
      puts "    <td>"
      puts "      DUET: #{items[9]} #{items[10]}"
      puts "    </td>"
      puts "    <td>"
      puts "      #{items[11]}"
      puts "    </td>"
      puts "    <td>"
      puts " \" \" "
      puts "    </td>"
      puts "    <td>"
      puts " \" \" "
      puts "    </td>"
      puts "    <td>"
      puts " \" \" "
      puts "    </td>"
      puts "    <td>"
      puts " \" \" "
      puts "    </td>"
      puts "  </tr>"
    end
  end
  puts "</table>"
end;


cgi = CGI.new(level = "html4")

fin = File.new("data/registered", "a+")
lines=[];
lines = fin.readlines();
fin.close;

if (!(cgi['fname'].empty?))
  lines = addLine(cgi,lines);
  fout = File.new("data/registered", "r+")
  fout.puts lines;
  fout.close;
  print "Content-type: text/html\n\n";
end
 
parseLines(lines);

