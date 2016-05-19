<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="studentList">
   <html>
      <head>
         <link rel="stylesheet" type="text/css" href="http://localhost/~jolleyboy/a10xml.css"/>
         <script src="http://localhost/~jolleyboy/a10xml.js" type="text/javascript"></script>
      </head>
     
      <body>
         <div id="bodyblackbar"></div>
         <div id="bodybluebar"></div>
         <div id="main">
            <div id="blackbar">
            <table id="nav">
               <tr>
                  <td style="padding-left:4px;">Home</td><td>About BYUI</td>
                  <td>Academics</td>
                  <td>Student Life</td><td style="border-right:none;">Contact BYUI</td>
               </tr>
            </table>
            <div id="search">
               <table id="smallnav">
                  <tr>
                     <td>Directories</td><td>Ask BYUI</td>
                     <td>Mobile Tools</td><td style="border:none;">myBYUI</td>
                  </tr>
               </table>
               <input id="sbar" type="text"/>
               <img id="searchPic"
                src="http://localhost/~jolleyboy/images/search.png"/>
            </div>
         </div>
         <div id="bluebar">
            <img src="http://localhost/~jolleyboy/images/byuilogo.png"/>
            <div id="buttons">
               <button>Students</button>
               <button>Future Students</button>
               <button>Parents</button>
               <button>Employees</button>
               <button>Alumni</button>
               <button>Visitors</button>
            </div>
            <span id="campusd" style="color:white">Campus Directory</span>
         </div>

         <div id="header2">
            <span id="title"><h3>Student Directory</h3></span>
            <label>SEARCH FOR</label>
            <input type="text" value="Best Friends"/>
            <label>SEARCH BY</label>
            <select>
               <option>Name Last,First</option>
            </select>
            <select>
               <option>From (optional)</option>
            </select>
            <button id="orange">SEARCH</button>
         </div>
            <div id="students">
            <table id="studentsTable">
               <tr>
                  <th>NAME</th>
                  <th>HOMETOWN</th>
                  <th>COLLEGE</th>
                  <th>DEPARTMENT</th>
                  <th>MAJOR</th>
               </tr>
               <xsl:for-each select="student">
                  <xsl:sort select="name/last"/>
                  <tr>
                     <td>
                        <xsl:value-of select="name/last"/> 
                        <xsl:value-of select="name/first"/>
                     </td>
                     <td>
                        <xsl:value-of select="location/city"/>
                        <xsl:value-of select="location/state"/>
                     </td>
                     <xsl:for-each select="college">
                        <td style="text-align:center;">
                           <xsl:value-of select="@name"/>
                        </td>
                        <td>
                           <xsl:value-of select="department/@name"/>
                        </td>
                           <td>
                              <xsl:value-of select="department/major"/>
                           </td>
                        
                     </xsl:for-each>
                  </tr>
               </xsl:for-each>
            </table>
            </div>
            <img id="fpic" src="http://localhost/~jolleyboy/images/fpic.png"/>
            <div id="bluebar2">
               <div id="buttons2">
                  <button>Students</button>
                  <button>Future Students</button>
                  <button>Parents</button>
                  <button>Employees</button>
                  <button>Alumni</button>
                  <button>Visitors</button>
               </div>
               <table id="rightnav">
                  <tr>
                     <td>Directories</td><td>Ask BYUI</td>
                     <td>Mobile Tools</td><td style="border:none;">myBYUI</td>
                  </tr>
               </table>
            </div>
            <div id="blackbar2"> 
             <img id="churchlogo" src="http://localhost/~jolleyboy/images/churchlogo.png"/>
             <div id="info">
               <p>Made by Joshua Jolley<br/>
                  Images and design from www.byui.edu</p>
             </div>  
            </div>
         </div>  
         <div id="bodybluebar2"></div>
         <div id="bodyblackbar2">
         </div>
         <div id="bodygreybar"></div>
      </body>
   </html>
</xsl:template>  
</xsl:stylesheet>