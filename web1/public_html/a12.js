/**************************************************
*FUNCTION: ajax
*This function validates the input of all functions;
***************************************************/
function ajax()
{
    var scity  = document.getElementById('startCity');
    var sstate = document.getElementById('startState');
    var ecity  = document.getElementById('endCity');
    var estate = document.getElementById('endState');

    var URL = "http://157.201.194.254/cgi-bin/ercanbracks/mileage/mileageAjaxXML";
    var query = "?startCity=" + scity.value;
    query += "&startState=" + sstate.value;
    query += "&endCity=" + ecity.value;
    query += "&endState=" + estate.value;
    
    URL += query;
    
    //Make an XMLHttpRequest object for the right browser
    if (window.XMLHttpRequest) //everything other than IE
    {
      xmlhttp=new XMLHttpRequest();
    }
    else  //for IE
    {
      xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
    }

    //our callback function
    xmlhttp.onreadystatechange=function()
    {
        //when it's ready and found the file
        if (xmlhttp.readyState==4 && xmlhttp.status==200)
        {
            xmlDoc=xmlhttp.responseXML;
            startcity  = xmlDoc.getElementsByTagName("startcity")[0].childNodes[0].nodeValue;
            startstate = xmlDoc.getElementsByTagName("startstate")[0].childNodes[0].nodeValue;
            endcity    = xmlDoc.getElementsByTagName("endcity")[0].childNodes[0].nodeValue;
            endstate   = xmlDoc.getElementsByTagName("endstate")[0].childNodes[0].nodeValue;
            miles      = xmlDoc.getElementsByTagName("miles")[0].childNodes[0].nodeValue;
            tmode      = xmlDoc.getElementsByTagName("tmode");

            displayString = "There are " + miles + " miles between ";
            displayString += startcity + ", " +startstate;
            displayString += " and " + endcity + ", " + endstate + "<br/>";
            displayString += "Available Travel Methods: <select>"

            for (i = 0; i < tmode.length; i++)
            {
                displayString += "<option>";
                displayString += tmode[i].childNodes[0].nodeValue;
                displayString += "</option>";
            }

            displayString += "</select>";
            document.getElementById("display").innerHTML=displayString;
        }
    }

    //call the methods to actually get it to do the work! :)
    xmlhttp.open("GET",URL,true);
    xmlhttp.send();
}
