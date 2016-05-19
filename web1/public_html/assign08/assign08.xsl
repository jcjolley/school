<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="bsa">
   <html>
      <head>
         <link href='http://fonts.googleapis.com/css?family=Open+Sans'
               rel='stylesheet' type='text/css'/>
         <link href='http://fonts.googleapis.com/css?family=Ubuntu'
               rel='stylesheet' type='text/css'/>
         <link rel="stylesheet" type="text/css" href="a08.css"/>
         <script src="a08.js" type="text/javascript"></script>
      </head>
      <body>
         <div id="main">
            <h1>Boy Scouts of America</h1>
            <xsl:for-each select="council">
               <div class="council">
               <h2> <label>Council: </label><xsl:value-of select="@name"/> </h2>
               <xsl:for-each select="troop">
                  <div class="troop">
                     <h3>
                        <label>Troop: </label> 
                        <xsl:value-of select="@unit"/> #
                        <xsl:value-of select="@number"/>
                     </h3>
                  <xsl:for-each select="scout">
                     <xsl:sort select="lname"/>
                     <div class="scout">
                        <strong>
                        <xsl:value-of select="lname"/>,&#160; 
                        <xsl:value-of select="fname"/> 
                        <br/> 
                        </strong>
                        <label>Phone: </label>
                        <xsl:value-of select="phone"/><br/>
                        
                        <div class="address">
                           <label>Address:</label><br/>
                           <xsl:value-of select="address/street"/><br/>
                           <xsl:value-of select="address/city"/>,&#160; 
                           <xsl:value-of select="address/state"/>
                       </div>
                        <xsl:if test="count(rank) &gt; 0">
                           <div class="rank">
                              <label>Ranks: </label> 
                              <select>
                                 <xsl:for-each select="rank">
                                    <option>   
                                       <xsl:value-of select="."/>
                                       | Earned:
                                       <xsl:value-of select="@date-earned"/>
                                    </option>
                                 </xsl:for-each>
                              </select>
                           </div>
                           </xsl:if>
                        <xsl:if test="count(meritbadge) &gt; 0">
                           <div class="mbadge">
                           <label>Badges:</label>
                           <select>
                              <xsl:for-each select="meritbadge">
                                 <option>   
                                    <xsl:value-of select="."/>
                                    | Earned:
                                    <xsl:value-of select="@date-earned"/>
                                 </option>
                              </xsl:for-each>
                           </select>
                           </div>
                        </xsl:if>
                     </div> <!-- end of scout --><br/>
                  </xsl:for-each>
                  </div> <!-- end of troop -->
               </xsl:for-each>
               </div> <!-- end of council -->
            </xsl:for-each>
         </div>
      </body>
   </html>
</xsl:template>

</xsl:stylesheet>