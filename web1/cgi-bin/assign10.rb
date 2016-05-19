#!/usr/bin/ruby -w
fNames = ["Josh", "Katie", "Dustin", "Brenton", "Lance"];
lNames = ["Jolley,", "Jolley,", "Harvey,", "Kreiger,", "Katwijk,"];
cities = ["Olympia,", "Rigby,", "Tumwater,", "Lacey,", "Rexburg,"];
states = ["WA", "ID", "WA", "WA", "ID"]
majors = ["Computer Science", "General Studies", "Computer Science", "Computer Science", "Eletrical Engineering"]

print "Content-type: text/xml\n\n";

puts '<?xml version="1.0"?>';
puts '<!DOCTYPE studentList SYSTEM "../../~jolleyboy/assign10.dtd">';
puts '<?xml-stylesheet type="text/xsl" href="../../~jolleyboy/assign10.xsl"?>';

puts '<studentList>'
0.upto(4) do |i|
   puts '<student>'
   puts '   <name>'
   puts '      <first>'
   puts "#{fNames[i]}"
   puts '      </first>'
   puts '      <last>'
   puts "#{lNames[i]}"
   puts '      </last>'
   puts '   </name>'
   puts '   <location>'
   puts '      <city>'
   puts "#{cities[i]}"
   puts '      </city>'
   puts '      <state>'
   puts "#{states[i]}";
   puts '      </state>'
   puts '   </location>'
   puts '   <college name="BYU-I">'
   puts '      <department name="Physical Sciences and Engineering">'
   puts '         <major>'
   puts "#{majors[i]}"
   puts '         </major>'
   puts '      </department>'
   puts '   </college>'
   puts '</student>'
end
puts '</studentList>';