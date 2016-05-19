#!/usr/bin/ruby -w
print "Content-type: text/html\n\n";

puts "<h2>Purchase Tickets</h2>
      <div id='content-top'>
         <img src='images/ticket.png'>
         <h3>Upcoming Events</h3>
         <table style='width:250px; text-align:left;border:1px solid #AAAAAA'>
            <tr>
               <th>
                  Event
               </th>
               <th>
                  Price
               </th>
            </tr>
            <tr>
               <th>
                  Extravaganza
               </th>
               <th>
                  $5.00
               </th>
            </tr>
            <tr>
               <th>
                  University Choir's Christmas
               </th>
               <th>
                  $3.00
               </th>
            </tr>
            <tr>
               <th>
                  Teacher's Ensemble
               </th>
               <th>
                  $5.00
               </th>
            </tr>
            <tr>
               <th>
                  Christmas with Motab
               </th>
               <th>
                  $25.00
               </th>
            </tr>
         </table><br/>
         <label>Select Event: </label>
         <select name='performance' onchange='loadInfo();'>
            <option value=""> </option>
            <option value='5'>Extravaganza</option>
            <option value='3'>University Choir's Christmas</option>
            <option value='5'>Teacher's Ensemble</option>
            <option value='25'>Christmas with Motab</option>
         </select><br/>
         <label>Number of Tickets: </label>
         <select name='numTickets' onchange='getTotal();'>
            <option value=""> </option>
            <option value='1'>1</option>
            <option value='2'>2</option>
            <option value='3'>3</option>
            <option value='4'>4</option>
            <option value='5'>5</option>
         </select><br/>
         <input type='button' value='Buy' onclick='buy();'
          style='width:75px; height:37px; font-size:200%'/>
         <h3>Total: <span id='total'></span></h3>
      </div><br/>
      <div id='content-bottom'>
         <h3>Event Information </h3>
         <div id='display'>
         </div>
      </div>
      ";