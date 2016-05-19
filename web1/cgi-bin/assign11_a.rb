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

cgi = CGI.new(level = "html4")

print "Content-type: text/html\n\n";
puts "<html>"
puts "   <head>"
puts "      <title>Review your purchase</title>"
puts "      <link rel=\"stylesheet\" type=\"text/css\" href=\"http://localhost/~jolleyboy/a11.css\"/>"
puts "   </head>"
puts "   <body>"
puts "   <div id='thanks'>"
if (cgi['submit'] == "Confirm")
   puts"<h1>Purchase confirmed</h1>"
else
   puts"<h1>Purchase cancelled</h1>"
end
puts "   </div>"
puts "   </body>"
puts "</html>"