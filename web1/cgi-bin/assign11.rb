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
puts "       <link href='http://fonts.googleapis.com/css?family=Open+Sans'
               rel='stylesheet' type='text/css'/>
            <link href='http://fonts.googleapis.com/css?family=Ubuntu'
               rel='stylesheet' type='text/css'/>"
puts "   </head>"
puts "   <body>"
puts "   <div id='main'>"
puts "      <h1>Please review your purchase</h1>"
puts "       <hr/>"
puts "      <label>Name: </label>#{cgi['fname']} #{cgi['lname']}<br/>"
puts "      <label>Address: </label><br/><br/>"
puts "      <div id='address'>#{cgi['address']}<br/>"
if (cgi['address2'].length > 0)
   puts "   #{cgi['address2']}<br/>"
end
puts "      #{cgi['city']}, #{cgi['state']} #{cgi['zip']}<br/></div>"
puts "      <label>Phone: </label> #{cgi['phone']}<br/>"
puts "      <label>Email: </label> #{cgi['email']}<br/>"
puts "      <div id='order'> <h2>Items Ordered:</h2>"
puts "         <table><tr><th>Item</th><th>Price</th></tr>" 

items = ["wheat", "bread", "milk", "cheese"];
total = 0.0;
0.upto(3) do |i|
   if (cgi.has_key?(items[i]))
      print "           <tr><td>#{items[i].capitalize}</td><td>"
      print "$%1.2f" % cgi[items[i]];
      puts "</td></tr>"
      total = total + cgi[items[i]].to_f;
   end
end
print "           <tr><td style='font-size:130%;'><strong>Total:</strong></td><td style='font-size:130%;'><strong>"
print "$%2.2f" % total
puts "</strong></td></tr>"
puts "         </table>"
puts "      </div><br/>"
puts "      <label>Credit Card:</label> #{cgi['cardType']}<br/>";
print "      <label>Expiration Date: </label>"

months = ["JolleysMonth", "January", "February", "March", 
          "April", "May", "June", "July", "August", 
          "September", "October", "November", "December"];
print months[cgi['expMonth'].to_i];
puts " #{cgi['expYear']}<br/><br/>"
puts "      <form action='http://localhost/cgi-bin/jol10005/assign11_a.rb'>"
puts "         <input type='submit' name='submit' value='Cancel'/>"
puts "         <input type='submit' name='submit' value='Confirm'/>"
puts "      </form>"
puts "   </div>"
puts "   </body>"
puts "</html>"
